#ifndef __MPU_HANDLE_H__
#define __MPU_HANDLE_H__

#include "main.h"
#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
#include "Wire.h"
#endif

// 原始数据
typedef struct
{
    int16_t ax;
    int16_t ay;
    int16_t az;
    int16_t gx;
    int16_t gy;
    int16_t gz;
} MPU_RAW_DATA;
extern MPU_RAW_DATA mpu_raw_data;

void Get_mpu_raw_data(void);
void MPU_init(void);
void Mpu_task(void);

#endif /* __MPU_HANDLE_H__ */
