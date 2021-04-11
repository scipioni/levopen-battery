#include <Arduino.h>
#define CONFIG_BT_NIMBLE_PINNED_TO_CORE
#include <NimBLEDevice.h>

class LevopenDisplay : public NimBLEServerCallbacks
{
private:
    NimBLEServer *pServer;

public:
    LevopenDisplay();

    void setup();

    void onConnect(NimBLEServer *, ble_gap_conn_desc *);
    void onDisconnect(NimBLEServer *, ble_gap_conn_desc *);
};