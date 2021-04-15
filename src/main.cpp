#include <Arduino.h>
#include "levopenBattery.h"

void setup()
{
  Serial.begin(230400);
  Serial.println("setup ...");
  levo.setup();

  //ble_setup();
}

void loop()
{
  /**  just spams notifications to all connected clients */
  delay(1000);
  // if (pServer->getConnectedCount())
  // {
  //    Serial.println("xxx ...");
  //   NimBLEService *pSvc = pServer->getServiceByUUID("BAAD");
  //   if (pSvc)
  //   {
  //     NimBLECharacteristic *pChr = pSvc->getCharacteristic("F00D");
  //     if (pChr)
  //     {
  //       pChr->notify(true);
  //     }
  //   }
  //}
  Serial.println(millis());
  Serial.print("Battery voltage is ");
	Serial.print(levo.battery.voltage());
	Serial.print(" (");
	Serial.print(levo.battery.level());
	Serial.println("%)");
}