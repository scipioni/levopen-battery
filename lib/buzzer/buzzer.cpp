#include <Arduino.h>
#include "buzzer.h"

//#define ACTIVE_BUZZER

QueueHandle_t xQueueBuzzer = NULL;

int melody[] = {
    NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};

int freq = 6000;
int channel = 0;
int resolution = 8;
int duty_cycle = 250;

void buzzer_play(int count)
{
    // ESP_LOGI(LOG_TAG, "buzzer %d", count);
    xQueueSend(xQueueBuzzer, &count, pdMS_TO_TICKS(1));
}
#ifdef ACTIVE_BUZZER

void buzzer_on()
{
    digitalWrite(BUZZER_PIN, HIGH); // buzzer acceso
}

void buzzer_task(void *parameter)
{
    uint8_t count, buff;
    long last_call = 0;

    for (;;)
    { // infinite loop

        xQueueReceive(xQueueBuzzer, &count, portMAX_DELAY);

        if (millis() > last_call)
        { // se non stanno arrivando troppi messaggi ravvicinati
            Serial.printf("buzzer play %d times", count);
            buff = count;
            while (buff--)
            {
                digitalWrite(BUZZER_PIN, HIGH); // buzzer acceso
                vTaskDelay(pdMS_TO_TICKS(50));
                digitalWrite(BUZZER_PIN, LOW); // buzzer spento
                vTaskDelay(pdMS_TO_TICKS(50));
            }

            last_call = millis() + 1000;
        }
    }
}

void buzzer_setup()
{
    xQueueBuzzer = xQueueCreate(5, sizeof(uint8_t));

    pinMode(BUZZER_PIN, OUTPUT);
    digitalWrite(BUZZER_PIN, LOW);

    xTaskCreate(
        buzzer_task,   // Function that should be called
        "buzzer_task", // Name of the task (for debugging)
        2048,          // Stack size (bytes)
        NULL,          // Parameter to pass
        1,             // Task priority
        NULL           // Task handle
    );

    Serial.println("buzzer initialized");
    // vTaskDelay(pdMS_TO_TICKS(3000));
    buzzer_play(3);
}
#else

void buzzer_on()
{
    // digitalWrite(BUZZER_PIN, HIGH); // buzzer acceso
    ledcWriteTone(channel, freq);
    ledcWrite(channel, duty_cycle);
}

void buzzer_task(void *parameter)
{
    uint8_t count, buff;
    long last_call = 0;
    // buzzer_play(3);

    for (;;)
    { // infinite loop

        xQueueReceive(xQueueBuzzer, &count, portMAX_DELAY);

        if (millis() > last_call)
        { // se non stanno arrivando troppi messaggi ravvicinati
            Serial.printf("buzzer play %d times", count);
            buff = count;

            while (buff--)
            {
                ledcWrite(channel, duty_cycle);
                vTaskDelay(pdMS_TO_TICKS(60));
                ledcWrite(channel, 0);
                vTaskDelay(pdMS_TO_TICKS(50));
            }

            last_call = millis() + 1000;
        }
    }
}

void buzzer_test()
{
    ledcWrite(channel, duty_cycle); // duty cycle

    for (int freq = 255; freq < 10000; freq = freq + 250)
    {
        Serial.println(freq);
        ledcWriteTone(channel, freq);
        delay(1000);
    }
}

void buzzer_test_duty_cycle()
{
    ledcWriteTone(channel, 2000);
    for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle = dutyCycle + 10)
    {

        Serial.println(dutyCycle);

        ledcWrite(channel, dutyCycle);
        delay(1000);
    }
}

void buzzer_setup()
{
    xQueueBuzzer = xQueueCreate(5, sizeof(uint8_t));

    ledcSetup(channel, freq, resolution);
    ledcAttachPin(BUZZER_PIN, channel);
    ledcWriteTone(channel, freq);
    ledcWrite(channel, 0); // 0 duty cycle = off
    // buzzer_test();
    //buzzer_test_duty_cycle();

    xTaskCreate(
        buzzer_task,   // Function that should be called
        "buzzer_task", // Name of the task (for debugging)
        2048,          // Stack size (bytes)
        NULL,          // Parameter to pass
        1,             // Task priority
        NULL           // Task handle
    );
    Serial.println("buzzer initialized");
    // vTaskDelay(pdMS_TO_TICKS(3000));
    buzzer_play(3);
}

#endif