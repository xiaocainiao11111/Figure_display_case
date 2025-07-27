#ifndef __FUNC_H__
#define __FUNC_H__

#include "main.h"
#include "mpu_handle.h"

typedef enum
{
    NORMAL = 2,
    PRESS = 1,
    RELEASE = 0,
} KEY_STATUS;

typedef struct
{
    uint8_t key_pin;       // 按键pin
    bool key_signal;       // 按键信号
    KEY_STATUS key_status; // 按键状态
    uint8_t count_time;    // 计数
    uint8_t key_code;      // 键码
} KEY_STRUCT;

/*
键码定义
注意特殊键码与标准键码不一致，详看src\combo\BleComboKeyboard.h
119 //w
97  //a
100 //d
115 //s
32  //space
114 //r
102 //f
*/

const uint8_t KEY_SPACE = 32;
const uint8_t KEY_w = 119;
const uint8_t KEY_a = 97;
const uint8_t KEY_s = 115;
const uint8_t KEY_d = 100;
const uint8_t KEY_r = 114;
const uint8_t KEY_f = 102;

extern KEY_STRUCT key_mouse_l;
extern KEY_STRUCT key_mouse_r;
extern KEY_STRUCT key_space;
extern KEY_STRUCT key_r;
extern KEY_STRUCT key_pattern;
extern KEY_STRUCT key_w;
extern KEY_STRUCT key_a;
extern KEY_STRUCT key_s;
extern KEY_STRUCT key_d;
extern KEY_STRUCT key_shift;

void Key_status_handle(void);
void Pattern_handle(void);
#endif /* __FUNC__ */