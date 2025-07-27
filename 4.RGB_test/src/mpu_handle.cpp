#include "mpu_handle.h"

/*
详看库例程
.pio\libdeps\esp32dev\I2Cdevlib-MPU6050\examples\MPU6050_DMP6\MPU6050_DMP6.ino

额外函数说明：
mpu.getIntStatus();//获取当前中断标志位
mpu.dmpGetFIFOPacketSize();// 获取数据包大小(默认42bytes)
*/

#define INTERRUPT_PIN 34 // int引脚

MPU6050 mpu;
MPU_RAW_DATA mpu_raw_data = {0};

VectorFloat gravity; // [x, y, z]            gravity vector
float euler[3];      // [psi, theta, phi]    Euler angle container
float ypr[3];        // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector

int16_t ax, ay, az, gx, gy, gz;

// packet structure for InvenSense teapot demo
uint8_t teapotPacket[14] = {'$', 0x02, 0, 0, 0, 0, 0, 0, 0, 0, 0x00, 0x00, '\r', '\n'};

volatile bool mpuInterrupt = false;
void dmpDataReady()
{
    mpuInterrupt = true;
}

void Get_mpu_raw_data(void)
{
    static uint8_t fifoBuffer[64]; // FIFO storage buffer
    if (mpu.dmpGetCurrentFIFOPacket(fifoBuffer))
    {
        // display Euler angles in degrees
        // mpu.dmpGetQuaternion(&q, fifoBuffer);
        // mpu.dmpGetGravity(&gravity, &q);
        // mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
        mpu.getMotion6(&mpu_raw_data.ax, &mpu_raw_data.ay, &mpu_raw_data.az, &mpu_raw_data.gx, &mpu_raw_data.gy, &mpu_raw_data.gz); // 只需要用到加速度
        delay(6);
    }
}

void MPU_init(void)
{
    Wire.begin();
    Wire.setClock(400000); // 400kHz I2C clock. Comment this line if having compilation difficulties

    while (!Serial)
        ;

    Serial.println(F("Initializing I2C devices..."));
    mpu.initialize();
    pinMode(INTERRUPT_PIN, INPUT);

    Serial.println(F("Testing device connections..."));
    Serial.println(mpu.testConnection() ? F("MPU6050 connection successful") : F("MPU6050 connection failed"));

    Serial.println(F("Initializing DMP..."));
    static uint8_t devStatus = mpu.dmpInitialize(); // return status after each device operation (0 = success, !0 = error)

    // 设置偏移
    mpu.setXGyroOffset(220);
    mpu.setYGyroOffset(76);
    mpu.setZGyroOffset(-85);
    mpu.setZAccelOffset(1788); // 1688 factory default for my test chip

    // make sure it worked (returns 0 if so)
    if (devStatus == 0)
    {
        // Calibration Time: generate offsets and calibrate our MPU6050
        mpu.CalibrateAccel(6);
        mpu.CalibrateGyro(6);
        mpu.PrintActiveOffsets();
        // turn on the DMP, now that it's ready
        Serial.println(F("Enabling DMP..."));
        mpu.setDMPEnabled(true);

        // enable Arduino interrupt detection
        Serial.print(F("Enabling interrupt detection (Arduino external interrupt "));
        Serial.print(digitalPinToInterrupt(INTERRUPT_PIN));
        Serial.println(F(")..."));
        attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), dmpDataReady, RISING);

        // set our DMP Ready flag so the main loop() function knows it's okay to use it
        Serial.println(F("DMP ready! Waiting for first interrupt..."));
    }
    else
    {
        // ERROR!
        // 1 = initial memory load failed
        // 2 = DMP configuration updates failed
        // (if it's going to break, usually the code will be 1)
        Serial.print(F("DMP Initialization failed (code "));
        Serial.print(devStatus);
        Serial.println(F(")"));
    }
}

// void Mpu_task(void)
// {
//     delay(3);
//     for (uint8_t _i = 0; _i < 4; _i++)
//     {
//         Mouse.move(-mpu_raw_data.gz / 250, mpu_raw_data.gy / 250);
//     }
// }
