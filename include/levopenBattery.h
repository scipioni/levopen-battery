#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include "battery.h"

#define VSENSE_PIN A0

class LevopenBattery : public BLEServerCallbacks
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
    LevopenBattery();
    Battery battery = Battery(3400, 4200, VSENSE_PIN);

    void setup();

    void onConnect(BLEServer *);
    void onDisconnect(BLEServer *);
    static void notify_cron(void *parameter);
    void notify();
};

extern LevopenBattery levo;