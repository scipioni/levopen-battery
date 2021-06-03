#include <Arduino.h>

#include "canbus.h"

CAN_device_t CAN_cfg;         // CAN Config
const int rx_queue_size = 10; // Receive Queue size
//unsigned long previousMillis = 0; // will store last time a CAN Message was send
//const int interval = 1000;        // interval at which send CAN Messages (milliseconds)

PLEVELS powers[3] = {
    {.mean = 0x1E, .max = 0x23, .code = 0x06, .buzzer = 1},
    {.mean = 0x28, .max = 0x5A, .code = 0x08, .buzzer = 2},
    {.mean = 0x5F, .max = 0x64, .code = 0x09, .buzzer = 3}};

SETTINGS settings = {.running = true, .motor_is_alive = false, .initial_assistance = 0};

//QueueHandle_t xQueueBuzzer = NULL;
#define MESSAGES_OUT 4
TX_FRAME messages_out[MESSAGES_OUT];
TX_FRAME tx_assistances[3];
TX_FRAME *tx_assistance; // current assistance
SemaphoreHandle_t xSemaphoreTx = NULL;
void initialize_assistance(TX_FRAME *tx, PLEVELS *plevel)
{
  tx->interval = 50;
  tx->buzzer = plevel->buzzer;
  tx->message.MsgID = 0x300;
  tx->message.FIR.B.DLC = 7;
  tx->message.data.u8[0] = 0x03;
  tx->message.data.u8[1] = 0x5A;
  tx->message.data.u8[2] = 0x0B;
  tx->message.data.u8[3] = 0x5A;
  tx->message.data.u8[4] = plevel->mean;
  tx->message.data.u8[5] = 0x00;
  tx->message.data.u8[6] = plevel->max;

  //0x5A, 0x0B, 0x5A, plevel->mean, 0x00, plevel->max}};
  //tx->message = (CAN_frame_t){.FIR.B.DLC = 7, .MsgID = 0x300, .data.u8 = {0x03, 0x5A, 0x0B, 0x5A, plevel->mean, 0x00, plevel->max}}; // {0x03,0x5A,0x0B,0x5A,0x1E,0x00,0x23}
}

void canbus_300_task(void *pvParameter)
{
  for (int i = 0; i < 3; i++)
    initialize_assistance(&tx_assistances[i], &powers[i]);

  tx_assistance = &tx_assistances[settings.initial_assistance];
  for (;;)
  {
    xSemaphoreTake(xSemaphoreTx, portMAX_DELAY);
    ESP_LOGD(LOG_TAG, "tx: id=%03x ....%02x00%02x", tx_assistance->message.identifier, tx_assistance->message.data[4], tx_assistance->message.data[6]);
    ESP32Can.CANWriteFrame(&tx_assistance->message);
    xSemaphoreGive(xSemaphoreTx);
    vTaskDelay(pdMS_TO_TICKS(tx_assistance->interval));
  }
}

void canbus_setup()
{
  CAN_cfg.speed = CAN_SPEED_250KBPS;
  CAN_cfg.tx_pin_id = (gpio_num_t)CANBUS_TX_PIN;
  CAN_cfg.rx_pin_id = (gpio_num_t)CANBUS_RX_PIN;
  CAN_cfg.rx_queue = xQueueCreate(rx_queue_size, sizeof(CAN_frame_t));

  xSemaphoreTx = xSemaphoreCreateMutex();
  xSemaphoreGive( ( xSemaphoreTx ) );

  pinMode(CANBUS_GND_PIN, OUTPUT);
  digitalWrite(CANBUS_GND_PIN, LOW);

  pinMode(CANBUS_POWER_PIN, OUTPUT);
  digitalWrite(CANBUS_POWER_PIN, HIGH);

  vTaskDelay(pdMS_TO_TICKS(30));

  ESP32Can.CANInit();

  xTaskCreate(&canbus_300_task, "canbus_300_task", 2048, NULL, 5, NULL);

  Serial.println("canbus initialized");
}