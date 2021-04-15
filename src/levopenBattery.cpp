#include <Arduino.h>
#include <NimBLEDevice.h>
#include <esp_wifi.h>
#include "battery.h"
#include "levopenBattery.h"
#include "led.h"

#if CONFIG_FREERTOS_UNICORE
#define ARDUINO_RUNNING_CORE 0
#else
#define ARDUINO_RUNNING_CORE 1
#endif

#define BLE_NAME "SPECIALIZED"
#define BLE_NOTIFY_INTERVAL 1000

uint8_t newMACAddress[] = {0x32, 0xAE, 0xA4, 0x07, 0x0D, 0x66};
LevopenBattery levo = LevopenBattery();

LevopenBattery::LevopenBattery()
{
    ; 
}

void LevopenBattery::setup()
{
    led_setup();

    

    esp_wifi_set_mac(WIFI_IF_STA, &newMACAddress[0]);

    NimBLEDevice::init(BLE_NAME);

    /** Optional: set the transmit power, default is 3db */
    NimBLEDevice::setPower(ESP_PWR_LVL_P3); /** +7db */

    pServer = NimBLEDevice::createServer();
    pServer->setCallbacks(this);
    pServer->advertiseOnDisconnect(true);

    // pService1800 = pServer->createService(BLE_SERVICE_1800);
    // pChar1800_2A00 = pService1800->createCharacteristic("00002a00-0000-1000-8000-00805f9b34fb", NIMBLE_PROPERTY::READ | NIMBLE_PROPERTY::WRITE);
    // pChar1800_2A00->setValue("5350454349414C495A4544"); // "Device Name"
    // pChar1800_2A01 = pService1800->createCharacteristic("00002a01-0000-1000-8000-00805f9b34fb", NIMBLE_PROPERTY::READ);
    // pChar1800_2A01->setValue("0000"); // "Appearance"
    // pChar1800_2A04 = pService1800->createCharacteristic("00002a04-0000-1000-8000-00805f9b34fb", NIMBLE_PROPERTY::READ);
    // pChar1800_2A04->setValue("1800200000009001"); // "Manufacturer Name String"
    // pService1800->start();

    // pService1801 = pServer->createService(BLE_SERVICE_1801);
    // pService1801->start();

    pService180A = pServer->createService("0000180a-0000-1000-8000-00805f9b34fb"); // device information
    pChar180A_2A28 = pService180A->createCharacteristic("00002a28-0000-1000-8000-00805f9b34fb", NIMBLE_PROPERTY::READ);
    pChar180A_2A28->setValue("56312E372E30"); // "Software Revision String"
    pChar180A_2A29 = pService180A->createCharacteristic("00002a29-0000-1000-8000-00805f9b34fb", NIMBLE_PROPERTY::READ);
    pChar180A_2A29->setValue("5350454349414C495A4544"); // "Manufacturer Name String"

    pService0001 = pServer->createService("00000001-0000-4b49-4e4f-525441474947");
    pChar0001_0011 = pService0001->createCharacteristic("00000011-0000-4b49-4e4f-525441474947", NIMBLE_PROPERTY::READ);
    pChar0001_0011->setValue("010800000000FFFFFFFFFFFFFFFFFFFFFFFFFFFF");

    pService0002 = pServer->createService("00000002-0000-4b49-4e4f-525441474947");
    pChar0002_0012 = pService0002->createCharacteristic("00000012-0000-4b49-4e4f-525441474947", NIMBLE_PROPERTY::WRITE);

    pService0003 = pServer->createService("00000003-0000-4b49-4e4f-525441474947");
    pChar0003_0013 = pService0003->createCharacteristic("00000013-0000-4b49-4e4f-525441474947", NIMBLE_PROPERTY::READ | NIMBLE_PROPERTY::NOTIFY);
    pChar0003_0013->setValue("1234");

    pService1816 = pServer->createService("00001816-0000-1000-8000-00805f9b34fb");
    pChar1816_2A5B = pService1816->createCharacteristic("00002a5b-0000-1000-8000-00805f9b34fb", NIMBLE_PROPERTY::NOTIFY);
    pChar1816_2A5C = pService1816->createCharacteristic("00002a5c-0000-1000-8000-00805f9b34fb", NIMBLE_PROPERTY::READ);
    pChar1816_2A5C->setValue("0300");
    
    /** Start the services when finished creating all Characteristics and Descriptors */
    pService180A->start();
    pService1816->start();
    pService0003->start();
    pService0002->start();
    pService0001->start();

    NimBLEAdvertising *pAdvertising = NimBLEDevice::getAdvertising(); //pServer->getAdvertising();
    pAdvertising->addServiceUUID(pService0003->getUUID());
    pAdvertising->addServiceUUID(pService180A->getUUID());
    pAdvertising->addServiceUUID(pService1816->getUUID());
    pAdvertising->addServiceUUID(pService0001->getUUID());
    pAdvertising->addServiceUUID(pService0002->getUUID());
    pAdvertising->setScanResponse(true); // better false for battery devices
    // pAdvertising->setMinPreferred(0x06); // functions that help with iPhone connections issue
    // pAdvertising->setMaxPreferred(0x12);

    // BLEDevice::startAdvertising();
    pAdvertising->start();

    /* has to run the task on the same core as Arduino is running */
    xTaskCreatePinnedToCore(this->notify_cron, "notify", 10500, NULL, 5, NULL, ARDUINO_RUNNING_CORE);
}

void LevopenBattery::onConnect(NimBLEServer *pServer, ble_gap_conn_desc *desc)
{
    Serial.print("Client connected: ");
    led_interval = BLINK_FAST;
    Serial.println(NimBLEAddress(desc->peer_ota_addr).toString().c_str());
    /** We can use the connection handle here to ask for different connection parameters.
         *  Args: connection handle, min connection interval, max connection interval
         *  latency, supervision timeout.
         *  Units; Min/Max Intervals: 1.25 millisecond increments.
         *  Latency: number of intervals allowed to skip.
         *  Timeout: 10 millisecond increments, try for 5x interval time for best results.  
         */
    pServer->updateConnParams(desc->conn_handle, 24, 48, 0, 60);
    //NimBLEDevice::startAdvertising();
}

void LevopenBattery::onDisconnect(NimBLEServer *pServer, ble_gap_conn_desc *desc)
{
    Serial.print("Client disconnected: ");
    led_interval = BLINK_SLOW;
    Serial.println(NimBLEAddress(desc->peer_ota_addr).toString().c_str());
    //pServer->startAdvertising(); // allow multiple connect
}

void LevopenBattery::notify_cron(void *parameter) // questa è statica
{
    //LevopenDisplay *instance = (LevopenBattery *)parameter;

    for (;;)
    {
        //levo.notify();
        vTaskDelay(BLE_NOTIFY_INTERVAL / portTICK_PERIOD_MS);
    }
}

void LevopenBattery::notify()
{
    Serial.println("notify");
    pChar0003_0013->setValue(String(millis()));
    pChar0003_0013->notify();
}