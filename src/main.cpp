#include <Arduino.h>
#include "bike.h"

void setup()
{
  Serial.begin(115200);
  Serial.println("setup()");
  bike.setup();

  //ble_setup();
}

void loop()
{
  /**  just spams notifications to all connected clients */
  delay(1000);

  if (battery.button())
  {
    bike.poweroff();
  }
  //vTaskDelay(1000);
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
  //Serial.println(millis());
  //Serial.printf("Battery voltage is %d (%d)\n", levo.battery.voltage(), levo.battery.level());
  // Serial.print(levo.battery.voltage());
  // Serial.print(" (");
  // Serial.print(levo.battery.level());
  // Serial.println("%)");
}