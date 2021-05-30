#include <Arduino.h>
#include <BLE2902.h>

#include "led.h"
#include "buzzer.h"
#include "bike.h"

#if CONFIG_FREERTOS_UNICORE
#define ARDUINO_RUNNING_CORE 0
#else
#define ARDUINO_RUNNING_CORE 1
#endif

#define BLE_NAME "SPECIALIZED"
#define BLE_NOTIFY_INTERVAL 1000

//uint8_t newMACAddress[] = {0x32, 0xAE, 0xA4, 0x07, 0x0D, 0x66};
static BLEUUID service_1816("00001816-0000-1000-8000-00805f9b34fb");

static BLEUUID service_180a("0000180a-0000-1000-8000-00805f9b34fb");
static BLEUUID char_2a29("00002a29-0000-1000-8000-00805f9b34fb");
static BLEUUID char_2a28("00002a28-0000-1000-8000-00805f9b34fb");


static BLEUUID service_0003("00000003-0000-4b49-4e4f-525441474947");
static BLEUUID char_0013("00000013-0000-4b49-4e4f-525441474947");

static BLEUUID service_0001("00000001-0000-4b49-4e4f-525441474947");
static BLEUUID char_0011("00000011-0000-4b49-4e4f-525441474947"); //
static BLEUUID char_0021("00000001-0000-4b49-4e4f-525441474947"); //

static BLEUUID service_0002("00000002-0000-4b49-4e4f-525441474947");
static BLEUUID char_0012("00000012-0000-4b49-4e4f-525441474947");

//#define SERVICE_0003_UUID "00000003-0000-4b49-4e4f-525441474947"

uint8_t battery_soc[20] = {00, 0x0c, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};

uint8_t Adv_DATA[] = {0x0D, 0x02, 0x02, 0xE7, 0x03, 0x01, 0xff, 0xff};

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

    // pinMode(POWER_OFF_PIN, OUTPUT);
    // digitalWrite(POWER_OFF_PIN, LOW);

    //esp_wifi_set_mac(WIFI_IF_STA, &newMACAddress[0]);

    // 0x09	«Complete Local Name»
    BLEDevice::init(BLE_NAME);

    // 0x01	«Flags»

    /** Optional: set the transmit power, default is 3db */
    //BLEDevice::setPower(ESP_PWR_LVL_P7); /** +7db */

    pServer = BLEDevice::createServer();
    pServer->setCallbacks(this);
    //pServer->advertiseOnDisconnect(true);

    BLEAdvertising *pAdvertising = BLEDevice::getAdvertising(); //pServer->getAdvertising();
    BLEAdvertisementData advertisementData;

    // 0xFF	«Manufacturer Specific Data»
    advertisementData.setManufacturerData(std::string((char *)&Adv_DATA[0], 8)); // 8 is length of Adv_DATA
    pAdvertising->setAdvertisementData(advertisementData);

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

    pService1816 = pServer->createService(service_1816);
    pChar1816_2A5B = pService1816->createCharacteristic("00002a5b-0000-1000-8000-00805f9b34fb", BLECharacteristic::PROPERTY_NOTIFY);
    pChar1816_2A5B->addDescriptor(new BLE2902());
    pChar1816_2A55 = pService1816->createCharacteristic("00002a55-0000-1000-8000-00805f9b34fb", BLECharacteristic::PROPERTY_WRITE | BLECharacteristic::PROPERTY_INDICATE);
    pChar1816_2A55->addDescriptor(new BLE2902());
    pChar1816_2A5C = pService1816->createCharacteristic("00002a5c-0000-1000-8000-00805f9b34fb", BLECharacteristic::PROPERTY_READ);
    uint8_t value2A5C[] = {0x30, 0x00};
    pChar1816_2A5C->setValue(value2A5C, 2);
    pService1816->start();
    pAdvertising->addServiceUUID(service_1816);

    pService180a = pServer->createService(service_180a);
    pChar180a_2a29 = pService180a->createCharacteristic(char_2a29, BLECharacteristic::PROPERTY_READ);
    pChar180a_2a29->setValue("SPECIALIZED");
    pChar180a_2a28 = pService180a->createCharacteristic(char_2a28, BLECharacteristic::PROPERTY_READ);
    pChar180a_2a28->setValue("V1.7.0");
    pService180a->start();

    pService0001 = pServer->createService(service_0001);
    pChar0001_0011 = pService0001->createCharacteristic(char_0011, BLECharacteristic::PROPERTY_READ);
    uint8_t value0011[] = {0xff, 0xff, 0xff, 0xff,0xff, 0xff,0xff, 0xff,0xff, 0xff,0xff, 0xff,0xff, 0xff,0xff, 0xff,0xff, 0xff,0xff, 0xff};
    pChar0001_0011->setValue(value0011, 20);
    pChar0001_0021 = pService0001->createCharacteristic(char_0021, BLECharacteristic::PROPERTY_WRITE);
    pService0001->start();

    pService0002 = pServer->createService(service_0002);
    pChar0002_0012 = pService0002->createCharacteristic(char_0012, BLECharacteristic::PROPERTY_WRITE);
    pService0002->start();

    pService0003 = pServer->createService(service_0003);
    pChar0003_0013 = pService0003->createCharacteristic(char_0013, BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY);
    uint8_t value0013[] = {0x01, 0x10, 0x24, 0xff,0xff, 0xff,0xff, 0xff,0xff, 0xff,0xff, 0xff,0xff, 0xff,0xff, 0xff,0xff, 0xff,0xff, 0xff};
    pChar0003_0013->setValue(value0013, 20);
    pChar0003_0013->addDescriptor(new BLE2902());
    pService0003->start();

    pAdvertising->setScanResponse(true); // better false for battery devices
    BLEDevice::startAdvertising();

    /* has to run the task on the same core as Arduino is running */
    xTaskCreatePinnedToCore(this->notify_task, "notify", 10500, NULL, 5, NULL, ARDUINO_RUNNING_CORE);
}

void Bike::onConnect(BLEServer *pServer)
{
    Serial.println("Client connected: ");
    deviceConnected = true;
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

void Bike::onDisconnect(BLEServer *pServer)
{
    Serial.println("Client disconnected: ");
    deviceConnected = false;
    led_interval = BLINK_SLOW;
    vTaskDelay(500 / portTICK_PERIOD_MS); // give the bluetooth stack the chance to get things ready
    //Serial.println(BLEAddress(desc->peer_ota_addr).toString().c_str());
    pServer->startAdvertising();
}

void Bike::notify_task(void *parameter) // questa è statica
{
    //LevopenDisplay *instance = (LevopenBattery *)parameter;

    for (;;)
    {
        bike.notify();
        vTaskDelay(BLE_NOTIFY_INTERVAL / portTICK_PERIOD_MS);
    }
}

void Bike::notify()
{
    if (!deviceConnected)
        return;
    Serial.println("notify");
    //uint8_t data[2] = { 0, 0 };
    battery_soc[2] = battery.capacity();
    //uint8_t battery_soc[20] = {00, 0x0c, battery.capacity(), 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
    pChar0003_0013->setValue((uint8_t *)&battery_soc, 20);
    pChar0003_0013->notify();
}

void Bike::poweroff()
{
    led_interval = BLINK_FAST;
    Serial.printf("power off, bye...");
    //digitalWrite(POWER_OFF_PIN, HIGH);
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