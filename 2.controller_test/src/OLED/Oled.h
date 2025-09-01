#include <Arduino.h>
#include "Controller/Controller.h"
void Oled_init();
void ui_proc();

void key_init();
void key_scan();
bool get_key_val(uint8_t ch);

extern bool key_en;