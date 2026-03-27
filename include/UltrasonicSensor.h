#ifndef ULTRASONIC_SENSOR_H
#define ULTRASONIC_SENSOR_H

#include <Arduino.h>

class UltrasonicSensor
{
private:
    int trigPin;
    int echoPin;

public:
    UltrasonicSensor(int trig, int echo)
        : trigPin(trig), echoPin(echo) {}

    void begin()
    {
        pinMode(trigPin, OUTPUT);
        pinMode(echoPin, INPUT);
    }

    long getDistance()
    {
        // 发送触发脉冲
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);
        // 测量回波时间
        long duration = pulseIn(echoPin, HIGH);
        // 计算距离（单位：厘米）
        long distance = duration * 0.034 / 2;
        return distance;
    }
};

#endif