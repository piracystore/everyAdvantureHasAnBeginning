# include "ServoPIDControl.h"

void ServoPIDControl::attach()
{
    servo.attach(servoPin);
    servo.write(angle);
}

void ServoPIDControl::PIDCalculate(int16_t &ax, int16_t &ay, int16_t &az, int16_t &gx, int16_t &gy, int16_t &gz)
{
    float current_time = millis();
    float dt = (current_time - lastError) / 1000.0;
    lastError = current_time;

    float gyro_rate = gx / 131.0;
    angle += gyro_rate * dt;

    float acc_angle = atan2(ay, az) * 180 / PI;
    angle = alpha * angle + (1 - alpha) * acc_angle;

    error = setPoint - angle;
    P = Kp * error;
    I += Ki * error * dt;
    D = Kd * (error - lastError) / dt;

    if (I > I_max)
        I = I_max;
    else if (I < -I_max)
        I = -I_max;

    PIDoutput = P + I + D;
    lastError = error;

    writeAngle(angle);
}