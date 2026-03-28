#include "RFTransmitter.h"

void RFTransmitter::begin()
{
    radio.begin();
    radio.setPALevel(RF24_PA_LOW);
    radio.setDataRate(RF24_1MBPS);
    radio.openWritingPipe(address);
    radio.stopListening();
}

void RFTransmitter::sendFloat(float value)
{
    radio.write(&value, sizeof(value));
    Serial.println("have sent");
}