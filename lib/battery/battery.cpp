// https://github.com/rlogiacco/BatterySense

#include "battery.h"
#include <Arduino.h>

void pollBattery(void *parameter)
{
   vTaskDelay(POWER_BUTTON_DELAY);
	for (;;)
	{ // infinite loop
		vTaskDelay(V_POLL_INTERVAL);
		Serial.printf("Battery mean=%dmV last=%dmV capacity=%d%%: button=%d\n",
					  battery.voltage(),
					  battery.voltage_last,
					  battery.capacity(),
					  battery.button());

#ifdef DEBUG_BATTERY
		battery.debug();
#endif
	}
}

Battery::Battery(float k, uint16_t minVoltage, uint16_t maxVoltage, uint8_t sensePin)
{
	button_pressed = 0;
	this->k = k;
	this->sensePin = sensePin;
	//this->activationPin = 0xFF;
	this->minVoltage = minVoltage;
	this->maxVoltage = maxVoltage;
	pinMode(this->sensePin, INPUT);
	analogReadResolution(9); // 9 bit for max 511

#if LATCH_MODE == CHANNEL_N
	pinMode(POWER_BUTTON_PIN, OUTPUT);
	digitalWrite(POWER_BUTTON_PIN, HIGH);
#else
	pinMode(POWER_BUTTON_PIN, INPUT_PULLUP);
#endif

	voltage_mean = 0;
	current_sample = 0;

	// if (this->activationPin < 0xFF)
	// {
	// 	pinMode(this->activationPin, OUTPUT);
	// }
	this->mapFunction = (mapFunction ? mapFunction : &sigmoidal);

	xTaskCreate(
		pollBattery,	// Function that should be called
		"poll battery", // Name of the task (for debugging)
		4096,			// Stack size (bytes)
		NULL,			// Parameter to pass
		1,				// Task priority
		NULL			// Task handle
	);
	//printf("battery initialized")
}

uint8_t Battery::capacity()
{
	if (voltage_mean <= minVoltage)
	{
		return 0;
	}
	else if (voltage_mean >= maxVoltage)
	{
		return 100;
	}
	else
	{
		return (*mapFunction)(voltage_mean, minVoltage, maxVoltage);
	}
}

bool Battery::button()
{
	return button_pressed > 1;
}

void Battery::debug()
{
	Serial.printf("current=%d   values=", current_sample);
	for (int i = 0; i < V_SAMPLE; i++)
		Serial.printf("%d ", voltages[i]);
	Serial.println("");
}

uint16_t Battery::voltage()
{
	//analogRead(sensePin);

	//delay(2); // allow the ADC to stabilize
	//uint16_t reading = 480 + analogRead(sensePin) * dividerRatio * refVoltage / 511; // 0.48V for diode
	if (voltage_mean == 0)
	{
		Serial.printf("init voltages %d\n", analogRead(sensePin));
		for (int i = 0; i < V_SAMPLE; i++)
			voltages[i] = this->k * analogRead(sensePin); // to speed up mean stabilization
		battery.debug();
	}

	if (current_sample >= V_SAMPLE)
		current_sample = 0;
	voltage_last = this->k * analogRead(sensePin);
	voltages[current_sample++] = voltage_last;

	long tot = 0;
	for (int i = 0; i < V_SAMPLE; i++)
		tot += voltages[i];
	voltage_mean = tot / V_SAMPLE; // 9 bit resolution 512-1

#if LATCH_MODE == CHANNEL_N
	uint16_t button_state = analogRead(sensePin);
	Serial.printf("button analog read %d\n", button_state);
#else
	uint16_t button_state = analogRead(POWER_BUTTON_PIN);
	pinMode(POWER_BUTTON_PIN, INPUT_PULLUP); // analogRead attaches the pin to ADC channel, which remaps it off the PU circuit. You have to set the mode back to INPUT_PULLUP after the read,
#endif

	if (button_state < V_BUTTON_TRIGGER)
	{
		button_pressed++;
	}
	else
	{
		button_pressed = 0;
	}

	return voltage_mean;
}