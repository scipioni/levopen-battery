#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include "battery.h"
#include "canbus.h"

#define BUZZER_PIN 14
#define BUTTON_PIN 12
#define BATTERY_V_MIN_mV 35000 
#define BATTERY_V_MAX_mV 42000
#define BATTERY_K 40850/214 // empiric: V_battery_mV/mean_pin

/*
#define POWER_OFF_PIN 32 // pin that control power off
#define MACADDRESS                         \
    {                                      \
        0xDC, 0x9E, 0x23, 0x1F, 0x92, 0x96 \
    } //DC:9E:23:1F:92:96
*/

class Bike : public BLEServerCallbacks
{
private:
    BLEServer *pServer;
    BLECharacteristic *pCharacteristic;

    BLEService *pService1800, *pService1801, *pService180A, *pService0001, *pService0002, *pService0003, *pService1816;
    BLECharacteristic *pChar1800_2A00, *pChar1800_2A01, *pChar1800_2A04;
    BLECharacteristic *pChar180A_2A29, *pChar180A_2A28;
    BLECharacteristic *pChar0003_0013;
    BLECharacteristic *pChar0001_0011;
    BLECharacteristic *pChar1816_0013;
    BLECharacteristic *pChar1816_2A5C;
    BLECharacteristic *pChar1816_2A5B;
    BLECharacteristic *pChar0002_0012;

public:
    Bike();
    

    void setup();

    void onConnect(BLEServer *);
    void onDisconnect(BLEServer *);
    static void notify_cron(void *parameter);
    void notify();
    void poweroff();
};

extern Bike bike;