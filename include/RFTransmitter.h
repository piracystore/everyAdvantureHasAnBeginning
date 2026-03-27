#ifndef RF_TRANSMMITTER_H
#define RF_TRANSMMITTER_H
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

    void begin()
    {
        radio.begin();
        radio.setPALevel(RF24_PA_LOW);
        radio.setDataRate(RF24_1MBPS);
        radio.openWritingPipe(address);
        radio.stopListening();
    }
    void sendFloat(float value)
    {
        radio.write(&value, sizeof(value));
    }
    
};
#endif