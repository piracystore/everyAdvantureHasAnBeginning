#include <Wire.h>
#include "OLEDDraw.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define HISTORY_LENGTH 128
#define OLED_RESET -1


OLEDDraw oledDraw(SCREEN_WIDTH, SCREEN_HEIGHT, HISTORY_LENGTH, OLED_RESET);


void loop()
{
  // static int phase = 0;
  // int value = sin(phase * 0.1) * 30 + 32;
  // phase++;
  
  // for (int i = 0; i < HISTORY_LENGTH - 1; i++)
  // {
  //   history[i] = history[i + 1];
  // }
  // history[HISTORY_LENGTH - 1] = value;

  oledDraw.drawCurve();

  // delay(0.00000001);
}

