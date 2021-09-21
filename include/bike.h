
#ifdef BOARD_WEMOS_D1_MINI32
#define BUZZER_PIN 25
#define BUTTON_PIN 27 // no PWM on startup
#endif

#ifdef BOARD_TTGO
#define BUZZER_PIN 25
#define BUTTON_PIN 27 // no PWM on startup
#endif

#define BATTERY_V_MIN_mV 34000
#define BATTERY_V_MAX_mV 41200
#define BATTERY_K 41200 / 275 // empiric: V_battery_mV/mean_pin

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