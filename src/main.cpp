#include <Arduino.h>
#include "ble.h"
//#include "led.h"

void setup()
{
  Serial.begin(230400);
  Serial.println("setup ...");
  led_setup();
  ble_setup();
}

void loop()
{
  /**  just spams notifications to all connected clients */
  delay(2000);
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
}