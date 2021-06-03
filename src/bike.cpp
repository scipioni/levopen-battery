#include <Arduino.h>
#include <BLE2902.h>

#include "led.h"
#include "buzzer.h"
#include "bike.h"

#define BLE_NOTIFY_INTERVAL 1000

Bike bike = Bike();
Battery battery = Battery(BATTERY_K, BATTERY_V_MIN_mV, BATTERY_V_MAX_mV, BUTTON_PIN);

Bike::Bike()
{
    ;
}

void Bike::setup()
{
    led_setup();
    buzzer_setup();
    buzzer_play(3); // togliere

#if CANBUS_ENABLE == 1
    canbus_setup();
#endif

    setup_ble();

    xTaskCreatePinnedToCore(this->notify_task, "notify", 10500, NULL, 5, NULL, ARDUINO_RUNNING_CORE);
}

void Bike::poweroff()
{
    led_interval = BLINK_FAST;
    Serial.printf("power off, bye...");
#if LATCH_MODE == CHANNEL_N
    //digitalWrite(POWER_BUTTON_PIN, LOW);
    buzzer_play(1);
    pinMode(BUTTON_PIN, INPUT_PULLDOWN);
#else
    pinMode(POWER_BUTTON_PIN, INPUT_PULLDOWN);

#endif
    //vTaskDelay(1000); // in produzione qui non ci arrivo
    //digitalWrite(POWER_OFF_PIN, LOW); // serve solo se sto alimentando con usb durante il debug
}

void Bike::notify()
{
    this->notify_ble(battery.capacity());
}

void Bike::notify_task(void *parameter) // questa è statica
{
    for (;;)
    {
        bike.notify();

        vTaskDelay(BLE_NOTIFY_INTERVAL / portTICK_PERIOD_MS);
    }
}
