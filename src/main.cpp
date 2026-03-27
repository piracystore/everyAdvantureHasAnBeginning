#include <Wire.h>
// #include "OLEDDraw.h"
#include "UltrasonicSensor.h"
#include "RFTransmitter.h"

// #define SCREEN_WIDTH 128
// #define SCREEN_HEIGHT 64
// #define HISTORY_LENGTH 128
// #define OLED_RESET -1

#define TRIG_PIN 3
#define ECHO_PIN 4

long duration;
float distance;

const byte *address = (const byte *)"54188";

// OLEDDraw oled(SCREEN_WIDTH, SCREEN_HEIGHT, HISTORY_LENGTH, OLED_RESET);
UltrasonicSensor ultrasonic(TRIG_PIN, ECHO_PIN);
RFTransmitter rfTransmitter(9, 10, address);

void setup()
{
  Serial.begin(9600);
  Serial.println("Setup start");
  Serial.print("asdfasdf");
  Serial.println("Setup end");
}

void loop()
{
  distance = ultrasonic.getDistance();
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // oled.updateHistory(distance);
  // oled.drawGraph();

  rfTransmitter.sendFloat(distance);

  delay(1000);
}
