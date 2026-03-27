#include "OLEDDraw.h"

Adafruit_SSD1306 OLEDDraw::Setup()
{
    Adafruit_SSD1306 display(ScreenWidth, ScreenHeight, &Wire, OLEDReset);
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
    return display;
}

void OLEDDraw::drawCurve()
{
    int history[HistoryLength] = {0};
    display->clearDisplay();
    for (int i = 0; i < HistoryLength; i++)
    {
        int x1 = map(i, 0, HistoryLength - 1, 0, ScreenWidth);
        int y1 = map(history[i], 0, 100, ScreenHeight, 0);
        int x2 = map(i, 0, HistoryLength - 1, 0, ScreenWidth);
        int y2 = map(history[i + 1], 0, 100, ScreenHeight, 0);
        display->drawLine(x1, y1, x2, y2, SSD1306_WHITE);
    }
    display->display();
}


// void loop()
// {
//     static int phase = 0;
//     int value = sin(phase * 0.1) * 30 + 32;
//     phase++;

//     for (int i = 0; i < HISTORY_LENGTH - 1; i++)
//     {
//         history[i] = history[i + 1];
//     }
//     history[HISTORY_LENGTH - 1] = value;

//     drawCurve();

//     delay(0.00000001);
// }