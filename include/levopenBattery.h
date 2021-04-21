#include <Arduino.h>
//#define CONFIG_BT_NIMBLE_PINNED_TO_CORE
#include <NimBLEDevice.h>
#include "battery.h"

#define VSENSE_PIN A0
#define MACADDRESS {0xDC, 0x9E, 0x23, 0x1F, 0x92, 0x96} //DC:9E:23:1F:92:96

class LevopenBattery : public NimBLEServerCallbacks
{
private:
    NimBLEServer *pServer;
    NimBLECharacteristic *pCharacteristic;

    NimBLEService *pService1800, *pService1801, *pService180A, *pService0001, *pService0002, *pService0003, *pService1816;
    NimBLECharacteristic *pChar1800_2A00, *pChar1800_2A01, *pChar1800_2A04;
    NimBLECharacteristic *pChar180A_2A29, *pChar180A_2A28;
    NimBLECharacteristic *pChar0003_0013;
    NimBLECharacteristic *pChar0001_0011;
    NimBLECharacteristic *pChar1816_0013;
    NimBLECharacteristic *pChar1816_2A5C;
    NimBLECharacteristic *pChar1816_2A5B;
    NimBLECharacteristic *pChar0002_0012;


public:
    LevopenBattery();
    Battery battery = Battery(3400, 4200, VSENSE_PIN);

    void setup();

    void onConnect(NimBLEServer *, ble_gap_conn_desc *);
    void onDisconnect(NimBLEServer *, ble_gap_conn_desc *);
    static void notify_cron(void *parameter);
    void notify();
};

extern LevopenBattery levo;