#include "OLEDDraw.h"

void OLEDDraw::Setup()
{
    Adafruit_SSD1306 Setingdisplay(ScreenWidth, ScreenHeight, &Wire, OLEDReset);
    Serial.begin(9600);
    if (!Setingdisplay.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;)
            ;
    }
    Setingdisplay.clearDisplay();
    Setingdisplay.setTextSize(1);
    Setingdisplay.setTextColor(SSD1306_WHITE);
    Setingdisplay.setCursor(0, 0);
    Setingdisplay.println("你好，世界!");
    Setingdisplay.display();
    delay(2000);
    display = &Setingdisplay;
}


void OLEDDraw::updateHistory(float newValue)
{
    for (int i = 0; i < HistoryLength - 1; i++)
    {
        history[i] = history[i + 1];
    }
    history[HistoryLength - 1] = newValue;
}

void OLEDDraw::drawGraph()
{
    display->clearDisplay();
    for (int i = 0; i < HistoryLength - 1; i++)
    {
        int x1 = map(i, 0, HistoryLength - 1, 0, ScreenWidth);
        int y1 = map(history[i], 0, 100, ScreenHeight, 0);
        int x2 = map(i + 1, 0, HistoryLength - 1, 0, ScreenWidth);
        int y2 = map(history[i + 1], 0, 100, ScreenHeight, 0);
        display->drawLine(x1, y1, x2, y2, SSD1306_WHITE);
    }
    display->display();
}