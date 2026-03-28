#include <Wire.h>
#include <Arduino.h>

class Gyroscope
{
    private:
        int16_t MPU_addr;

        int16_t ax_offset = 0, ay_offset = 0, az_offset = 0;
        int16_t gx_offset = 0, gy_offset = 0, gz_offset = 0;

        float pitch = 0.0;
        float alpha = 0.98; 
        unsigned long prev_time = 0;


    public:
        Gyroscope(int16_t MPU_addr)
            : MPU_addr(MPU_addr)
        {
        };
        void Setup();
        void update();
        void readMPU(int16_t &ax, int16_t &ay, int16_t &az, int16_t &gx, int16_t &gy, int16_t &gz);
        void calibrateMPU();
        void printOffsets();
};