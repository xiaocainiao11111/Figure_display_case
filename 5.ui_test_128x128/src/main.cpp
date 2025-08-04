#include <U8g2lib.h>
#include <SPI.h>

// 使用硬件SPI（VSPI默认引脚：SCLK=18, MOSI=23）
U8G2_SH1107_SEEED_128X128_F_4W_HW_SPI u8g2(
    U8G2_R0,
    /* CS=*/12,  // 自定义CS引脚
    /* DC=*/14,  // 自定义DC引脚
    /* RESET=*/2 // 自定义RESET引脚
);

// //总目录，缩进表示页面层级
// enum
// {
//   M_WINDOW,
//   M_SLEEP,
//     M_MAIN,
//       M_EDITOR,
//         M_KNOB,
//           M_KRF,
//           M_KPF,
//       M_SETTING,
//         M_ABOUT,
// };

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
    const char *m_select;
} M_SELECT;

// 主菜单
M_SELECT main_menu[]{
    {"Sleep"},
    {"Editor"},
    {"Volt"},
    {"Setting"},
};

// 副标题
M_SELECT main_menu_exp[]{
    {"[ Activate Func ]"},
    {"[ Modify Func ]"},
    {"[ View Voltages ]"},
    {"[ Modify Config ]"},
};

// editor菜单
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
    {"- PA0"},
    {"- PA1"},
    {"- PA2"},
    {"- PA3"},
    {"- PA4"},
    {"- PA5"},
    {"- PA6"},
    {"- PA7"},
    {"- PB0"},
    {"- PB1"},
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
    {"WouoUI"},
    {"v2.3"},
    {"Board: STM32F103"},
    {"Ram: 20k"},
    {"Flash: 64k"},
    {"Freq: 72Mhz"},
    {"Creator: RQNG"},
    {"Bili UID: 9182439"},
};

/************************************* 图片内容 *************************************/
PROGMEM const uint8_t main_icon_pic[][16 * 18]{
    {
        0xF8,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x1F,
        0xFE,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x7F,
        0xFE,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x7F,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x7F,
        0xE0,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x01,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x07,
        0xFC,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x0F,
        0xF8,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x1F,
        0xE0,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x3F,
        0xC0,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x7F,
        0x80,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x7F,
        0x00,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x00,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x00,
        0xFE,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x00,
        0xFC,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x01,
        0xFC,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x01,
        0xF8,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x01,
        0xF8,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x01,
        0xF8,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x01,
        0xF0,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x01,
        0xF0,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x01,
        0xF0,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x00,
        0xF0,
        0xEF,
        0xFF,
        0xFF,
        0xFF,
        0x00,
        0xF0,
        0xEF,
        0xFF,
        0xFF,
        0xFF,
        0x00,
        0xF0,
        0xCF,
        0xFF,
        0xFF,
        0x7F,
        0x00,
        0xF0,
        0xCF,
        0xFF,
        0xFF,
        0x7F,
        0x00,
        0xF0,
        0x8F,
        0xFF,
        0xFF,
        0x3F,
        0x00,
        0xF0,
        0x0F,
        0xFF,
        0xFF,
        0x1F,
        0x00,
        0xF0,
        0x1F,
        0xFE,
        0xFF,
        0x0F,
        0x00,
        0xF8,
        0x1F,
        0xFC,
        0xFF,
        0x07,
        0x00,
        0xF8,
        0x1F,
        0xF0,
        0xFF,
        0x01,
        0x00,
        0xF8,
        0x3F,
        0x80,
        0x3F,
        0x00,
        0x00,
        0xFC,
        0x3F,
        0x00,
        0x00,
        0x00,
        0x00,
        0xFC,
        0x7F,
        0x00,
        0x00,
        0x00,
        0x00,
        0xFE,
        0xFF,
        0x00,
        0x00,
        0x00,
        0x00,
        0xFF,
        0xFF,
        0x00,
        0x00,
        0x00,
        0x00,
        0xFF,
        0xFF,
        0x01,
        0x00,
        0x00,
        0x80,
        0xFF,
        0xFF,
        0x03,
        0x00,
        0x00,
        0xC0,
        0xFF,
        0xFF,
        0x07,
        0x00,
        0x00,
        0xE0,
        0xFF,
        0xFF,
        0x1F,
        0x00,
        0x00,
        0xF8,
        0xFF,
        0xFF,
        0x3F,
        0x00,
        0x00,
        0xFC,
        0xFF,
        0xFF,
        0xFF,
        0x00,
        0x00,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x07,
        0xE0,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFE,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x7F,
        0xFE,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x7F,
        0xF8,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x1F,
    },
    {
        0xF8,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x1F,
        0xFE,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x7F,
        0xFE,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x7F,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xF9,
        0x7F,
        0xFE,
        0x9F,
        0xFF,
        0xFF,
        0xF9,
        0x7F,
        0xFE,
        0x9F,
        0xFF,
        0xFF,
        0xF9,
        0x7F,
        0xFE,
        0x9F,
        0xFF,
        0xFF,
        0xF9,
        0x7F,
        0xFE,
        0x9F,
        0xFF,
        0xFF,
        0xF9,
        0x7F,
        0xFE,
        0x9F,
        0xFF,
        0xFF,
        0xF9,
        0x7F,
        0xFE,
        0x9F,
        0xFF,
        0xFF,
        0xF9,
        0x7F,
        0xFE,
        0x9F,
        0xFF,
        0xFF,
        0xF9,
        0x3F,
        0xFC,
        0x9F,
        0xFF,
        0xFF,
        0xF9,
        0x1F,
        0xF8,
        0x9F,
        0xFF,
        0xFF,
        0xF9,
        0x1F,
        0xF8,
        0x9F,
        0xFF,
        0xFF,
        0xF0,
        0x1F,
        0xF8,
        0x0F,
        0xFF,
        0xFF,
        0xF0,
        0x1F,
        0xF8,
        0x0F,
        0xFF,
        0xFF,
        0xF9,
        0x1F,
        0xF8,
        0x9F,
        0xFF,
        0xFF,
        0xF9,
        0x1F,
        0xF8,
        0x9F,
        0xFF,
        0xFF,
        0xF9,
        0x3F,
        0xFC,
        0x9F,
        0xFF,
        0xFF,
        0xF9,
        0x7F,
        0xFE,
        0x9F,
        0xFF,
        0xFF,
        0xF9,
        0x7F,
        0xFE,
        0x9F,
        0xFF,
        0xFF,
        0xF9,
        0x7F,
        0xFE,
        0x9F,
        0xFF,
        0xFF,
        0xF9,
        0x7F,
        0xFE,
        0x9F,
        0xFF,
        0xFF,
        0xF9,
        0x7F,
        0xFE,
        0x9F,
        0xFF,
        0xFF,
        0xF9,
        0x7F,
        0xFE,
        0x9F,
        0xFF,
        0xFF,
        0xF9,
        0x7F,
        0xFE,
        0x9F,
        0xFF,
        0xFF,
        0xF9,
        0x7F,
        0xFE,
        0x9F,
        0xFF,
        0xFF,
        0xF9,
        0x7F,
        0xFE,
        0x9F,
        0xFF,
        0xFF,
        0xF9,
        0x7F,
        0xFE,
        0x9F,
        0xFF,
        0xFF,
        0xF0,
        0x7F,
        0xFE,
        0x0F,
        0xFF,
        0x7F,
        0xE0,
        0x7F,
        0xFE,
        0x07,
        0xFE,
        0x7F,
        0xE0,
        0x7F,
        0xFE,
        0x07,
        0xFE,
        0x7F,
        0xE0,
        0x3F,
        0xFC,
        0x07,
        0xFE,
        0x7F,
        0xE0,
        0x3F,
        0xFC,
        0x07,
        0xFE,
        0x7F,
        0xE0,
        0x7F,
        0xFE,
        0x07,
        0xFE,
        0x7F,
        0xE0,
        0x7F,
        0xFE,
        0x07,
        0xFE,
        0xFF,
        0xF0,
        0x7F,
        0xFE,
        0x0F,
        0xFF,
        0xFF,
        0xF9,
        0x7F,
        0xFE,
        0x9F,
        0xFF,
        0xFF,
        0xF9,
        0x7F,
        0xFE,
        0x9F,
        0xFF,
        0xFF,
        0xF9,
        0x7F,
        0xFE,
        0x9F,
        0xFF,
        0xFF,
        0xF9,
        0x7F,
        0xFE,
        0x9F,
        0xFF,
        0xFF,
        0xF9,
        0x7F,
        0xFE,
        0x9F,
        0xFF,
        0xFF,
        0xF9,
        0x7F,
        0xFE,
        0x9F,
        0xFF,
        0xFF,
        0xF9,
        0x7F,
        0xFE,
        0x9F,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFE,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x7F,
        0xFE,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x7F,
        0xF8,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x1F,
    },
    {
        0xF8,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x1F,
        0xFE,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x7F,
        0xFE,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x7F,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFD,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xF8,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xF8,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x7F,
        0xF0,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x7F,
        0xF0,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x3F,
        0xE0,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x3F,
        0xE0,
        0xC1,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xF8,
        0x80,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x78,
        0x00,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x38,
        0x00,
        0xFE,
        0xFF,
        0xFF,
        0xFF,
        0x38,
        0x1C,
        0xFE,
        0xFF,
        0xFF,
        0xFF,
        0x18,
        0x3E,
        0xFC,
        0xFF,
        0xFF,
        0xFF,
        0x18,
        0x7F,
        0xFC,
        0xFF,
        0xFF,
        0xFF,
        0x08,
        0x7F,
        0xF8,
        0xFF,
        0xFB,
        0xFF,
        0x88,
        0xFF,
        0xF8,
        0xFF,
        0xFB,
        0xFF,
        0x80,
        0xFF,
        0xF0,
        0xFF,
        0xF9,
        0xFF,
        0xC0,
        0xFF,
        0xF1,
        0xFF,
        0xF9,
        0xFF,
        0xC0,
        0xFF,
        0xF1,
        0xFF,
        0xF9,
        0xFF,
        0xC0,
        0xFF,
        0xE1,
        0xFF,
        0xF8,
        0xFF,
        0xE0,
        0xFF,
        0xE3,
        0xFF,
        0xF8,
        0xFF,
        0xE0,
        0xFF,
        0xC3,
        0x7F,
        0xF8,
        0xFF,
        0xF0,
        0xFF,
        0xC7,
        0x7F,
        0xFC,
        0xFF,
        0xF0,
        0xFF,
        0xC7,
        0x7F,
        0xFC,
        0xFF,
        0xF0,
        0xFF,
        0x87,
        0x3F,
        0xFC,
        0xFF,
        0xF8,
        0xFF,
        0x8F,
        0x3F,
        0xFE,
        0xFF,
        0xF8,
        0xFF,
        0x0F,
        0x1F,
        0xFE,
        0xFF,
        0xF8,
        0xFF,
        0x1F,
        0x0E,
        0xFF,
        0xFF,
        0xF8,
        0xFF,
        0x1F,
        0x00,
        0xFF,
        0xFF,
        0xF8,
        0xFF,
        0x3F,
        0x80,
        0xFF,
        0xFF,
        0xF8,
        0xFF,
        0x3F,
        0xC0,
        0xFF,
        0xFF,
        0xF8,
        0xFF,
        0xFF,
        0xE0,
        0xFF,
        0xFF,
        0xF8,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xF8,
        0xFF,
        0xFF,
        0xCF,
        0xFF,
        0xFF,
        0xF8,
        0xFF,
        0xFF,
        0x0F,
        0xFF,
        0xFF,
        0x00,
        0x00,
        0x00,
        0x00,
        0xFC,
        0xFF,
        0x00,
        0x00,
        0x00,
        0x00,
        0xF8,
        0xFF,
        0x00,
        0x00,
        0x00,
        0x00,
        0xFC,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x0F,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xCF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFE,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x7F,
        0xFE,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x7F,
        0xF8,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x1F,
    },
    {
        0xF8,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x1F,
        0xFE,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x7F,
        0xFE,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x7F,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x3F,
        0xFC,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x1F,
        0xF8,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x1F,
        0xF8,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x1F,
        0xF8,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x1F,
        0xF8,
        0xFF,
        0xFF,
        0xFF,
        0xC7,
        0x0F,
        0xF0,
        0xE3,
        0xFF,
        0xFF,
        0x83,
        0x07,
        0xE0,
        0xC1,
        0xFF,
        0xFF,
        0x01,
        0x00,
        0x00,
        0x80,
        0xFF,
        0xFF,
        0x01,
        0x00,
        0x00,
        0x80,
        0xFF,
        0xFF,
        0x01,
        0x00,
        0x00,
        0x80,
        0xFF,
        0xFF,
        0x03,
        0x00,
        0x00,
        0xC0,
        0xFF,
        0xFF,
        0x07,
        0x00,
        0x00,
        0xE0,
        0xFF,
        0xFF,
        0x07,
        0xE0,
        0x07,
        0xE0,
        0xFF,
        0xFF,
        0x07,
        0xF8,
        0x1F,
        0xE0,
        0xFF,
        0xFF,
        0x07,
        0xFC,
        0x3F,
        0xE0,
        0xFF,
        0xFF,
        0x03,
        0xFE,
        0x7F,
        0xC0,
        0xFF,
        0xFF,
        0x01,
        0xFE,
        0x7F,
        0x80,
        0xFF,
        0x1F,
        0x00,
        0xFF,
        0xFF,
        0x00,
        0xF8,
        0x0F,
        0x00,
        0xFF,
        0xFF,
        0x00,
        0xF0,
        0x0F,
        0x00,
        0xFF,
        0xFF,
        0x00,
        0xF0,
        0x0F,
        0x00,
        0xFF,
        0xFF,
        0x00,
        0xF0,
        0x0F,
        0x00,
        0xFF,
        0xFF,
        0x00,
        0xF0,
        0x1F,
        0x00,
        0xFF,
        0xFF,
        0x00,
        0xF8,
        0xFF,
        0x03,
        0xFE,
        0x7F,
        0xC0,
        0xFF,
        0xFF,
        0x03,
        0xFE,
        0x7F,
        0xC0,
        0xFF,
        0xFF,
        0x07,
        0xFC,
        0x3F,
        0xE0,
        0xFF,
        0xFF,
        0x07,
        0xF8,
        0x1F,
        0xE0,
        0xFF,
        0xFF,
        0x07,
        0xE0,
        0x07,
        0xE0,
        0xFF,
        0xFF,
        0x07,
        0x00,
        0x00,
        0xE0,
        0xFF,
        0xFF,
        0x03,
        0x00,
        0x00,
        0xC0,
        0xFF,
        0xFF,
        0x01,
        0x00,
        0x00,
        0x80,
        0xFF,
        0xFF,
        0x01,
        0x00,
        0x00,
        0x80,
        0xFF,
        0xFF,
        0x01,
        0x00,
        0x00,
        0x80,
        0xFF,
        0xFF,
        0x83,
        0x07,
        0xE0,
        0xC1,
        0xFF,
        0xFF,
        0xC7,
        0x0F,
        0xF0,
        0xE3,
        0xFF,
        0xFF,
        0xFF,
        0x1F,
        0xF8,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x1F,
        0xF8,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x1F,
        0xF8,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x1F,
        0xF8,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x3F,
        0xFC,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFE,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x7F,
        0xFE,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x7F,
        0xF8,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0x1F,
    },
};

// OLED变量
#define DISP_H 128 // 屏幕高度
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

// ui结构体，只存在一个ui
struct
{
    bool init;
    uint8_t num[UI_MNUMB];
    uint8_t select[UI_DEPTH]; // ???
    uint8_t layer;            // 当前层级
    uint8_t index = M_SLEEP;  // 当前目录
    uint8_t state = S_NONE;   // 当前状态
    bool sleep = true;
    uint8_t fade = 1;
    uint8_t param[UI_PARAM]; // ui的各种参数
} ui;

// 磁贴变量
// 所有磁贴页面都使用同一套参数
#define TILE_B_FONT u8g2_font_helvB24_tr      // 磁贴大标题字体
#define TILE_S_FONT u8g2_font_HelvetiPixel_tr // 磁贴小标题字体
#define TILE_B_TITLE_H 25                     // 磁贴大标题字体高度
#define TILE_S_TITLE_H 8                      // 磁贴小标题字体高度
#define TILE_ICON_H 48                        // 磁贴图标高度
#define TILE_ICON_W 48                        // 磁贴图标宽度
#define TILE_ICON_S 57                        // 磁贴图标间距
#define TILE_INDI_H 40                        // 磁贴大标题指示器高度
#define TILE_INDI_W 10                        // 磁贴大标题指示器宽度
#define TILE_INDI_S 57                        // 磁贴大标题指示器上边距
// 磁贴结构体
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
    float indi_x; // ???
    float indi_x_trg;
    float title_y;     // 标题的y目前位置
    float title_y_trg; // 标题的y目标位置
} tile;

// 列表变量
// 默认参数

#define LIST_FONT u8g2_font_HelvetiPixel_tr // 列表字体
#define LIST_TEXT_H 8                       // 列表每行文字字体的高度
#define LIST_LINE_H 16                      // 列表单行高度
#define LIST_TEXT_S 4                       // 列表每行文字的上边距，左边距和右边距，下边距由它和字体高度和行高度决定
#define LIST_BAR_W 5                        // 列表进度条宽度，需要是奇数，因为正中间有1像素宽度的线
#define LIST_BOX_R 0.5f                     // 列表选择框圆角

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
#define WAVE_SAMPLE 20    // 采集倍数
#define WAVE_W DISP_W     // 波形宽度
#define WAVE_L 0          // 波形左边距
#define WAVE_U 0          // 波形上边距
#define WAVE_MAX 43       // 最大值
#define WAVE_MIN 5        // 最小值
#define WAVE_BOX_H 49     // 波形边框高度
#define WAVE_BOX_W DISP_W // 波形边框宽度
// 列表和文字背景框相关
#define VOLT_FONT u8g2_font_helvB24_tr // 电压数字字体
#define VOLT_LIST_U_S 94               // 列表上边距
#define VOLT_TEXT_BG_U_S 53            // 文字背景框上边距
#define VOLT_TEXT_BG_H 33              // 文字背景框高度
struct
{
    int ch0_adc[WAVE_SAMPLE * WAVE_W];
    int ch0_wave[WAVE_W];
    int val;
    float text_bg_l;
    float text_bg_l_trg;
} volt;

#define CHECK_BOX_L_S 95 // 选择框在每行的左边距
#define CHECK_BOX_U_S 2  // 选择框在每行的上边距
#define CHECK_BOX_F_W 12 // 选择框外框宽度
#define CHECK_BOX_F_H 12 // 选择框外框高度
#define CHECK_BOX_D_S 2  // 选择框里面的点距离外框的边距
// 选择框
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

// 弹窗结构体
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

// 关于本机页变量
#define ABOUT_FONT u8g2_font_HelvetiPixel_tr // 关于本机字体
#define ABOUT_INDI_S 4                       // 关于本机页面列表指示左边距，也用于规范页面内元素之间的位置关系
#define ABOUT_INDI_W 2                       // 关于本机页面列表指示器宽度
struct
{
    float indi_x;
    float indi_x_trg;
} about;

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
    //   eeprom.change = true;
}

// 单选框处理函数
void check_box_s_select(uint8_t val, uint8_t pos)
{
    *check_box.s = val;
    *check_box.s_p = pos;
    //   eeprom.change = true;
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

void setup()
{
    u8g2.begin();
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_ncenB08_tr);
    u8g2.drawStr(0, 20, "Hello ESP32!");
    u8g2.sendBuffer();
}

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

// 旋钮设置页初始化
void knob_param_init() { check_box_v_init(&knob.param[0]); }

// 旋钮旋转页初始化
void krf_param_init() { check_box_s_init(&knob.param[KNOB_ROT], &knob.param[KNOB_ROT_P]); }

// 旋钮点按页初始化
void kpf_param_init() { check_box_s_init(&knob.param[KNOB_COD], &knob.param[KNOB_COD_P]); }

// 电压测量页初始化
void volt_param_init()
{
    volt.text_bg_l = 0;
    volt.text_bg_l_trg = DISP_W;
}

// 设置页初始化
void setting_param_init()
{
    check_box_v_init(ui.param);
    check_box_m_init(ui.param);
}

// 关于本机页初始化
void about_param_init()
{
    about.indi_x = 0;
    about.indi_x_trg = ABOUT_INDI_S;
}

// 弹窗动画初始化
void window_param_init()
{
    win.bar = 0;
    win.y = WIN_Y;
    win.y_trg = win.u;
    ui.state = S_NONE;
}

// 进入更深层级时的初始化，层级++，初始化取消，列表归零，变为转场状态
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
    case M_ABOUT:
        about_param_init();
        break; // 设置页进入关于本机页，动画初始化
    }
}
// 进入睡眠时的初始化
void sleep_param_init()
{
    u8g2.setDrawColor(0);
    u8g2.drawBox(0, 0, DISP_W, DISP_H);
    u8g2.setPowerSave(1);
    ui.state = S_NONE;
    ui.sleep = true;
    //   if (eeprom.change)
    //   {
    //     eeprom_write_all_data();
    //     eeprom.change = false;
    //   }
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

// 磁贴类页面通用显示函数，输入主标题，副标题，图片
void tile_show(struct MENU arr_1[], struct MENU arr_2[], const uint8_t icon_pic[][16 * 18])
{
    // 计算动画过渡值，不断计算磁贴的位置
    animation(&tile.icon_x, &tile.icon_x_trg, TILE_ANI);
    animation(&tile.icon_y, &tile.icon_y_trg, TILE_ANI);
    animation(&tile.indi_x, &tile.indi_x_trg, TILE_ANI);
    animation(&tile.title_y, &tile.title_y_trg, TILE_ANI);

    // 设置大小标题的颜色和文字方向，0透显，1实显，2反色，这里都用实显
    u8g2.setDrawColor(1);
    u8g2.setFontDirection(0);

    // 绘制大标题
    u8g2.setFont(TILE_B_FONT);
    u8g2.drawStr(((DISP_W - TILE_INDI_W) - u8g2.getStrWidth(arr_1[ui.select[ui.layer]].m_select)) / 2 + TILE_INDI_W, tile.title_y, arr_1[ui.select[ui.layer]].m_select);

    // 绘制小标题
    u8g2.setFont(TILE_S_FONT);
    u8g2.drawStr(((DISP_W - u8g2.getStrWidth(arr_2[ui.select[ui.layer]].m_select)) / 2), 0.5 * (TILE_ICON_S + TILE_INDI_H + DISP_H + LIST_TEXT_H), arr_2[ui.select[ui.layer]].m_select);

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

void loop()
{
    // delay(1000);
    //     u8g2.clearBuffer();
    // u8g2.sendBuffer();
}