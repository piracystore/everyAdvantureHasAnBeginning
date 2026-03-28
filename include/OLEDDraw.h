#ifndef OLED_DRAW_H
#define OLED_DRAW_H

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class OLEDDraw
{
private:
    int ScreenWidth;
    int ScreenHeight;
    int HistoryLength; 
    int OLEDReset;
    int* history;
    Adafruit_SSD1306 display;

    public : OLEDDraw(int width, int height, int historyLength, int resetPin)
    : ScreenWidth(width), ScreenHeight(height), HistoryLength(historyLength), OLEDReset(resetPin)
    {
        history = new int[HistoryLength]();
    }

    ~OLEDDraw()
    {
        delete[] history;
    }

    void Setup();

    void updateHistory(float newValue);

    void drawGraph();


};
#endif // OLED_DRAW_H