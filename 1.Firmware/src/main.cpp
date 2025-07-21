// #include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <main.h>

// #define POWER_CLOCK 26
#define ESP32_RUNNING_CORE 1 // 内核选择   LVGL用核心0  其他用核心1

TaskHandle_t Task_start_Handle;  // 初始任务
TaskHandle_t Task_ws2812_Handle; // ws2812 任务
TaskHandle_t Task_key_Handle;    // 按键任务
TaskHandle_t Task_update_Handle; // 更新任务

QueueHandle_t start_Queue;       // 消息队列
QueueHandle_t iot_control_Queue; // ws2812接收消息队列
QueueHandle_t key_Queue;         // 按键接收消息队列

_ws2812_message WS2812_MSG;
uint16_t adc = 0;
void Task_start(void *pvParameters)
{

    while (1)
    {
        adc = analogRead(CONFIG_BAT_DET_PIN);
        Serial.println(adc);
        vTaskDelay(1000);
    }
}

void Task_ws2812(void *pvParameters)
{
    WS2812_init();
    while (1)
    {
        /* code */
        vTaskDelay(1000);
    }
}
void Task_update(void *pvParameters)
{
    while (1)
    {
        
        HAL::Update();
        vTaskDelay(20);



    }
}

void setup()
{

    HAL::Init();

    xTaskCreatePinnedToCore(
        Task_start, "start_task", 4096, NULL, 2, &Task_start_Handle, ESP32_RUNNING_CORE);
    xTaskCreatePinnedToCore(
        Task_ws2812, "Task_ws2812", 1024, NULL, 4, &Task_ws2812_Handle, ESP32_RUNNING_CORE);

    xTaskCreatePinnedToCore(
        Task_update, "Task_update", 1024, NULL, 4, &Task_update_Handle, ESP32_RUNNING_CORE);
}

void loop()
{
    HAL::Update();
    delay(20);
}
