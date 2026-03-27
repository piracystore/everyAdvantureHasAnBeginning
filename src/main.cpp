#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define HISTORY_LENGTH 128

#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int history[HISTORY_LENGTH] = {0};

void drawCurve()
{
  display.clearDisplay();
  for (int i = 0; i < HISTORY_LENGTH; i++)
  {
    int x1 = map(i, 0, HISTORY_LENGTH - 1, 0, SCREEN_WIDTH);
    int y1 = map(history[i], 0, 100, SCREEN_HEIGHT, 0);
    int x2 = map(i, 0, HISTORY_LENGTH - 1, 0, SCREEN_WIDTH);
    int y2 = map(history[i + 1], 0, 100, SCREEN_HEIGHT, 0);
    display.drawLine(x1, y1, x2, y2, SSD1306_WHITE);
  }
  display.display();
}

void setup()
{
  Serial.begin(9600);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("你好，世界!");
  display.display();
  delay(2000);
}

void loop()
{
  static int phase = 0;
  int value = sin(phase * 0.1) * 30 + 32;
  phase++;
  
  for (int i = 0; i < HISTORY_LENGTH - 1; i++)
  {
    history[i] = history[i + 1];
  }
  history[HISTORY_LENGTH - 1] = value;

  drawCurve();

  delay(0.00000001);
}

