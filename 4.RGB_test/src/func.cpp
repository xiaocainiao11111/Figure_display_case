#include "func.h"

#define INVALID 0 // 无效键码

KEY_STRUCT key_mouse_l = {.key_pin = 17, .key_signal = 0, .key_status = NORMAL, .count_time = 0, .key_code = MOUSE_LEFT};   // 鼠标左键
KEY_STRUCT key_mouse_r = {.key_pin = 12, .key_signal = 0, .key_status = NORMAL, .count_time = 0, .key_code = MOUSE_RIGHT};  // 鼠标右键
KEY_STRUCT key_space = {.key_pin = 32, .key_signal = 0, .key_status = NORMAL, .count_time = 0, .key_code = KEY_SPACE};      // 键盘 空格
KEY_STRUCT key_r = {.key_pin = 33, .key_signal = 0, .key_status = NORMAL, .count_time = 0, .key_code = KEY_r};              // 键盘 r
KEY_STRUCT key_pattern = {.key_pin = 35, .key_signal = 0, .key_status = NORMAL, .count_time = 0, .key_code = INVALID};      // 模式键
KEY_STRUCT key_w = {.key_pin = 0, .key_signal = 0, .key_status = NORMAL, .count_time = 0, .key_code = KEY_w};               // 键盘 w
KEY_STRUCT key_a = {.key_pin = 4, .key_signal = 0, .key_status = NORMAL, .count_time = 0, .key_code = KEY_a};               // 键盘 a
KEY_STRUCT key_s = {.key_pin = 0, .key_signal = 0, .key_status = NORMAL, .count_time = 0, .key_code = KEY_s};               // 键盘 s
KEY_STRUCT key_d = {.key_pin = 4, .key_signal = 0, .key_status = NORMAL, .count_time = 0, .key_code = KEY_d};               // 键盘 d
KEY_STRUCT key_shift = {.key_pin = 23, .key_signal = 0, .key_status = NORMAL, .count_time = 0, .key_code = KEY_LEFT_SHIFT}; // 键盘 shift

// 鼠标移动
void mouse_Move(int16_t _mouseX, int16_t _mouseY)
{
    delay(3);
    for (uint8_t _i = 0; _i < 4; _i++)
    {
        Mouse.move(_mouseX, -_mouseY);
    }
}

// 处理
void Key_signal_handle(KEY_STRUCT *_key_status)
{
    switch (_key_status->key_status)
    {
    case NORMAL:
        if (_key_status->key_signal) // 防止重复触发
        {
            _key_status->count_time++;
            if (_key_status->count_time >= 2) // 简单消抖
            {
                if (_key_status->key_code != 0)
                {
                    if ((_key_status->key_code == MOUSE_LEFT) || (_key_status->key_code == MOUSE_RIGHT))
                    {
                        Mouse.press(_key_status->key_code);
                    }
                    else
                    {
                        KeyBoard.press(_key_status->key_code);
                    }
                }
                _key_status->key_status = PRESS;
                _key_status->count_time = 0;
            }
        }
        break;
    case PRESS:
        if (_key_status->key_signal)
        {
            _key_status->count_time = 0;
        }
        else
        {
            _key_status->count_time++;
            if (_key_status->count_time >= 2)
            {
                if (_key_status->key_code != 0)
                {
                    if ((_key_status->key_code == MOUSE_LEFT) || (_key_status->key_code == MOUSE_RIGHT))
                    {
                        Mouse.release(_key_status->key_code);
                    }
                    else
                    {
                        KeyBoard.release(_key_status->key_code);
                    }
                }
                _key_status->key_status = RELEASE;
                _key_status->count_time = 0;
            }
        }
        break;
    case RELEASE:
        if (_key_status->key_signal)
        {
            _key_status->count_time++;
            if (_key_status->count_time >= 2)
            {
                if (_key_status->key_code != 0)
                {
                    if ((_key_status->key_code == MOUSE_LEFT) || (_key_status->key_code == MOUSE_RIGHT))
                    {
                        Mouse.press(_key_status->key_code);
                    }
                    else
                    {
                        KeyBoard.press(_key_status->key_code);
                    }
                }
                _key_status->key_status = PRESS;
                _key_status->count_time = 0;
            }
        }
        else
        {
            _key_status->count_time = 0;
        }
        break;
    default:
        break;
    }
}

void Key_status_handle(void)
{
    key_mouse_l.key_signal = digitalRead(key_mouse_l.key_pin);
    key_mouse_r.key_signal = digitalRead(key_mouse_r.key_pin);
    key_space.key_signal = digitalRead(key_space.key_pin);
    key_r.key_signal = digitalRead(key_r.key_pin);
    key_pattern.key_signal = digitalRead(key_pattern.key_pin);
    key_shift.key_signal = !digitalRead(key_shift.key_pin);

    // (analogRead(key_w.key_pin) >= 3500) ? (key_w.key_signal = 1) : (key_w.key_signal = 0);
    // (analogRead(key_s.key_pin) <= 500) ? (key_s.key_signal = 1) : (key_s.key_signal = 0);
    // (analogRead(key_d.key_pin) >= 3500) ? (key_d.key_signal = 1) : (key_d.key_signal = 0);
    // (analogRead(key_a.key_pin) <= 500) ? (key_a.key_signal = 1) : (key_a.key_signal = 0);

    Key_signal_handle(&key_mouse_l);
    Key_signal_handle(&key_mouse_r);
    Key_signal_handle(&key_space);
    Key_signal_handle(&key_r);
    Key_signal_handle(&key_pattern);
    // Key_signal_handle(&key_w);
    // Key_signal_handle(&key_a);
    // Key_signal_handle(&key_s);
    // Key_signal_handle(&key_d);
    Key_signal_handle(&key_shift);
}

void Pattern_handle(void)
{
    if (key_pattern.key_status == PRESS)
    {
    }
    else
    {
        // 还能优化
        delay(1);
        for (uint8_t _i = 0; _i < 2; _i++)
        {
            Mouse.move(-mpu_raw_data.gz / 200, mpu_raw_data.gx / 200);
        }
    }
}

void Motion_pad(uint16_t _conver)
{
    mouse_Move(-mpu_raw_data.gz / _conver, -mpu_raw_data.gy / _conver);
}
