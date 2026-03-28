#include <Servo.h>
#include <Arduino.h>

class ServoPIDControl
{
    private:
        Servo servo;
        int servoPin;
        int angle;

        float Kp = 0.15;
        float Ki = 0.05;
        float Kd = 0.05;
        float setPoint = 0.0;
        float error = 0;
        float lastError = 0;
        float P, I, D;
        float PIDoutput;
        float I_max = 20;

    public:
        ServoPIDControl(int pin ,int initialAngle = 90)
            : servoPin(pin), angle(initialAngle)
        {
        };
        void attach();
        void PIDCalculate(int16_t &ax, int16_t &ay, int16_t &az, int16_t &gx, int16_t &gy, int16_t &gz);
        void writeAngle(int degrees);
        void readAngle();
};