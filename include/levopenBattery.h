#include <Arduino.h>
//#define CONFIG_BT_NIMBLE_PINNED_TO_CORE
#include <NimBLEDevice.h>

class LevopenBattery : public NimBLEServerCallbacks
{
private:
    NimBLEServer *pServer;
    NimBLECharacteristic *pCharacteristic;

public:
    LevopenBattery();

    void setup();

    void onConnect(NimBLEServer *, ble_gap_conn_desc *);
    void onDisconnect(NimBLEServer *, ble_gap_conn_desc *);
    static void notify_cron(void *parameter);
    void notify();
};

extern LevopenBattery levo;