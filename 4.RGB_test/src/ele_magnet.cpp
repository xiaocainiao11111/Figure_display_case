#include "ele_magnet.h"

static uint16_t _time_c = 0;
static bool _ele_flag = 0;
void Ele_magnet_on(uint16_t _time)
{
    _ele_flag = 1;
    // digitalWrite(ELE_magnet_pin, HIGH);
    _time_c++;
    if (_time_c == _time)
    {
        digitalWrite(ELE_magnet_pin, HIGH);
    }
    if (_time_c >= _time * 2)
    {
        digitalWrite(ELE_magnet_pin, LOW);
        _time_c = 0;
    }
}

void Ele_magnet_off(void)
{
    if (_ele_flag == 1)
    {
        _ele_flag = 0;
        digitalWrite(ELE_magnet_pin, LOW);
        _time_c = 0;
    }
}

void Ele_mode(void)
{
    
}