#include <Arduino.h>

#include "canbus.h"
#include "buzzer.h"
#include "battery.h"

#define WALK 0xA5
#define WALK_OFF 0x5A

CAN_device_t CAN_cfg; // CAN Config
// const int rx_queue_size = 10; // Receive Queue size
// unsigned long previousMillis = 0; // will store last time a CAN Message was send
// const int interval = 1000;        // interval at which send CAN Messages (milliseconds)

PLEVELS powers[3] = {
    {.mean = 0x1E, .max = 0x23, .code = 0x06, .buzzer = 1},
    {.mean = 0x28, .max = 0x5A, .code = 0x08, .buzzer = 2},
    {.mean = 0x5F, .max = 0x64, .code = 0x09, .buzzer = 3}};

SETTINGS settings = {.running = true, .motor_is_alive = false, .initial_assistance = 0};

// QueueHandle_t xQueueBuzzer = NULL;
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

  // 0x5A, 0x0B, 0x5A, plevel->mean, 0x00, plevel->max}};
  // tx->message = (CAN_frame_t){.FIR.B.DLC = 7, .MsgID = 0x300, .data.u8 = {0x03, 0x5A, 0x0B, 0x5A, plevel->mean, 0x00, plevel->max}}; // {0x03,0x5A,0x0B,0x5A,0x1E,0x00,0x23}
}

void canbus_300_task(void *pvParameter)
{
  for (int i = 0; i < 3; i++)
    initialize_assistance(&tx_assistances[i], &powers[i]);

  tx_assistance = &tx_assistances[settings.initial_assistance];
  for (;;)
  {
    xSemaphoreTake(xSemaphoreTx, portMAX_DELAY);
    ESP_LOGD(LOG_TAG, "tx: id=%03x ....%02x00%02x", tx_assistance->message.MsgID, tx_assistance->message.data[4], tx_assistance->message.data[6]);
    ESP32Can.CANWriteFrame(&tx_assistance->message);
    xSemaphoreGive(xSemaphoreTx);
    vTaskDelay(pdMS_TO_TICKS(tx_assistance->interval));
  }
}

void canbus_400_task(void *pvParameter)
{
  TX_FRAME tx;
  tx.interval = 100;
  tx.message.FIR.B.FF = CAN_frame_std;
  tx.message.MsgID = 0x400;
  tx.message.FIR.B.DLC = 4;
  tx.message.data.u8[0] = 0x01;
  tx.message.data.u8[1] = 0x00;
  tx.message.data.u8[2] = 0x0C;
  tx.message.data.u8[3] = 0x00;
  Serial.println("400 task started");
  vTaskDelay(pdMS_TO_TICKS(20));
  for (;;)
  {
    ESP_LOGD(LOG_TAG, "tx: id=%03x", tx.message.MsgID);
    // Serial.printf("tx: id=%03x\n", tx.message.MsgID);
    ESP32Can.CANWriteFrame(&tx.message);
    vTaskDelay(pdMS_TO_TICKS(tx.interval));
  }
}

void canbus_451_task(void *pvParameter)
{
  /* complete 4 messages transmitted before any 300 message */
  messages_out[0].interval = 50;
  messages_out[0].message.MsgID = 0x451;
  messages_out[0].message.FIR.B.DLC = 7;
  messages_out[0].message.data.u8[0] = 0x10;
  messages_out[0].message.data.u8[1] = 0x01;
  messages_out[0].message.data.u8[2] = 0x00;
  messages_out[0].message.data.u8[3] = 0x00;
  messages_out[0].message.data.u8[4] = powers[0].max;
  messages_out[0].message.data.u8[5] = powers[1].max;
  messages_out[0].message.data.u8[6] = powers[2].max;

  messages_out[1].interval = 50;
  messages_out[1].message.MsgID = 0x451;
  messages_out[1].message.FIR.B.DLC = 5;
  messages_out[1].message.data.u8[0] = powers[0].code;
  messages_out[1].message.data.u8[1] = 0x01;
  messages_out[1].message.data.u8[2] = 0x00;
  messages_out[1].message.data.u8[3] = 0x00;
  messages_out[1].message.data.u8[4] = powers[0].mean;

  messages_out[2].interval = 50;
  messages_out[2].message.MsgID = 0x451;
  messages_out[2].message.FIR.B.DLC = 5;
  messages_out[2].message.data.u8[0] = powers[1].code;
  messages_out[2].message.data.u8[1] = 0x01;
  messages_out[2].message.data.u8[2] = 0x00;
  messages_out[2].message.data.u8[3] = 0x00;
  messages_out[2].message.data.u8[4] = powers[1].mean;

  messages_out[3].interval = 50;
  messages_out[3].message.MsgID = 0x451;
  messages_out[3].message.FIR.B.DLC = 5;
  messages_out[3].message.data.u8[0] = powers[2].code;
  messages_out[3].message.data.u8[1] = 0x01;
  messages_out[3].message.data.u8[2] = 0x00;
  messages_out[3].message.data.u8[3] = 0x00;
  messages_out[3].message.data.u8[4] = powers[2].mean;

  int current = 0;

  for (;;)
  {
    ESP_LOGD(LOG_TAG, "tx: id=%03x %02x...%02x", messages_out[current].message.MsgID, messages_out[current].message.data[0], messages_out[current].message.data[4]);
    ESP32Can.CANWriteFrame(&messages_out[current].message);
    vTaskDelay(pdMS_TO_TICKS(messages_out[current].interval));

    if (++current >= MESSAGES_OUT)
    {
      current = 0;
      // xSemaphoreGive(xSemaphore300); // now transmit 300
    }
  }
}

void canbus_receive_task(void *pvParameter)
{
  int transition = 0;
  CAN_frame_t rx_frame;
  uint8_t button, walk_button; //, soc1, soc2;
  //long charge1, charge2;

  for (;;)
  {
    if (xQueueReceive(CAN_cfg.rx_queue, &rx_frame, portMAX_DELAY) == pdTRUE)
    {
      if (rx_frame.MsgID == 0x454) // from motor 0x454 or from battery 0x300)
      {
        if (!battery.motor_is_alive)
        {
          // motor_is_alive = true;
          battery.motor_is_alive = true;
          buzzer_play(tx_assistance->buzzer);
        }
        button = rx_frame.data.u8[6];
        if (button == 0x0A || button == 0x0E) //  button + or -
        {
          if (transition > 0)
          {
            ESP_LOGI(LOG_TAG, "power changed to %x", tx_assistance->message.data.u8[4]);
            xSemaphoreTake(xSemaphoreTx, portMAX_DELAY);
            tx_assistance->message.data.u8[6] = transition; // restore value, we have to send 300#035A0B5A28005A
            transition = 0;
            xSemaphoreGive(xSemaphoreTx);
            buzzer_play(tx_assistance->buzzer);
          }
          else
          {
            for (int i = 0; i < 3; i++) // search wanted power
            {
              if (rx_frame.data.u8[4] == tx_assistances[i].message.data.u8[4])
              {
                ESP_LOGI(LOG_TAG, "power changing from %x to %x", tx_assistance->message.data.u8[4], rx_frame.data.u8[4]);

                xSemaphoreTake(xSemaphoreTx, portMAX_DELAY);
                tx_assistance = &tx_assistances[i];

                if (transition == 0 && (button == 0x0A || button == 0x0E)) // just arrived 454#035A0B5A28000E, so we have to send 300#035A0B5A28000E
                {
                  transition = tx_assistance->message.data.u8[6]; // save value
                  tx_assistance->message.data.u8[6] = button;     // send 0E
                }

                xSemaphoreGive(xSemaphoreTx);
                break;
              }
            }
          }
        }
        walk_button = rx_frame.data.u8[1];
        if (tx_assistance->message.data.u8[1] != walk_button)
        {
          xSemaphoreTake(xSemaphoreTx, portMAX_DELAY);
          tx_assistance->message.data.u8[1] = (walk_button == WALK ? WALK : WALK_OFF);
          xSemaphoreGive(xSemaphoreTx);
        }
      }
      else if (rx_frame.MsgID == 0x201)
      { // from motor 0x201 velocity payload
        if (rx_frame.data.u8[0] || rx_frame.data.u8[1])
        { // velocity > 0, bike is moving
          battery.resetIdle();
        }
      }
      else if (rx_frame.MsgID == 0x402)  
      {
        // 402#5D 00 00 00 CC AC 05 00
        // 5D = 93% soc
        // 0005ACCC = 371916mWh = 371.916Wh charge
        battery.soc1 = rx_frame.data.u8[0];
        battery.charge1 = (long)rx_frame.data.u8[7]<<24|(long)rx_frame.data.u8[6]<<16|rx_frame.data.u8[5]<<8|rx_frame.data.u8[4];

      }
      else if (rx_frame.MsgID == 0x403) 
      {
        // 403#5C 00 00 00 D4 0D 06 00
        // 0x00060DD4 = 396756mWh = 396.756Wh —> 396.756*1.12 = 444wH
        battery.soc2 = rx_frame.data.u8[0];
        battery.charge2 = (long)rx_frame.data.u8[7]<<24|(long)rx_frame.data.u8[6]<<16|rx_frame.data.u8[5]<<8|rx_frame.data.u8[4];
      }
    }
  }
}

// void canbus_setup_test()
// {
// pinMode(CANBUS_TX_PIN, OUTPUT);
// digitalWrite(CANBUS_TX_PIN, HIGH);

// pinMode(CANBUS_RX_PIN, OUTPUT);
// digitalWrite(CANBUS_RX_PIN, HIGH);

// }

void canbus_setup()
{
  CAN_cfg.speed = CAN_SPEED_250KBPS;
  CAN_cfg.tx_pin_id = (gpio_num_t)CANBUS_TX_PIN;
  CAN_cfg.rx_pin_id = (gpio_num_t)CANBUS_RX_PIN;
  CAN_cfg.rx_queue = xQueueCreate(5, sizeof(CAN_frame_t));

  xSemaphoreTx = xSemaphoreCreateMutex();
  xSemaphoreGive((xSemaphoreTx));

  // pinMode(CANBUS_GND_PIN, OUTPUT);
  // digitalWrite(CANBUS_GND_PIN, LOW);

  // pinMode(CANBUS_POWER_PIN, OUTPUT);
  // digitalWrite(CANBUS_POWER_PIN, HIGH);

  vTaskDelay(pdMS_TO_TICKS(30));
  // esp_log_level_set("*", ESP_LOG_DEBUG);
  ESP32Can.CANInit();

  xTaskCreate(&canbus_300_task, "canbus_300_task", 2048, NULL, 5, NULL);
  xTaskCreate(&canbus_400_task, "canbus_400_task", 2048, NULL, 5, NULL);
  vTaskDelay(pdMS_TO_TICKS(1525));
  xTaskCreate(&canbus_451_task, "canbus_451_task", 2048, NULL, 5, NULL);
  xTaskCreate(&canbus_receive_task, "canbus_receive_task", 2048, NULL, 5, NULL);

  Serial.println("canbus initialized");
}