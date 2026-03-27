#ifndef RF_TRANSMITTER_H
#define RF_TRANSMITTER_H

#include <Arduino.h>
#include <RF24.h>

class RFTransmitter
{
private:
    RF24 radio;
    const byte *address;

public:
    RFTransmitter(int cePin, int csnPin, const byte *addr)
        : radio(cePin, csnPin), address(addr) {}

    void begin();

    void sendFloat(float value);
};
#endif