#include "RGB.h"

#define WS2812_PIN 19 // RGB选择引脚
#define WS2812_NUM 10  // 定义led个数，决定数组长度

Adafruit_NeoPixel strip = Adafruit_NeoPixel(WS2812_NUM, WS2812_PIN, NEO_GRB + NEO_KHZ800);



unsigned long _millis = 0;
int RGB_time = 0;
// RGB随机数
int R;
int G;
int B;


// void RGB()
// {
//     // RGB随机数
//     R = random(255);
//     G = random(255);
//     B = random(255);
//     if (num2 == 80)
//     {
//         strip.setPixelColor(0, R, G, B);
//         strip.setPixelColor(1, B, R, G);
//         strip.setPixelColor(2, G, B, R);
//         strip.show();
//     }
//     if (num2 == 120)
//     {
//         strip.clear(); // 关闭所有灯
//         strip.show();
//         num2 = 0;
//     }
//     num2++;
// }



// RGB功能实现
//  Some functions of our own for creating animated effects -----------------
//  Fill strip pixels one after another with a color. Strip is NOT cleared
//  first; anything there will be covered pixel by pixel. Pass in color
//  (as a single 'packed' 32-bit value, which you can get by calling
//  strip.Color(red, green, blue) as shown in the loop() function above),
//  and a delay time (in milliseconds) between pixels.
void colorWipe(uint32_t color, int wait)
{
    for (int i = 0; i < strip.numPixels(); i++)
    {                                  // For each pixel in strip...
        strip.setPixelColor(i, color); //  Set pixel's color (in RAM)
        strip.show();                  //  Update strip to match
        delay(wait);                   //  Pause for a moment
    }
}

// Theater-marquee-style chasing lights. Pass in a color (32-bit value,
// a la strip.Color(r,g,b) as mentioned above), and a delay time (in ms)
// between frames.
void theaterChase(uint32_t color, int wait)
{
    for (int a = 0; a < 10; a++)
    { // Repeat 10 times...
        for (int b = 0; b < 3; b++)
        {                  //  'b' counts from 0 to 2...
            strip.clear(); //   Set all pixels in RAM to 0 (off)
            // 'c' counts up from 'b' to end of strip in steps of 3...
            for (int c = b; c < strip.numPixels(); c += 3)
            {
                strip.setPixelColor(c, color); // Set pixel 'c' to value 'color'
            }
            strip.show(); // Update strip with new contents
            delay(wait);  // Pause for a moment
        }
    }
}

void rainbow(int wait)
{
    for (long firstPixelHue = 0; firstPixelHue < 5 * 65536; firstPixelHue += 256)
    {

        strip.rainbow(firstPixelHue);
        // Above line is equivalent to:
        // strip.rainbow(firstPixelHue, 1, 255, 255, true);
        strip.show(); // Update strip with new contents
        delay(wait);  // Pause for a moment
    }
}

// Rainbow-enhanced theater marquee. Pass delay time (in ms) between frames.
void theaterChaseRainbow(int wait)
{
    if (millis() > _millis)
    {
        int firstPixelHue = 0; // First pixel starts at red (hue 0)
        for (int a = 0; a < 30; a++)
        { // Repeat 30 times...
            for (int b = 0; b < 3; b++)
            {                  //  'b' counts from 0 to 2...
                strip.clear(); //   Set all pixels in RAM to 0 (off)
                // 'c' counts up from 'b' to end of strip in increments of 3...
                for (int c = b; c < strip.numPixels(); c += 3)
                {
                    // hue of pixel 'c' is offset by an amount to make one full
                    // revolution of the color wheel (range 65536) along the length
                    // of the strip (strip.numPixels() steps):
                    int hue = firstPixelHue + c * 65536L / strip.numPixels();
                    uint32_t color = strip.gamma32(strip.ColorHSV(hue)); // hue -> RGB
                    strip.setPixelColor(c, color);                       // Set pixel 'c' to value 'color'
                }
                strip.show(); // Update strip with new contents
                // delay(wait); // Pause for a moment
                firstPixelHue += 65536 / 90; // One cycle of color wheel over 90 frames
                _millis = millis() + 1000;
            }
        }
    }
}