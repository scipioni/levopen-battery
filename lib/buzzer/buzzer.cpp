#include <Arduino.h>
#include "buzzer.h"

QueueHandle_t xQueueBuzzer = NULL;

void buzzer_play(int count)
{
    //ESP_LOGI(LOG_TAG, "buzzer %d", count);
    xQueueSend(xQueueBuzzer, &count, pdMS_TO_TICKS(1));
}

void buzzer_task(void *parameter)
{
    uint8_t count, buff;

    for (;;)
    { // infinite loop

        xQueueReceive(xQueueBuzzer, &count, portMAX_DELAY);
        buff = count;
        while (buff--)
        {
            digitalWrite(BUZZER_PIN, HIGH); // buzzer acceso
            vTaskDelay(pdMS_TO_TICKS(50));
            digitalWrite(BUZZER_PIN, LOW); // buzzer spento
            vTaskDelay(pdMS_TO_TICKS(50));
        }
    }
}

void buzzer_setup()
{
    xQueueBuzzer = xQueueCreate(5, sizeof(uint8_t));

    pinMode(BUZZER_PIN, OUTPUT);
    digitalWrite(BUZZER_PIN, LOW);

    xTaskCreate(
        buzzer_task, // Function that should be called
        "buzzer_task",    // Name of the task (for debugging)
        2048,        // Stack size (bytes)
        NULL,        // Parameter to pass
        1,           // Task priority
        NULL         // Task handle
    );

    Serial.println("buzzer initialized");
}