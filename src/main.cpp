#include <Arduino.h>
#include "Gyroscope.h"
#include "OLEDDraw.h"

Gyroscope gyroscope(0x68);
OLEDDraw oledDraw(128, 64, 50, -1);

void setup()
{
  Serial.begin(9600);
  gyroscope.Setup();
  oledDraw.Setup();
}

void loop()
{
  gyroscope.update();   
}
