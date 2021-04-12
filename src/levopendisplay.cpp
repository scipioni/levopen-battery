#include <Arduino.h>
#include <NimBLEDevice.h>
#include "levopendisplay.h"
#include "led.h"

#if CONFIG_FREERTOS_UNICORE
#define ARDUINO_RUNNING_CORE 0
#else
#define ARDUINO_RUNNING_CORE 1
#endif

/*
Sun Apr 11 08:31:06 GMT+02:00 2021: Service 00001800-0000-1000-8000-00805f9b34fb
Characteristics:
|--00002a00-0000-1000-8000-00805f9b34fb: Readable, Writable
|--00002a01-0000-1000-8000-00805f9b34fb: Readable
|--00002a04-0000-1000-8000-00805f9b34fb: Readable

Sun Apr 11 08:31:06 GMT+02:00 2021: Service 00001801-0000-1000-8000-00805f9b34fb
Characteristics:
|--

Sun Apr 11 08:31:06 GMT+02:00 2021: Service 0000180a-0000-1000-8000-00805f9b34fb
Characteristics:
|--00002a29-0000-1000-8000-00805f9b34fb: Readable
|--00002a28-0000-1000-8000-00805f9b34fb: Readable

Sun Apr 11 08:31:06 GMT+02:00 2021: Service 00001816-0000-1000-8000-00805f9b34fb
Characteristics:
|--00002a5b-0000-1000-8000-00805f9b34fb: Notify
|------00002902-0000-1000-8000-00805f9b34fb: <EMPTY>
|--00002a5c-0000-1000-8000-00805f9b34fb: Readable
|--00002a55-0000-1000-8000-00805f9b34fb: Writable, Indicate
|------00002902-0000-1000-8000-00805f9b34fb: <EMPTY>

Sun Apr 11 08:31:06 GMT+02:00 2021: Service 00000001-0000-4b49-4e4f-525441474947
Characteristics:
|--00000011-0000-4b49-4e4f-525441474947: Readable
|--00000021-0000-4b49-4e4f-525441474947: Writable

Sun Apr 11 08:31:06 GMT+02:00 2021: Service 00000002-0000-4b49-4e4f-525441474947
Characteristics:
|--00000012-0000-4b49-4e4f-525441474947: Writable

Sun Apr 11 08:31:06 GMT+02:00 2021: Service 00000003-0000-4b49-4e4f-525441474947
Characteristics:
|--00000013-0000-4b49-4e4f-525441474947: Readable, Notify
|------00002902-0000-1000-8000-00805f9b34fb: <EMPTY>
*/

#define BLE_NAME "SPECIALIZED"
#define BLE_SERVICE_3 "0003"
#define BLE_SERVICE_3_1 "0013"

#define BLE_NOTIFY_INTERVAL 1000

LevopenDisplay levo = LevopenDisplay();

LevopenDisplay::LevopenDisplay()
{
    ;
}

void LevopenDisplay::setup()
{
    led_setup();
    NimBLEDevice::init(BLE_NAME);

    pServer = NimBLEDevice::createServer();
    pServer->setCallbacks(this);

    NimBLEService *pService = pServer->createService(BLE_SERVICE_3);
    this->pCharacteristic = pService->createCharacteristic(BLE_SERVICE_3_1,
                                                           NIMBLE_PROPERTY::READ |
                                                               NIMBLE_PROPERTY::WRITE |
                                                               NIMBLE_PROPERTY::NOTIFY);

    pService->start();
    this->pCharacteristic->setValue("Hello BLE");

    NimBLEAdvertising *pAdvertising = NimBLEDevice::getAdvertising();
    pAdvertising->addServiceUUID(BLE_SERVICE_3);
    pAdvertising->setScanResponse(true); // better false for battery devices
    pAdvertising->start();

    /* has to run the task on the same core as Arduino is running */
    xTaskCreatePinnedToCore(this->notify_cron, "notify", 10500, NULL, 5, NULL, ARDUINO_RUNNING_CORE);
}

void LevopenDisplay::onConnect(NimBLEServer *pServer, ble_gap_conn_desc *desc)
{
    Serial.print("Client connected: ");
    led_interval = BLINK_FAST;
    Serial.println(NimBLEAddress(desc->peer_ota_addr).toString().c_str());
    NimBLEDevice::startAdvertising();
}

void LevopenDisplay::onDisconnect(NimBLEServer *pServer, ble_gap_conn_desc *desc)
{
    Serial.print("Client disconnected: ");
    led_interval = BLINK_SLOW;
    Serial.println(NimBLEAddress(desc->peer_ota_addr).toString().c_str());
    NimBLEDevice::startAdvertising();
}

void LevopenDisplay::notify_cron(void *parameter) // questa è statica
{
    //LevopenDisplay *instance = (LevopenBattery *)parameter;

    for (;;)
    {
        levo.notify();
        vTaskDelay(BLE_NOTIFY_INTERVAL / portTICK_PERIOD_MS);
    }
}

void LevopenDisplay::notify()
{
    Serial.println("notify");
    this->pCharacteristic->setValue(String(millis()));
    this->pCharacteristic->notify();
}