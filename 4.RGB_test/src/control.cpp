#include "control.h"

void User_task(void)
{



    // if()
    delay(3);
    for (uint8_t _i = 0; _i < 4; _i++)
    {
        Mouse.move(-mpu_raw_data.gz / 250, mpu_raw_data.gy / 250);
    }
}