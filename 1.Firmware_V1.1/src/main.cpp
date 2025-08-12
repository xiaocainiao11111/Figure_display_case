#include <main.h>

// #define POWER_CLOCK 26
#define ESP32_RUNNING_CORE 1 // 内核选择   LVGL用核心0  其他用核心1

TaskHandle_t Task_start_Handle;  // 初始任务
TaskHandle_t Task_ws2812_Handle; // ws2812 任务
TaskHandle_t Task_motor_Handle;  // motor 任务
TaskHandle_t Task_key_Handle;    // 按键任务
TaskHandle_t Task_update_Handle; // 更新任务
TaskHandle_t Task_oled_Handle;   // oled任务

QueueHandle_t start_Queue;       // 消息队列
QueueHandle_t iot_control_Queue; // ws2812接收消息队列
QueueHandle_t key_Queue;         // 按键接收消息队列
QueueHandle_t oled_Queue;        // oled消息队列

_ws2812_message WS2812_MSG;
uint16_t adc = 0;

Adafruit_NeoPixel RGB3 = Adafruit_NeoPixel(RGB_3_NUM, RGB_PIN_3, NEO_GRB + NEO_KHZ800);
Motor motor(MOTOR_PIN_1, MOTOR_PIN_2, MOTOR_PWM, 1000, 1);

void Task_start(void *pvParameters)
{

    while (1)
    {
        adc = analogRead(CONFIG_BAT_DET_PIN);
        // Serial.println(adc);
        vTaskDelay(1000);
    }
}

void Task_key(void *pvParameters)
{
    ENCODER::Encoder_Init();
    while (1)
    {
        ENCODER::Encoder_Update();
        vTaskDelay(10);
    }
}

void Task_oled(void *pvParameters)
{
    // Oled_init();
    while (1)
    {
        key_scan();
        // ui_proc();
        vTaskDelay(10);
    }
}

void Task_ws2812(void *pvParameters)
{
    RGB3.begin();            // INITIALIZE NeoPixel strip object (REQUIRED)把对应pin设置为输出
    RGB3.show();             // Turn OFF all pixels ASAP
    RGB3.setBrightness(255); // Set BRIGHTNESS to about 1/5 (max = 255)，设置亮度
    // 注意：只有这三行灯不会亮
    while (1)
    {
        // theaterChaseRainbow(5);
        rainbow(5);
        // vTaskDelay(1000);
    }
}

void Task_motor(void *pvParameters)
{
    vTaskDelay(1000);
    // motor.drive(-200);
    // pinMode(MOTOR_PWM, OUTPUT);
    // ledcSetup(1, 1000, 8);
    // ledcAttachPin(MOTOR_PWM, 1);
    // vTaskDelay(10);
    // ledcWrite(1, 125);

    while (1)
    {
        vTaskDelay(20);
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
        Task_key, "Task_key", 2048, NULL, 4, &Task_key_Handle, ESP32_RUNNING_CORE);
    xTaskCreatePinnedToCore(
        Task_motor, "Task_motor", 1024, NULL, 4, &Task_motor_Handle, ESP32_RUNNING_CORE);
    xTaskCreatePinnedToCore(
        Task_update, "Task_update", 1024, NULL, 4, &Task_update_Handle, ESP32_RUNNING_CORE);
    xTaskCreatePinnedToCore(
        Task_oled, "Task_oled", 4096, NULL, 4, &Task_oled_Handle, ESP32_RUNNING_CORE);
}

void loop()
{
    delay(20);
}
