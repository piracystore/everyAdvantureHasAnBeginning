# include "UltrasonicSensor.h"

void UltrasonicSensor::begin()
{
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

long UltrasonicSensor::getDistance()
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    long duration = pulseIn(echoPin, HIGH);
    long distance = duration * 0.034 / 2;
    return distance;
}