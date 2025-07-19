// #include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <main.h>


#define POWER_CLOCK 26
#define ESP32_RUNNING_CORE 1 // 内核选择   LVGL用核心0  其他用核心1

TaskHandle_t Task_start_Handle; // 初始任务

QueueHandle_t start_Queue; // 消息队列

void Task_start(void *pvParameters)
{
    pinMode(POWER_CLOCK, OUTPUT);
    digitalWrite(POWER_CLOCK, HIGH);
    while (1)
    {
        /* code */
    }
}

void setup()
{
    // pinMode(POWER_CLOCK, OUTPUT);
    // digitalWrite(POWER_CLOCK, LOW);
    Serial.begin(115200);
    Serial1.begin(115200);

    xTaskCreatePinnedToCore(
        Task_start, "start_task", 4096, NULL, 2, &Task_start_Handle, ESP32_RUNNING_CORE);
}

void loop()
{
    delay(10000);
}
