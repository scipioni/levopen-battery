#define BUZZER_PIN 16
#define BUTTON_PIN 4 // no PWM on startup
#define BATTERY_V_MIN_mV 32000
#define BATTERY_V_MAX_mV 42000
#define BATTERY_K 40850 / 288 // empiric: V_battery_mV/mean_pin

#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include "battery.h"
#include "canbus.h"
#include "ble.h"
/*
#define POWER_OFF_PIN 32 // pin that control power off
#define MACADDRESS                         \
    {                                      \
        0xDC, 0x9E, 0x23, 0x1F, 0x92, 0x96 \
    } //DC:9E:23:1F:92:96
*/

class Bike : public BLE
{
private:
    // bool deviceConnected = false;

    // BLEServer *pServer;
    // BLECharacteristic *pCharacteristic;

    // BLEService *pService1816;
    // BLECharacteristic *pChar1816_0013;
    // BLECharacteristic *pChar1816_2A5C;
    // BLECharacteristic *pChar1816_2A55;
    // BLECharacteristic *pChar1816_2A5B;

    // BLEService *pService180a;
    // BLECharacteristic *pChar180a_2a29;
    // BLECharacteristic *pChar180a_2a28;

    // BLEService *pService0003;
    // BLECharacteristic *pChar0003_0013;

    // BLEService *pService0001;
    // BLECharacteristic *pChar0001_0011;
    // BLECharacteristic *pChar0001_0021;

    // BLEService *pService0002;
    // BLECharacteristic *pChar0002_0012;

public:
    Bike();

    void setup();

    //void onConnect(BLEServer *);
    //void onDisconnect(BLEServer *);
    static void notify_task(void *parameter);
    void notify();
    void poweroff();
};

extern Bike bike;