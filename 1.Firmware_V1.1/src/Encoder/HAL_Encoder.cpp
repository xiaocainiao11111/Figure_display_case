#include "Encoder/ButtonEvent.h"

static ButtonEvent EncoderPush(5000);

static bool EncoderEnable = true;
static volatile int16_t EncoderDiff = 0;
static bool EncoderDiffDisable = false;

static void Encoder_IrqHandler()
{
    if (!EncoderEnable || EncoderDiffDisable)
    {
        return;
    }

    static volatile int count, countLast;
    static volatile uint8_t a0, b0;
    static volatile uint8_t ab0;
    uint8_t a = digitalRead(KEY_A);
    uint8_t b = digitalRead(KEY_B);
    if (a != a0)
    {
        a0 = a;
        if (b != b0)
        {
            b0 = b;
            count += ((a == b) ? 1 : -1);
            if ((a == b) != ab0)
            {
                count += ((a == b) ? 1 : -1);
            }
            ab0 = (a == b);
        }
    }

    if (count != countLast)
    {
        EncoderDiff += (count - countLast) > 0 ? 1 : -1;
        countLast = count;
    }
}

// 按键回调
static void Encoder_PushHandler(ButtonEvent *btn, int event)
{
    if (event == ButtonEvent::EVENT_PRESSED)
    {
        EncoderDiffDisable = true;
    }
    else if (event == ButtonEvent::EVENT_RELEASED)
    {
        EncoderDiffDisable = false;
    }
    else if (event == ButtonEvent::EVENT_LONG_PRESSED)
    {
        // 长按关机
        // ENCODER::Power_Shutdown();
    }
}

static void Encoder_RotateHandler(int16_t diff)
{
}

void ENCODER::Encoder_Init()
{
    pinMode(KEY_A, INPUT_PULLUP);
    pinMode(KEY_B, INPUT_PULLUP);
    pinMode(KEY_EN, INPUT_PULLUP);

    attachInterrupt(KEY_A, Encoder_IrqHandler, CHANGE);

    EncoderPush.EventAttach(Encoder_PushHandler);
}

void ENCODER::Encoder_Update()
{
    EncoderPush.EventMonitor(Encoder_GetIsPush());
}

int16_t ENCODER::Encoder_GetDiff()
{
    int16_t diff = -EncoderDiff / 2;
    if (diff != 0)
    {
        // EncoderDiff是实际的脉冲数；把本次变量用掉了，需要重新置0
        EncoderDiff = 0;
        Encoder_RotateHandler(diff);
    }

    return diff;
}

// 按下判断
bool ENCODER::Encoder_GetIsPush()
{
    if (!EncoderEnable)
    {
        return false;
    }

    return (digitalRead(KEY_EN) == LOW);
}

void ENCODER::Encoder_SetEnable(bool en)
{
    EncoderEnable = en;
}
