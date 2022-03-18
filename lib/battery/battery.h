// https://github.com/rlogiacco/BatterySense#higher-than-5v-with-external-voltage-regulator

#ifndef BATTERY_H_
#define BATTERY_H_

#include <Arduino.h>
#include <movingAvg.h>

#define V_SAMPLE 30 // how many values use for mean value
//#define BUTTON_PIN 12
//#define BATTERY_V_MIN_mV 35000 // real value minus 500mV of diode
//#define BATTERY_V_MAX_mV 42000
//#define BATTERY_K 40800/244 // empiric: Vbattery_mV/last
#define V_POLL_INTERVAL 1000 //

#ifdef BOARD_TTGO
#define V_BUTTON_TRIGGER 120
#endif

#ifdef BOARD_DOIT
#define V_BUTTON_TRIGGER 130
#endif

//#define POWER_BUTTON_PIN 4
#define POWER_BUTTON_DELAY 2000 // ms
#define IDLE_POWEROFF_MOTOR 300 // sec
#define IDLE_POWEROFF_CHARGING 3600*4 // sec
//#define DEBUG_BATTERY

typedef uint8_t (*mapFn_t)(uint16_t, uint16_t, uint16_t);

class Battery
{
public:
	/**
		 * Creates an instance to monitor battery voltage and level.
		 * Initialization parameters depend on battery type and configuration.
		 *
		 * @param minVoltage is the voltage, expressed in millivolts, corresponding to an empty battery
		 * @param maxVoltage is the voltage, expressed in millivolts, corresponding to a full battery
		 * @param sensePin is the analog pin used for sensing the battery voltage
		 */
	Battery(float k, uint16_t minVoltage, uint16_t maxVoltage, uint8_t sensePin);

	/**
		 * Enables on-demand activation of the sensing circuit to limit battery consumption.
		 *
		 * @param activationPin is the pin which will be turned HIGH or LOW before starting the battery sensing
		 * @param activationMode is the optional value to set on the activationPin to enable battery sensing, defaults to LOW
		 *            useful when using a resistor divider to save on battery consumption, but it can be changed to HIGH in case
		 *            you are using a P-CH MOSFET or a PNP BJT
		 */
	//void onDemand(uint8_t activationPin, uint8_t activationMode = LOW);

	/**
		 * Activation pin value disabling the on-demand feature.
		 */
	static const uint8_t ON_DEMAND_DISABLE = 0xFF;

	/**
		 * Returns the current battery level as a number between 0 and 100, with 0 indicating an empty battery and 100 a
		 * full battery.
		 */
	uint8_t capacity();

	/**
		 * Returns the current battery voltage in millivolts.
		 */
	uint16_t voltage();

	bool button();

	uint16_t voltage_last = 0;
	uint8_t button_pressed;
	uint16_t voltage_pin_mean;
    bool power = true;
	bool motor_is_alive = false;
	void resetIdle(void);
	bool idle(void);
	uint16_t minVoltage;
	uint16_t maxVoltage;
private:
	uint16_t idle_poweroff = 0;

	float k;
	uint8_t sensePin;
	// uint8_t activationPin;
	// uint8_t activationMode;
	mapFn_t mapFunction;
	uint16_t voltage_mean;
	//uint16_t voltage_mean_old;
	//uint16_t voltages[V_SAMPLE];
	//uint8_t current_sample;
	uint16_t readButtonPin();
	movingAvg voltageAvg = movingAvg(V_SAMPLE); 
};

//
// Plots of the functions below available at
// https://www.desmos.com/calculator/x0esk5bsrk
//

/**
 * Symmetric sigmoidal approximation
 * https://www.desmos.com/calculator/7m9lu26vpy
 *
 * c - c / (1 + k*x/v)^3
 */
static inline uint8_t sigmoidal(uint16_t voltage, uint16_t minVoltage, uint16_t maxVoltage)
{
	// slow
	// uint8_t result = 110 - (110 / (1 + pow(1.468 * (voltage - minVoltage)/(maxVoltage - minVoltage), 6)));

	// steep
	// uint8_t result = 102 - (102 / (1 + pow(1.621 * (voltage - minVoltage)/(maxVoltage - minVoltage), 8.1)));

	// normal
	uint8_t result = round(105 - (105 / (1 + pow(1.724 * (voltage - minVoltage) / (maxVoltage - minVoltage), 5.5))));
	return result >= 100 ? 100 : result;
}

/**
 * Asymmetric sigmoidal approximation
 * https://www.desmos.com/calculator/oyhpsu8jnw
 *
 * c - c / [1 + (k*x/v)^4.5]^3
 */
static inline uint8_t asigmoidal(uint16_t voltage, uint16_t minVoltage, uint16_t maxVoltage)
{
	uint8_t result = 101 - (101 / pow(1 + pow(1.33 * (voltage - minVoltage) / (maxVoltage - minVoltage), 4.5), 3));
	return result >= 100 ? 100 : result;
}

/**
 * Linear mapping
 * https://www.desmos.com/calculator/sowyhttjta
 *
 * x * 100 / v
 */
static inline uint8_t linear(uint16_t voltage, uint16_t minVoltage, uint16_t maxVoltage)
{
	return (unsigned long)(voltage - minVoltage) * 100 / (maxVoltage - minVoltage);
}
#endif // BATTERY_H_

 extern Battery battery;