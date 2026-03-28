#include "Gyroscope.h"

void Gyroscope::Setup()
{
    Wire.begin();
    Wire.beginTransmission(MPU_addr);
    Wire.write(0x6B);
    Wire.write(0x00);
    Wire.endTransmission();
    delay(100);

    Serial.println(" Will Calibrate gyroscope in 3 seconds...");
    delay(3000);
    calibrateMPU();
    Serial.println("Calibration done!");
    prev_time = millis();
}

void Gyroscope::calibrateMPU()
{
    const int numReadings = 1200;
    int32_t ax_sum = 0, ay_sum = 0, az_sum = 0;
    int32_t gx_sum = 0, gy_sum = 0, gz_sum = 0;

    for (int i = 0; i < numReadings; i++)
    {
        int16_t ax, ay, az, gx, gy, gz;
        readMPU(ax, ay, az, gx, gy, gz);
        ax_sum += ax;
        ay_sum += ay;
        az_sum += az;
        gx_sum += gx;
        gy_sum += gy;
        gz_sum += gz;
        delay(1);
    }

    ax_offset = ax_sum / numReadings;
    ay_offset = ay_sum / numReadings;
    az_offset = az_sum / numReadings - 16384;
    gx_offset = gx_sum / numReadings;
    gy_offset = gy_sum / numReadings;
    gz_offset = gz_sum / numReadings;

    Serial.print("Gyroscope Offsets - ax: ");
    Serial.print(ax_offset);
    Serial.print(", ay: ");
    Serial.print(ay_offset);
    Serial.print(", az: ");
    Serial.print(az_offset);
    Serial.print(", gx: ");
    Serial.print(gx_offset);
    Serial.print(", gy: ");
    Serial.print(gy_offset);
    Serial.print(", gz: ");
    Serial.println(gz_offset);
}

void Gyroscope::readMPU(int16_t &ax, int16_t &ay, int16_t &az, int16_t &gx, int16_t &gy, int16_t &gz)
{
    Wire.beginTransmission(MPU_addr);
    Wire.write(0x3B);
    Wire.endTransmission(false);
    Wire.requestFrom(MPU_addr, 14, true);

    ax = Wire.read() << 8 | Wire.read();
    ay = Wire.read() << 8 | Wire.read();
    az = Wire.read() << 8 | Wire.read();
    gx = Wire.read() << 8 | Wire.read();
    gy = Wire.read() << 8 | Wire.read();
    gz = Wire.read() << 8 | Wire.read();

    ax -= ax_offset;
    ay -= ay_offset;
    az -= az_offset;
    gx -= gx_offset;
    gy -= gy_offset;
    gz -= gz_offset;
}

void Gyroscope::update()
{
    int16_t ax, ay, az, gx, gy, gz;
    readMPU(ax, ay, az, gx, gy, gz);
    printOffsets();
}

void Gyroscope::printOffsets()
{
    Serial.print("Gyroscope Offsets - ax: ");
    Serial.print(ax_offset);
    Serial.print(", ay: ");
    Serial.print(ay_offset);
    Serial.print(", az: ");
    Serial.print(az_offset);
    Serial.print(", gx: ");
    Serial.print(gx_offset);
    Serial.print(", gy: ");
    Serial.print(gy_offset);
    Serial.print(", gz: ");
    Serial.println(gz_offset);
}