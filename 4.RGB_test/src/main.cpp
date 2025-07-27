#include "main.h"

BleComboKeyboard KeyBoard = BleComboKeyboard("cainiao_gun_V2.0", "Espressif", 100);
BleComboMouse Mouse(&KeyBoard);

// 参数打印
void _print()
{
    Serial.println(
        " w:" + String(key_w.key_status) +
        " s:" + String(key_s.key_status) +
        " a:" + String(key_a.key_status) +
        " d:" + String(key_d.key_status) +
        " mouse_l:" + String(key_mouse_l.key_status) +
        " mouse_r:" + String(key_mouse_r.key_status) +
        " space:" + String(key_space.key_status) +
        " r:" + String(key_r.key_status) +
        " f:" + String(key_pattern.key_status) +
        " shift:" + String(key_shift.key_status) +
        " gz:" + String(mpu_raw_data.gz) +
        " gy:" + String(mpu_raw_data.gy) +
        " gx:" + String(mpu_raw_data.gx)

    );
}

void setup()
{
    Serial.begin(115200);
    Serial.println("Starting work!");

    strip.begin();            // INITIALIZE NeoPixel strip object (REQUIRED)把对应pin设置为输出
    strip.show();             // Turn OFF all pixels ASAP
    strip.setBrightness(255); // Set BRIGHTNESS to about 1/5 (max = 255)，设置亮度

    pinMode(25, OUTPUT); // 电磁铁
    pinMode(key_mouse_l.key_pin, INPUT_PULLDOWN);
    pinMode(key_mouse_r.key_pin, INPUT_PULLDOWN);
    pinMode(key_space.key_pin, INPUT_PULLDOWN);
    pinMode(key_r.key_pin, INPUT_PULLDOWN);
    pinMode(key_pattern.key_pin, INPUT_PULLDOWN);
    pinMode(key_w.key_pin, INPUT_PULLDOWN);
    pinMode(key_a.key_pin, INPUT_PULLDOWN);
    pinMode(key_s.key_pin, INPUT_PULLDOWN);
    pinMode(key_d.key_pin, INPUT_PULLDOWN);
    pinMode(key_shift.key_pin, INPUT_PULLUP);
    KeyBoard.begin();
    Mouse.begin();
    MPU_init();

    delay(10);
}

static bool ele_mode = 0;
static uint8_t ele_time = 0;

void loop()
{

    rainbow(5);
    Get_mpu_raw_data();
    Key_status_handle();
    Pattern_handle();
    //_print();

    // Mouse.press(119);

    // if (key_mouse_l.key_status == PRESS)
    // {
    //     Ele_magnet_on(20);
    // }
    // else
    // {
    //     Ele_magnet_off();
    // }
    // delay(80);
}

//.......演示用
// if (key_pattern.key_status == PRESS)
// {
//     ele_mode = 1;
// }

// if (ele_mode == 0)
// {
//     if (key_mouse_l.key_status == PRESS)
//     {
//         digitalWrite(ELE_magnet_pin, HIGH);
//     }
//     else
//     {
//         digitalWrite(ELE_magnet_pin, LOW);
//     }
// }
// else
// {
//     if (key_mouse_l.key_status == PRESS)
//     {
//         Ele_magnet_on(10);
//     }
//     else
//     {
//         Ele_magnet_off();
//     }
// }