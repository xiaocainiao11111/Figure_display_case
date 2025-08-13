#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>
#include "main.h"

// #define SPEED 4 // 16的因数
// #define ICON_SPEED 12
// #define ICON_SPACE 48 // 图标间隔，speed倍数

// #define READ 2
// #define BTN0 KEY_A
// #define BTN1 KEY_B
// #define BTN2 KEY_EN

// void chart_draw_frame();

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* clock=*/OLED_SCL, /* data=*/OLED_SDA);

// PROGMEM const uint8_t icon_pic[][200]{
//     {
//         0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x3E,
//         0x00, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x00,
//         0x00, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x00,
//         0x00, 0x00, 0x00, 0x7F, 0x00, 0x00, 0x00, 0x00,
//         0x7F, 0x00, 0x00, 0x00, 0x80, 0x7F, 0x00, 0x00,
//         0x00, 0x80, 0x7F, 0x00, 0x00, 0x00, 0xC0, 0x7F,
//         0x00, 0x00, 0x00, 0xE0, 0x7F, 0x00, 0x00, 0x00,
//         0xF8, 0x7F, 0x00, 0x00, 0xF0, 0xF8, 0xFF, 0xFF,
//         0x01, 0xFC, 0xF8, 0xFF, 0xFF, 0x07, 0xFC, 0xF8,
//         0xFF, 0xFF, 0x07, 0xFE, 0xF8, 0xFF, 0xFF, 0x07,
//         0xFE, 0xF8, 0xFF, 0xFF, 0x07, 0xFE, 0xF8, 0xFF,
//         0xFF, 0x07, 0xFE, 0xF8, 0xFF, 0xFF, 0x07, 0xFE,
//         0xF8, 0xFF, 0xFF, 0x07, 0xFE, 0xF8, 0xFF, 0xFF,
//         0x03, 0xFE, 0xF8, 0xFF, 0xFF, 0x03, 0xFE, 0xF8,
//         0xFF, 0xFF, 0x03, 0xFE, 0xF8, 0xFF, 0xFF, 0x03,
//         0xFE, 0xF8, 0xFF, 0xFF, 0x01, 0xFE, 0xF8, 0xFF,
//         0xFF, 0x01, 0xFE, 0xF8, 0xFF, 0xFF, 0x01, 0xFE,
//         0xF8, 0xFF, 0xFF, 0x01, 0xFE, 0xF8, 0xFF, 0xFF,
//         0x00, 0xFE, 0xF8, 0xFF, 0xFF, 0x00, 0xFC, 0xF8,
//         0xFF, 0x7F, 0x00, 0xFC, 0xF8, 0xFF, 0x3F, 0x00,
//         0xF8, 0xF8, 0xFF, 0x1F, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 /*"C:\Users\ROG\Desktop\三连\点赞.bmp",0*/
//                                                  /* (36 X 35 )*/
//     },
//     {
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00,
//         0x00, 0x1F, 0x00, 0x00, 0x00, 0x80, 0x1F, 0x00,
//         0x00, 0x00, 0x80, 0x3F, 0x00, 0x00, 0x00, 0xC0,
//         0x3F, 0x00, 0x00, 0x00, 0xC0, 0x3F, 0x00, 0x00,
//         0x00, 0xC0, 0x7F, 0x00, 0x00, 0x00, 0xE0, 0xFF,
//         0x00, 0x00, 0x00, 0xF0, 0xFF, 0x01, 0x00, 0x00,
//         0xFC, 0xFF, 0x03, 0x00, 0xE0, 0xFF, 0xFF, 0xFF,
//         0x00, 0xFC, 0xFF, 0xFF, 0xFF, 0x07, 0xFE, 0xFF,
//         0xFF, 0xFF, 0x07, 0xFC, 0xFF, 0xFF, 0xFF, 0x07,
//         0xFC, 0xFF, 0xFF, 0xFF, 0x03, 0xF8, 0xFF, 0xFF,
//         0xFF, 0x01, 0xF0, 0xFF, 0xFF, 0xFF, 0x00, 0xE0,
//         0xFF, 0xFF, 0x7F, 0x00, 0xC0, 0xFF, 0xFF, 0x3F,
//         0x00, 0x80, 0xFF, 0xFF, 0x3F, 0x00, 0x00, 0xFF,
//         0xFF, 0x1F, 0x00, 0x00, 0xFF, 0xFF, 0x1F, 0x00,
//         0x00, 0xFF, 0xFF, 0x0F, 0x00, 0x00, 0xFF, 0xFF,
//         0x0F, 0x00, 0x00, 0xFF, 0xFF, 0x0F, 0x00, 0x00,
//         0xFF, 0xFF, 0x0F, 0x00, 0x00, 0xFF, 0xFF, 0x0F,
//         0x00, 0x00, 0xFF, 0xFF, 0x1F, 0x00, 0x00, 0xFF,
//         0xFF, 0x1F, 0x00, 0x80, 0xFF, 0xF0, 0x1F, 0x00,
//         0x80, 0x3F, 0xC0, 0x1F, 0x00, 0x80, 0x1F, 0x00,
//         0x1F, 0x00, 0x00, 0x07, 0x00, 0x1C, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00 /*"C:\Users\ROG\Desktop\三连\收藏.bmp",0*/
//              /* (36 X 37 )*/
//     },
//     {
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x1F,
//         0x00, 0x00, 0x00, 0xF0, 0xFF, 0x01, 0x00, 0x00,
//         0xFC, 0xFF, 0x07, 0x00, 0x00, 0xFF, 0xFF, 0x0F,
//         0x00, 0x80, 0xFF, 0xFF, 0x1F, 0x00, 0xC0, 0xFF,
//         0xFF, 0x7F, 0x00, 0xE0, 0x07, 0x00, 0x7C, 0x00,
//         0xF0, 0x03, 0x00, 0xFC, 0x00, 0xF0, 0x03, 0x00,
//         0xFC, 0x01, 0xF8, 0xFF, 0xF1, 0xFF, 0x01, 0xF8,
//         0xFF, 0xF1, 0xFF, 0x03, 0xF8, 0x7F, 0xC0, 0xFF,
//         0x03, 0xFC, 0x1F, 0x00, 0xFF, 0x03, 0xFC, 0x07,
//         0x00, 0xFE, 0x07, 0xFC, 0x07, 0x01, 0xFC, 0x07,
//         0xFC, 0xC3, 0x31, 0xF8, 0x07, 0xFC, 0xE1, 0xF1,
//         0xF8, 0x07, 0xFC, 0xF1, 0xF1, 0xF0, 0x07, 0xFC,
//         0xF1, 0xF1, 0xF0, 0x07, 0xFC, 0xF1, 0xF1, 0xF1,
//         0x07, 0xFC, 0xF1, 0xF1, 0xF1, 0x07, 0xFC, 0xF1,
//         0xF1, 0xF1, 0x03, 0xF8, 0xF1, 0xF1, 0xF1, 0x03,
//         0xF8, 0xFF, 0xF1, 0xFF, 0x03, 0xF8, 0xFF, 0xF1,
//         0xFF, 0x01, 0xF0, 0xFF, 0xF1, 0xFF, 0x01, 0xF0,
//         0xFF, 0xF1, 0xFF, 0x00, 0xE0, 0xFF, 0xF1, 0x7F,
//         0x00, 0xC0, 0xFF, 0xFF, 0x7F, 0x00, 0x80, 0xFF,
//         0xFF, 0x3F, 0x00, 0x00, 0xFF, 0xFF, 0x0F, 0x00,
//         0x00, 0xFC, 0xFF, 0x07, 0x00, 0x00, 0xF0, 0xFF,
//         0x01, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00 /*"C:\Users\ROG\Desktop\三连\投币.bmp",0*/
//                                /* (36 X 36 )*/
//     },
//     {
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x00,
//         0x00, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x00,
//         0xFC, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x01, 0x00,
//         0x00, 0x00, 0xFC, 0x03, 0x00, 0x00, 0x00, 0xFC,
//         0x07, 0x00, 0x00, 0x00, 0xFC, 0x0F, 0x00, 0x00,
//         0x00, 0xFE, 0x1F, 0x00, 0x00, 0xF8, 0xFF, 0x3F,
//         0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0xC0, 0xFF,
//         0xFF, 0xFF, 0x01, 0xE0, 0xFF, 0xFF, 0xFF, 0x03,
//         0xF0, 0xFF, 0xFF, 0xFF, 0x07, 0xF0, 0xFF, 0xFF,
//         0xFF, 0x0F, 0xF8, 0xFF, 0xFF, 0xFF, 0x0F, 0xFC,
//         0xFF, 0xFF, 0xFF, 0x07, 0xFC, 0xFF, 0xFF, 0xFF,
//         0x03, 0xFE, 0xFF, 0xFF, 0xFF, 0x01, 0xFE, 0xFF,
//         0xFF, 0xFF, 0x00, 0xFF, 0x03, 0xFE, 0x3F, 0x00,
//         0xFF, 0x00, 0xFC, 0x1F, 0x00, 0x3F, 0x00, 0xFC,
//         0x0F, 0x00, 0x1F, 0x00, 0xFC, 0x07, 0x00, 0x07,
//         0x00, 0xFC, 0x03, 0x00, 0x03, 0x00, 0xFC, 0x01,
//         0x00, 0x01, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00,
//         0x3C, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00,
//         0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, /*"C:\Users\13944\Desktop\fenxiang.bmp",0*/
//     },
// };

// uint8_t icon_width[] = {35, 37, 36, 36};

// // main界面图片
// PROGMEM const uint8_t LOGO[] =
//     {
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x10, 0x01, 0x24, 0x00, 0x44, 0x04, 0x80, 0x20, 0x00, 0x00, 0x10, 0xF2, 0x3C, 0x20, 0xE0, 0x00,
//         0x10, 0x01, 0x24, 0x00, 0xC4, 0x04, 0x80, 0x20, 0x00, 0x00, 0x10, 0x11, 0x24, 0x30, 0x10, 0x01,
//         0x10, 0x71, 0x24, 0x0F, 0xC4, 0xE2, 0x99, 0x3C, 0x00, 0x00, 0x20, 0x11, 0x24, 0x20, 0x10, 0x01,
//         0xF0, 0x89, 0xA4, 0x10, 0xA8, 0x12, 0x8A, 0x22, 0x00, 0x00, 0x20, 0xF1, 0x1C, 0x20, 0x10, 0x01,
//         0x10, 0xF9, 0xA4, 0x10, 0x98, 0x13, 0x8A, 0x22, 0x00, 0x00, 0xA0, 0x10, 0x24, 0x20, 0x10, 0x01,
//         0x10, 0x09, 0xA4, 0x10, 0x98, 0x11, 0x8A, 0x22, 0x00, 0x00, 0xA0, 0x10, 0x24, 0x20, 0x10, 0x01,
//         0x10, 0xF1, 0x24, 0x0F, 0x10, 0xE1, 0x89, 0x3C, 0x00, 0x00, 0x40, 0xF0, 0x44, 0x20, 0xE2, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F,
//         0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F,
//         0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
//         0xFF, 0xFF, 0xE7, 0xFF, 0xFB, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
//         0x0F, 0xFE, 0x99, 0xFF, 0xE4, 0x1F, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
//         0xE7, 0xFD, 0xBD, 0xFF, 0xDE, 0xDF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0xFE,
//         0xF7, 0xFD, 0x7D, 0x7F, 0xDF, 0xDF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0xFD,
//         0xF7, 0xFD, 0x7D, 0x7F, 0xDF, 0xDF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0xFD,
//         0xF7, 0xFD, 0x7D, 0x7F, 0xDF, 0x1F, 0xF0, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0xFD,
//         0xF7, 0xFD, 0x7D, 0x7F, 0xDF, 0xFF, 0xF7, 0xFD, 0xFF, 0x1F, 0xFE, 0xFF, 0x83, 0xFF, 0xE3, 0xF1,
//         0xF7, 0xFD, 0x7D, 0x7F, 0xDF, 0xFF, 0xF7, 0xFD, 0xFF, 0xE3, 0xF1, 0xFF, 0x7C, 0xF8, 0xF9, 0xEF,
//         0xF7, 0xFD, 0x7D, 0x7F, 0xDF, 0xFF, 0xF7, 0xFD, 0xFF, 0xFD, 0xEF, 0x3F, 0xFF, 0xF3, 0xFD, 0xDF,
//         0xF7, 0xFD, 0x7D, 0x7F, 0xDF, 0xFF, 0xF7, 0xFD, 0xFF, 0x1E, 0xDC, 0xBF, 0x03, 0xF7, 0xE3, 0xE1,
//         0xF7, 0xFD, 0x7D, 0x7F, 0xDF, 0xFF, 0xF7, 0xFD, 0x7F, 0xEF, 0xB9, 0xDF, 0xFB, 0xF0, 0xEF, 0xFD,
//         0xF7, 0xFD, 0x7D, 0x7F, 0xDF, 0xFF, 0xF7, 0xFD, 0x7F, 0xE7, 0xBB, 0xDF, 0xF3, 0xFF, 0xEF, 0xFD,
//         0xF7, 0xFD, 0x7D, 0x7F, 0xDF, 0xFF, 0xF7, 0xFD, 0xBF, 0xF7, 0x7B, 0xDF, 0x0F, 0xFF, 0xEF, 0xFD,
//         0xF7, 0xFD, 0x7D, 0x7F, 0xDF, 0xFF, 0xF7, 0xFD, 0xBF, 0x0F, 0x7C, 0xBF, 0xFF, 0xFC, 0xEF, 0xFD,
//         0xF7, 0xFD, 0x7D, 0x7F, 0xDF, 0xFF, 0xF7, 0xFD, 0xBF, 0xFF, 0xBF, 0x7F, 0xFE, 0xF3, 0xEF, 0xFD,
//         0xF7, 0xFD, 0xBE, 0x7F, 0xDF, 0xFF, 0xF7, 0xFD, 0xBF, 0x07, 0xC0, 0xFF, 0xE1, 0xF7, 0xEF, 0xFD,
//         0xEF, 0xFB, 0xBE, 0x7F, 0xDF, 0xFF, 0xF7, 0xFD, 0xBF, 0xEF, 0xFF, 0xFF, 0x9F, 0xEF, 0xEF, 0xFD,
//         0xEF, 0x07, 0xBF, 0x7F, 0xDF, 0xFF, 0xF7, 0xFD, 0x7F, 0xEF, 0xC7, 0x3F, 0x3E, 0xEF, 0xEF, 0xFD,
//         0xDF, 0xFF, 0xDF, 0x7F, 0xDF, 0xFF, 0xF7, 0xFD, 0xFF, 0x1E, 0xB8, 0xDF, 0xB9, 0xF7, 0xEF, 0xE3,
//         0x9F, 0xFF, 0xEF, 0x7F, 0xDF, 0xFF, 0xF7, 0xFD, 0xFF, 0xFC, 0xBF, 0x9F, 0xC7, 0xF7, 0xDF, 0xCF,
//         0x7F, 0xFF, 0xF3, 0xFF, 0xDE, 0xFF, 0xEF, 0xFD, 0xFF, 0xFB, 0xCF, 0x3F, 0xFF, 0xF9, 0x9F, 0xEF,
//         0xFF, 0x00, 0xFC, 0xFF, 0xE1, 0xFF, 0x1F, 0xFE, 0xFF, 0x07, 0xF0, 0xFF, 0x00, 0xFE, 0x7F, 0xF0,
//         0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
//         0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F,
//         0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x00, 0x40, 0x00, 0x02, 0x10, 0x00, 0x00,
//         0x00, 0x00, 0x88, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x00, 0x60, 0x00, 0x02, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x88, 0x9C, 0x24, 0xC7, 0x1C, 0x0F, 0x68, 0x22, 0xA0, 0xCC, 0x23, 0x91, 0xC7, 0x01,
//         0x00, 0xFE, 0x88, 0xA2, 0xAA, 0x48, 0xA2, 0x08, 0x98, 0x14, 0xB0, 0x24, 0x22, 0x91, 0x24, 0x02,
//         0x00, 0x00, 0x78, 0xA2, 0xAB, 0x4F, 0xBE, 0x08, 0x88, 0x14, 0xF0, 0x24, 0x22, 0x91, 0x24, 0x02,
//         0x00, 0x00, 0x08, 0x22, 0x9B, 0x40, 0x82, 0x08, 0x88, 0x0C, 0x08, 0x25, 0x22, 0x91, 0x24, 0x02,
//         0x00, 0x00, 0x08, 0x1C, 0x11, 0x4F, 0x3C, 0x0F, 0x78, 0x08, 0x08, 0xC5, 0xE3, 0x91, 0xC4, 0x01,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

// const float PID_MAX = 10.00; // PID最大允许值
// // PID变量
// float Kpid[3] = {9.97, 0.2, 0.01}; // Kp,Ki,Kd
// // float Kp=8.96;
// // float Ki=0.2;
// // float Kd=0.01;

// uint8_t disappear_step = 1;

// float angle, angle_last;
// // 实时坐标
// uint8_t chart_x;
// bool frame_is_drawed = false;

// // 指向buf首地址的指针
// uint8_t *buf_ptr;
// uint16_t buf_len;

// // 选择界面变量
// uint8_t x;
// int16_t y, y_trg;                 // 文本的位置，当前和目标
// uint8_t line_y, line_y_trg;       // 右边滑块线的位置
// uint8_t box_width, box_width_trg; // 框的宽度
// int16_t box_y, box_y_trg;         // 框的当前值和目标值
// int8_t ui_select;                 // 当前选中那一栏

// // pid界面变量
// // int8_t pid_y,pid_y_trg;
// uint8_t pid_line_y, pid_line_y_trg;       // 线的位置
// uint8_t pid_box_width, pid_box_width_trg; // 框的宽度
// int16_t pid_box_y, pid_box_y_trg;         // 框的当前值和目标值
// int8_t pid_select;                        // 当前选中那一栏

// // icon界面变量
// int16_t icon_x, icon_x_trg;
// int16_t app_y, app_y_trg;

// int8_t icon_select;

// uint8_t ui_index, ui_state;

// enum // ui_index
// {
//     M_LOGO,      // 开始界面
//     M_SELECT,    // 选择界面
//     M_PID,       // PID界面
//     M_PID_EDIT,  // pid编辑
//     M_ICON,      // icon界面
//     M_CHART,     // 图表
//     M_TEXT_EDIT, // 文字编辑
//     M_VIDEO,     // 视频显示
//     M_ABOUT,     // 关于本机
// };

// enum // ui_state
// {
//     S_NONE,
//     S_DISAPPEAR,
//     S_SWITCH,
//     S_MENU_TO_MENU,
//     S_MENU_TO_PIC,
//     S_PIC_TO_MENU,
// };

// // const char* text="This is a text Hello world ! follow up one two three four may jun july";

// // 菜单结构体
// typedef struct
// {
//     char *select;
// } SELECT_LIST;

// SELECT_LIST pid[]{
//     {"-Proportion"},
//     {"-Integral"},
//     {"-Derivative"},
//     {"Return"},
// };

// uint8_t pid_num = sizeof(pid) / sizeof(SELECT_LIST); // PID选项数量

// SELECT_LIST list[]{
//     {"MainUI"},
//     {"+PID Editor"},
//     {"-Icon Test"},
//     {"-Chart Test"},
//     {"-Text Edit"},
//     {"-Play Video"},
//     {"{ About }"},
// };

// uint8_t list_num = sizeof(list) / sizeof(SELECT_LIST); // 选择界面数量
// uint8_t single_line_length = 63 / list_num;
// uint8_t total_line_length = single_line_length * list_num + 1;

// SELECT_LIST icon[]{
//     {"Likes"},
//     {"Collection"},
//     {"Slot"},
//     {"Share"},
// };

// // 设备名称
// char name[] = "Hello World ";
// // 允许名字的最大长度
// const uint8_t name_len = 12; // 0-11for name  12 for return
// uint8_t edit_index = 0;
// bool edit_flag = false;         // 默认不在编辑
// uint8_t blink_flag;             // 默认高亮
// const uint8_t BLINK_SPEED = 16; // 2的倍数

// uint8_t icon_num = sizeof(icon) / sizeof(SELECT_LIST);

// // 按键变量
// typedef struct
// {
//     bool val;
//     bool last_val;
// } KEY;

// KEY key[3] = {false};

// // 按键信息
// typedef struct
// {
//     uint8_t id; // 0：前一个，1：后一个,2：确认
//     bool pressed;
// } KEY_MSG;

// KEY_MSG key_msg = {0};

// bool get_key_val(uint8_t ch)
// {
//     switch (ch)
//     {
//     case 0:
//         // Serial.printf("btn0:%d  ", digitalRead(BTN0));
//         return digitalRead(BTN0);

//         break;
//     case 1:
//         // Serial.printf("btn1:%d  ", digitalRead(BTN1));
//         return digitalRead(BTN1);

//         break;
//     case 2:
//         // Serial.printf("btn2:%d\n", !digitalRead(BTN2));
//         return !digitalRead(BTN2);

//         break;
//     default:
//         break;
//     }
// }

// void key_init()
// {
//     for (uint8_t i = 0; i < (sizeof(key) / sizeof(KEY)); ++i)
//     {
//         key[i].val = key[i].last_val = get_key_val(i);
//     }
// }

// void key_scan()
// {
//     for (uint8_t i = 0; i < (sizeof(key) / sizeof(KEY)); ++i)
//     {
//         key[i].val = get_key_val(i);       // 获取键值
//         if (key[i].last_val != key[i].val) // 发生改变
//         {
//             key[i].last_val = key[i].val; // 更新状态
//             if (key[i].val == LOW)
//             {
//                 key_msg.id = i;
//                 key_msg.pressed = true;
//             }
//         }
//     }
// }

// // 移动函数
// bool move(int16_t *a, int16_t *a_trg)
// {
//     Serial.println("move");
//     if (*a < *a_trg)
//     {
//         *a += SPEED;
//         if (*a > *a_trg)
//             *a = *a_trg; // 加完超过
//     }
//     else if (*a > *a_trg)
//     {
//         *a -= SPEED;
//         if (*a < *a_trg)
//             *a = *a_trg; // 减完不足
//     }
//     else
//     {
//         return true; // 到达目标
//     }
//     return false; // 未到达
// }

// // 移动函数
// bool move_icon(int16_t *a, int16_t *a_trg)
// {
//     Serial.println("move_icon");

//     if (*a < *a_trg)
//     {
//         *a += ICON_SPEED;
//         if (*a > *a_trg)
//             *a = *a_trg; // 加完超过
//     }
//     else if (*a > *a_trg)
//     {
//         *a -= ICON_SPEED;
//         if (*a < *a_trg)
//             *a = *a_trg; // 减完不足
//     }
//     else
//     {
//         return true; // 到达目标
//     }
//     return false; // 未到达
// }

// // 宽度移动函数
// bool move_width(uint8_t *a, uint8_t *a_trg, uint8_t select, uint8_t id)
// {
//     Serial.println("move_width");

//     if (*a < *a_trg)
//     {
//         uint8_t step = 16 / SPEED; // 判断步数
//         uint8_t len;
//         if (ui_index == M_SELECT)
//         {
//             len = abs(u8g2.getStrWidth(list[select].select) - u8g2.getStrWidth(list[id == 0 ? select + 1 : select - 1].select));
//         }
//         else if (ui_index == M_PID)
//         {
//             len = abs(u8g2.getStrWidth(pid[select].select) - u8g2.getStrWidth(pid[id == 0 ? select + 1 : select - 1].select));
//         }
//         uint8_t width_speed = ((len % step) == 0 ? (len / step) : (len / step + 1)); // 计算步长
//         *a += width_speed;
//         if (*a > *a_trg)
//             *a = *a_trg; //
//     }
//     else if (*a > *a_trg)
//     {
//         uint8_t step = 16 / SPEED; // 判断步数
//         uint8_t len;
//         if (ui_index == M_SELECT)
//         {
//             len = abs(u8g2.getStrWidth(list[select].select) - u8g2.getStrWidth(list[id == 0 ? select + 1 : select - 1].select));
//         }
//         else if (ui_index == M_PID)
//         {
//             len = abs(u8g2.getStrWidth(pid[select].select) - u8g2.getStrWidth(pid[id == 0 ? select + 1 : select - 1].select));
//         }
//         uint8_t width_speed = ((len % step) == 0 ? (len / step) : (len / step + 1)); // 计算步长
//         *a -= width_speed;
//         if (*a < *a_trg)
//             *a = *a_trg;
//     }
//     else
//     {
//         return true; // 到达目标
//     }
//     return false; // 未到达
// }

// // 进度条移动函数
// bool move_bar(uint8_t *a, uint8_t *a_trg)
// {
//     Serial.println("move_bar");

//     if (*a < *a_trg)
//     {
//         uint8_t step = 16 / SPEED;                                                                                                // 判断步数
//         uint8_t width_speed = ((single_line_length % step) == 0 ? (single_line_length / step) : (single_line_length / step + 1)); // 计算步长
//         *a += width_speed;
//         if (*a > *a_trg)
//             *a = *a_trg; //
//     }
//     else if (*a > *a_trg)
//     {
//         uint8_t step = 16 / SPEED;                                                                                                // 判断步数
//         uint8_t width_speed = ((single_line_length % step) == 0 ? (single_line_length / step) : (single_line_length / step + 1)); // 计算步长
//         *a -= width_speed;
//         if (*a < *a_trg)
//             *a = *a_trg;
//     }
//     else
//     {
//         return true; // 到达目标
//     }
//     return false; // 未到达
// }

// // 文字编辑函数
// void text_edit(bool dir, uint8_t index)
// {
//     Serial.println("text_edit");
//     if (!dir)
//     {
//         if (name[index] >= 'A' && name[index] <= 'Z') // 大写字母
//         {
//             if (name[index] == 'A')
//             {
//                 name[index] = 'z';
//             }
//             else
//             {
//                 name[index] -= 1;
//             }
//         }
//         else if (name[index] >= 'a' && name[index] <= 'z') // 小写字母
//         {
//             if (name[index] == 'a')
//             {
//                 name[index] = ' ';
//             }
//             else
//             {
//                 name[index] -= 1;
//             }
//         }
//         else
//         {
//             name[index] = 'Z';
//         }
//     }
//     else
//     {
//         if (name[index] >= 'A' && name[index] <= 'Z') // 大写字母
//         {
//             if (name[index] == 'Z')
//             {
//                 name[index] = ' ';
//             }
//             else
//             {
//                 name[index] += 1;
//             }
//         }
//         else if (name[index] >= 'a' && name[index] <= 'z') // 小写字母
//         {
//             if (name[index] == 'z')
//             {
//                 name[index] = 'A';
//             }
//             else
//             {
//                 name[index] += 1;
//             }
//         }
//         else
//         {
//             name[index] = 'a';
//         }
//     }
// }

// // 消失函数
// void disappear()
// {
//     Serial.println("disappear");

//     switch (disappear_step)
//     {
//     case 1:
//         for (uint16_t i = 0; i < buf_len; ++i)
//         {
//             if (i % 2 == 0)
//                 buf_ptr[i] = buf_ptr[i] & 0x55;
//         }
//         break;
//     case 2:
//         for (uint16_t i = 0; i < buf_len; ++i)
//         {
//             if (i % 2 != 0)
//                 buf_ptr[i] = buf_ptr[i] & 0xAA;
//         }
//         break;
//     case 3:
//         for (uint16_t i = 0; i < buf_len; ++i)
//         {
//             if (i % 2 == 0)
//                 buf_ptr[i] = buf_ptr[i] & 0x00;
//         }
//         break;
//     case 4:
//         for (uint16_t i = 0; i < buf_len; ++i)
//         {
//             if (i % 2 != 0)
//                 buf_ptr[i] = buf_ptr[i] & 0x00;
//         }
//         break;
//     default:
//         ui_state = S_NONE;
//         disappear_step = 0;
//         break;
//     }
//     disappear_step++;
// }

// /**************************界面显示*******************************/

// void logo_ui_show() // 显示logo
// {
//     Serial.println("logo_ui_show");

//     u8g2.drawXBMP(0, 0, 128, 64, LOGO);

//     // for(uint16_t i=0;i<buf_len;++i)
//     // {
//     //   if(i%4==0||i%4==1)
//     //   {
//     //   buf_ptr[i]=buf_ptr[i] & 0x33;
//     //   }
//     //   else
//     //   {
//     //   buf_ptr[i]=buf_ptr[i] & 0xCC;
//     //   }
//     // }
// }

// void select_ui_show() // 选择界面，包括右边滑块和左边选择框
// {
//     Serial.println("select_ui_show");

//     move_bar(&line_y, &line_y_trg);
//     move(&y, &y_trg);
//     move(&box_y, &box_y_trg);
//     move_width(&box_width, &box_width_trg, ui_select, key_msg.id);
//     u8g2.drawVLine(126, 0, total_line_length);
//     u8g2.drawPixel(125, 0);
//     u8g2.drawPixel(127, 0);
//     for (uint8_t i = 0; i < list_num; ++i)
//     {
//         u8g2.drawStr(x, 16 * i + y + 12, list[i].select); // 第一段输出位置，这里的y起缓出的作用
//         u8g2.drawPixel(125, single_line_length * (i + 1));
//         u8g2.drawPixel(127, single_line_length * (i + 1));
//     }
//     u8g2.drawVLine(125, line_y, single_line_length - 1);
//     u8g2.drawVLine(127, line_y, single_line_length - 1);

//     // 使用异或绘制一个圆角矩形，用于选择框的颜色反转，然后恢复原来颜色
//     u8g2.setDrawColor(2);
//     u8g2.drawRBox(0, box_y, box_width, 16, 1);
//     u8g2.setDrawColor(1);
//     Serial.printf("line_y:%d  line_y_trg:%d  box_y:%d  box_y_trg:%d  y:%d  y_trg:%d  \n", line_y, line_y_trg, box_y, box_y_trg, y, y_trg);
// }

// void pid_ui_show() // PID界面
// {
//     Serial.println("pid_ui_show");

//     move_bar(&pid_line_y, &pid_line_y_trg);
//     move(&pid_box_y, &pid_box_y_trg);
//     move_width(&pid_box_width, &pid_box_width_trg, pid_select, key_msg.id);
//     u8g2.drawVLine(126, 0, 61);
//     u8g2.drawPixel(125, 0);
//     u8g2.drawPixel(127, 0);
//     for (uint8_t i = 0; i < pid_num; ++i)
//     {
//         u8g2.drawStr(x, 16 * i + 12, pid[i].select); // 第一段输出位置
//         u8g2.drawPixel(125, 15 * (i + 1));
//         u8g2.drawPixel(127, 15 * (i + 1));
//     }

//     u8g2.setDrawColor(2);
//     u8g2.drawRBox(0, pid_box_y, pid_box_width, 16, 1);
//     u8g2.setDrawColor(1);
//     u8g2.drawVLine(125, pid_line_y, 14);
//     u8g2.drawVLine(127, pid_line_y, 14);
//     Serial.printf("pid_line_y:%d  pid_line_y_trg:%d  pid_box_y:%d  pid_box_y_trg:%d  pid_box_width:%d  pid_box_width_trg:%d  pid_select:%d\n",
//                   pid_line_y, pid_line_y_trg, pid_box_y, pid_box_y_trg, pid_box_width, pid_box_width_trg, pid_select);
// }

// void pid_edit_ui_show() // 显示PID编辑
// {
//     Serial.println("pid_edit_ui_show");

//     u8g2.drawBox(16, 16, 96, 31);
//     u8g2.setDrawColor(2);
//     u8g2.drawBox(17, 17, 94, 29);
//     u8g2.setDrawColor(1);

//     // u8g2.drawBox(17,17,(int)(Kpid[pid_select]/PID_MAX)),30);
//     u8g2.drawFrame(18, 36, 60, 8);
//     u8g2.drawBox(20, 38, (uint8_t)(Kpid[pid_select] / PID_MAX * 56), 4);

//     u8g2.setCursor(22, 30);
//     switch (pid_select)
//     {
//     case 0:
//         u8g2.print("Editing Kp");
//         break;
//     case 1:
//         u8g2.print("Editing Ki");
//         break;
//     case 2:
//         u8g2.print("Editing Kd");
//         break;
//     default:
//         break;
//     }

//     u8g2.setCursor(81, 44);
//     u8g2.print(Kpid[pid_select]);
//     Serial.printf("Kpid[pid_select] / PID_MAX * 56:%d\n",
//                   (uint8_t)(Kpid[pid_select] / PID_MAX * 56));
// }

// void icon_ui_show(void) // 显示icon
// {
//     Serial.println("icon_ui_show");

//     move_icon(&icon_x, &icon_x_trg);
//     move(&app_y, &app_y_trg);

//     for (uint8_t i = 0; i < icon_num; ++i)
//     {
//         u8g2.drawXBMP(46 + icon_x + i * ICON_SPACE, 6, 36, icon_width[i], icon_pic[i]); // 这里icon_x起缓出作用
//         u8g2.setClipWindow(0, 48, 128, 64);
//         u8g2.drawStr((128 - u8g2.getStrWidth(icon[i].select)) / 2, 62 - app_y + i * 16, icon[i].select);
//         u8g2.setMaxClipWindow();
//     }
//     Serial.printf("icon_x:%d  icon_x_trg:%d  app_y:%d  app_y_trg:%d\n",
//                   icon_x, icon_x_trg, app_y, app_y_trg);
// }

// void chart_ui_show() // chart界面
// {
//     Serial.println("chart_ui_show");

//     if (!frame_is_drawed) // 框架只画一遍
//     {
//         u8g2.clearBuffer();
//         chart_draw_frame();
//         angle_last = 20.00 + (float)analogRead(READ) / 100.00;
//         frame_is_drawed = true;
//     }

//     u8g2.drawBox(96, 0, 30, 14);

//     u8g2.drawVLine(chart_x + 10, 59, 3);
//     if (chart_x == 100)
//         chart_x = 0;

//     // u8g2.drawBox(chart_x+11,24,8,32);

//     u8g2.drawVLine(chart_x + 11, 24, 34);
//     u8g2.drawVLine(chart_x + 12, 24, 34);
//     u8g2.drawVLine(chart_x + 13, 24, 34);
//     u8g2.drawVLine(chart_x + 14, 24, 34);

//     // 异或绘制
//     u8g2.setDrawColor(2);
//     angle = 20.00 + (float)analogRead(READ) / 100.00;
//     u8g2.drawLine(chart_x + 11, 58 - (int)angle_last / 2, chart_x + 12, 58 - (int)angle / 2);
//     u8g2.drawVLine(chart_x + 12, 59, 3);
//     angle_last = angle;
//     chart_x += 2;
//     u8g2.drawBox(96, 0, 30, 14);
//     u8g2.setDrawColor(1);

//     u8g2.setCursor(96, 12);
//     u8g2.print(angle);

//     // Serial.printf("icon_x:%d  icon_x_trg:%d  app_y:%d  app_y_trg:%d\n",
//     //               icon_x, icon_x_trg, app_y, app_y_trg);
// }

// void chart_draw_frame() // chart界面
// {
//     Serial.println("chart_draw_frame");

//     u8g2.drawStr(4, 12, "Real time angle :");
//     u8g2.drawRBox(4, 18, 120, 46, 8);
//     u8g2.setDrawColor(2);
//     u8g2.drawHLine(10, 58, 108);
//     u8g2.drawVLine(10, 24, 34);
//     // 箭头
//     u8g2.drawPixel(7, 27);
//     u8g2.drawPixel(8, 26);
//     u8g2.drawPixel(9, 25);

//     u8g2.drawPixel(116, 59);
//     u8g2.drawPixel(115, 60);
//     u8g2.drawPixel(114, 61);
//     u8g2.setDrawColor(1);
// }

// void text_edit_ui_show()
// {
//     Serial.println("text_edit_ui_show");

//     u8g2.drawRFrame(4, 6, 120, 52, 8);
//     u8g2.drawStr((128 - u8g2.getStrWidth("--Text Editor--")) / 2, 20, "--Text Editor--");
//     u8g2.drawStr(10, 38, name);
//     u8g2.drawStr(80, 50, "-Return");

//     uint8_t box_x = 9;

//     // 绘制光标
//     if (edit_index < name_len)
//     {
//         if (blink_flag < BLINK_SPEED / 2)
//         {
//             for (uint8_t i = 0; i < edit_index; ++i)
//             {
//                 char temp[2] = {name[i], '\0'};
//                 box_x += u8g2.getStrWidth(temp);
//                 if (name[i] != ' ')
//                 {
//                     box_x++;
//                 }
//             }
//             char temp[2] = {name[edit_index], '\0'};
//             u8g2.setDrawColor(2);
//             u8g2.drawBox(box_x, 26, u8g2.getStrWidth(temp) + 2, 16);
//             u8g2.setDrawColor(1);
//         }
//     }
//     else
//     {
//         u8g2.setDrawColor(2);
//         u8g2.drawRBox(78, 38, u8g2.getStrWidth("-Return") + 4, 16, 1);
//         u8g2.setDrawColor(1);
//     }

//     if (edit_flag) // 处于编辑状态
//     {
//         if (blink_flag < BLINK_SPEED)
//         {
//             blink_flag += 1;
//         }
//         else
//         {
//             blink_flag = 0;
//         }
//     }
//     else
//     {
//         blink_flag = 0;
//     }
// }

// void about_ui_show() // about界面
// {
//     Serial.println("about_ui_show");

//     u8g2.drawStr(2, 12, "MCU : ESP32");
//     u8g2.drawStr(2, 28, "FLASH : 4MB");
//     u8g2.drawStr(2, 44, "SRAM : 520KB");
//     u8g2.drawStr(2, 60, "RTC SRAM : 16KB");

//     // u8g2.drawStr(2,12,"MCU : MEGA2560");
//     // u8g2.drawStr(2,28,"FLASH : 256KB");
//     // u8g2.drawStr(2,44,"SRAM : 8KB");
//     // u8g2.drawStr(2,60,"EEPROM : 4KB");
// }

// /**************************界面处理*******************************/

// void logo_proc() // logo界面处理函数
// {
//     Serial.println("logo_proc");

//     if (key_msg.pressed)
//     {
//         key_msg.pressed = false;
//         ui_state = S_DISAPPEAR;
//         ui_index = M_SELECT;
//     }
//     logo_ui_show();
// }

// void pid_edit_proc(void) // pid编辑界面处理函数
// {
//     Serial.println("pid_edit_proc");

//     if (key_msg.pressed)
//     {
//         key_msg.pressed = false;
//         switch (key_msg.id)
//         {
//         case 0:
//             if (Kpid[pid_select] > 0)
//                 Kpid[pid_select] -= 0.01;
//             break;
//         case 1:
//             if (Kpid[pid_select] < PID_MAX)
//                 Kpid[pid_select] += 0.01;
//             break;
//         case 2:
//             ui_index = M_PID;
//             break;
//         default:
//             break;
//         }
//     }
//     pid_ui_show();
//     for (uint16_t i = 0; i < buf_len; ++i)
//     {
//         buf_ptr[i] = buf_ptr[i] & (i % 2 == 0 ? 0x55 : 0xAA);
//     }
//     pid_edit_ui_show();
// }

// void pid_proc() // pid界面处理函数
// {
//     Serial.println("pid_proc");

//     pid_ui_show();
//     if (key_msg.pressed)
//     {
//         key_msg.pressed = false;
//         switch (key_msg.id)
//         {
//         case 0:
//             if (pid_select != 0)
//             {
//                 pid_select -= 1;
//                 pid_line_y_trg -= 15;
//                 pid_box_y_trg -= 16;
//                 break;
//             }
//             else
//             {
//                 break;
//             }
//         case 1:
//             if (pid_select != 3)
//             {
//                 pid_select += 1;
//                 pid_line_y_trg += 15;
//                 pid_box_y_trg += 16;
//             }
//             else
//             {
//                 break;
//             }
//             break;
//         case 2:
//             if (pid_select == 3)
//             {
//                 ui_index = M_SELECT;
//                 ui_state = S_DISAPPEAR;
//                 pid_select = 0;
//                 pid_line_y = pid_line_y_trg = 1;
//                 pid_box_y = pid_box_y_trg = 0;
//                 pid_box_width = pid_box_width_trg = u8g2.getStrWidth(pid[pid_select].select) + x * 2;
//             }
//             else
//             {
//                 ui_index = M_PID_EDIT;
//             }
//             break;
//         default:
//             break;
//         }
//         pid_box_width_trg = u8g2.getStrWidth(pid[pid_select].select) + x * 2;
//     }
// }

// void select_proc(void) // 选择界面处理
// {
//     Serial.println("select_proc");

//     if (key_msg.pressed)
//     {
//         key_msg.pressed = false;
//         switch (key_msg.id)
//         {
//         case 0:
//             if (ui_select < 1) // 处在最小的ui，直接退出
//                 break;
//             ui_select -= 1; // 选择前一个
//             line_y_trg -= single_line_length;
//             if (ui_select < -(y / 16))
//             {
//                 y_trg += 16;
//             }
//             else
//             {
//                 box_y_trg -= 16;
//             }

//             break;
//         case 1:
//             if ((ui_select + 2) > (sizeof(list) / sizeof(SELECT_LIST)))
//                 break;
//             ui_select += 1;
//             line_y_trg += single_line_length;
//             if ((ui_select + 1) > (4 - y / 16))
//             {
//                 y_trg -= 16;
//             }
//             else
//             {
//                 box_y_trg += 16;
//             }

//             break;
//         case 2:
//             switch (ui_select)
//             {
//             case 0: // return
//                 ui_state = S_DISAPPEAR;
//                 ui_index = M_LOGO;
//                 break;
//             case 1: // pid
//                 ui_state = S_DISAPPEAR;
//                 ui_index = M_PID;
//                 break;
//             case 2: // icon
//                 ui_state = S_DISAPPEAR;
//                 ui_index = M_ICON;
//                 break;
//             case 3: // chart
//                 ui_state = S_DISAPPEAR;
//                 ui_index = M_CHART;
//                 break;
//             case 4: // textedit
//                 ui_state = S_DISAPPEAR;
//                 ui_index = M_TEXT_EDIT;
//                 break;
//             case 6: // about
//                 ui_state = S_DISAPPEAR;
//                 ui_index = M_ABOUT;
//                 break;
//             default:
//                 break;
//             }
//         // Serial.println("Btn2");
//         default:
//             break;
//         }
//         // Serial.println(ui_select);
//         box_width_trg = u8g2.getStrWidth(list[ui_select].select) + x * 2;
//     }
//     select_ui_show();
// }

// void icon_proc(void) // icon界面处理
// {
//     Serial.println("icon_proc");

//     icon_ui_show();
//     if (key_msg.pressed)
//     {
//         key_msg.pressed = false;
//         switch (key_msg.id)
//         {
//         case 1:
//             if (icon_select != (icon_num - 1))
//             {
//                 icon_select += 1;
//                 app_y_trg += 16;
//                 icon_x_trg -= ICON_SPACE;
//             }
//             break;
//         case 0:
//             if (icon_select != 0)
//             {
//                 icon_select -= 1;
//                 app_y_trg -= 16;
//                 icon_x_trg += ICON_SPACE;
//             }
//             break;
//         case 2:
//             ui_state = S_DISAPPEAR;
//             ui_index = M_SELECT;
//             icon_select = 0;
//             icon_x = icon_x_trg = 0;
//             app_y = app_y_trg = 0;
//             break;
//         default:
//             break;
//         }
//     }
// }

// void chart_proc() // chart界面处理函数
// {
//     Serial.println("chart_proc");

//     chart_ui_show();
//     if (key_msg.pressed)
//     {
//         key_msg.pressed = false;
//         ui_state = S_DISAPPEAR;
//         ui_index = M_SELECT;
//         frame_is_drawed = false; // 退出后框架为未画状态
//         chart_x = 0;
//     }
// }

// void text_edit_proc()
// {
//     Serial.println("text_edit_proc");

//     text_edit_ui_show();
//     if (key_msg.pressed)
//     {
//         key_msg.pressed = false;
//         switch (key_msg.id)
//         {
//         case 0:
//             if (edit_flag)
//             {
//                 // 编辑
//                 text_edit(false, edit_index);
//             }
//             else
//             {
//                 if (edit_index == 0)
//                 {
//                     edit_index = name_len;
//                 }
//                 else
//                 {
//                     edit_index -= 1;
//                 }
//             }
//             break;
//         case 1:
//             if (edit_flag)
//             {
//                 // 编辑
//                 text_edit(true, edit_index);
//             }
//             else
//             {
//                 if (edit_index == name_len)
//                 {
//                     edit_index = 0;
//                 }
//                 else
//                 {
//                     edit_index += 1;
//                 }
//             }
//             break;
//         case 2:
//             if (edit_index == name_len)
//             {
//                 ui_state = S_DISAPPEAR;
//                 ui_index = M_SELECT;
//                 edit_index = 0;
//             }
//             else
//             {
//                 edit_flag = !edit_flag;
//             }
//             break;
//         default:
//             break;
//         }
//     }
// }

// void about_proc() // about界面处理函数
// {
//     Serial.println("about_proc");

//     if (key_msg.pressed)
//     {
//         key_msg.pressed = false;
//         ui_state = S_DISAPPEAR;
//         ui_index = M_SELECT;
//     }
//     about_ui_show();
// }
// /********************************总的UI显示************************************/

// void ui_proc() // 总的UI进程
// {
//     Serial.println("ui_proc");

//     switch (ui_state)
//     {
//     case S_NONE:
//         if (ui_index != M_CHART)
//             u8g2.clearBuffer();
//         switch (ui_index)
//         {
//         case M_LOGO:
//             logo_proc();
//             break;
//         case M_SELECT:
//             select_proc();
//             break;
//         case M_PID:
//             pid_proc();
//             break;
//         case M_ICON:
//             icon_proc();
//             break;
//         case M_CHART:
//             chart_proc();
//             break;
//         case M_TEXT_EDIT:
//             text_edit_proc();
//             break;
//         case M_PID_EDIT:
//             pid_edit_proc();
//             break;
//         case M_ABOUT:
//             about_proc();
//             break;
//         default:
//             break;
//         }
//         break;
//     case S_DISAPPEAR:
//         disappear();
//         break;
//     default:
//         break;
//     }
//     u8g2.sendBuffer();
// }

// // 注意：屏幕启动失败会堵塞住
// void Oled_init()
// {
//     // Serial.begin(115200);
//     Wire.begin(21,22,400000);
//     pinMode(BTN0, INPUT_PULLUP);
//     pinMode(BTN1, INPUT_PULLUP);
//     pinMode(BTN2, INPUT_PULLUP);
//     key_init();
//     u8g2.setBusClock(800000);
//     u8g2.begin();
//     u8g2.setFont(u8g2_font_wqy12_t_chinese1);
//     // u8g2.setContrast(10);

//     buf_ptr = u8g2.getBufferPtr();                                        // 拿到buffer首地址
//     buf_len = 8 * u8g2.getBufferTileHeight() * u8g2.getBufferTileWidth(); // 1024
//     // Serial.println(buf_len);

//     x = 4;
//     y = y_trg = 0;
//     line_y = line_y_trg = 1;
//     pid_line_y = pid_line_y_trg = 1;
//     ui_select = pid_select = icon_select = 0;
//     icon_x = icon_x_trg = 0;
//     app_y = app_y_trg = 0;

//     box_width = box_width_trg = u8g2.getStrWidth(list[ui_select].select) + x * 2;         // 两边各多2
//     pid_box_width = pid_box_width_trg = u8g2.getStrWidth(pid[pid_select].select) + x * 2; // 两边各多2

//     ui_index = M_LOGO;
//     // ui_index=M_TEXT_EDIT;
//     ui_state = S_NONE;
// }

// // void loop()
// // {
// //     key_scan();
// //     ui_proc();
// // }

/*

//总目录，缩进表示页面层级
enum
{
  M_WINDOW,
  M_SLEEP,
    M_MAIN,
      M_EDITOR,
        M_KNOB,
          M_KRF,
          M_KPF,
      M_VOLT,
      M_SETTING,
        M_ABOUT,
};

*/

// 总目录，缩进表示页面层级
enum
{
    M_WINDOW,
    M_SLEEP,
    M_MAIN,
    M_EDITOR,
    M_KNOB,
    M_KRF,
    M_KPF,
    M_VOLT,
    M_SETTING,
    M_ABOUT,
};

// 状态，初始化标签
enum
{
    S_FADE,      // 转场动画
    S_WINDOW,    // 弹窗初始化
    S_LAYER_IN,  // 层级初始化
    S_LAYER_OUT, // 层级初始化
    S_NONE,      // 直接选择页面
};

// 菜单结构体
typedef struct MENU
{
    char *m_select;
} M_SELECT;

M_SELECT main_menu[]{
    {"Sleep"},
    {"Editor"},
    {"Volt"},
    {"Setting"},
};

M_SELECT editor_menu[]{
    {"[ Editor ]"},
    {"- Function 0"},
    {"- Function 1"},
    {"- Function 2"},
    {"- Function 3"},
    {"- Function 4"},
    {"- Function 5"},
    {"- Function 6"},
    {"- Function 7"},
    {"- Function 8"},
    {"- Function 9"},
    {"- Knob"},
};

M_SELECT knob_menu[]{
    {"[ Knob ]"},
    {"# Rotate Func"},
    {"$ Press Func"},
};

M_SELECT krf_menu[]{
    {"[ Rotate Function ]"},
    {"--------------------------"},
    {"= Disable"},
    {"--------------------------"},
    {"= Volume"},
    {"= Brightness"},
    {"--------------------------"},
};

M_SELECT kpf_menu[]{
    {"[ Press Function ]"},
    {"--------------------------"},
    {"= Disable"},
    {"--------------------------"},
    {"= A"},
    {"= B"},
    {"= C"},
    {"= D"},
    {"= E"},
    {"= F"},
    {"= G"},
    {"= H"},
    {"= I"},
    {"= J"},
    {"= K"},
    {"= L"},
    {"= M"},
    {"= N"},
    {"= O"},
    {"= P"},
    {"= Q"},
    {"= R"},
    {"= S"},
    {"= T"},
    {"= U"},
    {"= V"},
    {"= W"},
    {"= X"},
    {"= Y"},
    {"= Z"},
    {"--------------------------"},
    {"= 0"},
    {"= 1"},
    {"= 2"},
    {"= 3"},
    {"= 4"},
    {"= 5"},
    {"= 6"},
    {"= 7"},
    {"= 8"},
    {"= 9"},
    {"--------------------------"},
    {"= Esc"},
    {"= F1"},
    {"= F2"},
    {"= F3"},
    {"= F4"},
    {"= F5"},
    {"= F6"},
    {"= F7"},
    {"= F8"},
    {"= F9"},
    {"= F10"},
    {"= F11"},
    {"= F12"},
    {"--------------------------"},
    {"= Left Ctrl"},
    {"= Left Shift"},
    {"= Left Alt"},
    {"= Left Win"},
    {"= Right Ctrl"},
    {"= Right Shift"},
    {"= Right Alt"},
    {"= Right Win"},
    {"--------------------------"},
    {"= Caps Lock"},
    {"= Backspace"},
    {"= Return"},
    {"= Insert"},
    {"= Delete"},
    {"= Tab"},
    {"--------------------------"},
    {"= Home"},
    {"= End"},
    {"= Page Up"},
    {"= Page Down"},
    {"--------------------------"},
    {"= Up Arrow"},
    {"= Down Arrow"},
    {"= Left Arrow"},
    {"= Right Arrow"},
    {"--------------------------"},
};

M_SELECT volt_menu[]{
    {"A0"},
    {"A1"},
    {"A2"},
    {"A3"},
    {"A4"},
    {"A5"},
    {"A6"},
    {"A7"},
    {"B0"},
    {"B1"},
};

M_SELECT setting_menu[]{
    {"[ Setting ]"},
    {"~ Disp Bri"},
    {"~ Tile Ani"},
    {"~ List Ani"},
    {"~ Win Ani"},
    {"~ Spot Ani"},
    {"~ Tag Ani"},
    {"~ Fade Ani"},
    {"~ Btn SPT"},
    {"~ Btn LPT"},
    {"+ T Ufd Fm Scr"},
    {"+ L Ufd Fm Scr"},
    {"+ T Loop Mode"},
    {"+ L Loop Mode"},
    {"+ Win Bokeh Bg"},
    {"+ Knob Rot Dir"},
    {"+ Dark Mode"},
    {"- [ About ]"},
};

M_SELECT about_menu[]{
    {"[ WouoUI ]"},
    {"- Version: v2.3"},
    {"- Board: STM32F103"},
    {"- Ram: 20k"},
    {"- Flash: 64k"},
    {"- Freq: 72Mhz"},
    {"- Creator: RQNG"},
    {"- Bili UID: 9182439"},
};

/************************************* 图片内容 *************************************/

PROGMEM const uint8_t main_icon_pic[][120]{

   {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF9,0xFF,0xFF,0xFB,0xFC,0xFF,0xFF,0xF3,0x3C,0xFF,0xFF,0x07,0x98,0xFF,0xFF,0xC7,0xC3,0xFF,0x9F,0xF3,
0xCF,0xFF,0x3F,0xF9,0xDF,0xFF,0x7F,0xCC,0xDF,0xFE,0xFF,0x9E,0x11,0xFE,0xFF,0xBE,0x9C,0xFF,0x0F,0xBE,0xDE,0xFF,0xEF,0xBE,0xCE,0xFF,0xFF,0xBE,0xCE,0xFF,
0xFF,0xBC,0x0E,0xFC,0x7F,0xF9,0x63,0xFF,0x1F,0xE3,0xE3,0xFF,0xFF,0x01,0xE8,0xFF,0xFF,0xCC,0xCD,0xFF,0xFF,0x8E,0xFD,0xFF,0x7F,0x1E,0xFC,0xFF,0xFF,0xDF,
0xFD,0xFF,0xFF,0x9F,0xFD,0xFF,0xFF,0x1F,0xFC,0xFF,0xFF,0x3F,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},




// {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x0F,0x00,0x00,0x9E,0x79,0x00,0x80,0x03,0xC0,0x00,0xC0,0x00,
// 0x80,0x01,0x60,0x00,0x00,0x03,0x30,0x00,0x00,0x02,0x18,0x0F,0x0C,0x02,0x88,0x19,0x3E,0x04,0x88,0x10,0x22,0x04,0x88,0x10,0x22,0x04,0x88,0x1B,0x36,0x04,
// 0x08,0x0E,0x1C,0x04,0x08,0x00,0x00,0x04,0x08,0x00,0x00,0x04,0x18,0x00,0x04,0x06,0x10,0x00,0x04,0x02,0x10,0x08,0x04,0x02,0x10,0x18,0x06,0x02,0x30,0x70,
// 0x03,0x03,0x20,0xC0,0x81,0x01,0xE0,0x00,0xC0,0x00,0x80,0x03,0x60,0x00,0x00,0x7E,0x38,0x00,0x00,0xC0,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},



    // {0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xF1, 0x3F,
    //  0xFF, 0xFF, 0xC3, 0x3F, 0xFF, 0xFF, 0x87, 0x3F, 0xFF, 0xFF, 0x07, 0x3F, 0xFF, 0xFF, 0x0F, 0x3E,
    //  0xFF, 0xFF, 0x0F, 0x3E, 0xFF, 0xFF, 0x0F, 0x3C, 0xFF, 0xFF, 0x0F, 0x3C, 0xFF, 0xFF, 0x0F, 0x38,
    //  0xFF, 0xFF, 0x0F, 0x38, 0xFF, 0xFF, 0x0F, 0x38, 0xFF, 0xFF, 0x07, 0x38, 0xFF, 0xFF, 0x07, 0x38,
    //  0xFF, 0xFF, 0x03, 0x38, 0xF7, 0xFF, 0x01, 0x38, 0xE7, 0xFF, 0x00, 0x3C, 0x87, 0x3F, 0x00, 0x3C,
    //  0x0F, 0x00, 0x00, 0x3E, 0x0F, 0x00, 0x00, 0x3E, 0x1F, 0x00, 0x00, 0x3F, 0x3F, 0x00, 0x80, 0x3F,
    //  0x7F, 0x00, 0xC0, 0x3F, 0xFF, 0x01, 0xF0, 0x3F, 0xFF, 0x07, 0xFC, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F,
    //  0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F},
    {0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xF9, 0xE7, 0x3F,
     0xFF, 0xF9, 0xE7, 0x3F, 0xFF, 0xF9, 0xE7, 0x3F, 0xFF, 0xF0, 0xE7, 0x3F, 0x7F, 0xE0, 0xE7, 0x3F,
     0x7F, 0xE0, 0xC3, 0x3F, 0x7F, 0xE0, 0xC3, 0x3F, 0x7F, 0xE0, 0xC3, 0x3F, 0x7F, 0xE0, 0xE7, 0x3F,
     0xFF, 0xF0, 0xE7, 0x3F, 0xFF, 0xF9, 0xE7, 0x3F, 0xFF, 0xF9, 0xE7, 0x3F, 0xFF, 0xF9, 0xE7, 0x3F,
     0xFF, 0xF9, 0xE7, 0x3F, 0xFF, 0xF9, 0xC3, 0x3F, 0xFF, 0xF9, 0x81, 0x3F, 0xFF, 0xF0, 0x81, 0x3F,
     0xFF, 0xF0, 0x81, 0x3F, 0xFF, 0xF0, 0x81, 0x3F, 0xFF, 0xF9, 0x81, 0x3F, 0xFF, 0xF9, 0xC3, 0x3F,
     0xFF, 0xF9, 0xE7, 0x3F, 0xFF, 0xF9, 0xE7, 0x3F, 0xFF, 0xF9, 0xE7, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F,
     0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F},
    {
        0xFF,
        0xFF,
        0xFF,
        0x3F,
        0xFF,
        0xFF,
        0xFF,
        0x3F,
        0xEF,
        0xFF,
        0xFF,
        0x3F,
        0xC7,
        0xFF,
        0xFF,
        0x3F,
        0xC7,
        0xF3,
        0xFF,
        0x3F,
        0x83,
        0xC0,
        0xFF,
        0x3F,
        0xEF,
        0xCC,
        0xFF,
        0x3F,
        0x6F,
        0x9E,
        0xFF,
        0x3F,
        0x6F,
        0x9E,
        0xFF,
        0x3F,
        0x2F,
        0x3F,
        0xFF,
        0x3F,
        0x2F,
        0x3F,
        0xFF,
        0x3F,
        0x8F,
        0x7F,
        0xFE,
        0x3F,
        0x8F,
        0x7F,
        0xFE,
        0x39,
        0x8F,
        0x7F,
        0xFE,
        0x39,
        0xCF,
        0xFF,
        0xFC,
        0x3C,
        0xCF,
        0xFF,
        0xFC,
        0x3C,
        0xEF,
        0xFF,
        0xFC,
        0x3C,
        0xEF,
        0xFF,
        0x79,
        0x3E,
        0xEF,
        0xFF,
        0x79,
        0x3E,
        0xEF,
        0xFF,
        0x33,
        0x3F,
        0xEF,
        0xFF,
        0x33,
        0x3F,
        0xEF,
        0xFF,
        0x87,
        0x3F,
        0xEF,
        0xFF,
        0xCF,
        0x3F,
        0xEF,
        0xFF,
        0x7F,
        0x3E,
        0xEF,
        0xFF,
        0x7F,
        0x38,
        0x0F,
        0x00,
        0x00,
        0x30,
        0xFF,
        0xFF,
        0x7F,
        0x38,
        0xFF,
        0xFF,
        0x7F,
        0x3E,
        0xFF,
        0xFF,
        0xFF,
        0x3F,
        0xFF,
        0xFF,
        0xFF,
        0x3F,
    },
    {0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F,
     0xFF, 0x1F, 0xFE, 0x3F, 0xFF, 0x1F, 0xFE, 0x3F, 0xFF, 0x0C, 0xCC, 0x3F, 0x7F, 0x00, 0x80, 0x3F,
     0x3F, 0x00, 0x00, 0x3F, 0x3F, 0xE0, 0x01, 0x3F, 0x7F, 0xF8, 0x87, 0x3F, 0x7F, 0xFC, 0x8F, 0x3F,
     0x3F, 0xFC, 0x0F, 0x3F, 0x0F, 0x3E, 0x1F, 0x3C, 0x0F, 0x1E, 0x1E, 0x3C, 0x0F, 0x1E, 0x1E, 0x3C,
     0x0F, 0x3E, 0x1F, 0x3C, 0x3F, 0xFC, 0x0F, 0x3F, 0x7F, 0xFC, 0x8F, 0x3F, 0x7F, 0xF8, 0x87, 0x3F,
     0x3F, 0xE0, 0x01, 0x3F, 0x3F, 0x00, 0x00, 0x3F, 0x7F, 0x00, 0x80, 0x3F, 0xFF, 0x0C, 0xCC, 0x3F,
     0xFF, 0x1F, 0xFE, 0x3F, 0xFF, 0x1F, 0xFE, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F,
     0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F},
};

/************************************* 页面变量 *************************************/

// OLED变量
#define DISP_H 64  // 屏幕高度
#define DISP_W 128 // 屏幕宽度
uint8_t *buf_ptr;  // 指向屏幕缓冲的指针
uint16_t buf_len;  // 缓冲长度

// UI变量
#define UI_DEPTH 20  // 最深层级数
#define UI_MNUMB 100 // 菜单数量
#define UI_PARAM 16  // 参数数量
enum
{
    DISP_BRI,  // 屏幕亮度
    TILE_ANI,  // 磁贴动画速度
    LIST_ANI,  // 列表动画速度
    WIN_ANI,   // 弹窗动画速度
    SPOT_ANI,  // 聚光动画速度
    TAG_ANI,   // 标签动画速度
    FADE_ANI,  // 消失动画速度
    BTN_SPT,   // 按键短按时长
    BTN_LPT,   // 按键长按时长
    TILE_UFD,  // 磁贴图标从头展开开关
    LIST_UFD,  // 菜单列表从头展开开关
    TILE_LOOP, // 磁贴图标循环模式开关
    LIST_LOOP, // 菜单列表循环模式开关
    WIN_BOK,   // 弹窗背景虚化开关
    KNOB_DIR,  // 旋钮方向切换开关
    DARK_MODE, // 黑暗模式开关
};
struct
{
    bool init;
    uint8_t num[UI_MNUMB];
    uint8_t select[UI_DEPTH];
    uint8_t layer;
    uint8_t index = M_MAIN;
    uint8_t state = S_NONE;
    bool sleep = true;
    uint8_t fade = 1;
    uint8_t param[UI_PARAM];
} ui;

// 磁贴变量
// 所有磁贴页面都使用同一套参数
#define TILE_B_FONT u8g2_font_helvB18_tr // 磁贴大标题字体
#define TILE_B_TITLE_H 18                // 磁贴大标题字体高度
#define TILE_ICON_H 30                   // 磁贴图标高度
#define TILE_ICON_W 30                   // 磁贴图标宽度
#define TILE_ICON_S 36                   // 磁贴图标间距
#define TILE_INDI_H 27                   // 磁贴大标题指示器高度
#define TILE_INDI_W 7                    // 磁贴大标题指示器宽度
#define TILE_INDI_S 36                   // 磁贴大标题指示器上边距
struct
{
    float title_y_calc = TILE_INDI_S + (TILE_INDI_H - TILE_B_TITLE_H) / 2 + TILE_B_TITLE_H * 2;
    float title_y_trg_calc = TILE_INDI_S + (TILE_INDI_H - TILE_B_TITLE_H) / 2 + TILE_B_TITLE_H;
    int16_t temp;
    bool select_flag;
    float icon_x;
    float icon_x_trg;
    float icon_y;
    float icon_y_trg;
    float indi_x;
    float indi_x_trg;
    float title_y;
    float title_y_trg;
} tile;

// 列表变量
// 默认参数

#define LIST_FONT u8g2_font_HelvetiPixel_tr // 列表字体
#define LIST_TEXT_H 8                       // 列表每行文字字体的高度
#define LIST_LINE_H 16                      // 列表单行高度
#define LIST_TEXT_S 4                       // 列表每行文字的上边距，左边距和右边距，下边距由它和字体高度和行高度决定
#define LIST_BAR_W 5                        // 列表进度条宽度，需要是奇数，因为正中间有1像素宽度的线
#define LIST_BOX_R 0.5f                     // 列表选择框圆角

/*
//超窄行高度测试
#define   LIST_FONT           u8g2_font_4x6_tr            //列表字体
#define   LIST_TEXT_H         5                           //列表每行文字字体的高度
#define   LIST_LINE_H         7                           //列表单行高度
#define   LIST_TEXT_S         1                           //列表每行文字的上边距，左边距和右边距，下边距由它和字体高度和行高度决定
#define   LIST_BAR_W          7                           //列表进度条宽度，需要是奇数，因为正中间有1像素宽度的线
#define   LIST_BOX_R          0.5f                        //列表选择框圆角
*/
struct
{
    uint8_t line_n = DISP_H / LIST_LINE_H;
    int16_t temp;
    bool loop;
    float y;
    float y_trg;
    float box_x;
    float box_x_trg;
    float box_y;
    float box_y_trg[UI_DEPTH];
    float bar_y;
    float bar_y_trg;
} list;

// 电压测量页面变量
// 开发板模拟引脚
uint8_t analog_pin[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
// 曲线相关
#define WAVE_SAMPLE 20  // 采集倍数
#define WAVE_W 94       // 波形宽度
#define WAVE_L 24       // 波形左边距
#define WAVE_U 0        // 波形上边距
#define WAVE_MAX 27     // 最大值
#define WAVE_MIN 4      // 最小值
#define WAVE_BOX_H 32   // 波形边框高度
#define WAVE_BOX_W 94   // 波形边框宽度
#define WAVE_BOX_L_S 24 // 波形边框左边距
// 列表和文字背景框相关
#define VOLT_FONT u8g2_font_helvB18_tr // 电压数字字体
#define VOLT_TEXT_BG_L_S 24            // 文字背景框左边距
#define VOLT_TEXT_BG_W 94              // 文字背景框宽度
#define VOLT_TEXT_BG_H 29              // 文字背景框高度
struct
{
    int ch0_adc[WAVE_SAMPLE * WAVE_W];
    int ch0_wave[WAVE_W];
    int val;
    float text_bg_r;
    float text_bg_r_trg;
} volt;

// 选择框变量

// 默认参数
#define CHECK_BOX_L_S 95 // 选择框在每行的左边距
#define CHECK_BOX_U_S 2  // 选择框在每行的上边距
#define CHECK_BOX_F_W 12 // 选择框外框宽度
#define CHECK_BOX_F_H 12 // 选择框外框高度
#define CHECK_BOX_D_S 2  // 选择框里面的点距离外框的边距

/*
//超窄行高度测试
#define   CHECK_BOX_L_S       99                          //选择框在每行的左边距
#define   CHECK_BOX_U_S       0                           //选择框在每行的上边距
#define   CHECK_BOX_F_W       5                           //选择框外框宽度
#define   CHECK_BOX_F_H       5                           //选择框外框高度
#define   CHECK_BOX_D_S       1                           //选择框里面的点距离外框的边距
*/
struct
{
    uint8_t *v;
    uint8_t *m;
    uint8_t *s;
    uint8_t *s_p;
} check_box;

// 弹窗变量
#define WIN_FONT u8g2_font_HelvetiPixel_tr // 弹窗字体
#define WIN_H 32                           // 弹窗高度
#define WIN_W 102                          // 弹窗宽度
#define WIN_BAR_W 92                       // 弹窗进度条宽度
#define WIN_BAR_H 7                        // 弹窗进度条高度
#define WIN_Y -WIN_H - 2                   // 弹窗竖直方向出场起始位置
#define WIN_Y_TRG -WIN_H - 2               // 弹窗竖直方向退场终止位置
struct
{
    // uint8_t
    uint8_t *value;
    uint8_t max;
    uint8_t min;
    uint8_t step;

    MENU *bg;
    uint8_t index;
    char title[20];
    uint8_t select;
    uint8_t l = (DISP_W - WIN_W) / 2;
    uint8_t u = (DISP_H - WIN_H) / 2;
    float bar;
    float bar_trg;
    float y;
    float y_trg;
} win;

// 聚光灯变量
struct
{
    float l;
    float l_trg;
    float r;
    float r_trg;
    float u;
    float u_trg;
    float d;
    float d_trg;
} spot;

/********************************** 自定义功能变量 **********************************/

// 旋钮功能变量
#define KNOB_PARAM 4
#define KNOB_DISABLE 0
#define KNOB_ROT_VOL 1
#define KNOB_ROT_BRI 2
enum
{
    KNOB_ROT,   // 睡眠下旋转旋钮的功能，0 禁用，1 音量，2 亮度
    KNOB_COD,   // 睡眠下短按旋钮输入的字符码，0 禁用
    KNOB_ROT_P, // 旋转旋钮功能在单选框中选择的位置
    KNOB_COD_P, // 字符码在单选框中选择的位置
};
struct
{
    uint8_t param[KNOB_PARAM] = {KNOB_DISABLE, KNOB_DISABLE, 2, 2}; // 禁用在列表的第2个选项，第0个是标题，第1个是分界线
} knob;

/************************************* 旋钮相关 *************************************/

// 可按下旋钮引脚
#define AIO 23
#define BIO 24
#define SW 25

// 按键ID
#define BTN_ID_CC 0 // 逆时针旋转
#define BTN_ID_CW 1 // 顺时针旋转
#define BTN_ID_SP 2 // 短按
#define BTN_ID_LP 3 // 长按

// 按键变量
#define BTN_PARAM_TIMES 2 // 由于uint8_t最大值可能不够，但它存储起来方便，这里放大两倍使用
struct
{
    uint8_t id;
    bool flag;
    bool pressed;
    bool CW_1;
    bool CW_2;
    bool val;
    bool val_last;
    bool alv;
    bool blv;
    long count;
} volatile btn;

void knob_inter()
{
    btn.alv = digitalRead(AIO);
    btn.blv = digitalRead(BIO);
    if (!btn.flag && btn.alv == LOW)
    {
        btn.CW_1 = btn.blv;
        btn.flag = true;
    }
    if (btn.flag && btn.alv)
    {
        btn.CW_2 = !btn.blv;
        if (btn.CW_1 && btn.CW_2)
        {
            btn.id = ui.param[KNOB_DIR];
            btn.pressed = true;
        }
        if (btn.CW_1 == false && btn.CW_2 == false)
        {
            btn.id = !ui.param[KNOB_DIR];
            btn.pressed = true;
        }
        btn.flag = false;
    }
}

void btn_scan()
{
    btn.val = digitalRead(SW);
    if (btn.val != btn.val_last)
    {
        btn.val_last = btn.val;
        delay(ui.param[BTN_SPT] * BTN_PARAM_TIMES);
        btn.val = digitalRead(SW);
        if (btn.val == LOW)
        {
            btn.pressed = true;
            btn.count = 0;
            while (!digitalRead(SW))
            {
                btn.count++;
                delay(1);
            }
            if (btn.count < ui.param[BTN_LPT] * BTN_PARAM_TIMES)
                btn.id = BTN_ID_SP;
            else
                btn.id = BTN_ID_LP;
        }
    }
}

void btn_init()
{
    pinMode(AIO, INPUT);
    pinMode(BIO, INPUT);
    pinMode(SW, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(AIO), knob_inter, CHANGE);
}

/************************************ 初始化函数 ***********************************/

/********************************* 初始化数据处理函数 *******************************/

// 显示数值的初始化
void check_box_v_init(uint8_t *param)
{
    check_box.v = param;
}

// 多选框的初始化
void check_box_m_init(uint8_t *param)
{
    check_box.m = param;
}

// 单选框时的初始化
void check_box_s_init(uint8_t *param, uint8_t *param_p)
{
    check_box.s = param;
    check_box.s_p = param_p;
}

// 多选框处理函数
void check_box_m_select(uint8_t param)
{
    check_box.m[param] = !check_box.m[param];
}

// 单选框处理函数
void check_box_s_select(uint8_t val, uint8_t pos)
{
    *check_box.s = val;
    *check_box.s_p = pos;
}

// 弹窗数值初始化
void window_value_init(char title[], uint8_t select, uint8_t *value, uint8_t max, uint8_t min, uint8_t step, MENU *bg, uint8_t index)
{
    strcpy(win.title, title);
    win.select = select;
    win.value = value;
    win.max = max;
    win.min = min;
    win.step = step;
    win.bg = bg;
    win.index = index;
    ui.index = M_WINDOW;
    ui.state = S_WINDOW;
}

/*********************************** UI 初始化函数 *********************************/

// 在初始化EEPROM时，选择性初始化的默认设置
void ui_param_init()
{
    ui.param[DISP_BRI] = 255; // 屏幕亮度
    ui.param[TILE_ANI] = 30;  // 磁贴动画速度
    ui.param[LIST_ANI] = 60;  // 列表动画速度
    ui.param[WIN_ANI] = 25;   // 弹窗动画速度
    ui.param[SPOT_ANI] = 50;  // 聚光动画速度
    ui.param[TAG_ANI] = 60;   // 标签动画速度
    ui.param[FADE_ANI] = 30;  // 消失动画速度
    ui.param[BTN_SPT] = 25;   // 按键短按时长
    ui.param[BTN_LPT] = 150;  // 按键长按时长
    ui.param[TILE_UFD] = 1;   // 磁贴图标从头展开开关
    ui.param[LIST_UFD] = 1;   // 菜单列表从头展开开关
    ui.param[TILE_LOOP] = 0;  // 磁贴图标循环模式开关
    ui.param[LIST_LOOP] = 0;  // 菜单列表循环模式开关
    ui.param[WIN_BOK] = 0;    // 弹窗背景虚化开关
    ui.param[KNOB_DIR] = 0;   // 旋钮方向切换开关
    ui.param[DARK_MODE] = 1;  // 黑暗模式开关
}

// 列表类页面列表行数初始化，必须初始化的参数
void ui_init()
{
    ui.num[M_MAIN] = sizeof(main_menu) / sizeof(M_SELECT);
    ui.num[M_EDITOR] = sizeof(editor_menu) / sizeof(M_SELECT);
    ui.num[M_KNOB] = sizeof(knob_menu) / sizeof(M_SELECT);
    ui.num[M_KRF] = sizeof(krf_menu) / sizeof(M_SELECT);
    ui.num[M_KPF] = sizeof(kpf_menu) / sizeof(M_SELECT);
    ui.num[M_VOLT] = sizeof(volt_menu) / sizeof(M_SELECT);
    ui.num[M_SETTING] = sizeof(setting_menu) / sizeof(M_SELECT);
    ui.num[M_ABOUT] = sizeof(about_menu) / sizeof(M_SELECT);
}

/********************************* 分页面初始化函数 ********************************/

// 进入磁贴类时的初始化
void tile_param_init()
{
    ui.init = false;
    tile.icon_x = 0;
    tile.icon_x_trg = TILE_ICON_S;
    tile.icon_y = -TILE_ICON_H;
    tile.icon_y_trg = 0;
    tile.indi_x = 0;
    tile.indi_x_trg = TILE_INDI_W;
    tile.title_y = tile.title_y_calc;
    tile.title_y_trg = tile.title_y_trg_calc;
}

// 进入睡眠时的初始化
void sleep_param_init()
{
    u8g2.setDrawColor(0);
    u8g2.drawBox(0, 0, DISP_W, DISP_H);
    u8g2.setPowerSave(1);
    ui.state = S_NONE;
    ui.sleep = true;
}

// 旋钮设置页初始化
void knob_param_init() { check_box_v_init(knob.param); }

// 旋钮旋转页初始化
void krf_param_init() { check_box_s_init(&knob.param[KNOB_ROT], &knob.param[KNOB_ROT_P]); }

// 旋钮点按页初始化
void kpf_param_init() { check_box_s_init(&knob.param[KNOB_COD], &knob.param[KNOB_COD_P]); }

// 电压测量页初始化
void volt_param_init()
{
    volt.text_bg_r = 0;
    volt.text_bg_r_trg = VOLT_TEXT_BG_W;
}

// 设置页初始化
void setting_param_init()
{
    check_box_v_init(ui.param);
    check_box_m_init(ui.param);
}

/********************************** 通用初始化函数 *********************************/

/*
  页面层级管理逻辑是，把所有页面都先当作列表类初始化，不是列表类按需求再初始化对应函数
  这样做会浪费一些资源，但跳转页面时只需要考虑页面层级，逻辑上更清晰，减少出错
*/

// 弹窗动画初始化
void window_param_init()
{
    win.bar = 0;
    win.y = WIN_Y;
    win.y_trg = win.u;
    ui.state = S_NONE;
}

// 进入更深层级时的初始化
void layer_init_in()
{
    ui.layer++;
    ui.init = 0;
    list.y = 0;
    list.y_trg = LIST_LINE_H;
    list.box_x = 0;
    list.box_y = 0;
    list.bar_y = 0;
    ui.state = S_FADE;
    switch (ui.index)
    {
    case M_MAIN:
        tile_param_init();
        break; // 睡眠进入主菜单，动画初始化
    case M_KNOB:
        knob_param_init();
        break; // 旋钮设置页，行末尾文字初始化
    case M_KRF:
        krf_param_init();
        break; // 旋钮旋转页，单选框初始化
    case M_KPF:
        kpf_param_init();
        break; // 旋钮点按页，单选框初始化
    case M_VOLT:
        volt_param_init();
        break; // 主菜单进入电压测量页，动画初始化
    case M_SETTING:
        setting_param_init();
        break; // 主菜单进入设置页，单选框初始化
    }
}

// 进入更浅层级时的初始化
void layer_init_out()
{
    ui.select[ui.layer] = 0;
    list.box_y_trg[ui.layer] = 0;
    ui.layer--;
    ui.init = 0;
    list.y = 0;
    list.y_trg = LIST_LINE_H;
    list.bar_y = 0;
    ui.state = S_FADE;
    switch (ui.index)
    {
    case M_SLEEP:
        sleep_param_init();
        break; // 主菜单进入睡眠页，检查是否需要写EEPROM
    case M_MAIN:
        tile_param_init();
        break; // 不管什么页面进入主菜单时，动画初始化
    }
}

/************************************* 动画函数 *************************************/

// 动画函数
void animation(float *a, float *a_trg, uint8_t n)
{
    if (*a != *a_trg)
    {
        if (fabs(*a - *a_trg) < 0.15f)
            *a = *a_trg;
        else
            *a += (*a_trg - *a) / (ui.param[n] / 10.0f);
    }
}

// 消失函数
void fade()
{
    delay(ui.param[FADE_ANI]);
    if (ui.param[DARK_MODE])
    {
        switch (ui.fade)
        {
        case 1:
            for (uint16_t i = 0; i < buf_len; ++i)
                if (i % 2 != 0)
                    buf_ptr[i] = buf_ptr[i] & 0xAA;
            break;
        case 2:
            for (uint16_t i = 0; i < buf_len; ++i)
                if (i % 2 != 0)
                    buf_ptr[i] = buf_ptr[i] & 0x00;
            break;
        case 3:
            for (uint16_t i = 0; i < buf_len; ++i)
                if (i % 2 == 0)
                    buf_ptr[i] = buf_ptr[i] & 0x55;
            break;
        case 4:
            for (uint16_t i = 0; i < buf_len; ++i)
                if (i % 2 == 0)
                    buf_ptr[i] = buf_ptr[i] & 0x00;
            break;
        default:
            ui.state = S_NONE;
            ui.fade = 0;
            break;
        }
    }
    else
    {
        switch (ui.fade)
        {
        case 1:
            for (uint16_t i = 0; i < buf_len; ++i)
                if (i % 2 != 0)
                    buf_ptr[i] = buf_ptr[i] | 0xAA;
            break;
        case 2:
            for (uint16_t i = 0; i < buf_len; ++i)
                if (i % 2 != 0)
                    buf_ptr[i] = buf_ptr[i] | 0x00;
            break;
        case 3:
            for (uint16_t i = 0; i < buf_len; ++i)
                if (i % 2 == 0)
                    buf_ptr[i] = buf_ptr[i] | 0x55;
            break;
        case 4:
            for (uint16_t i = 0; i < buf_len; ++i)
                if (i % 2 == 0)
                    buf_ptr[i] = buf_ptr[i] | 0x00;
            break;
        default:
            ui.state = S_NONE;
            ui.fade = 0;
            break;
        }
    }
    ui.fade++;
}

/************************************* 显示函数 *************************************/

// 磁贴类页面通用显示函数
void tile_show(struct MENU arr_1[], const uint8_t icon_pic[][120])
{
    // 计算动画过渡值
    animation(&tile.icon_x, &tile.icon_x_trg, TILE_ANI);
    animation(&tile.icon_y, &tile.icon_y_trg, TILE_ANI);
    animation(&tile.indi_x, &tile.indi_x_trg, TILE_ANI);
    animation(&tile.title_y, &tile.title_y_trg, TILE_ANI);

    // 设置大标题的颜色，0透显，1实显，2反色，这里用实显
    u8g2.setDrawColor(1);

    // 绘制大标题
    u8g2.setFont(TILE_B_FONT);
    u8g2.drawStr(((DISP_W - TILE_INDI_W) - u8g2.getStrWidth(arr_1[ui.select[ui.layer]].m_select)) / 2 + TILE_INDI_W, tile.title_y, arr_1[ui.select[ui.layer]].m_select);

    // 绘制大标题指示器
    u8g2.drawBox(0, TILE_ICON_S, tile.indi_x, TILE_INDI_H);

    // 绘制图标
    if (!ui.init)
    {
        for (uint8_t i = 0; i < ui.num[ui.index]; ++i)
        {
            if (ui.param[TILE_UFD])
                tile.temp = (DISP_W - TILE_ICON_W) / 2 + i * tile.icon_x - TILE_ICON_S * ui.select[ui.layer];
            else
                tile.temp = (DISP_W - TILE_ICON_W) / 2 + (i - ui.select[ui.layer]) * tile.icon_x;
            u8g2.drawXBMP(tile.temp, (int16_t)tile.icon_y, TILE_ICON_W, TILE_ICON_H, icon_pic[i]);
        }
        if (tile.icon_x == tile.icon_x_trg)
        {
            ui.init = true;
            tile.icon_x = tile.icon_x_trg = -ui.select[ui.layer] * TILE_ICON_S;
        }
    }
    else
        for (uint8_t i = 0; i < ui.num[ui.index]; ++i)
            u8g2.drawXBMP((DISP_W - TILE_ICON_W) / 2 + (int16_t)tile.icon_x + i * TILE_ICON_S, 0, TILE_ICON_W, TILE_ICON_H, icon_pic[i]);

    // 反转屏幕内元素颜色，白天模式遮罩
    u8g2.setDrawColor(2);
    if (!ui.param[DARK_MODE])
        u8g2.drawBox(0, 0, DISP_W, DISP_H);
}

/*************** 根据列表每行开头符号，判断每行尾部是否绘制以及绘制什么内容 *************/

// 列表显示数值
void list_draw_value(int n) { u8g2.print(check_box.v[n - 1]); }

// 绘制外框
void list_draw_check_box_frame() { u8g2.drawRFrame(CHECK_BOX_L_S, list.temp + CHECK_BOX_U_S, CHECK_BOX_F_W, CHECK_BOX_F_H, 1); }

// 绘制框里面的点
void list_draw_check_box_dot() { u8g2.drawBox(CHECK_BOX_L_S + CHECK_BOX_D_S + 1, list.temp + CHECK_BOX_U_S + CHECK_BOX_D_S + 1, CHECK_BOX_F_W - (CHECK_BOX_D_S + 1) * 2, CHECK_BOX_F_H - (CHECK_BOX_D_S + 1) * 2); }

// 列表显示旋钮功能
void list_draw_krf(int n)
{
    switch (check_box.v[n - 1])
    {
    case 0:
        u8g2.print("OFF");
        break;
    case 1:
        u8g2.print("VOL");
        break;
    case 2:
        u8g2.print("BRI");
        break;
    }
}

// 列表显示按键键值
void list_draw_kpf(int n)
{
    if (check_box.v[n - 1] == 0)
        u8g2.print("OFF");
    else if (check_box.v[n - 1] <= 90)
        u8g2.print((char)check_box.v[n - 1]);
    else
        u8g2.print("?");
}

// 判断列表尾部内容
void list_draw_text_and_check_box(struct MENU arr[], int i)
{
    u8g2.drawStr(LIST_TEXT_S, list.temp + LIST_TEXT_H + LIST_TEXT_S, arr[i].m_select);
    u8g2.setCursor(CHECK_BOX_L_S, list.temp + LIST_TEXT_H + LIST_TEXT_S);
    switch (arr[i].m_select[0])
    {
    case '~':
        list_draw_value(i);
        break;
    case '+':
        list_draw_check_box_frame();
        if (check_box.m[i - 1] == 1)
            list_draw_check_box_dot();
        break;
    case '=':
        list_draw_check_box_frame();
        if (*check_box.s_p == i)
            list_draw_check_box_dot();
        break;
    case '#':
        list_draw_krf(i);
        break;
    case '$':
        list_draw_kpf(i);
        break;
    }
}

/******************************** 列表显示函数 **************************************/

// 列表类页面通用显示函数
void list_show(struct MENU arr[], uint8_t ui_index)
{
    // 更新动画目标值
    u8g2.setFont(LIST_FONT);
    list.box_x_trg = u8g2.getStrWidth(arr[ui.select[ui.layer]].m_select) + LIST_TEXT_S * 2;
    list.bar_y_trg = ceil((ui.select[ui.layer]) * ((float)DISP_H / (ui.num[ui_index] - 1)));

    // 计算动画过渡值
    animation(&list.y, &list.y_trg, LIST_ANI);
    animation(&list.box_x, &list.box_x_trg, LIST_ANI);
    animation(&list.box_y, &list.box_y_trg[ui.layer], LIST_ANI);
    animation(&list.bar_y, &list.bar_y_trg, LIST_ANI);

    // 检查循环动画是否结束
    if (list.loop && list.box_y == list.box_y_trg[ui.layer])
        list.loop = false;

    // 设置文字和进度条颜色，0透显，1实显，2反色，这里都用实显
    u8g2.setDrawColor(1);

    // 绘制进度条
    u8g2.drawHLine(DISP_W - LIST_BAR_W, 0, LIST_BAR_W);
    u8g2.drawHLine(DISP_W - LIST_BAR_W, DISP_H - 1, LIST_BAR_W);
    u8g2.drawVLine(DISP_W - ceil((float)LIST_BAR_W / 2), 0, DISP_H);
    u8g2.drawBox(DISP_W - LIST_BAR_W, 0, LIST_BAR_W, list.bar_y);

    // 绘制列表文字
    if (!ui.init)
    {
        for (int i = 0; i < ui.num[ui_index]; ++i)
        {
            if (ui.param[LIST_UFD])
                list.temp = i * list.y - LIST_LINE_H * ui.select[ui.layer] + list.box_y_trg[ui.layer];
            else
                list.temp = (i - ui.select[ui.layer]) * list.y + list.box_y_trg[ui.layer];
            list_draw_text_and_check_box(arr, i);
        }
        if (list.y == list.y_trg)
        {
            ui.init = true;
            list.y = list.y_trg = -LIST_LINE_H * ui.select[ui.layer] + list.box_y_trg[ui.layer];
        }
    }
    else
        for (int i = 0; i < ui.num[ui_index]; ++i)
        {
            list.temp = LIST_LINE_H * i + list.y;
            list_draw_text_and_check_box(arr, i);
        }

    // 绘制文字选择框，0透显，1实显，2反色，这里用反色
    u8g2.setDrawColor(2);
    u8g2.drawRBox(0, list.box_y, list.box_x, LIST_LINE_H, LIST_BOX_R);

    // 反转屏幕内元素颜色，白天模式遮罩，在这里屏蔽有列表参与的页面，使遮罩作用在那个页面上
    if (!ui.param[DARK_MODE])
    {
        u8g2.drawBox(0, 0, DISP_W, DISP_H);
        switch (ui.index)
        {
        case M_WINDOW:
        case M_VOLT:
            u8g2.drawBox(0, 0, DISP_W, DISP_H);
        }
    }
}

// 电压页面显示函数
void volt_show()
{
    // 使用列表类显示选项
    list_show(volt_menu, M_VOLT);

    // 计算动画过渡值
    animation(&volt.text_bg_r, &volt.text_bg_r_trg, TAG_ANI);

    // 设置曲线颜色，0透显，1实显，2反色，这里用实显
    u8g2.setDrawColor(1);

    // 绘制电压曲线和外框
    volt.val = 0;
    u8g2.drawFrame(WAVE_BOX_L_S, 0, WAVE_BOX_W, WAVE_BOX_H);
    u8g2.drawFrame(WAVE_BOX_L_S + 1, 1, WAVE_BOX_W - 2, WAVE_BOX_H - 2);
    if (list.box_y == list.box_y_trg[ui.layer] && list.y == list.y_trg)
    {
        for (int i = 0; i < WAVE_SAMPLE * WAVE_W; i++)
            volt.ch0_adc[i] = volt.val = analogRead(analog_pin[ui.select[ui.layer]]);
        for (int i = 1; i < WAVE_W - 1; i++)
        {
            volt.ch0_wave[i] = map(volt.ch0_adc[int(5 * i)], 0, 4095, WAVE_MAX, WAVE_MIN);
            u8g2.drawLine(WAVE_L + i - 1, WAVE_U + volt.ch0_wave[i - 1], WAVE_L + i, WAVE_U + volt.ch0_wave[i]);
        }
    }

    // 绘制电压值
    u8g2.setFontDirection(0);
    u8g2.setFont(VOLT_FONT);
    u8g2.setCursor(39, DISP_H - 6);
    u8g2.print(volt.val / 4096.0f * 3.3f);
    u8g2.print("V");

    // 绘制列表选择框和电压文字背景
    u8g2.setDrawColor(2);
    u8g2.drawBox(VOLT_TEXT_BG_L_S, DISP_H - VOLT_TEXT_BG_H, volt.text_bg_r, VOLT_TEXT_BG_H);

    // 反转屏幕内元素颜色，白天模式遮罩
    if (!ui.param[DARK_MODE])
        u8g2.drawBox(0, 0, DISP_W, DISP_H);
}

// 弹窗通用显示函数
void window_show()
{
    // 绘制背景列表，根据开关判断背景是否要虚化
    list_show(win.bg, win.index);
    if (ui.param[WIN_BOK])
        for (uint16_t i = 0; i < buf_len; ++i)
            buf_ptr[i] = buf_ptr[i] & (i % 2 == 0 ? 0x55 : 0xAA);

    // 更新动画目标值
    u8g2.setFont(WIN_FONT);
    win.bar_trg = (float)(*win.value - win.min) / (float)(win.max - win.min) * (WIN_BAR_W - 4);

    // 计算动画过渡值
    animation(&win.bar, &win.bar_trg, WIN_ANI);
    animation(&win.y, &win.y_trg, WIN_ANI);

    // 绘制窗口
    u8g2.setDrawColor(0);
    u8g2.drawRBox(win.l, (int16_t)win.y, WIN_W, WIN_H, 2); // 绘制外框背景
    u8g2.setDrawColor(1);
    u8g2.drawRFrame(win.l, (int16_t)win.y, WIN_W, WIN_H, 2);                  // 绘制外框描边
    u8g2.drawRFrame(win.l + 5, (int16_t)win.y + 20, WIN_BAR_W, WIN_BAR_H, 1); // 绘制进度条外框
    u8g2.drawBox(win.l + 7, (int16_t)win.y + 22, win.bar, WIN_BAR_H - 4);     // 绘制进度条
    u8g2.setCursor(win.l + 5, (int16_t)win.y + 14);
    u8g2.print(win.title); // 绘制标题
    u8g2.setCursor(win.l + 78, (int16_t)win.y + 14);
    u8g2.print(*win.value); // 绘制当前值

    // 需要在窗口修改参数时立即见效的函数
    if (!strcmp(win.title, "Disp Bri"))
        u8g2.setContrast(ui.param[DISP_BRI]);

    // 反转屏幕内元素颜色，白天模式遮罩
    u8g2.setDrawColor(2);
    if (!ui.param[DARK_MODE])
        u8g2.drawBox(0, 0, DISP_W, DISP_H);
}

/************************************* 处理函数 *************************************/

/*********************************** 通用处理函数 ***********************************/

// 磁贴类页面旋转时判断通用函数
void tile_rotate_switch()
{
    switch (btn.id)
    {
    case BTN_ID_CC:
        if (ui.init)
        {
            if (ui.select[ui.layer] > 0)
            {
                ui.select[ui.layer] -= 1;
                tile.icon_x_trg += TILE_ICON_S;
                tile.select_flag = false;
            }
            else
            {
                if (ui.param[TILE_LOOP])
                {
                    ui.select[ui.layer] = ui.num[ui.index] - 1;
                    tile.icon_x_trg = -TILE_ICON_S * (ui.num[ui.index] - 1);
                    break;
                }
                else
                    tile.select_flag = true;
            }
        }
        break;

    case BTN_ID_CW:
        if (ui.init)
        {
            if (ui.select[ui.layer] < (ui.num[ui.index] - 1))
            {
                ui.select[ui.layer] += 1;
                tile.icon_x_trg -= TILE_ICON_S;
                tile.select_flag = false;
            }
            else
            {
                if (ui.param[TILE_LOOP])
                {
                    ui.select[ui.layer] = 0;
                    tile.icon_x_trg = 0;
                    break;
                }
                else
                    tile.select_flag = true;
            }
        }
        break;
    }
}

// 列表类页面旋转时判断通用函数
void list_rotate_switch()
{
    if (!list.loop)
    {
        switch (btn.id)
        {
        case BTN_ID_CC:
            if (ui.select[ui.layer] == 0)
            {
                if (ui.param[LIST_LOOP] && ui.init)
                {
                    list.loop = true;
                    ui.select[ui.layer] = ui.num[ui.index] - 1;
                    if (ui.num[ui.index] > list.line_n)
                    {
                        list.box_y_trg[ui.layer] = DISP_H - LIST_LINE_H;
                        list.y_trg = DISP_H - ui.num[ui.index] * LIST_LINE_H;
                    }
                    else
                        list.box_y_trg[ui.layer] = (ui.num[ui.index] - 1) * LIST_LINE_H;
                    break;
                }
                else
                    break;
            }
            if (ui.init)
            {
                ui.select[ui.layer] -= 1;
                if (ui.select[ui.layer] < -(list.y_trg / LIST_LINE_H))
                {
                    if (!(DISP_H % LIST_LINE_H))
                        list.y_trg += LIST_LINE_H;
                    else
                    {
                        if (list.box_y_trg[ui.layer] == DISP_H - LIST_LINE_H * list.line_n)
                        {
                            list.y_trg += (list.line_n + 1) * LIST_LINE_H - DISP_H;
                            list.box_y_trg[ui.layer] = 0;
                        }
                        else if (list.box_y_trg[ui.layer] == LIST_LINE_H)
                        {
                            list.box_y_trg[ui.layer] = 0;
                        }
                        else
                            list.y_trg += LIST_LINE_H;
                    }
                }
                else
                    list.box_y_trg[ui.layer] -= LIST_LINE_H;
                break;
            }

        case BTN_ID_CW:
            if (ui.select[ui.layer] == (ui.num[ui.index] - 1))
            {
                if (ui.param[LIST_LOOP] && ui.init)
                {
                    list.loop = true;
                    ui.select[ui.layer] = 0;
                    list.y_trg = 0;
                    list.box_y_trg[ui.layer] = 0;
                    break;
                }
                else
                    break;
            }
            if (ui.init)
            {
                ui.select[ui.layer] += 1;
                if ((ui.select[ui.layer] + 1) > (list.line_n - list.y_trg / LIST_LINE_H))
                {
                    if (!(DISP_H % LIST_LINE_H))
                        list.y_trg -= LIST_LINE_H;
                    else
                    {
                        if (list.box_y_trg[ui.layer] == LIST_LINE_H * (list.line_n - 1))
                        {
                            list.y_trg -= (list.line_n + 1) * LIST_LINE_H - DISP_H;
                            list.box_y_trg[ui.layer] = DISP_H - LIST_LINE_H;
                        }
                        else if (list.box_y_trg[ui.layer] == DISP_H - LIST_LINE_H * 2)
                        {
                            list.box_y_trg[ui.layer] = DISP_H - LIST_LINE_H;
                        }
                        else
                            list.y_trg -= LIST_LINE_H;
                    }
                }
                else
                    list.box_y_trg[ui.layer] += LIST_LINE_H;
                break;
            }
            break;
        }
    }
}

// 弹窗通用处理函数
void window_proc()
{
    window_show();
    if (win.y == WIN_Y_TRG)
        ui.index = win.index;
    if (btn.pressed && win.y == win.y_trg && win.y != WIN_Y_TRG)
    {
        btn.pressed = false;
        switch (btn.id)
        {
            //   case BTN_ID_CW: if (*win.value < win.max)  *win.value += win.step;  eeprom.change = true;  break;
            //   case BTN_ID_CC: if (*win.value > win.min)  *win.value -= win.step;  eeprom.change = true;  break;
            //   case BTN_ID_SP: case BTN_ID_LP: win.y_trg = WIN_Y_TRG; break;
        }
    }
}

/********************************** 分页面处理函数 **********************************/

// 睡眠页面处理函数
void sleep_proc()
{
    while (ui.sleep)
    {
        // 睡眠时循环执行的函数

        // 睡眠时需要扫描旋钮才能退出睡眠
        btn_scan();

        // 当旋钮有动作时
        if (btn.pressed)
        {
            btn.pressed = false;
            switch (btn.id)
            {

                // //睡眠时顺时针旋转执行的函数
                // case BTN_ID_CW:
                //   switch (knob.param[KNOB_ROT])
                //   {
                //     case KNOB_ROT_VOL: Consumer.press(HIDConsumer::VOLUME_UP);       Consumer.release(); break;
                //     case KNOB_ROT_BRI: Consumer.press(HIDConsumer::BRIGHTNESS_UP);   Consumer.release(); break;
                //   }
                //   break;

                // //睡眠时逆时针旋转执行的函数
                // case BTN_ID_CC:
                //   switch (knob.param[KNOB_ROT])
                //   {
                //     case KNOB_ROT_VOL: Consumer.press(HIDConsumer::VOLUME_DOWN);     Consumer.release(); break;
                //     case KNOB_ROT_BRI: Consumer.press(HIDConsumer::BRIGHTNESS_DOWN); Consumer.release(); break;
                //   }
                //   break;

                // //睡眠时短按执行的函数
                // case BTN_ID_SP: Keyboard.press(knob.param[KNOB_COD]);  Keyboard.release(knob.param[KNOB_COD]); break;

                // //睡眠时长按执行的函数
                // case BTN_ID_LP: ui.index = M_MAIN;  ui.state = S_LAYER_IN; u8g2.setPowerSave(0); ui.sleep = false; break;
            }
        }
    }
}

// 主菜单处理函数，磁贴类模板
void main_proc()
{
    tile_show(main_menu, main_icon_pic);
    if (btn.pressed)
    {
        btn.pressed = false;
        switch (btn.id)
        {
        case BTN_ID_CW:
        case BTN_ID_CC:
            tile_rotate_switch();
            break;
        case BTN_ID_SP:
            switch (ui.select[ui.layer])
            {

            case 0:
                ui.index = M_SLEEP;
                ui.state = S_LAYER_OUT;
                break;
            case 1:
                ui.index = M_EDITOR;
                ui.state = S_LAYER_IN;
                break;
            case 2:
                ui.index = M_VOLT;
                ui.state = S_LAYER_IN;
                break;
            case 3:
                ui.index = M_SETTING;
                ui.state = S_LAYER_IN;
                break;
            }
        }
        if (!tile.select_flag && ui.init)
        {
            tile.indi_x = 0;
            tile.title_y = tile.title_y_calc;
        }
    }
}

// 编辑器菜单处理函数
void editor_proc()
{
    list_show(editor_menu, M_EDITOR);
    if (btn.pressed)
    {
        btn.pressed = false;
        switch (btn.id)
        {
        case BTN_ID_CW:
        case BTN_ID_CC:
            list_rotate_switch();
            break;
        case BTN_ID_LP:
            ui.select[ui.layer] = 0;
        case BTN_ID_SP:
            switch (ui.select[ui.layer])
            {

            case 0:
                ui.index = M_MAIN;
                ui.state = S_LAYER_OUT;
                break;
            case 11:
                ui.index = M_KNOB;
                ui.state = S_LAYER_IN;
                break;
            }
        }
    }
}

// 旋钮编辑菜单处理函数
void knob_proc()
{
    list_show(knob_menu, M_KNOB);
    if (btn.pressed)
    {
        btn.pressed = false;
        switch (btn.id)
        {
        case BTN_ID_CW:
        case BTN_ID_CC:
            list_rotate_switch();
            break;
        case BTN_ID_LP:
            ui.select[ui.layer] = 0;
        case BTN_ID_SP:
            switch (ui.select[ui.layer])
            {

            case 0:
                ui.index = M_EDITOR;
                ui.state = S_LAYER_OUT;
                break;
            case 1:
                ui.index = M_KRF;
                ui.state = S_LAYER_IN;
                check_box_s_init(&knob.param[KNOB_ROT], &knob.param[KNOB_ROT_P]);
                break;
            case 2:
                ui.index = M_KPF;
                ui.state = S_LAYER_IN;
                check_box_s_init(&knob.param[KNOB_COD], &knob.param[KNOB_COD_P]);
                break;
            }
        }
    }
}

// 旋钮旋转功能菜单处理函数
void krf_proc()
{
    list_show(krf_menu, M_KRF);
    if (btn.pressed)
    {
        btn.pressed = false;
        switch (btn.id)
        {
        case BTN_ID_CW:
        case BTN_ID_CC:
            list_rotate_switch();
            break;
        case BTN_ID_LP:
            ui.select[ui.layer] = 0;
        case BTN_ID_SP:
            switch (ui.select[ui.layer])
            {

            case 0:
                ui.index = M_KNOB;
                ui.state = S_LAYER_OUT;
                break;
            case 1:
                break;
            case 2:
                check_box_s_select(KNOB_DISABLE, ui.select[ui.layer]);
                break;
            case 3:
                break;
            case 4:
                check_box_s_select(KNOB_ROT_VOL, ui.select[ui.layer]);
                break;
            case 5:
                check_box_s_select(KNOB_ROT_BRI, ui.select[ui.layer]);
                break;
            case 6:
                break;
            }
        }
    }
}

// 旋钮点按功能菜单处理函数
void kpf_proc()
{
    list_show(kpf_menu, M_KPF);
    if (btn.pressed)
    {
        btn.pressed = false;
        switch (btn.id)
        {
        case BTN_ID_CW:
        case BTN_ID_CC:
            list_rotate_switch();
            break;
        case BTN_ID_LP:
            ui.select[ui.layer] = 0;
        case BTN_ID_SP:
            switch (ui.select[ui.layer])
            {

                // case 0:   ui.index = M_KNOB;  ui.state = S_LAYER_OUT; break;
                // case 1:   break;
                // case 2:   check_box_s_select(KNOB_DISABLE, ui.select[ui.layer]); break;
                // case 3:   break;
                // case 4:   check_box_s_select('A', ui.select[ui.layer]); break;
                // case 5:   check_box_s_select('B', ui.select[ui.layer]); break;
                // case 6:   check_box_s_select('C', ui.select[ui.layer]); break;
                // case 7:   check_box_s_select('D', ui.select[ui.layer]); break;
                // case 8:   check_box_s_select('E', ui.select[ui.layer]); break;
                // case 9:   check_box_s_select('F', ui.select[ui.layer]); break;
                // case 10:  check_box_s_select('G', ui.select[ui.layer]); break;
                // case 11:  check_box_s_select('H', ui.select[ui.layer]); break;
                // case 12:  check_box_s_select('I', ui.select[ui.layer]); break;
                // case 13:  check_box_s_select('J', ui.select[ui.layer]); break;
                // case 14:  check_box_s_select('K', ui.select[ui.layer]); break;
                // case 15:  check_box_s_select('L', ui.select[ui.layer]); break;
                // case 16:  check_box_s_select('M', ui.select[ui.layer]); break;
                // case 17:  check_box_s_select('N', ui.select[ui.layer]); break;
                // case 18:  check_box_s_select('O', ui.select[ui.layer]); break;
                // case 19:  check_box_s_select('P', ui.select[ui.layer]); break;
                // case 20:  check_box_s_select('Q', ui.select[ui.layer]); break;
                // case 21:  check_box_s_select('R', ui.select[ui.layer]); break;
                // case 22:  check_box_s_select('S', ui.select[ui.layer]); break;
                // case 23:  check_box_s_select('T', ui.select[ui.layer]); break;
                // case 24:  check_box_s_select('U', ui.select[ui.layer]); break;
                // case 25:  check_box_s_select('V', ui.select[ui.layer]); break;
                // case 26:  check_box_s_select('W', ui.select[ui.layer]); break;
                // case 27:  check_box_s_select('X', ui.select[ui.layer]); break;
                // case 28:  check_box_s_select('Y', ui.select[ui.layer]); break;
                // case 29:  check_box_s_select('Z', ui.select[ui.layer]); break;
                // case 30:  break;
                // case 31:  check_box_s_select('0', ui.select[ui.layer]); break;
                // case 32:  check_box_s_select('1', ui.select[ui.layer]); break;
                // case 33:  check_box_s_select('2', ui.select[ui.layer]); break;
                // case 34:  check_box_s_select('3', ui.select[ui.layer]); break;
                // case 35:  check_box_s_select('4', ui.select[ui.layer]); break;
                // case 36:  check_box_s_select('5', ui.select[ui.layer]); break;
                // case 37:  check_box_s_select('6', ui.select[ui.layer]); break;
                // case 38:  check_box_s_select('7', ui.select[ui.layer]); break;
                // case 39:  check_box_s_select('8', ui.select[ui.layer]); break;
                // case 40:  check_box_s_select('9', ui.select[ui.layer]); break;
                // case 41:  break;
                // case 42:  check_box_s_select( KEY_ESC, ui.select[ui.layer]); break;
                // case 43:  check_box_s_select( KEY_F1,  ui.select[ui.layer]); break;
                // case 44:  check_box_s_select( KEY_F2,  ui.select[ui.layer]); break;
                // case 45:  check_box_s_select( KEY_F3,  ui.select[ui.layer]); break;
                // case 46:  check_box_s_select( KEY_F4,  ui.select[ui.layer]); break;
                // case 47:  check_box_s_select( KEY_F5,  ui.select[ui.layer]); break;
                // case 48:  check_box_s_select( KEY_F6,  ui.select[ui.layer]); break;
                // case 49:  check_box_s_select( KEY_F7,  ui.select[ui.layer]); break;
                // case 50:  check_box_s_select( KEY_F8,  ui.select[ui.layer]); break;
                // case 51:  check_box_s_select( KEY_F9,  ui.select[ui.layer]); break;
                // case 52:  check_box_s_select( KEY_F10, ui.select[ui.layer]); break;
                // case 53:  check_box_s_select( KEY_F11, ui.select[ui.layer]); break;
                // case 54:  check_box_s_select( KEY_F12, ui.select[ui.layer]); break;
                // case 55:  break;
                // case 56:  check_box_s_select( KEY_LEFT_CTRL,   ui.select[ui.layer]); break;
                // case 57:  check_box_s_select( KEY_LEFT_SHIFT,  ui.select[ui.layer]); break;
                // case 58:  check_box_s_select( KEY_LEFT_ALT,    ui.select[ui.layer]); break;
                // case 59:  check_box_s_select( KEY_LEFT_GUI,    ui.select[ui.layer]); break;
                // case 60:  check_box_s_select( KEY_RIGHT_CTRL,  ui.select[ui.layer]); break;
                // case 61:  check_box_s_select( KEY_RIGHT_SHIFT, ui.select[ui.layer]); break;
                // case 62:  check_box_s_select( KEY_RIGHT_ALT,   ui.select[ui.layer]); break;
                // case 63:  check_box_s_select( KEY_RIGHT_GUI,   ui.select[ui.layer]); break;
                // case 64:  break;
                // case 65:  check_box_s_select( KEY_CAPS_LOCK,   ui.select[ui.layer]); break;
                // case 66:  check_box_s_select( KEY_BACKSPACE,   ui.select[ui.layer]); break;
                // case 67:  check_box_s_select( KEY_RETURN,      ui.select[ui.layer]); break;
                // case 68:  check_box_s_select( KEY_INSERT,      ui.select[ui.layer]); break;
                // case 69:  check_box_s_select( KEY_DELETE,      ui.select[ui.layer]); break;
                // case 70:  check_box_s_select( KEY_TAB,         ui.select[ui.layer]); break;
                // case 71:  break;
                // case 72:  check_box_s_select( KEY_HOME,        ui.select[ui.layer]); break;
                // case 73:  check_box_s_select( KEY_END,         ui.select[ui.layer]); break;
                // case 74:  check_box_s_select( KEY_PAGE_UP,     ui.select[ui.layer]); break;
                // case 75:  check_box_s_select( KEY_PAGE_DOWN,   ui.select[ui.layer]); break;
                // case 76:  break;
                // case 77:  check_box_s_select( KEY_UP_ARROW,    ui.select[ui.layer]); break;
                // case 78:  check_box_s_select( KEY_DOWN_ARROW,  ui.select[ui.layer]); break;
                // case 79:  check_box_s_select( KEY_LEFT_ARROW,  ui.select[ui.layer]); break;
                // case 80:  check_box_s_select( KEY_RIGHT_ARROW, ui.select[ui.layer]); break;
                // case 81:  break;
            }
        }
    }
}

// 电压测量页处理函数
void volt_proc()
{
    volt_show();
    if (btn.pressed)
    {
        btn.pressed = false;
        switch (btn.id)
        {
        case BTN_ID_CW:
        case BTN_ID_CC:
            list_rotate_switch();
            break;

        case BTN_ID_SP:
        case BTN_ID_LP:
            ui.index = M_MAIN;
            ui.state = S_LAYER_OUT;
            break;
        }
    }
}

// 设置菜单处理函数，多选框列表类模板，弹窗模板
void setting_proc()
{
    list_show(setting_menu, M_SETTING);
    if (btn.pressed)
    {
        btn.pressed = false;
        switch (btn.id)
        {
        case BTN_ID_CW:
        case BTN_ID_CC:
            list_rotate_switch();
            break;
        case BTN_ID_LP:
            ui.select[ui.layer] = 0;
        case BTN_ID_SP:
            switch (ui.select[ui.layer])
            {

            // 返回更浅层级，长按被当作选择这一项，也是执行这一行
            case 0:
                ui.index = M_MAIN;
                ui.state = S_LAYER_OUT;
                break;

            // 弹出窗口，参数初始化：标题，参数名，参数值，最大值，最小值，步长，背景列表名，背景列表标签
            case 1:
                window_value_init("Disp Bri", DISP_BRI, &ui.param[DISP_BRI], 255, 0, 5, setting_menu, M_SETTING);
                break;
            case 2:
                window_value_init("Tile Ani", TILE_ANI, &ui.param[TILE_ANI], 100, 10, 1, setting_menu, M_SETTING);
                break;
            case 3:
                window_value_init("List Ani", LIST_ANI, &ui.param[LIST_ANI], 100, 10, 1, setting_menu, M_SETTING);
                break;
            case 4:
                window_value_init("Win Ani", WIN_ANI, &ui.param[WIN_ANI], 100, 10, 1, setting_menu, M_SETTING);
                break;
            case 5:
                window_value_init("Spot Ani", SPOT_ANI, &ui.param[SPOT_ANI], 100, 10, 1, setting_menu, M_SETTING);
                break;
            case 6:
                window_value_init("Tag Ani", TAG_ANI, &ui.param[TAG_ANI], 100, 10, 1, setting_menu, M_SETTING);
                break;
            case 7:
                window_value_init("Fade Ani", FADE_ANI, &ui.param[FADE_ANI], 255, 0, 1, setting_menu, M_SETTING);
                break;
            case 8:
                window_value_init("Btn SPT", BTN_SPT, &ui.param[BTN_SPT], 255, 0, 1, setting_menu, M_SETTING);
                break;
            case 9:
                window_value_init("Btn LPT", BTN_LPT, &ui.param[BTN_LPT], 255, 0, 1, setting_menu, M_SETTING);
                break;

            // 多选框
            case 10:
                check_box_m_select(TILE_UFD);
                break;
            case 11:
                check_box_m_select(LIST_UFD);
                break;
            case 12:
                check_box_m_select(TILE_LOOP);
                break;
            case 13:
                check_box_m_select(LIST_LOOP);
                break;
            case 14:
                check_box_m_select(WIN_BOK);
                break;
            case 15:
                check_box_m_select(KNOB_DIR);
                break;
            case 16:
                check_box_m_select(DARK_MODE);
                break;

            // 关于本机
            case 17:
                ui.index = M_ABOUT;
                ui.state = S_LAYER_IN;
                break;
            }
        }
    }
}

// 关于本机页
void about_proc()
{
    list_show(about_menu, M_ABOUT);
    if (btn.pressed)
    {
        btn.pressed = false;
        switch (btn.id)
        {
        case BTN_ID_CW:
        case BTN_ID_CC:
            list_rotate_switch();
            break;
        case BTN_ID_LP:
            ui.select[ui.layer] = 0;
        case BTN_ID_SP:
            switch (ui.select[ui.layer])
            {

            case 0:
                ui.index = M_SETTING;
                ui.state = S_LAYER_OUT;
                break;
            }
        }
    }
}

// 总的UI进程
void ui_proc()
{
    u8g2.sendBuffer();
    switch (ui.state)
    {
    case S_FADE:
        fade();
        break; // 转场动画
    case S_WINDOW:
        window_param_init();
        break; // 弹窗初始化
    case S_LAYER_IN:
        layer_init_in();
        break; // 层级初始化
    case S_LAYER_OUT:
        layer_init_out();
        break; // 层级初始化

    case S_NONE:
        u8g2.clearBuffer();
        switch (ui.index) // 直接选择页面
        {
        case M_WINDOW:
            window_proc();
            break;
        case M_SLEEP:
            sleep_proc();
            break;
        case M_MAIN:
            main_proc();
            break;
        case M_EDITOR:
            editor_proc();
            break;
        case M_KNOB:
            knob_proc();
            break;
        case M_KRF:
            krf_proc();
            break;
        case M_KPF:
            kpf_proc();
            break;
        case M_VOLT:
            volt_proc();
            break;
        case M_SETTING:
            setting_proc();
            break;
        case M_ABOUT:
            about_proc();
            break;
        }
    }
}

// OLED初始化函数
void oled_init()
{
    Wire.begin(21, 22, 400000);
    // pinMode(BTN0, INPUT_PULLUP);
    // pinMode(BTN1, INPUT_PULLUP);
    // pinMode(BTN2, INPUT_PULLUP);
    // key_init();
    u8g2.setBusClock(800000);
    // u8g2.setBusClock(1000000); // 硬件IIC接口使用
    u8g2.begin();
    u8g2.setContrast(ui.param[DISP_BRI]);
    buf_ptr = u8g2.getBufferPtr();
    buf_len = 8 * u8g2.getBufferTileHeight() * u8g2.getBufferTileWidth();
}

void Oled_init()
{
    ui_param_init();
    ui_init();
    oled_init();
    // btn_init();
}

// void loop()
// {
//   btn_scan();
//   ui_proc();
// }
