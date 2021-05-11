#include <Arduino.h>

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

//uint8_t newMACAddress[] = {0x32, 0xAE, 0xA4, 0x07, 0x0D, 0x66};
static BLEUUID uuid1816("00001816-0000-1000-8000-00805f9b34fb");
uint8_t Adv_DATA[] = {0x0D, 0x02, 0x02, 0xE7, 0x03, 0x01, 0xff, 0xff};

LevopenBattery levo = LevopenBattery();
Battery battery = Battery(V_K, V_MIN_mV, V_MAX_mV, V_PIN);

LevopenBattery::LevopenBattery()
{
    ;
}

void LevopenBattery::setup()
{
    led_setup();
    canbus_setup();

    // pinMode(POWER_OFF_PIN, OUTPUT);
    // digitalWrite(POWER_OFF_PIN, LOW);

    //esp_wifi_set_mac(WIFI_IF_STA, &newMACAddress[0]);

    BLEDevice::init(BLE_NAME);

    /** Optional: set the transmit power, default is 3db */
    BLEDevice::setPower(ESP_PWR_LVL_P7); /** +7db */

    pServer = BLEDevice::createServer();
    //pServer->setCallbacks(this);
    //pServer->advertiseOnDisconnect(true);

    // pService180A = pServer->createService("0000180a-0000-1000-8000-00805f9b34fb"); // device information
    // pChar180A_2A28 = pService180A->createCharacteristic("00002a28-0000-1000-8000-00805f9b34fb", BLE_PROPERTY::READ);
    // pChar180A_2A28->setValue("56312E372E30"); // "Software Revision String"
    // pChar180A_2A29 = pService180A->createCharacteristic("00002a29-0000-1000-8000-00805f9b34fb", BLE_PROPERTY::READ);
    // pChar180A_2A29->setValue("5350454349414C495A4544"); // "Manufacturer Name String"

    // pService0001 = pServer->createService("00000001-0000-4b49-4e4f-525441474947");
    // pChar0001_0011 = pService0001->createCharacteristic("00000011-0000-4b49-4e4f-525441474947", BLE_PROPERTY::READ);
    // pChar0001_0011->setValue("010800000000FFFFFFFFFFFFFFFFFFFFFFFFFFFF");

    // pService0002 = pServer->createService("00000002-0000-4b49-4e4f-525441474947");
    // pChar0002_0012 = pService0002->createCharacteristic("00000012-0000-4b49-4e4f-525441474947", BLE_PROPERTY::WRITE);

    // pService0003 = pServer->createService("00000003-0000-4b49-4e4f-525441474947");
    // pChar0003_0013 = pService0003->createCharacteristic("00000013-0000-4b49-4e4f-525441474947", BLE_PROPERTY::READ | BLE_PROPERTY::NOTIFY);
    // pChar0003_0013->setValue("1234");

    pService1816 = pServer->createService(uuid1816);
    pChar1816_2A5B = pService1816->createCharacteristic("00002a5b-0000-1000-8000-00805f9b34fb", BLECharacteristic::PROPERTY_NOTIFY);
    pChar1816_2A5C = pService1816->createCharacteristic("00002a5c-0000-1000-8000-00805f9b34fb", BLECharacteristic::PROPERTY_READ);
    pChar1816_2A5C->setValue("0300");

    /** Start the services when finished creating all Characteristics and Descriptors */
    // pService180A->start();
    pService1816->start();
    // pService0003->start();
    // pService0002->start();
    // pService0001->start();

    BLEAdvertising *pAdvertising = BLEDevice::getAdvertising(); //pServer->getAdvertising();
    BLEAdvertisementData advertisementData;

    advertisementData.setManufacturerData(std::string((char *)&Adv_DATA[0], 8)); // 8 is length of Adv_DATA
    pAdvertising->setAdvertisementData(advertisementData);
    pAdvertising->addServiceUUID(uuid1816);

    // pAdvertising->addServiceUUID(pService0003->getUUID());
    // pAdvertising->addServiceUUID(pService180A->getUUID());
    // pAdvertising->addServiceUUID(pService1816->getUUID());
    // pAdvertising->addServiceUUID(pService0001->getUUID());
    // pAdvertising->addServiceUUID(pService0002->getUUID());
    pAdvertising->setScanResponse(true); // better false for battery devices
    // pAdvertising->setMinPreferred(0x06); // functions that help with iPhone connections issue
    // pAdvertising->setMaxPreferred(0x12);

    // BLEDevice::startAdvertising();
    pAdvertising->start();

    /* has to run the task on the same core as Arduino is running */
    xTaskCreatePinnedToCore(this->notify_cron, "notify", 10500, NULL, 5, NULL, ARDUINO_RUNNING_CORE);
}

void LevopenBattery::onConnect(BLEServer *pServer)
{
    Serial.print("Client connected: ");
    led_interval = BLINK_FAST;
    //Serial.println(BLEAddress(desc->peer_ota_addr).toString().c_str());
    /** We can use the connection handle here to ask for different connection parameters.
         *  Args: connection handle, min connection interval, max connection interval
         *  latency, supervision timeout.
         *  Units; Min/Max Intervals: 1.25 millisecond increments.
         *  Latency: number of intervals allowed to skip.
         *  Timeout: 10 millisecond increments, try for 5x interval time for best results.  
         */
    //pServer->updateConnParams(desc->conn_handle, 24, 48, 0, 60);
    //BLEDevice::startAdvertising();
}

void LevopenBattery::onDisconnect(BLEServer *pServer)
{
    Serial.print("Client disconnected: ");
    led_interval = BLINK_SLOW;
    //Serial.println(BLEAddress(desc->peer_ota_addr).toString().c_str());
    pServer->startAdvertising();
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
    //uint8_t data[2] = { 0, 0 };
    //pChar0003_0013->setValue(data, 2);
    //pChar0003_0013->setValue(String(millis()));
    //pChar0003_0013->notify();
}

void LevopenBattery::poweroff()
{
    led_interval = BLINK_FAST;
    Serial.printf("power off, bye...");
   //digitalWrite(POWER_OFF_PIN, HIGH);
    pinMode(POWER_BUTTON_PIN, INPUT_PULLDOWN);
    //vTaskDelay(1000); // in produzione qui non ci arrivo
    //digitalWrite(POWER_OFF_PIN, LOW); // serve solo se sto alimentando con usb durante il debug
}