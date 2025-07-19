// #include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <main.h>

#define POWER_CLOCK 26
#define ESP32_RUNNING_CORE 1 // 内核选择   LVGL用核心0  其他用核心1

TaskHandle_t Task_start_Handle;  // 初始任务
TaskHandle_t Task_ws2812_Handle; // ws2812 任务
TaskHandle_t Task_key_Handle;  // 初始任务

QueueHandle_t start_Queue;       // 消息队列
QueueHandle_t iot_control_Queue; // ws2812 接收消息队列
QueueHandle_t key_Queue; // ws2812 接收消息队列


_ws2812_message WS2812_MSG;

void Task_start(void *pvParameters)
{
    pinMode(POWER_CLOCK, OUTPUT);
    digitalWrite(POWER_CLOCK, HIGH);
    while (1)
    {
        // __attachInterruptFunctionalArg();
        /* code */
        Serial.println("12345");
        vTaskDelay(1000);
    }
}

void Task_ws2812(void *pvParameters)
{
    // pinMode(POWER_CLOCK, OUTPUT);
    // digitalWrite(POWER_CLOCK, HIGH);
    while (1)
    {
        /* code */
        vTaskDelay(1000);
    }
}

void setup()
{
    // pinMode(POWER_CLOCK, OUTPUT);
    // digitalWrite(POWER_CLOCK, LOW);
    Serial.begin(115200);

    xTaskCreatePinnedToCore(
        Task_start, "start_task", 4096, NULL, 2, &Task_start_Handle, ESP32_RUNNING_CORE);
    xTaskCreatePinnedToCore(
        Task_ws2812, "Task_ws2812", 1024, NULL, 4, &Task_ws2812_Handle, ESP32_RUNNING_CORE);
}

void loop()
{
    // delay(10000);
}
