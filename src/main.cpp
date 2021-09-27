#include "bike.h"

void setup()
{
  Serial.begin(115200);
  Serial.println("setup()");
  bike.setup();
}

void loop()
{
  if (battery.button() || battery.idle())
  {
    bike.poweroff();
  }
  delay(1000);
}