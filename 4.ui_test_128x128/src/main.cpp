// #include <U8g2lib.h>
// #include <SPI.h>

// // 使用硬件SPI（VSPI默认引脚：SCLK=18, MOSI=23）
// U8G2_SH1107_SEEED_128X128_F_4W_HW_SPI u8g2(
//     U8G2_R0,
//     /* CS=*/12,  // 自定义CS引脚
//     /* DC=*/14,  // 自定义DC引脚
//     /* RESET=*/2 // 自定义RESET引脚
// );

// // //总目录，缩进表示页面层级
// // enum
// // {
// //   M_WINDOW,
// //   M_SLEEP,
// //     M_MAIN,
// //       M_EDITOR,
// //         M_KNOB,
// //           M_KRF,
// //           M_KPF,
// //       M_SETTING,
// //         M_ABOUT,
// // };

// // 总目录，缩进表示页面层级
// enum
// {
//     M_WINDOW,
//     M_SLEEP,
//     M_MAIN,
//     M_EDITOR,
//     M_KNOB,
//     M_KRF,
//     M_KPF,
//     M_VOLT,
//     M_SETTING,
//     M_ABOUT,
// };

// // 状态，初始化标签
// enum
// {
//     S_FADE,      // 转场动画
//     S_WINDOW,    // 弹窗初始化
//     S_LAYER_IN,  // 层级初始化
//     S_LAYER_OUT, // 层级初始化
//     S_NONE,      // 直接选择页面
// };

// // 菜单结构体
// typedef struct MENU
// {
//     const char *m_select;
// } M_SELECT;

// // 主菜单
// M_SELECT main_menu[]{
//     {"Sleep"},
//     {"Editor"},
//     {"Volt"},
//     {"Setting"},
// };

// // 副标题
// M_SELECT main_menu_exp[]{
//     {"[ Activate Func ]"},
//     {"[ Modify Func ]"},
//     {"[ View Voltages ]"},
//     {"[ Modify Config ]"},
// };

// // editor菜单
// M_SELECT editor_menu[]{
//     {"[ Editor ]"},
//     {"- Function 0"},
//     {"- Function 1"},
//     {"- Function 2"},
//     {"- Function 3"},
//     {"- Function 4"},
//     {"- Function 5"},
//     {"- Function 6"},
//     {"- Function 7"},
//     {"- Function 8"},
//     {"- Function 9"},
//     {"- Knob"},
// };

// M_SELECT knob_menu[]{
//     {"[ Knob ]"},
//     {"# Rotate Func"},
//     {"$ Press Func"},
// };

// M_SELECT krf_menu[]{
//     {"[ Rotate Function ]"},
//     {"--------------------------"},
//     {"= Disable"},
//     {"--------------------------"},
//     {"= Volume"},
//     {"= Brightness"},
//     {"--------------------------"},
// };

// M_SELECT kpf_menu[]{
//     {"[ Press Function ]"},
//     {"--------------------------"},
//     {"= Disable"},
//     {"--------------------------"},
//     {"= A"},
//     {"= B"},
//     {"= C"},
//     {"= D"},
//     {"= E"},
//     {"= F"},
//     {"= G"},
//     {"= H"},
//     {"= I"},
//     {"= J"},
//     {"= K"},
//     {"= L"},
//     {"= M"},
//     {"= N"},
//     {"= O"},
//     {"= P"},
//     {"= Q"},
//     {"= R"},
//     {"= S"},
//     {"= T"},
//     {"= U"},
//     {"= V"},
//     {"= W"},
//     {"= X"},
//     {"= Y"},
//     {"= Z"},
//     {"--------------------------"},
//     {"= 0"},
//     {"= 1"},
//     {"= 2"},
//     {"= 3"},
//     {"= 4"},
//     {"= 5"},
//     {"= 6"},
//     {"= 7"},
//     {"= 8"},
//     {"= 9"},
//     {"--------------------------"},
//     {"= Esc"},
//     {"= F1"},
//     {"= F2"},
//     {"= F3"},
//     {"= F4"},
//     {"= F5"},
//     {"= F6"},
//     {"= F7"},
//     {"= F8"},
//     {"= F9"},
//     {"= F10"},
//     {"= F11"},
//     {"= F12"},
//     {"--------------------------"},
//     {"= Left Ctrl"},
//     {"= Left Shift"},
//     {"= Left Alt"},
//     {"= Left Win"},
//     {"= Right Ctrl"},
//     {"= Right Shift"},
//     {"= Right Alt"},
//     {"= Right Win"},
//     {"--------------------------"},
//     {"= Caps Lock"},
//     {"= Backspace"},
//     {"= Return"},
//     {"= Insert"},
//     {"= Delete"},
//     {"= Tab"},
//     {"--------------------------"},
//     {"= Home"},
//     {"= End"},
//     {"= Page Up"},
//     {"= Page Down"},
//     {"--------------------------"},
//     {"= Up Arrow"},
//     {"= Down Arrow"},
//     {"= Left Arrow"},
//     {"= Right Arrow"},
//     {"--------------------------"},
// };

// M_SELECT volt_menu[]{
//     {"- PA0"},
//     {"- PA1"},
//     {"- PA2"},
//     {"- PA3"},
//     {"- PA4"},
//     {"- PA5"},
//     {"- PA6"},
//     {"- PA7"},
//     {"- PB0"},
//     {"- PB1"},
// };

// M_SELECT setting_menu[]{
//     {"[ Setting ]"},
//     {"~ Disp Bri"},
//     {"~ Tile Ani"},
//     {"~ List Ani"},
//     {"~ Win Ani"},
//     {"~ Spot Ani"},
//     {"~ Tag Ani"},
//     {"~ Fade Ani"},
//     {"~ Btn SPT"},
//     {"~ Btn LPT"},
//     {"+ T Ufd Fm Scr"},
//     {"+ L Ufd Fm Scr"},
//     {"+ T Loop Mode"},
//     {"+ L Loop Mode"},
//     {"+ Win Bokeh Bg"},
//     {"+ Knob Rot Dir"},
//     {"+ Dark Mode"},
//     {"- [ About ]"},
// };

// M_SELECT about_menu[]{
//     {"WouoUI"},
//     {"v2.3"},
//     {"Board: STM32F103"},
//     {"Ram: 20k"},
//     {"Flash: 64k"},
//     {"Freq: 72Mhz"},
//     {"Creator: RQNG"},
//     {"Bili UID: 9182439"},
// };

// /************************************* 图片内容 *************************************/
// PROGMEM const uint8_t main_icon_pic[][16 * 18]{
//     {
//         0xF8,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x1F,
//         0xFE,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x7F,
//         0xFE,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x7F,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x7F,
//         0xE0,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x01,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x07,
//         0xFC,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x0F,
//         0xF8,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x1F,
//         0xE0,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x3F,
//         0xC0,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x7F,
//         0x80,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x7F,
//         0x00,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x00,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x00,
//         0xFE,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x00,
//         0xFC,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x01,
//         0xFC,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x01,
//         0xF8,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x01,
//         0xF8,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x01,
//         0xF8,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x01,
//         0xF0,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x01,
//         0xF0,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x01,
//         0xF0,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x00,
//         0xF0,
//         0xEF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x00,
//         0xF0,
//         0xEF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x00,
//         0xF0,
//         0xCF,
//         0xFF,
//         0xFF,
//         0x7F,
//         0x00,
//         0xF0,
//         0xCF,
//         0xFF,
//         0xFF,
//         0x7F,
//         0x00,
//         0xF0,
//         0x8F,
//         0xFF,
//         0xFF,
//         0x3F,
//         0x00,
//         0xF0,
//         0x0F,
//         0xFF,
//         0xFF,
//         0x1F,
//         0x00,
//         0xF0,
//         0x1F,
//         0xFE,
//         0xFF,
//         0x0F,
//         0x00,
//         0xF8,
//         0x1F,
//         0xFC,
//         0xFF,
//         0x07,
//         0x00,
//         0xF8,
//         0x1F,
//         0xF0,
//         0xFF,
//         0x01,
//         0x00,
//         0xF8,
//         0x3F,
//         0x80,
//         0x3F,
//         0x00,
//         0x00,
//         0xFC,
//         0x3F,
//         0x00,
//         0x00,
//         0x00,
//         0x00,
//         0xFC,
//         0x7F,
//         0x00,
//         0x00,
//         0x00,
//         0x00,
//         0xFE,
//         0xFF,
//         0x00,
//         0x00,
//         0x00,
//         0x00,
//         0xFF,
//         0xFF,
//         0x00,
//         0x00,
//         0x00,
//         0x00,
//         0xFF,
//         0xFF,
//         0x01,
//         0x00,
//         0x00,
//         0x80,
//         0xFF,
//         0xFF,
//         0x03,
//         0x00,
//         0x00,
//         0xC0,
//         0xFF,
//         0xFF,
//         0x07,
//         0x00,
//         0x00,
//         0xE0,
//         0xFF,
//         0xFF,
//         0x1F,
//         0x00,
//         0x00,
//         0xF8,
//         0xFF,
//         0xFF,
//         0x3F,
//         0x00,
//         0x00,
//         0xFC,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x00,
//         0x00,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x07,
//         0xE0,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFE,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x7F,
//         0xFE,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x7F,
//         0xF8,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x1F,
//     },
//     {
//         0xF8,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x1F,
//         0xFE,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x7F,
//         0xFE,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x7F,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xF9,
//         0x7F,
//         0xFE,
//         0x9F,
//         0xFF,
//         0xFF,
//         0xF9,
//         0x7F,
//         0xFE,
//         0x9F,
//         0xFF,
//         0xFF,
//         0xF9,
//         0x7F,
//         0xFE,
//         0x9F,
//         0xFF,
//         0xFF,
//         0xF9,
//         0x7F,
//         0xFE,
//         0x9F,
//         0xFF,
//         0xFF,
//         0xF9,
//         0x7F,
//         0xFE,
//         0x9F,
//         0xFF,
//         0xFF,
//         0xF9,
//         0x7F,
//         0xFE,
//         0x9F,
//         0xFF,
//         0xFF,
//         0xF9,
//         0x7F,
//         0xFE,
//         0x9F,
//         0xFF,
//         0xFF,
//         0xF9,
//         0x3F,
//         0xFC,
//         0x9F,
//         0xFF,
//         0xFF,
//         0xF9,
//         0x1F,
//         0xF8,
//         0x9F,
//         0xFF,
//         0xFF,
//         0xF9,
//         0x1F,
//         0xF8,
//         0x9F,
//         0xFF,
//         0xFF,
//         0xF0,
//         0x1F,
//         0xF8,
//         0x0F,
//         0xFF,
//         0xFF,
//         0xF0,
//         0x1F,
//         0xF8,
//         0x0F,
//         0xFF,
//         0xFF,
//         0xF9,
//         0x1F,
//         0xF8,
//         0x9F,
//         0xFF,
//         0xFF,
//         0xF9,
//         0x1F,
//         0xF8,
//         0x9F,
//         0xFF,
//         0xFF,
//         0xF9,
//         0x3F,
//         0xFC,
//         0x9F,
//         0xFF,
//         0xFF,
//         0xF9,
//         0x7F,
//         0xFE,
//         0x9F,
//         0xFF,
//         0xFF,
//         0xF9,
//         0x7F,
//         0xFE,
//         0x9F,
//         0xFF,
//         0xFF,
//         0xF9,
//         0x7F,
//         0xFE,
//         0x9F,
//         0xFF,
//         0xFF,
//         0xF9,
//         0x7F,
//         0xFE,
//         0x9F,
//         0xFF,
//         0xFF,
//         0xF9,
//         0x7F,
//         0xFE,
//         0x9F,
//         0xFF,
//         0xFF,
//         0xF9,
//         0x7F,
//         0xFE,
//         0x9F,
//         0xFF,
//         0xFF,
//         0xF9,
//         0x7F,
//         0xFE,
//         0x9F,
//         0xFF,
//         0xFF,
//         0xF9,
//         0x7F,
//         0xFE,
//         0x9F,
//         0xFF,
//         0xFF,
//         0xF9,
//         0x7F,
//         0xFE,
//         0x9F,
//         0xFF,
//         0xFF,
//         0xF9,
//         0x7F,
//         0xFE,
//         0x9F,
//         0xFF,
//         0xFF,
//         0xF0,
//         0x7F,
//         0xFE,
//         0x0F,
//         0xFF,
//         0x7F,
//         0xE0,
//         0x7F,
//         0xFE,
//         0x07,
//         0xFE,
//         0x7F,
//         0xE0,
//         0x7F,
//         0xFE,
//         0x07,
//         0xFE,
//         0x7F,
//         0xE0,
//         0x3F,
//         0xFC,
//         0x07,
//         0xFE,
//         0x7F,
//         0xE0,
//         0x3F,
//         0xFC,
//         0x07,
//         0xFE,
//         0x7F,
//         0xE0,
//         0x7F,
//         0xFE,
//         0x07,
//         0xFE,
//         0x7F,
//         0xE0,
//         0x7F,
//         0xFE,
//         0x07,
//         0xFE,
//         0xFF,
//         0xF0,
//         0x7F,
//         0xFE,
//         0x0F,
//         0xFF,
//         0xFF,
//         0xF9,
//         0x7F,
//         0xFE,
//         0x9F,
//         0xFF,
//         0xFF,
//         0xF9,
//         0x7F,
//         0xFE,
//         0x9F,
//         0xFF,
//         0xFF,
//         0xF9,
//         0x7F,
//         0xFE,
//         0x9F,
//         0xFF,
//         0xFF,
//         0xF9,
//         0x7F,
//         0xFE,
//         0x9F,
//         0xFF,
//         0xFF,
//         0xF9,
//         0x7F,
//         0xFE,
//         0x9F,
//         0xFF,
//         0xFF,
//         0xF9,
//         0x7F,
//         0xFE,
//         0x9F,
//         0xFF,
//         0xFF,
//         0xF9,
//         0x7F,
//         0xFE,
//         0x9F,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFE,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x7F,
//         0xFE,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x7F,
//         0xF8,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x1F,
//     },
//     {
//         0xF8,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x1F,
//         0xFE,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x7F,
//         0xFE,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x7F,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFD,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xF8,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xF8,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x7F,
//         0xF0,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x7F,
//         0xF0,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x3F,
//         0xE0,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x3F,
//         0xE0,
//         0xC1,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xF8,
//         0x80,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x78,
//         0x00,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x38,
//         0x00,
//         0xFE,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x38,
//         0x1C,
//         0xFE,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x18,
//         0x3E,
//         0xFC,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x18,
//         0x7F,
//         0xFC,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x08,
//         0x7F,
//         0xF8,
//         0xFF,
//         0xFB,
//         0xFF,
//         0x88,
//         0xFF,
//         0xF8,
//         0xFF,
//         0xFB,
//         0xFF,
//         0x80,
//         0xFF,
//         0xF0,
//         0xFF,
//         0xF9,
//         0xFF,
//         0xC0,
//         0xFF,
//         0xF1,
//         0xFF,
//         0xF9,
//         0xFF,
//         0xC0,
//         0xFF,
//         0xF1,
//         0xFF,
//         0xF9,
//         0xFF,
//         0xC0,
//         0xFF,
//         0xE1,
//         0xFF,
//         0xF8,
//         0xFF,
//         0xE0,
//         0xFF,
//         0xE3,
//         0xFF,
//         0xF8,
//         0xFF,
//         0xE0,
//         0xFF,
//         0xC3,
//         0x7F,
//         0xF8,
//         0xFF,
//         0xF0,
//         0xFF,
//         0xC7,
//         0x7F,
//         0xFC,
//         0xFF,
//         0xF0,
//         0xFF,
//         0xC7,
//         0x7F,
//         0xFC,
//         0xFF,
//         0xF0,
//         0xFF,
//         0x87,
//         0x3F,
//         0xFC,
//         0xFF,
//         0xF8,
//         0xFF,
//         0x8F,
//         0x3F,
//         0xFE,
//         0xFF,
//         0xF8,
//         0xFF,
//         0x0F,
//         0x1F,
//         0xFE,
//         0xFF,
//         0xF8,
//         0xFF,
//         0x1F,
//         0x0E,
//         0xFF,
//         0xFF,
//         0xF8,
//         0xFF,
//         0x1F,
//         0x00,
//         0xFF,
//         0xFF,
//         0xF8,
//         0xFF,
//         0x3F,
//         0x80,
//         0xFF,
//         0xFF,
//         0xF8,
//         0xFF,
//         0x3F,
//         0xC0,
//         0xFF,
//         0xFF,
//         0xF8,
//         0xFF,
//         0xFF,
//         0xE0,
//         0xFF,
//         0xFF,
//         0xF8,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xF8,
//         0xFF,
//         0xFF,
//         0xCF,
//         0xFF,
//         0xFF,
//         0xF8,
//         0xFF,
//         0xFF,
//         0x0F,
//         0xFF,
//         0xFF,
//         0x00,
//         0x00,
//         0x00,
//         0x00,
//         0xFC,
//         0xFF,
//         0x00,
//         0x00,
//         0x00,
//         0x00,
//         0xF8,
//         0xFF,
//         0x00,
//         0x00,
//         0x00,
//         0x00,
//         0xFC,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x0F,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xCF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFE,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x7F,
//         0xFE,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x7F,
//         0xF8,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x1F,
//     },
//     {
//         0xF8,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x1F,
//         0xFE,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x7F,
//         0xFE,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x7F,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x3F,
//         0xFC,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x1F,
//         0xF8,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x1F,
//         0xF8,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x1F,
//         0xF8,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x1F,
//         0xF8,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xC7,
//         0x0F,
//         0xF0,
//         0xE3,
//         0xFF,
//         0xFF,
//         0x83,
//         0x07,
//         0xE0,
//         0xC1,
//         0xFF,
//         0xFF,
//         0x01,
//         0x00,
//         0x00,
//         0x80,
//         0xFF,
//         0xFF,
//         0x01,
//         0x00,
//         0x00,
//         0x80,
//         0xFF,
//         0xFF,
//         0x01,
//         0x00,
//         0x00,
//         0x80,
//         0xFF,
//         0xFF,
//         0x03,
//         0x00,
//         0x00,
//         0xC0,
//         0xFF,
//         0xFF,
//         0x07,
//         0x00,
//         0x00,
//         0xE0,
//         0xFF,
//         0xFF,
//         0x07,
//         0xE0,
//         0x07,
//         0xE0,
//         0xFF,
//         0xFF,
//         0x07,
//         0xF8,
//         0x1F,
//         0xE0,
//         0xFF,
//         0xFF,
//         0x07,
//         0xFC,
//         0x3F,
//         0xE0,
//         0xFF,
//         0xFF,
//         0x03,
//         0xFE,
//         0x7F,
//         0xC0,
//         0xFF,
//         0xFF,
//         0x01,
//         0xFE,
//         0x7F,
//         0x80,
//         0xFF,
//         0x1F,
//         0x00,
//         0xFF,
//         0xFF,
//         0x00,
//         0xF8,
//         0x0F,
//         0x00,
//         0xFF,
//         0xFF,
//         0x00,
//         0xF0,
//         0x0F,
//         0x00,
//         0xFF,
//         0xFF,
//         0x00,
//         0xF0,
//         0x0F,
//         0x00,
//         0xFF,
//         0xFF,
//         0x00,
//         0xF0,
//         0x0F,
//         0x00,
//         0xFF,
//         0xFF,
//         0x00,
//         0xF0,
//         0x1F,
//         0x00,
//         0xFF,
//         0xFF,
//         0x00,
//         0xF8,
//         0xFF,
//         0x03,
//         0xFE,
//         0x7F,
//         0xC0,
//         0xFF,
//         0xFF,
//         0x03,
//         0xFE,
//         0x7F,
//         0xC0,
//         0xFF,
//         0xFF,
//         0x07,
//         0xFC,
//         0x3F,
//         0xE0,
//         0xFF,
//         0xFF,
//         0x07,
//         0xF8,
//         0x1F,
//         0xE0,
//         0xFF,
//         0xFF,
//         0x07,
//         0xE0,
//         0x07,
//         0xE0,
//         0xFF,
//         0xFF,
//         0x07,
//         0x00,
//         0x00,
//         0xE0,
//         0xFF,
//         0xFF,
//         0x03,
//         0x00,
//         0x00,
//         0xC0,
//         0xFF,
//         0xFF,
//         0x01,
//         0x00,
//         0x00,
//         0x80,
//         0xFF,
//         0xFF,
//         0x01,
//         0x00,
//         0x00,
//         0x80,
//         0xFF,
//         0xFF,
//         0x01,
//         0x00,
//         0x00,
//         0x80,
//         0xFF,
//         0xFF,
//         0x83,
//         0x07,
//         0xE0,
//         0xC1,
//         0xFF,
//         0xFF,
//         0xC7,
//         0x0F,
//         0xF0,
//         0xE3,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x1F,
//         0xF8,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x1F,
//         0xF8,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x1F,
//         0xF8,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x1F,
//         0xF8,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x3F,
//         0xFC,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFE,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x7F,
//         0xFE,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x7F,
//         0xF8,
//         0xFF,
//         0xFF,
//         0xFF,
//         0xFF,
//         0x1F,
//     },
// };

// // OLED变量
// #define DISP_H 128 // 屏幕高度
// #define DISP_W 128 // 屏幕宽度
// uint8_t *buf_ptr;  // 指向屏幕缓冲的指针
// uint16_t buf_len;  // 缓冲长度

// // UI变量
// #define UI_DEPTH 20  // 最深层级数
// #define UI_MNUMB 100 // 菜单数量
// #define UI_PARAM 16  // 参数数量

// enum
// {
//     DISP_BRI,  // 屏幕亮度
//     TILE_ANI,  // 磁贴动画速度
//     LIST_ANI,  // 列表动画速度
//     WIN_ANI,   // 弹窗动画速度
//     SPOT_ANI,  // 聚光动画速度
//     TAG_ANI,   // 标签动画速度
//     FADE_ANI,  // 消失动画速度
//     BTN_SPT,   // 按键短按时长
//     BTN_LPT,   // 按键长按时长
//     TILE_UFD,  // 磁贴图标从头展开开关
//     LIST_UFD,  // 菜单列表从头展开开关
//     TILE_LOOP, // 磁贴图标循环模式开关
//     LIST_LOOP, // 菜单列表循环模式开关
//     WIN_BOK,   // 弹窗背景虚化开关
//     KNOB_DIR,  // 旋钮方向切换开关
//     DARK_MODE, // 黑暗模式开关
// };

// // ui结构体，只存在一个ui
// struct
// {
//     bool init;
//     uint8_t num[UI_MNUMB];
//     uint8_t select[UI_DEPTH]; // ???
//     uint8_t layer;            // 当前层级
//     uint8_t index = M_SLEEP;  // 当前目录
//     uint8_t state = S_NONE; // 当前状态
//     bool sleep = true;
//     uint8_t fade = 1;
//     uint8_t param[UI_PARAM]; // ui的各种参数
// } ui;

// // 磁贴变量
// // 所有磁贴页面都使用同一套参数
// #define TILE_B_FONT u8g2_font_helvB24_tr      // 磁贴大标题字体
// #define TILE_S_FONT u8g2_font_HelvetiPixel_tr // 磁贴小标题字体
// #define TILE_B_TITLE_H 25                     // 磁贴大标题字体高度
// #define TILE_S_TITLE_H 8                      // 磁贴小标题字体高度
// #define TILE_ICON_H 48                        // 磁贴图标高度
// #define TILE_ICON_W 48                        // 磁贴图标宽度
// #define TILE_ICON_S 57                        // 磁贴图标间距
// #define TILE_INDI_H 40                        // 磁贴大标题指示器高度
// #define TILE_INDI_W 10                        // 磁贴大标题指示器宽度
// #define TILE_INDI_S 57                        // 磁贴大标题指示器上边距
// // 磁贴结构体
// struct
// {
//     float title_y_calc = TILE_INDI_S + (TILE_INDI_H - TILE_B_TITLE_H) / 2 + TILE_B_TITLE_H * 2;
//     float title_y_trg_calc = TILE_INDI_S + (TILE_INDI_H - TILE_B_TITLE_H) / 2 + TILE_B_TITLE_H;
//     int16_t temp;
//     bool select_flag;
//     float icon_x;
//     float icon_x_trg;
//     float icon_y;
//     float icon_y_trg;
//     float indi_x; // ???
//     float indi_x_trg;
//     float title_y;     // 标题的y目前位置
//     float title_y_trg; // 标题的y目标位置
// } tile;

// // 列表变量
// // 默认参数

// #define LIST_FONT u8g2_font_HelvetiPixel_tr // 列表字体
// #define LIST_TEXT_H 8                       // 列表每行文字字体的高度
// #define LIST_LINE_H 16                      // 列表单行高度
// #define LIST_TEXT_S 4                       // 列表每行文字的上边距，左边距和右边距，下边距由它和字体高度和行高度决定
// #define LIST_BAR_W 5                        // 列表进度条宽度，需要是奇数，因为正中间有1像素宽度的线
// #define LIST_BOX_R 0.5f                     // 列表选择框圆角

// struct
// {
//     uint8_t line_n = DISP_H / LIST_LINE_H;
//     int16_t temp;
//     bool loop;
//     float y;
//     float y_trg;
//     float box_x;
//     float box_x_trg;
//     float box_y;
//     float box_y_trg[UI_DEPTH];
//     float bar_y;
//     float bar_y_trg;
// } list;

// // 电压测量页面变量
// // 开发板模拟引脚
// uint8_t analog_pin[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
// // 曲线相关
// #define WAVE_SAMPLE 20    // 采集倍数
// #define WAVE_W DISP_W     // 波形宽度
// #define WAVE_L 0          // 波形左边距
// #define WAVE_U 0          // 波形上边距
// #define WAVE_MAX 43       // 最大值
// #define WAVE_MIN 5        // 最小值
// #define WAVE_BOX_H 49     // 波形边框高度
// #define WAVE_BOX_W DISP_W // 波形边框宽度
// // 列表和文字背景框相关
// #define VOLT_FONT u8g2_font_helvB24_tr // 电压数字字体
// #define VOLT_LIST_U_S 94               // 列表上边距
// #define VOLT_TEXT_BG_U_S 53            // 文字背景框上边距
// #define VOLT_TEXT_BG_H 33              // 文字背景框高度
// struct
// {
//     int ch0_adc[WAVE_SAMPLE * WAVE_W];
//     int ch0_wave[WAVE_W];
//     int val;
//     float text_bg_l;
//     float text_bg_l_trg;
// } volt;

// #define CHECK_BOX_L_S 95 // 选择框在每行的左边距
// #define CHECK_BOX_U_S 2  // 选择框在每行的上边距
// #define CHECK_BOX_F_W 12 // 选择框外框宽度
// #define CHECK_BOX_F_H 12 // 选择框外框高度
// #define CHECK_BOX_D_S 2  // 选择框里面的点距离外框的边距
// // 选择框
// struct
// {
//     uint8_t *v; // 单选
//     uint8_t *m; // 多选
//     uint8_t *s;
//     uint8_t *s_p;
// } check_box;

// // 弹窗变量
// #define WIN_FONT u8g2_font_HelvetiPixel_tr // 弹窗字体
// #define WIN_H 32                           // 弹窗高度
// #define WIN_W 102                          // 弹窗宽度
// #define WIN_BAR_W 92                       // 弹窗进度条宽度
// #define WIN_BAR_H 7                        // 弹窗进度条高度
// #define WIN_Y -WIN_H - 2                   // 弹窗竖直方向出场起始位置
// #define WIN_Y_TRG -WIN_H - 2               // 弹窗竖直方向退场终止位置

// // 弹窗结构体
// struct
// {
//     // uint8_t
//     uint8_t *value;
//     uint8_t max;
//     uint8_t min;
//     uint8_t step;

//     MENU *bg;
//     uint8_t index;
//     char title[20];
//     uint8_t select;
//     uint8_t l = (DISP_W - WIN_W) / 2;
//     uint8_t u = (DISP_H - WIN_H) / 2;
//     float bar;
//     float bar_trg;
//     float y;
//     float y_trg;
// } win;

// // 聚光灯变量
// struct
// {
//     float l;
//     float l_trg;
//     float r;
//     float r_trg;
//     float u;
//     float u_trg;
//     float d;
//     float d_trg;
// } spot;

// // 关于本机页变量
// #define ABOUT_FONT u8g2_font_HelvetiPixel_tr // 关于本机字体
// #define ABOUT_INDI_S 4                       // 关于本机页面列表指示左边距，也用于规范页面内元素之间的位置关系
// #define ABOUT_INDI_W 2                       // 关于本机页面列表指示器宽度
// struct
// {
//     float indi_x;
//     float indi_x_trg;
// } about;

// // 显示数值的初始化
// void check_box_v_init(uint8_t *param)
// {
//     check_box.v = param;
// }

// // 多选框的初始化
// void check_box_m_init(uint8_t *param)
// {
//     check_box.m = param;
// }

// // 单选框时的初始化
// void check_box_s_init(uint8_t *param, uint8_t *param_p)
// {
//     check_box.s = param;
//     check_box.s_p = param_p;
// }

// // 多选框处理函数
// void check_box_m_select(uint8_t param)
// {
//     check_box.m[param] = !check_box.m[param];
//     //   eeprom.change = true;
// }

// // 单选框处理函数
// void check_box_s_select(uint8_t val, uint8_t pos)
// {
//     *check_box.s = val;
//     *check_box.s_p = pos;
//     //   eeprom.change = true;
// }

// // 弹窗数值初始化
// void window_value_init(char title[], uint8_t select, uint8_t *value, uint8_t max, uint8_t min, uint8_t step, MENU *bg, uint8_t index)
// {
//     strcpy(win.title, title);
//     win.select = select;
//     win.value = value;
//     win.max = max;
//     win.min = min;
//     win.step = step;
//     win.bg = bg;
//     win.index = index;
//     ui.index = M_WINDOW;
//     ui.state = S_WINDOW;
// }

// // 在初始化EEPROM时，选择性初始化的默认设置
// void ui_param_init()
// {
//     ui.param[DISP_BRI] = 255; // 屏幕亮度
//     ui.param[TILE_ANI] = 30;  // 磁贴动画速度
//     ui.param[LIST_ANI] = 60;  // 列表动画速度
//     ui.param[WIN_ANI] = 25;   // 弹窗动画速度
//     ui.param[SPOT_ANI] = 50;  // 聚光动画速度
//     ui.param[TAG_ANI] = 60;   // 标签动画速度
//     ui.param[FADE_ANI] = 30;  // 消失动画速度
//     ui.param[BTN_SPT] = 25;   // 按键短按时长
//     ui.param[BTN_LPT] = 150;  // 按键长按时长
//     ui.param[TILE_UFD] = 1;   // 磁贴图标从头展开开关
//     ui.param[LIST_UFD] = 1;   // 菜单列表从头展开开关
//     ui.param[TILE_LOOP] = 0;  // 磁贴图标循环模式开关
//     ui.param[LIST_LOOP] = 0;  // 菜单列表循环模式开关
//     ui.param[WIN_BOK] = 0;    // 弹窗背景虚化开关
//     ui.param[KNOB_DIR] = 0;   // 旋钮方向切换开关
//     ui.param[DARK_MODE] = 1;  // 黑暗模式开关
// }

// // 列表类页面列表行数初始化，必须初始化的参数
// void ui_init()
// {
//     ui.num[M_MAIN] = sizeof(main_menu) / sizeof(M_SELECT);
//     ui.num[M_EDITOR] = sizeof(editor_menu) / sizeof(M_SELECT);
//     ui.num[M_KNOB] = sizeof(knob_menu) / sizeof(M_SELECT);
//     ui.num[M_KRF] = sizeof(krf_menu) / sizeof(M_SELECT);
//     ui.num[M_KPF] = sizeof(kpf_menu) / sizeof(M_SELECT);
//     ui.num[M_VOLT] = sizeof(volt_menu) / sizeof(M_SELECT);
//     ui.num[M_SETTING] = sizeof(setting_menu) / sizeof(M_SELECT);
//     ui.num[M_ABOUT] = sizeof(about_menu) / sizeof(M_SELECT);
// }

// // 进入磁贴类时的初始化
// void tile_param_init()
// {
//     ui.init = false;
//     tile.icon_x = 0;
//     tile.icon_x_trg = TILE_ICON_S;
//     tile.icon_y = -TILE_ICON_H;
//     tile.icon_y_trg = 0;
//     tile.indi_x = 0;
//     tile.indi_x_trg = TILE_INDI_W;
//     tile.title_y = tile.title_y_calc;
//     tile.title_y_trg = tile.title_y_trg_calc;
// }

// /********************************** 自定义功能变量 **********************************/

// // 旋钮功能变量
// #define KNOB_PARAM 4
// #define KNOB_DISABLE 0
// #define KNOB_ROT_VOL 1
// #define KNOB_ROT_BRI 2
// enum
// {
//     KNOB_ROT,   // 睡眠下旋转旋钮的功能，0 禁用，1 音量，2 亮度
//     KNOB_COD,   // 睡眠下短按旋钮输入的字符码，0 禁用
//     KNOB_ROT_P, // 旋转旋钮功能在单选框中选择的位置
//     KNOB_COD_P, // 字符码在单选框中选择的位置
// };
// struct
// {
//     uint8_t param[KNOB_PARAM] = {KNOB_DISABLE, KNOB_DISABLE, 2, 2}; // 禁用在列表的第2个选项，第0个是标题，第1个是分界线
// } knob;

// // 旋钮设置页初始化
// void knob_param_init() { check_box_v_init(&knob.param[0]); }

// // 旋钮旋转页初始化
// void krf_param_init() { check_box_s_init(&knob.param[KNOB_ROT], &knob.param[KNOB_ROT_P]); }

// // 旋钮点按页初始化
// void kpf_param_init() { check_box_s_init(&knob.param[KNOB_COD], &knob.param[KNOB_COD_P]); }

// // 电压测量页初始化
// void volt_param_init()
// {
//     volt.text_bg_l = 0;
//     volt.text_bg_l_trg = DISP_W;
// }

// // 设置页初始化
// void setting_param_init()
// {
//     check_box_v_init(ui.param);
//     check_box_m_init(ui.param);
// }

// // 关于本机页初始化
// void about_param_init()
// {
//     about.indi_x = 0;
//     about.indi_x_trg = ABOUT_INDI_S;
// }

// // 弹窗动画初始化
// void window_param_init()
// {
//     win.bar = 0;
//     win.y = WIN_Y;
//     win.y_trg = win.u;
//     ui.state = S_NONE;
// }

// // 进入更深层级时的初始化，层级++，初始化取消，列表归零，变为转场状态
// void layer_init_in()
// {
//     ui.layer++;
//     ui.init = 0;
//     list.y = 0;
//     list.y_trg = LIST_LINE_H;
//     list.box_x = 0;
//     list.box_y = 0;
//     list.bar_y = 0;
//     ui.state = S_FADE;
//     switch (ui.index)
//     {
//     case M_MAIN:
//         tile_param_init();
//         break; // 睡眠进入主菜单，动画初始化
//     case M_KNOB:
//         knob_param_init();
//         break; // 旋钮设置页，行末尾文字初始化
//     case M_KRF:
//         krf_param_init();
//         break; // 旋钮旋转页，单选框初始化
//     case M_KPF:
//         kpf_param_init();
//         break; // 旋钮点按页，单选框初始化
//     case M_VOLT:
//         volt_param_init();
//         break; // 主菜单进入电压测量页，动画初始化
//     case M_SETTING:
//         setting_param_init();
//         break; // 主菜单进入设置页，单选框初始化
//     case M_ABOUT:
//         about_param_init();
//         break; // 设置页进入关于本机页，动画初始化
//     }
// }
// // 进入睡眠时的初始化
// void sleep_param_init()
// {
//     u8g2.setDrawColor(0);
//     u8g2.drawBox(0, 0, DISP_W, DISP_H);
//     u8g2.setPowerSave(1);
//     ui.state = S_NONE;
//     ui.sleep = true;
//     //   if (eeprom.change)
//     //   {
//     //     eeprom_write_all_data();
//     //     eeprom.change = false;
//     //   }
// }
// // 进入更浅层级时的初始化
// void layer_init_out()
// {
//     ui.select[ui.layer] = 0;
//     list.box_y_trg[ui.layer] = 0;
//     ui.layer--;
//     ui.init = 0;
//     list.y = 0;
//     list.y_trg = LIST_LINE_H;
//     list.bar_y = 0;
//     ui.state = S_FADE;
//     switch (ui.index)
//     {
//     case M_SLEEP:
//         sleep_param_init();
//         break; // 主菜单进入睡眠页，检查是否需要写EEPROM
//     case M_MAIN:
//         tile_param_init();
//         break; // 不管什么页面进入主菜单时，动画初始化
//     }
// }

// // 动画函数
// void animation(float *a, float *a_trg, uint8_t n)
// {
//     if (*a != *a_trg)
//     {
//         if (fabs(*a - *a_trg) < 0.15f)
//             *a = *a_trg;
//         else
//             *a += (*a_trg - *a) / (ui.param[n] / 10.0f);
//     }
// }

// // 消失函数
// void fade()
// {
//     delay(ui.param[FADE_ANI]);
//     if (ui.param[DARK_MODE])
//     {
//         switch (ui.fade)
//         {
//         case 1:
//             for (uint16_t i = 0; i < buf_len; ++i)
//                 if (i % 2 != 0)
//                     buf_ptr[i] = buf_ptr[i] & 0xAA;
//             break;
//         case 2:
//             for (uint16_t i = 0; i < buf_len; ++i)
//                 if (i % 2 != 0)
//                     buf_ptr[i] = buf_ptr[i] & 0x00;
//             break;
//         case 3:
//             for (uint16_t i = 0; i < buf_len; ++i)
//                 if (i % 2 == 0)
//                     buf_ptr[i] = buf_ptr[i] & 0x55;
//             break;
//         case 4:
//             for (uint16_t i = 0; i < buf_len; ++i)
//                 if (i % 2 == 0)
//                     buf_ptr[i] = buf_ptr[i] & 0x00;
//             break;
//         default:
//             ui.state = S_NONE;
//             ui.fade = 0;
//             break;
//         }
//     }
//     else
//     {
//         switch (ui.fade)
//         {
//         case 1:
//             for (uint16_t i = 0; i < buf_len; ++i)
//                 if (i % 2 != 0)
//                     buf_ptr[i] = buf_ptr[i] | 0xAA;
//             break;
//         case 2:
//             for (uint16_t i = 0; i < buf_len; ++i)
//                 if (i % 2 != 0)
//                     buf_ptr[i] = buf_ptr[i] | 0x00;
//             break;
//         case 3:
//             for (uint16_t i = 0; i < buf_len; ++i)
//                 if (i % 2 == 0)
//                     buf_ptr[i] = buf_ptr[i] | 0x55;
//             break;
//         case 4:
//             for (uint16_t i = 0; i < buf_len; ++i)
//                 if (i % 2 == 0)
//                     buf_ptr[i] = buf_ptr[i] | 0x00;
//             break;
//         default:
//             ui.state = S_NONE;
//             ui.fade = 0;
//             break;
//         }
//     }
//     ui.fade++;
// }

// // 磁贴类页面通用显示函数，输入主标题，副标题，图片
// void tile_show(struct MENU arr_1[], struct MENU arr_2[], const uint8_t icon_pic[][16 * 18])
// {
//     // 计算动画过渡值，不断计算磁贴的位置
//     animation(&tile.icon_x, &tile.icon_x_trg, TILE_ANI);
//     animation(&tile.icon_y, &tile.icon_y_trg, TILE_ANI);
//     animation(&tile.indi_x, &tile.indi_x_trg, TILE_ANI);
//     animation(&tile.title_y, &tile.title_y_trg, TILE_ANI);

//     // 设置大小标题的颜色和文字方向，0透显，1实显，2反色，这里都用实显
//     u8g2.setDrawColor(1);
//     u8g2.setFontDirection(0);

//     // 绘制大标题
//     u8g2.setFont(TILE_B_FONT);
//     u8g2.drawStr(((DISP_W - TILE_INDI_W) - u8g2.getStrWidth(arr_1[ui.select[ui.layer]].m_select)) / 2 + TILE_INDI_W, tile.title_y, arr_1[ui.select[ui.layer]].m_select);

//     // 绘制小标题
//     u8g2.setFont(TILE_S_FONT);
//     u8g2.drawStr(((DISP_W - u8g2.getStrWidth(arr_2[ui.select[ui.layer]].m_select)) / 2), 0.5 * (TILE_ICON_S + TILE_INDI_H + DISP_H + LIST_TEXT_H), arr_2[ui.select[ui.layer]].m_select);

//     // 绘制大标题指示器
//     u8g2.drawBox(0, TILE_ICON_S, tile.indi_x, TILE_INDI_H);

//     // 绘制图标
//     if (!ui.init)
//     {
//         for (uint8_t i = 0; i < ui.num[ui.index]; ++i)
//         {
//             if (ui.param[TILE_UFD])
//                 tile.temp = (DISP_W - TILE_ICON_W) / 2 + i * tile.icon_x - TILE_ICON_S * ui.select[ui.layer];
//             else
//                 tile.temp = (DISP_W - TILE_ICON_W) / 2 + (i - ui.select[ui.layer]) * tile.icon_x;
//             u8g2.drawXBMP(tile.temp, (int16_t)tile.icon_y, TILE_ICON_W, TILE_ICON_H, icon_pic[i]);
//         }
//         if (tile.icon_x == tile.icon_x_trg)
//         {
//             ui.init = true;
//             tile.icon_x = tile.icon_x_trg = -ui.select[ui.layer] * TILE_ICON_S;
//         }
//     }
//     else
//         for (uint8_t i = 0; i < ui.num[ui.index]; ++i)
//             u8g2.drawXBMP((DISP_W - TILE_ICON_W) / 2 + (int16_t)tile.icon_x + i * TILE_ICON_S, 0, TILE_ICON_W, TILE_ICON_H, icon_pic[i]);

//     // 反转屏幕内元素颜色，白天模式遮罩
//     u8g2.setDrawColor(2);
//     if (!ui.param[DARK_MODE])
//         u8g2.drawBox(0, 0, DISP_W, DISP_H);
// }

// // 列表显示数值
// void list_draw_value(int n) { u8g2.print(check_box.v[n - 1]); }
// // 绘制外框，给单选和多选画选择框
// void list_draw_check_box_frame() { u8g2.drawRFrame(CHECK_BOX_L_S, list.temp + CHECK_BOX_U_S, CHECK_BOX_F_W, CHECK_BOX_F_H, 1); }
// // 绘制框里面的点,在框里画box
// void list_draw_check_box_dot() { u8g2.drawBox(CHECK_BOX_L_S + CHECK_BOX_D_S + 1, list.temp + CHECK_BOX_U_S + CHECK_BOX_D_S + 1, CHECK_BOX_F_W - (CHECK_BOX_D_S + 1) * 2, CHECK_BOX_F_H - (CHECK_BOX_D_S + 1) * 2); }

// // 列表显示旋钮功能
// void list_draw_krf(int n)
// {
//     switch (check_box.v[n - 1])
//     {
//     case 0:
//         u8g2.print("OFF");
//         break;
//     case 1:
//         u8g2.print("VOL");
//         break;
//     case 2:
//         u8g2.print("BRI");
//         break;
//     }
// }

// // 列表显示按键键值
// void list_draw_kpf(int n)
// {
//     if (check_box.v[n - 1] == 0)
//         u8g2.print("OFF");
//     else if (check_box.v[n - 1] <= 90)
//         u8g2.print((char)check_box.v[n - 1]);
//     else
//         u8g2.print("?");
// }

// // 判断列表尾部内容，从字符串开头判断
// void list_draw_text_and_check_box(struct MENU arr[], int i)
// {
//     u8g2.drawStr(LIST_TEXT_S, list.temp + LIST_TEXT_H + LIST_TEXT_S, arr[i].m_select);
//     u8g2.setCursor(CHECK_BOX_L_S, list.temp + LIST_TEXT_H + LIST_TEXT_S);
//     switch (arr[i].m_select[0])
//     {
//     case '~':
//         list_draw_value(i);
//         break;
//     case '+':
//         list_draw_check_box_frame();
//         if (check_box.m[i - 1] == 1)
//             list_draw_check_box_dot();
//         break;
//     case '=':
//         list_draw_check_box_frame();
//         if (*check_box.s_p == i)
//             list_draw_check_box_dot();
//         break;
//     case '#':
//         list_draw_krf(i);
//         break;
//     case '$':
//         list_draw_kpf(i);
//         break;
//     }
// }

// // 列表类页面通用显示函数
// void list_show(struct MENU arr[], uint8_t ui_index)
// {
//     // 更新动画目标值
//     u8g2.setFont(LIST_FONT);
//     list.box_x_trg = u8g2.getStrWidth(arr[ui.select[ui.layer]].m_select) + LIST_TEXT_S * 2;
//     list.bar_y_trg = ceil((ui.select[ui.layer]) * ((float)DISP_H / (ui.num[ui_index] - 1)));

//     // 计算动画过渡值
//     animation(&list.y, &list.y_trg, LIST_ANI);
//     animation(&list.box_x, &list.box_x_trg, LIST_ANI);
//     animation(&list.box_y, &list.box_y_trg[ui.layer], LIST_ANI);
//     animation(&list.bar_y, &list.bar_y_trg, LIST_ANI);

//     // 检查循环动画是否结束
//     if (list.loop && list.box_y == list.box_y_trg[ui.layer])
//         list.loop = false;

//     // 设置文字和进度条颜色，0透显，1实显，2反色，这里都用实显
//     u8g2.setDrawColor(1);

//     // 绘制进度条
//     u8g2.drawHLine(DISP_W - LIST_BAR_W, 0, LIST_BAR_W);
//     u8g2.drawHLine(DISP_W - LIST_BAR_W, DISP_H - 1, LIST_BAR_W);
//     u8g2.drawVLine(DISP_W - ceil((float)LIST_BAR_W / 2), 0, DISP_H);
//     u8g2.drawBox(DISP_W - LIST_BAR_W, 0, LIST_BAR_W, list.bar_y);

//     // 绘制列表文字
//     if (!ui.init)
//     {
//         for (int i = 0; i < ui.num[ui_index]; ++i)
//         {
//             if (ui.param[LIST_UFD])
//                 list.temp = i * list.y - LIST_LINE_H * ui.select[ui.layer] + list.box_y_trg[ui.layer];
//             else
//                 list.temp = (i - ui.select[ui.layer]) * list.y + list.box_y_trg[ui.layer];
//             list_draw_text_and_check_box(arr, i);
//         }
//         if (list.y == list.y_trg)
//         {
//             ui.init = true;
//             list.y = list.y_trg = -LIST_LINE_H * ui.select[ui.layer] + list.box_y_trg[ui.layer];
//         }
//     }
//     else
//         for (int i = 0; i < ui.num[ui_index]; ++i)
//         {
//             list.temp = LIST_LINE_H * i + list.y;
//             list_draw_text_and_check_box(arr, i);
//         }

//     // 绘制文字选择框，0透显，1实显，2反色，这里用反色
//     u8g2.setDrawColor(2);
//     u8g2.drawRBox(0, list.box_y, list.box_x, LIST_LINE_H, LIST_BOX_R);

//     // 反转屏幕内元素颜色，白天模式遮罩，在这里屏蔽有列表参与的页面，使遮罩作用在那个页面上
//     if (!ui.param[DARK_MODE])
//     {
//         u8g2.drawBox(0, 0, DISP_W, DISP_H);
//         switch (ui.index)
//         {
//         case M_WINDOW:
//         case M_VOLT:
//             u8g2.drawBox(0, 0, DISP_W, DISP_H);
//         }
//     }
// }

// // 电压页面显示函数
// void volt_show()
// {
//     // 更新动画目标值
//     u8g2.setFont(LIST_FONT);
//     list.box_x_trg = u8g2.getStrWidth(volt_menu[ui.select[ui.layer]].m_select) + LIST_TEXT_S * 2;

//     // 计算动画过渡值
//     animation(&list.y, &list.y_trg, LIST_ANI);
//     animation(&list.box_x, &list.box_x_trg, LIST_ANI);
//     animation(&list.box_y, &list.box_y_trg[ui.layer], LIST_ANI);
//     animation(&volt.text_bg_l, &volt.text_bg_l_trg, TAG_ANI);

//     // 检查循环动画是否结束
//     if (list.loop && list.box_y == list.box_y_trg[ui.layer])
//         list.loop = false;

//     // 设置文字和曲线颜色，0透显，1实显，2反色，这里都用实显
//     u8g2.setDrawColor(1);

//     // 绘制列表文字
//     u8g2.setFontDirection(1);
//     if (!ui.init)
//     {
//         for (uint8_t i = 0; i < ui.num[ui.index]; ++i)
//             u8g2.drawStr(LIST_TEXT_S + (i - ui.select[ui.layer]) * list.y + list.box_y_trg[ui.layer] - 1, VOLT_LIST_U_S, volt_menu[i].m_select);
//         if (list.y == list.y_trg)
//         {
//             ui.init = true;
//             list.y = list.y_trg = -LIST_LINE_H * ui.select[ui.layer] + list.box_y_trg[ui.layer];
//         }
//     }
//     else
//         for (uint8_t i = 0; i < ui.num[ui.index]; ++i)
//             u8g2.drawStr(LIST_TEXT_S + LIST_LINE_H * i + (int16_t)list.y - 1, VOLT_LIST_U_S, volt_menu[i].m_select);

//     // 绘制电压曲线和外框
//     volt.val = 0;
//     u8g2.drawFrame(0, 0, WAVE_BOX_W, WAVE_BOX_H);
//     u8g2.drawFrame(1, 1, WAVE_BOX_W - 2, WAVE_BOX_H - 2);
//     if (list.box_y == list.box_y_trg[ui.layer] && list.y == list.y_trg)
//     {
//         for (int i = 0; i < WAVE_SAMPLE * WAVE_W; i++)
//             volt.ch0_adc[i] = volt.val = analogRead(analog_pin[ui.select[ui.layer]]);
//         for (int i = 1; i < WAVE_W - 1; i++)
//         {
//             volt.ch0_wave[i] = map(volt.ch0_adc[int(5 * i)], 0, 4095, WAVE_MAX, WAVE_MIN);
//             u8g2.drawLine(WAVE_L + i - 1, WAVE_U + volt.ch0_wave[i - 1], WAVE_L + i, WAVE_U + volt.ch0_wave[i]);
//         }
//     }

//     // 绘制电压值
//     u8g2.setFontDirection(0);
//     u8g2.setFont(VOLT_FONT);
//     u8g2.setCursor(23, VOLT_LIST_U_S - 12);
//     u8g2.print(volt.val / 4096.0f * 3.3f);
//     u8g2.print("V");

//     // 绘制列表选择框和电压文字背景
//     u8g2.setDrawColor(2);
//     u8g2.drawRBox(list.box_y, VOLT_LIST_U_S - LIST_TEXT_S, LIST_LINE_H, list.box_x, LIST_BOX_R);
//     u8g2.drawBox(DISP_W - volt.text_bg_l, VOLT_TEXT_BG_U_S, DISP_W, VOLT_TEXT_BG_H);

//     // 反转屏幕内元素颜色，白天模式遮罩
//     if (!ui.param[DARK_MODE])
//         u8g2.drawBox(0, 0, DISP_W, DISP_H);
// }

// // 弹窗通用显示函数
// void window_show()
// {
//     // 绘制背景列表，根据开关判断背景是否要虚化
//     list_show(win.bg, win.index);
//     if (ui.param[WIN_BOK])
//         for (uint16_t i = 0; i < buf_len; ++i)
//             buf_ptr[i] = buf_ptr[i] & (i % 2 == 0 ? 0x55 : 0xAA);

//     // 更新动画目标值
//     u8g2.setFont(WIN_FONT);
//     win.bar_trg = (float)(*win.value - win.min) / (float)(win.max - win.min) * (WIN_BAR_W - 4);

//     // 计算动画过渡值
//     animation(&win.bar, &win.bar_trg, WIN_ANI);
//     animation(&win.y, &win.y_trg, WIN_ANI);

//     // 绘制窗口
//     u8g2.setDrawColor(0);
//     u8g2.drawRBox(win.l, (int16_t)win.y, WIN_W, WIN_H, 2); // 绘制外框背景
//     u8g2.setDrawColor(1);
//     u8g2.drawRFrame(win.l, (int16_t)win.y, WIN_W, WIN_H, 2);                  // 绘制外框描边
//     u8g2.drawRFrame(win.l + 5, (int16_t)win.y + 20, WIN_BAR_W, WIN_BAR_H, 1); // 绘制进度条外框
//     u8g2.drawBox(win.l + 7, (int16_t)win.y + 22, win.bar, WIN_BAR_H - 4);     // 绘制进度条
//     u8g2.setCursor(win.l + 5, (int16_t)win.y + 14);
//     u8g2.print(win.title); // 绘制标题
//     u8g2.setCursor(win.l + 78, (int16_t)win.y + 14);
//     u8g2.print(*win.value); // 绘制当前值

//     // 需要在窗口修改参数时立即见效的函数
//     if (!strcmp(win.title, "Disp Bri"))
//         u8g2.setContrast(ui.param[DISP_BRI]);

//     // 反转屏幕内元素颜色，白天模式遮罩
//     u8g2.setDrawColor(2);
//     if (!ui.param[DARK_MODE])
//         u8g2.drawBox(0, 0, DISP_W, DISP_H);
// }

// // // 主菜单处理函数，磁贴类模板
// // void main_proc()
// // {
// // /*
// // 1、初始化磁贴




// // */

// //   tile_show(main_menu, main_menu_exp, main_icon_pic);
// //   if (btn.pressed)
// //   {
// //     btn.pressed = false;
// //     switch (btn.id)
// //     {
// //     case BTN_ID_CW:
// //     case BTN_ID_CC:
// //       tile_rotate_switch();
// //       break;
// //     case BTN_ID_SP:
// //       switch (ui.select[ui.layer])
// //       {

// //       case 0:
// //         ui.index = M_SLEEP;
// //         ui.state = S_LAYER_OUT;
// //         break;
// //       case 1:
// //         ui.index = M_EDITOR;
// //         ui.state = S_LAYER_IN;
// //         break;
// //       case 2:
// //         ui.index = M_VOLT;
// //         ui.state = S_LAYER_IN;
// //         break;
// //       case 3:
// //         ui.index = M_SETTING;
// //         ui.state = S_LAYER_IN;
// //         break;
// //       }
// //     }
// //     if (!tile.select_flag && ui.init)
// //     {
// //       tile.indi_x = 0;
// //       tile.title_y = tile.title_y_calc;
// //     }
// //   }
// // }

// // 总的UI进程
// void ui_proc()
// {
//     u8g2.sendBuffer();
//     ui.state = S_LAYER_IN;
//     switch (ui.state)
//     {
//     case S_FADE:
//         fade();
//         break; // 转场动画
//     case S_WINDOW:
//         window_param_init();
//         break; // 弹窗初始化
//     case S_LAYER_IN:
//         layer_init_in();
//         break; // 层级初始化
//     case S_LAYER_OUT:
//         layer_init_out();
//         break; // 层级初始化

//     case S_NONE:
//         u8g2.clearBuffer();
//         switch (ui.index) // 直接选择页面
//         {
//             // case M_WINDOW:
//             //   window_proc();
//             //   break;
//             // case M_SLEEP:
//             //   sleep_proc();
//             //   break;
//             // case M_MAIN:
//             //   main_proc();
//             //   break;
//             // case M_EDITOR:
//             //   editor_proc();
//             //   break;
//             // case M_KNOB:
//             //   knob_proc();
//             //   break;
//             // case M_KRF:
//             //   krf_proc();
//             //   break;
//             // case M_KPF:
//             //   kpf_proc();
//             //   break;
//             // case M_VOLT:
//             //   volt_proc();
//             //   break;
//             // case M_SETTING:
//             //   setting_proc();
//             //   break;
//             // case M_ABOUT:
//             //   about_proc();
//             //   break;
//         }
//     }
// }

// // OLED初始化函数
// void oled_init()
// {
//     u8g2.setBusClock(10000000); // 硬件SPI接口使用
//     u8g2.begin();
//     u8g2.setContrast(ui.param[DISP_BRI]); // 最大亮度
//     buf_ptr = u8g2.getBufferPtr();
//     buf_len = 8 * u8g2.getBufferTileHeight() * u8g2.getBufferTileWidth();
//     // 打印看看
// }

// void setup()
// {
//     //   eeprom_init();
//     ui_init();
//     oled_init();
//     //   btn_init();
//     //   // hid_init();
// }

// void loop()
// {
//     ui_proc();
// }

// #include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>

// #define ESP32 0
// #define MEGA2560 1

// #define MCU 1

#define SPEED 4 // 16的因数
#define ICON_SPEED 12
#define ICON_SPACE 48 // 图标间隔，speed倍数

//  #define READ A0
//  #define BTN0 5
//  #define BTN1 6
//  #define BTN2 7
#define READ 1
#define BTN0 4
#define BTN1 5
#define BTN2 19

void chart_draw_frame();

// U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* clock=*/22, /* data=*/21); // ESP32 Thing, pure SW emulated I2C
// U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, 22, 21);

// 使用硬件SPI（VSPI默认引脚：SCLK=18, MOSI=23）
U8G2_SH1107_SEEED_128X128_F_4W_HW_SPI u8g2(
    U8G2_R0,
    /* CS=*/12,  // 自定义CS引脚
    /* DC=*/14,  // 自定义DC引脚
    /* RESET=*/2 // 自定义RESET引脚
);


PROGMEM const uint8_t icon_pic[][200]{
    {
        0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x3E,
        0x00, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x00,
        0x00, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x00,
        0x00, 0x00, 0x00, 0x7F, 0x00, 0x00, 0x00, 0x00,
        0x7F, 0x00, 0x00, 0x00, 0x80, 0x7F, 0x00, 0x00,
        0x00, 0x80, 0x7F, 0x00, 0x00, 0x00, 0xC0, 0x7F,
        0x00, 0x00, 0x00, 0xE0, 0x7F, 0x00, 0x00, 0x00,
        0xF8, 0x7F, 0x00, 0x00, 0xF0, 0xF8, 0xFF, 0xFF,
        0x01, 0xFC, 0xF8, 0xFF, 0xFF, 0x07, 0xFC, 0xF8,
        0xFF, 0xFF, 0x07, 0xFE, 0xF8, 0xFF, 0xFF, 0x07,
        0xFE, 0xF8, 0xFF, 0xFF, 0x07, 0xFE, 0xF8, 0xFF,
        0xFF, 0x07, 0xFE, 0xF8, 0xFF, 0xFF, 0x07, 0xFE,
        0xF8, 0xFF, 0xFF, 0x07, 0xFE, 0xF8, 0xFF, 0xFF,
        0x03, 0xFE, 0xF8, 0xFF, 0xFF, 0x03, 0xFE, 0xF8,
        0xFF, 0xFF, 0x03, 0xFE, 0xF8, 0xFF, 0xFF, 0x03,
        0xFE, 0xF8, 0xFF, 0xFF, 0x01, 0xFE, 0xF8, 0xFF,
        0xFF, 0x01, 0xFE, 0xF8, 0xFF, 0xFF, 0x01, 0xFE,
        0xF8, 0xFF, 0xFF, 0x01, 0xFE, 0xF8, 0xFF, 0xFF,
        0x00, 0xFE, 0xF8, 0xFF, 0xFF, 0x00, 0xFC, 0xF8,
        0xFF, 0x7F, 0x00, 0xFC, 0xF8, 0xFF, 0x3F, 0x00,
        0xF8, 0xF8, 0xFF, 0x1F, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 /*"C:\Users\ROG\Desktop\三连\点赞.bmp",0*/
                                                 /* (36 X 35 )*/
    },
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00,
        0x00, 0x1F, 0x00, 0x00, 0x00, 0x80, 0x1F, 0x00,
        0x00, 0x00, 0x80, 0x3F, 0x00, 0x00, 0x00, 0xC0,
        0x3F, 0x00, 0x00, 0x00, 0xC0, 0x3F, 0x00, 0x00,
        0x00, 0xC0, 0x7F, 0x00, 0x00, 0x00, 0xE0, 0xFF,
        0x00, 0x00, 0x00, 0xF0, 0xFF, 0x01, 0x00, 0x00,
        0xFC, 0xFF, 0x03, 0x00, 0xE0, 0xFF, 0xFF, 0xFF,
        0x00, 0xFC, 0xFF, 0xFF, 0xFF, 0x07, 0xFE, 0xFF,
        0xFF, 0xFF, 0x07, 0xFC, 0xFF, 0xFF, 0xFF, 0x07,
        0xFC, 0xFF, 0xFF, 0xFF, 0x03, 0xF8, 0xFF, 0xFF,
        0xFF, 0x01, 0xF0, 0xFF, 0xFF, 0xFF, 0x00, 0xE0,
        0xFF, 0xFF, 0x7F, 0x00, 0xC0, 0xFF, 0xFF, 0x3F,
        0x00, 0x80, 0xFF, 0xFF, 0x3F, 0x00, 0x00, 0xFF,
        0xFF, 0x1F, 0x00, 0x00, 0xFF, 0xFF, 0x1F, 0x00,
        0x00, 0xFF, 0xFF, 0x0F, 0x00, 0x00, 0xFF, 0xFF,
        0x0F, 0x00, 0x00, 0xFF, 0xFF, 0x0F, 0x00, 0x00,
        0xFF, 0xFF, 0x0F, 0x00, 0x00, 0xFF, 0xFF, 0x0F,
        0x00, 0x00, 0xFF, 0xFF, 0x1F, 0x00, 0x00, 0xFF,
        0xFF, 0x1F, 0x00, 0x80, 0xFF, 0xF0, 0x1F, 0x00,
        0x80, 0x3F, 0xC0, 0x1F, 0x00, 0x80, 0x1F, 0x00,
        0x1F, 0x00, 0x00, 0x07, 0x00, 0x1C, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00 /*"C:\Users\ROG\Desktop\三连\收藏.bmp",0*/
             /* (36 X 37 )*/
    },
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x1F,
        0x00, 0x00, 0x00, 0xF0, 0xFF, 0x01, 0x00, 0x00,
        0xFC, 0xFF, 0x07, 0x00, 0x00, 0xFF, 0xFF, 0x0F,
        0x00, 0x80, 0xFF, 0xFF, 0x1F, 0x00, 0xC0, 0xFF,
        0xFF, 0x7F, 0x00, 0xE0, 0x07, 0x00, 0x7C, 0x00,
        0xF0, 0x03, 0x00, 0xFC, 0x00, 0xF0, 0x03, 0x00,
        0xFC, 0x01, 0xF8, 0xFF, 0xF1, 0xFF, 0x01, 0xF8,
        0xFF, 0xF1, 0xFF, 0x03, 0xF8, 0x7F, 0xC0, 0xFF,
        0x03, 0xFC, 0x1F, 0x00, 0xFF, 0x03, 0xFC, 0x07,
        0x00, 0xFE, 0x07, 0xFC, 0x07, 0x01, 0xFC, 0x07,
        0xFC, 0xC3, 0x31, 0xF8, 0x07, 0xFC, 0xE1, 0xF1,
        0xF8, 0x07, 0xFC, 0xF1, 0xF1, 0xF0, 0x07, 0xFC,
        0xF1, 0xF1, 0xF0, 0x07, 0xFC, 0xF1, 0xF1, 0xF1,
        0x07, 0xFC, 0xF1, 0xF1, 0xF1, 0x07, 0xFC, 0xF1,
        0xF1, 0xF1, 0x03, 0xF8, 0xF1, 0xF1, 0xF1, 0x03,
        0xF8, 0xFF, 0xF1, 0xFF, 0x03, 0xF8, 0xFF, 0xF1,
        0xFF, 0x01, 0xF0, 0xFF, 0xF1, 0xFF, 0x01, 0xF0,
        0xFF, 0xF1, 0xFF, 0x00, 0xE0, 0xFF, 0xF1, 0x7F,
        0x00, 0xC0, 0xFF, 0xFF, 0x7F, 0x00, 0x80, 0xFF,
        0xFF, 0x3F, 0x00, 0x00, 0xFF, 0xFF, 0x0F, 0x00,
        0x00, 0xFC, 0xFF, 0x07, 0x00, 0x00, 0xF0, 0xFF,
        0x01, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00 /*"C:\Users\ROG\Desktop\三连\投币.bmp",0*/
                               /* (36 X 36 )*/
    },
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x00,
        0x00, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x00,
        0xFC, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x01, 0x00,
        0x00, 0x00, 0xFC, 0x03, 0x00, 0x00, 0x00, 0xFC,
        0x07, 0x00, 0x00, 0x00, 0xFC, 0x0F, 0x00, 0x00,
        0x00, 0xFE, 0x1F, 0x00, 0x00, 0xF8, 0xFF, 0x3F,
        0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0xC0, 0xFF,
        0xFF, 0xFF, 0x01, 0xE0, 0xFF, 0xFF, 0xFF, 0x03,
        0xF0, 0xFF, 0xFF, 0xFF, 0x07, 0xF0, 0xFF, 0xFF,
        0xFF, 0x0F, 0xF8, 0xFF, 0xFF, 0xFF, 0x0F, 0xFC,
        0xFF, 0xFF, 0xFF, 0x07, 0xFC, 0xFF, 0xFF, 0xFF,
        0x03, 0xFE, 0xFF, 0xFF, 0xFF, 0x01, 0xFE, 0xFF,
        0xFF, 0xFF, 0x00, 0xFF, 0x03, 0xFE, 0x3F, 0x00,
        0xFF, 0x00, 0xFC, 0x1F, 0x00, 0x3F, 0x00, 0xFC,
        0x0F, 0x00, 0x1F, 0x00, 0xFC, 0x07, 0x00, 0x07,
        0x00, 0xFC, 0x03, 0x00, 0x03, 0x00, 0xFC, 0x01,
        0x00, 0x01, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00,
        0x3C, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00,
        0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, /*"C:\Users\13944\Desktop\fenxiang.bmp",0*/
    },
};

uint8_t icon_width[] = {35, 37, 36, 36};

// main界面图片
PROGMEM const uint8_t LOGO[] =
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x10, 0x01, 0x24, 0x00, 0x44, 0x04, 0x80, 0x20, 0x00, 0x00, 0x10, 0xF2, 0x3C, 0x20, 0xE0, 0x00,
        0x10, 0x01, 0x24, 0x00, 0xC4, 0x04, 0x80, 0x20, 0x00, 0x00, 0x10, 0x11, 0x24, 0x30, 0x10, 0x01,
        0x10, 0x71, 0x24, 0x0F, 0xC4, 0xE2, 0x99, 0x3C, 0x00, 0x00, 0x20, 0x11, 0x24, 0x20, 0x10, 0x01,
        0xF0, 0x89, 0xA4, 0x10, 0xA8, 0x12, 0x8A, 0x22, 0x00, 0x00, 0x20, 0xF1, 0x1C, 0x20, 0x10, 0x01,
        0x10, 0xF9, 0xA4, 0x10, 0x98, 0x13, 0x8A, 0x22, 0x00, 0x00, 0xA0, 0x10, 0x24, 0x20, 0x10, 0x01,
        0x10, 0x09, 0xA4, 0x10, 0x98, 0x11, 0x8A, 0x22, 0x00, 0x00, 0xA0, 0x10, 0x24, 0x20, 0x10, 0x01,
        0x10, 0xF1, 0x24, 0x0F, 0x10, 0xE1, 0x89, 0x3C, 0x00, 0x00, 0x40, 0xF0, 0x44, 0x20, 0xE2, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F,
        0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xE7, 0xFF, 0xFB, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0x0F, 0xFE, 0x99, 0xFF, 0xE4, 0x1F, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xE7, 0xFD, 0xBD, 0xFF, 0xDE, 0xDF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0xFE,
        0xF7, 0xFD, 0x7D, 0x7F, 0xDF, 0xDF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0xFD,
        0xF7, 0xFD, 0x7D, 0x7F, 0xDF, 0xDF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0xFD,
        0xF7, 0xFD, 0x7D, 0x7F, 0xDF, 0x1F, 0xF0, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0xFD,
        0xF7, 0xFD, 0x7D, 0x7F, 0xDF, 0xFF, 0xF7, 0xFD, 0xFF, 0x1F, 0xFE, 0xFF, 0x83, 0xFF, 0xE3, 0xF1,
        0xF7, 0xFD, 0x7D, 0x7F, 0xDF, 0xFF, 0xF7, 0xFD, 0xFF, 0xE3, 0xF1, 0xFF, 0x7C, 0xF8, 0xF9, 0xEF,
        0xF7, 0xFD, 0x7D, 0x7F, 0xDF, 0xFF, 0xF7, 0xFD, 0xFF, 0xFD, 0xEF, 0x3F, 0xFF, 0xF3, 0xFD, 0xDF,
        0xF7, 0xFD, 0x7D, 0x7F, 0xDF, 0xFF, 0xF7, 0xFD, 0xFF, 0x1E, 0xDC, 0xBF, 0x03, 0xF7, 0xE3, 0xE1,
        0xF7, 0xFD, 0x7D, 0x7F, 0xDF, 0xFF, 0xF7, 0xFD, 0x7F, 0xEF, 0xB9, 0xDF, 0xFB, 0xF0, 0xEF, 0xFD,
        0xF7, 0xFD, 0x7D, 0x7F, 0xDF, 0xFF, 0xF7, 0xFD, 0x7F, 0xE7, 0xBB, 0xDF, 0xF3, 0xFF, 0xEF, 0xFD,
        0xF7, 0xFD, 0x7D, 0x7F, 0xDF, 0xFF, 0xF7, 0xFD, 0xBF, 0xF7, 0x7B, 0xDF, 0x0F, 0xFF, 0xEF, 0xFD,
        0xF7, 0xFD, 0x7D, 0x7F, 0xDF, 0xFF, 0xF7, 0xFD, 0xBF, 0x0F, 0x7C, 0xBF, 0xFF, 0xFC, 0xEF, 0xFD,
        0xF7, 0xFD, 0x7D, 0x7F, 0xDF, 0xFF, 0xF7, 0xFD, 0xBF, 0xFF, 0xBF, 0x7F, 0xFE, 0xF3, 0xEF, 0xFD,
        0xF7, 0xFD, 0xBE, 0x7F, 0xDF, 0xFF, 0xF7, 0xFD, 0xBF, 0x07, 0xC0, 0xFF, 0xE1, 0xF7, 0xEF, 0xFD,
        0xEF, 0xFB, 0xBE, 0x7F, 0xDF, 0xFF, 0xF7, 0xFD, 0xBF, 0xEF, 0xFF, 0xFF, 0x9F, 0xEF, 0xEF, 0xFD,
        0xEF, 0x07, 0xBF, 0x7F, 0xDF, 0xFF, 0xF7, 0xFD, 0x7F, 0xEF, 0xC7, 0x3F, 0x3E, 0xEF, 0xEF, 0xFD,
        0xDF, 0xFF, 0xDF, 0x7F, 0xDF, 0xFF, 0xF7, 0xFD, 0xFF, 0x1E, 0xB8, 0xDF, 0xB9, 0xF7, 0xEF, 0xE3,
        0x9F, 0xFF, 0xEF, 0x7F, 0xDF, 0xFF, 0xF7, 0xFD, 0xFF, 0xFC, 0xBF, 0x9F, 0xC7, 0xF7, 0xDF, 0xCF,
        0x7F, 0xFF, 0xF3, 0xFF, 0xDE, 0xFF, 0xEF, 0xFD, 0xFF, 0xFB, 0xCF, 0x3F, 0xFF, 0xF9, 0x9F, 0xEF,
        0xFF, 0x00, 0xFC, 0xFF, 0xE1, 0xFF, 0x1F, 0xFE, 0xFF, 0x07, 0xF0, 0xFF, 0x00, 0xFE, 0x7F, 0xF0,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F,
        0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x00, 0x40, 0x00, 0x02, 0x10, 0x00, 0x00,
        0x00, 0x00, 0x88, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x00, 0x60, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x88, 0x9C, 0x24, 0xC7, 0x1C, 0x0F, 0x68, 0x22, 0xA0, 0xCC, 0x23, 0x91, 0xC7, 0x01,
        0x00, 0xFE, 0x88, 0xA2, 0xAA, 0x48, 0xA2, 0x08, 0x98, 0x14, 0xB0, 0x24, 0x22, 0x91, 0x24, 0x02,
        0x00, 0x00, 0x78, 0xA2, 0xAB, 0x4F, 0xBE, 0x08, 0x88, 0x14, 0xF0, 0x24, 0x22, 0x91, 0x24, 0x02,
        0x00, 0x00, 0x08, 0x22, 0x9B, 0x40, 0x82, 0x08, 0x88, 0x0C, 0x08, 0x25, 0x22, 0x91, 0x24, 0x02,
        0x00, 0x00, 0x08, 0x1C, 0x11, 0x4F, 0x3C, 0x0F, 0x78, 0x08, 0x08, 0xC5, 0xE3, 0x91, 0xC4, 0x01,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

const float PID_MAX = 10.00; // PID最大允许值
// PID变量
float Kpid[3] = {9.97, 0.2, 0.01}; // Kp,Ki,Kd
// float Kp=8.96;
// float Ki=0.2;
// float Kd=0.01;

uint8_t disappear_step = 1;

float angle, angle_last;
// 实时坐标
uint8_t chart_x;
bool frame_is_drawed = false;

// 指向buf首地址的指针
uint8_t *buf_ptr;
uint16_t buf_len;

// 选择界面变量
uint8_t x;
int16_t y, y_trg;                 // 目标和当前
uint8_t line_y, line_y_trg;       // 线的位置
uint8_t box_width, box_width_trg; // 框的宽度
int16_t box_y, box_y_trg;         // 框的当前值和目标值
int8_t ui_select;                 // 当前选中那一栏

// pid界面变量
// int8_t pid_y,pid_y_trg;
uint8_t pid_line_y, pid_line_y_trg;       // 线的位置
uint8_t pid_box_width, pid_box_width_trg; // 框的宽度
int16_t pid_box_y, pid_box_y_trg;         // 框的当前值和目标值
int8_t pid_select;                        // 当前选中那一栏

// icon界面变量
int16_t icon_x, icon_x_trg;
int16_t app_y, app_y_trg;

int8_t icon_select;

uint8_t ui_index, ui_state;

enum // ui_index
{
    M_LOGO,      // 开始界面
    M_SELECT,    // 选择界面
    M_PID,       // PID界面
    M_PID_EDIT,  // pid编辑
    M_ICON,      // icon界面
    M_CHART,     // 图表
    M_TEXT_EDIT, // 文字编辑
    M_VIDEO,     // 视频显示
    M_ABOUT,     // 关于本机
};

enum // ui_state
{
    S_NONE,
    S_DISAPPEAR,
    S_SWITCH,
    S_MENU_TO_MENU,
    S_MENU_TO_PIC,
    S_PIC_TO_MENU,
};

// const char* text="This is a text Hello world ! follow up one two three four may jun july";

// 菜单结构体
typedef struct
{
    char *select;
} SELECT_LIST;

SELECT_LIST pid[]{
    {"-Proportion"},
    {"-Integral"},
    {"-Derivative"},
    {"Return"},
};

uint8_t pid_num = sizeof(pid) / sizeof(SELECT_LIST); // PID选项数量

SELECT_LIST list[]{
    {"MainUI"},
    {"+PID Editor"},
    {"-Icon Test"},
    {"-Chart Test"},
    {"-Text Edit"},
    {"-Play Video"},
    {"{ About }"},
};

uint8_t list_num = sizeof(list) / sizeof(SELECT_LIST); // 选择界面数量
uint8_t single_line_length = 63 / list_num;
uint8_t total_line_length = single_line_length * list_num + 1;

SELECT_LIST icon[]{
    {"Likes"},
    {"Collection"},
    {"Slot"},
    {"Share"},
};

// 设备名称
char name[] = "Hello World ";
// 允许名字的最大长度
const uint8_t name_len = 12; // 0-11for name  12 for return
uint8_t edit_index = 0;
bool edit_flag = false;         // 默认不在编辑
uint8_t blink_flag;             // 默认高亮
const uint8_t BLINK_SPEED = 16; // 2的倍数

uint8_t icon_num = sizeof(icon) / sizeof(SELECT_LIST);

// 按键变量
typedef struct
{
    bool val;
    bool last_val;
} KEY;

KEY key[3] = {false};

// 按键信息
typedef struct
{
    uint8_t id;
    bool pressed;
} KEY_MSG;

KEY_MSG key_msg = {0};

bool get_key_val(uint8_t ch)
{
    switch (ch)
    {
    case 0:
        return digitalRead(BTN0);
        break;
    case 1:
        return digitalRead(BTN1);
        break;
    case 2:
        return digitalRead(BTN2);
        break;
    default:
        break;
    }
}

void key_init()
{
    for (uint8_t i = 0; i < (sizeof(key) / sizeof(KEY)); ++i)
    {
        key[i].val = key[i].last_val = get_key_val(i);
    }
}

void key_scan()
{
    for (uint8_t i = 0; i < (sizeof(key) / sizeof(KEY)); ++i)
    {
        key[i].val = get_key_val(i);       // 获取键值
        if (key[i].last_val != key[i].val) // 发生改变
        {
            key[i].last_val = key[i].val; // 更新状态
            if (key[i].val == LOW)
            {
                key_msg.id = i;
                key_msg.pressed = true;
            }
        }
    }
}

// 移动函数
bool move(int16_t *a, int16_t *a_trg)
{
    if (*a < *a_trg)
    {
        *a += SPEED;
        if (*a > *a_trg)
            *a = *a_trg; // 加完超过
    }
    else if (*a > *a_trg)
    {
        *a -= SPEED;
        if (*a < *a_trg)
            *a = *a_trg; // 减完不足
    }
    else
    {
        return true; // 到达目标
    }
    return false; // 未到达
}

// 移动函数
bool move_icon(int16_t *a, int16_t *a_trg)
{
    if (*a < *a_trg)
    {
        *a += ICON_SPEED;
        if (*a > *a_trg)
            *a = *a_trg; // 加完超过
    }
    else if (*a > *a_trg)
    {
        *a -= ICON_SPEED;
        if (*a < *a_trg)
            *a = *a_trg; // 减完不足
    }
    else
    {
        return true; // 到达目标
    }
    return false; // 未到达
}

// 宽度移动函数
bool move_width(uint8_t *a, uint8_t *a_trg, uint8_t select, uint8_t id)
{
    if (*a < *a_trg)
    {
        uint8_t step = 16 / SPEED; // 判断步数
        uint8_t len;
        if (ui_index == M_SELECT)
        {
            len = abs(u8g2.getStrWidth(list[select].select) - u8g2.getStrWidth(list[id == 0 ? select + 1 : select - 1].select));
        }
        else if (ui_index == M_PID)
        {
            len = abs(u8g2.getStrWidth(pid[select].select) - u8g2.getStrWidth(pid[id == 0 ? select + 1 : select - 1].select));
        }
        uint8_t width_speed = ((len % step) == 0 ? (len / step) : (len / step + 1)); // 计算步长
        *a += width_speed;
        if (*a > *a_trg)
            *a = *a_trg; //
    }
    else if (*a > *a_trg)
    {
        uint8_t step = 16 / SPEED; // 判断步数
        uint8_t len;
        if (ui_index == M_SELECT)
        {
            len = abs(u8g2.getStrWidth(list[select].select) - u8g2.getStrWidth(list[id == 0 ? select + 1 : select - 1].select));
        }
        else if (ui_index == M_PID)
        {
            len = abs(u8g2.getStrWidth(pid[select].select) - u8g2.getStrWidth(pid[id == 0 ? select + 1 : select - 1].select));
        }
        uint8_t width_speed = ((len % step) == 0 ? (len / step) : (len / step + 1)); // 计算步长
        *a -= width_speed;
        if (*a < *a_trg)
            *a = *a_trg;
    }
    else
    {
        return true; // 到达目标
    }
    return false; // 未到达
}

// 进度条移动函数
bool move_bar(uint8_t *a, uint8_t *a_trg)
{
    if (*a < *a_trg)
    {
        uint8_t step = 16 / SPEED;                                                                                                // 判断步数
        uint8_t width_speed = ((single_line_length % step) == 0 ? (single_line_length / step) : (single_line_length / step + 1)); // 计算步长
        *a += width_speed;
        if (*a > *a_trg)
            *a = *a_trg; //
    }
    else if (*a > *a_trg)
    {
        uint8_t step = 16 / SPEED;                                                                                                // 判断步数
        uint8_t width_speed = ((single_line_length % step) == 0 ? (single_line_length / step) : (single_line_length / step + 1)); // 计算步长
        *a -= width_speed;
        if (*a < *a_trg)
            *a = *a_trg;
    }
    else
    {
        return true; // 到达目标
    }
    return false; // 未到达
}

// 文字编辑函数
void text_edit(bool dir, uint8_t index)
{
    if (!dir)
    {
        if (name[index] >= 'A' && name[index] <= 'Z') // 大写字母
        {
            if (name[index] == 'A')
            {
                name[index] = 'z';
            }
            else
            {
                name[index] -= 1;
            }
        }
        else if (name[index] >= 'a' && name[index] <= 'z') // 小写字母
        {
            if (name[index] == 'a')
            {
                name[index] = ' ';
            }
            else
            {
                name[index] -= 1;
            }
        }
        else
        {
            name[index] = 'Z';
        }
    }
    else
    {
        if (name[index] >= 'A' && name[index] <= 'Z') // 大写字母
        {
            if (name[index] == 'Z')
            {
                name[index] = ' ';
            }
            else
            {
                name[index] += 1;
            }
        }
        else if (name[index] >= 'a' && name[index] <= 'z') // 小写字母
        {
            if (name[index] == 'z')
            {
                name[index] = 'A';
            }
            else
            {
                name[index] += 1;
            }
        }
        else
        {
            name[index] = 'a';
        }
    }
}

// 消失函数
void disappear()
{
    switch (disappear_step)
    {
    case 1:
        for (uint16_t i = 0; i < buf_len; ++i)
        {
            if (i % 2 == 0)
                buf_ptr[i] = buf_ptr[i] & 0x55;
        }
        break;
    case 2:
        for (uint16_t i = 0; i < buf_len; ++i)
        {
            if (i % 2 != 0)
                buf_ptr[i] = buf_ptr[i] & 0xAA;
        }
        break;
    case 3:
        for (uint16_t i = 0; i < buf_len; ++i)
        {
            if (i % 2 == 0)
                buf_ptr[i] = buf_ptr[i] & 0x00;
        }
        break;
    case 4:
        for (uint16_t i = 0; i < buf_len; ++i)
        {
            if (i % 2 != 0)
                buf_ptr[i] = buf_ptr[i] & 0x00;
        }
        break;
    default:
        ui_state = S_NONE;
        disappear_step = 0;
        break;
    }
    disappear_step++;
}

/**************************界面显示*******************************/

void logo_ui_show() // 显示logo
{
    u8g2.drawXBMP(0, 0, 128, 64, LOGO);

    for(uint16_t i=0;i<buf_len;++i)
    {
      if(i%4==0||i%4==1)
      {
      buf_ptr[i]=buf_ptr[i] & 0x33;
      }
      else
      {
      buf_ptr[i]=buf_ptr[i] & 0xCC;
      }
    }
}

void select_ui_show() // 选择界面
{
    move_bar(&line_y, &line_y_trg);
    move(&y, &y_trg);
    move(&box_y, &box_y_trg);
    move_width(&box_width, &box_width_trg, ui_select, key_msg.id);
    u8g2.drawVLine(126, 0, total_line_length);
    u8g2.drawPixel(125, 0);
    u8g2.drawPixel(127, 0);
    for (uint8_t i = 0; i < list_num; ++i)
    {
        u8g2.drawStr(x, 16 * i + y + 12, list[i].select); // 第一段输出位置
        u8g2.drawPixel(125, single_line_length * (i + 1));
        u8g2.drawPixel(127, single_line_length * (i + 1));
    }
    u8g2.drawVLine(125, line_y, single_line_length - 1);
    u8g2.drawVLine(127, line_y, single_line_length - 1);

    // 使用异或绘制一个圆角矩形，用于选择框的颜色反转，然后恢复原来颜色
    u8g2.setDrawColor(2);
    u8g2.drawRBox(0, box_y, box_width, 16, 1);
    u8g2.setDrawColor(1);
}

void pid_ui_show() // PID界面
{
    move_bar(&pid_line_y, &pid_line_y_trg);
    move(&pid_box_y, &pid_box_y_trg);
    move_width(&pid_box_width, &pid_box_width_trg, pid_select, key_msg.id);
    u8g2.drawVLine(126, 0, 61);
    u8g2.drawPixel(125, 0);
    u8g2.drawPixel(127, 0);
    for (uint8_t i = 0; i < pid_num; ++i)
    {
        u8g2.drawStr(x, 16 * i + 12, pid[i].select); // 第一段输出位置
        u8g2.drawPixel(125, 15 * (i + 1));
        u8g2.drawPixel(127, 15 * (i + 1));
    }

    u8g2.setDrawColor(2);
    u8g2.drawRBox(0, pid_box_y, pid_box_width, 16, 1);
    u8g2.setDrawColor(1);
    u8g2.drawVLine(125, pid_line_y, 14);
    u8g2.drawVLine(127, pid_line_y, 14);
}

void pid_edit_ui_show() // 显示PID编辑
{
    u8g2.drawBox(16, 16, 96, 31);
    u8g2.setDrawColor(2);
    u8g2.drawBox(17, 17, 94, 29);
    u8g2.setDrawColor(1);

    // u8g2.drawBox(17,17,(int)(Kpid[pid_select]/PID_MAX)),30);
    u8g2.drawFrame(18, 36, 60, 8);
    u8g2.drawBox(20, 38, (uint8_t)(Kpid[pid_select] / PID_MAX * 56), 4);

    u8g2.setCursor(22, 30);
    switch (pid_select)
    {
    case 0:
        u8g2.print("Editing Kp");
        break;
    case 1:
        u8g2.print("Editing Ki");
        break;
    case 2:
        u8g2.print("Editing Kd");
        break;
    default:
        break;
    }

    u8g2.setCursor(81, 44);
    u8g2.print(Kpid[pid_select]);
}

void icon_ui_show(void) // 显示icon
{

    move_icon(&icon_x, &icon_x_trg);
    move(&app_y, &app_y_trg);

    for (uint8_t i = 0; i < icon_num; ++i)
    {
        u8g2.drawXBMP(46 + icon_x + i * ICON_SPACE, 6, 36, icon_width[i], icon_pic[i]);
        u8g2.setClipWindow(0, 48, 128, 64);
        u8g2.drawStr((128 - u8g2.getStrWidth(icon[i].select)) / 2, 62 - app_y + i * 16, icon[i].select);
        u8g2.setMaxClipWindow();
    }
}

void chart_ui_show() // chart界面
{
    if (!frame_is_drawed) // 框架只画一遍
    {
        u8g2.clearBuffer();
        chart_draw_frame();
        angle_last = 20.00 + (float)analogRead(READ) / 100.00;
        frame_is_drawed = true;
    }

    u8g2.drawBox(96, 0, 30, 14);

    u8g2.drawVLine(chart_x + 10, 59, 3);
    if (chart_x == 100)
        chart_x = 0;

    // u8g2.drawBox(chart_x+11,24,8,32);

    u8g2.drawVLine(chart_x + 11, 24, 34);
    u8g2.drawVLine(chart_x + 12, 24, 34);
    u8g2.drawVLine(chart_x + 13, 24, 34);
    u8g2.drawVLine(chart_x + 14, 24, 34);

    // 异或绘制
    u8g2.setDrawColor(2);
    angle = 20.00 + (float)analogRead(READ) / 100.00;
    u8g2.drawLine(chart_x + 11, 58 - (int)angle_last / 2, chart_x + 12, 58 - (int)angle / 2);
    u8g2.drawVLine(chart_x + 12, 59, 3);
    angle_last = angle;
    chart_x += 2;
    u8g2.drawBox(96, 0, 30, 14);
    u8g2.setDrawColor(1);

    u8g2.setCursor(96, 12);
    u8g2.print(angle);
}

void chart_draw_frame() // chart界面
{

    u8g2.drawStr(4, 12, "Real time angle :");
    u8g2.drawRBox(4, 18, 120, 46, 8);
    u8g2.setDrawColor(2);
    u8g2.drawHLine(10, 58, 108);
    u8g2.drawVLine(10, 24, 34);
    // 箭头
    u8g2.drawPixel(7, 27);
    u8g2.drawPixel(8, 26);
    u8g2.drawPixel(9, 25);

    u8g2.drawPixel(116, 59);
    u8g2.drawPixel(115, 60);
    u8g2.drawPixel(114, 61);
    u8g2.setDrawColor(1);
}

void text_edit_ui_show()
{
    u8g2.drawRFrame(4, 6, 120, 52, 8);
    u8g2.drawStr((128 - u8g2.getStrWidth("--Text Editor--")) / 2, 20, "--Text Editor--");
    u8g2.drawStr(10, 38, name);
    u8g2.drawStr(80, 50, "-Return");

    uint8_t box_x = 9;

    // 绘制光标
    if (edit_index < name_len)
    {
        if (blink_flag < BLINK_SPEED / 2)
        {
            for (uint8_t i = 0; i < edit_index; ++i)
            {
                char temp[2] = {name[i], '\0'};
                box_x += u8g2.getStrWidth(temp);
                if (name[i] != ' ')
                {
                    box_x++;
                }
            }
            char temp[2] = {name[edit_index], '\0'};
            u8g2.setDrawColor(2);
            u8g2.drawBox(box_x, 26, u8g2.getStrWidth(temp) + 2, 16);
            u8g2.setDrawColor(1);
        }
    }
    else
    {
        u8g2.setDrawColor(2);
        u8g2.drawRBox(78, 38, u8g2.getStrWidth("-Return") + 4, 16, 1);
        u8g2.setDrawColor(1);
    }

    if (edit_flag) // 处于编辑状态
    {
        if (blink_flag < BLINK_SPEED)
        {
            blink_flag += 1;
        }
        else
        {
            blink_flag = 0;
        }
    }
    else
    {
        blink_flag = 0;
    }
}

void about_ui_show() // about界面
{

    u8g2.drawStr(2, 12, "MCU : ESP32");
    u8g2.drawStr(2, 28, "FLASH : 4MB");
    u8g2.drawStr(2, 44, "SRAM : 520KB");
    u8g2.drawStr(2, 60, "RTC SRAM : 16KB");

    // u8g2.drawStr(2,12,"MCU : MEGA2560");
    // u8g2.drawStr(2,28,"FLASH : 256KB");
    // u8g2.drawStr(2,44,"SRAM : 8KB");
    // u8g2.drawStr(2,60,"EEPROM : 4KB");
}

/**************************界面处理*******************************/

void logo_proc() // logo界面处理函数
{
    if (key_msg.pressed)
    {
        key_msg.pressed = false;
        ui_state = S_DISAPPEAR;
        ui_index = M_SELECT;
    }
    logo_ui_show();
}

void pid_edit_proc(void) // pid编辑界面处理函数
{
    if (key_msg.pressed)
    {
        key_msg.pressed = false;
        switch (key_msg.id)
        {
        case 0:
            if (Kpid[pid_select] > 0)
                Kpid[pid_select] -= 0.01;
            break;
        case 1:
            if (Kpid[pid_select] < PID_MAX)
                Kpid[pid_select] += 0.01;
            break;
        case 2:
            ui_index = M_PID;
            break;
        default:
            break;
        }
    }
    pid_ui_show();
    for (uint16_t i = 0; i < buf_len; ++i)
    {
        buf_ptr[i] = buf_ptr[i] & (i % 2 == 0 ? 0x55 : 0xAA);
    }
    pid_edit_ui_show();
}

void pid_proc() // pid界面处理函数
{
    pid_ui_show();
    if (key_msg.pressed)
    {
        key_msg.pressed = false;
        switch (key_msg.id)
        {
        case 0:
            if (pid_select != 0)
            {
                pid_select -= 1;
                pid_line_y_trg -= 15;
                pid_box_y_trg -= 16;
                break;
            }
            else
            {
                break;
            }
        case 1:
            if (pid_select != 3)
            {
                pid_select += 1;
                pid_line_y_trg += 15;
                pid_box_y_trg += 16;
            }
            else
            {
                break;
            }
            break;
        case 2:
            if (pid_select == 3)
            {
                ui_index = M_SELECT;
                ui_state = S_DISAPPEAR;
                pid_select = 0;
                pid_line_y = pid_line_y_trg = 1;
                pid_box_y = pid_box_y_trg = 0;
                pid_box_width = pid_box_width_trg = u8g2.getStrWidth(pid[pid_select].select) + x * 2;
            }
            else
            {
                ui_index = M_PID_EDIT;
            }
            break;
        default:
            break;
        }
        pid_box_width_trg = u8g2.getStrWidth(pid[pid_select].select) + x * 2;
    }
}

void select_proc(void) // 选择界面处理
{
    if (key_msg.pressed)
    {
        key_msg.pressed = false;
        switch (key_msg.id)
        {
        case 0:
            if (ui_select < 1)
                break;
            ui_select -= 1;
            line_y_trg -= single_line_length;
            if (ui_select < -(y / 16))
            {
                y_trg += 16;
            }
            else
            {
                box_y_trg -= 16;
            }

            break;
        case 1:
            if ((ui_select + 2) > (sizeof(list) / sizeof(SELECT_LIST)))
                break;
            ui_select += 1;
            line_y_trg += single_line_length;
            if ((ui_select + 1) > (4 - y / 16))
            {
                y_trg -= 16;
            }
            else
            {
                box_y_trg += 16;
            }

            break;
        case 2:
            switch (ui_select)
            {
            case 0: // return
                ui_state = S_DISAPPEAR;
                ui_index = M_LOGO;
                break;
            case 1: // pid
                ui_state = S_DISAPPEAR;
                ui_index = M_PID;
                break;
            case 2: // icon
                ui_state = S_DISAPPEAR;
                ui_index = M_ICON;
                break;
            case 3: // chart
                ui_state = S_DISAPPEAR;
                ui_index = M_CHART;
                break;
            case 4: // textedit
                ui_state = S_DISAPPEAR;
                ui_index = M_TEXT_EDIT;
                break;
            case 6: // about
                ui_state = S_DISAPPEAR;
                ui_index = M_ABOUT;
                break;
            default:
                break;
            }
        // Serial.println("Btn2");
        default:
            break;
        }
        // Serial.println(ui_select);
        box_width_trg = u8g2.getStrWidth(list[ui_select].select) + x * 2;
    }
    select_ui_show();
}

void icon_proc(void) // icon界面处理
{
    icon_ui_show();
    if (key_msg.pressed)
    {
        key_msg.pressed = false;
        switch (key_msg.id)
        {
        case 1:
            if (icon_select != (icon_num - 1))
            {
                icon_select += 1;
                app_y_trg += 16;
                icon_x_trg -= ICON_SPACE;
            }
            break;
        case 0:
            if (icon_select != 0)
            {
                icon_select -= 1;
                app_y_trg -= 16;
                icon_x_trg += ICON_SPACE;
            }
            break;
        case 2:
            ui_state = S_DISAPPEAR;
            ui_index = M_SELECT;
            icon_select = 0;
            icon_x = icon_x_trg = 0;
            app_y = app_y_trg = 0;
            break;
        default:
            break;
        }
    }
}

void chart_proc() // chart界面处理函数
{
    chart_ui_show();
    if (key_msg.pressed)
    {
        key_msg.pressed = false;
        ui_state = S_DISAPPEAR;
        ui_index = M_SELECT;
        frame_is_drawed = false; // 退出后框架为未画状态
        chart_x = 0;
    }
}

void text_edit_proc()
{
    text_edit_ui_show();
    if (key_msg.pressed)
    {
        key_msg.pressed = false;
        switch (key_msg.id)
        {
        case 0:
            if (edit_flag)
            {
                // 编辑
                text_edit(false, edit_index);
            }
            else
            {
                if (edit_index == 0)
                {
                    edit_index = name_len;
                }
                else
                {
                    edit_index -= 1;
                }
            }
            break;
        case 1:
            if (edit_flag)
            {
                // 编辑
                text_edit(true, edit_index);
            }
            else
            {
                if (edit_index == name_len)
                {
                    edit_index = 0;
                }
                else
                {
                    edit_index += 1;
                }
            }
            break;
        case 2:
            if (edit_index == name_len)
            {
                ui_state = S_DISAPPEAR;
                ui_index = M_SELECT;
                edit_index = 0;
            }
            else
            {
                edit_flag = !edit_flag;
            }
            break;
        default:
            break;
        }
    }
}

void about_proc() // about界面处理函数
{
    if (key_msg.pressed)
    {
        key_msg.pressed = false;
        ui_state = S_DISAPPEAR;
        ui_index = M_SELECT;
    }
    about_ui_show();
}
/********************************总的UI显示************************************/

void ui_proc() // 总的UI进程
{
    switch (ui_state)
    {
    case S_NONE:
        if (ui_index != M_CHART)
            u8g2.clearBuffer();
        switch (ui_index)
        {
        case M_LOGO:
            logo_proc();
            break;
        case M_SELECT:
            select_proc();
            break;
        case M_PID:
            pid_proc();
            break;
        case M_ICON:
            icon_proc();
            break;
        case M_CHART:
            chart_proc();
            break;
        case M_TEXT_EDIT:
            text_edit_proc();
            break;
        case M_PID_EDIT:
            pid_edit_proc();
            break;
        case M_ABOUT:
            about_proc();
            break;
        default:
            break;
        }
        break;
    case S_DISAPPEAR:
        disappear();
        break;
    default:
        break;
    }
    u8g2.sendBuffer();
}

void setup()
{
    Serial.begin(9600);
    // Wire.begin(21,22,400000);
    pinMode(BTN0, INPUT_PULLUP);
    pinMode(BTN1, INPUT_PULLUP);
    pinMode(BTN2, INPUT_PULLUP);
    key_init();
    u8g2.setBusClock(800000);
    u8g2.begin();
    u8g2.setFont(u8g2_font_wqy12_t_chinese1);
    // u8g2.setContrast(10);

    buf_ptr = u8g2.getBufferPtr(); // 拿到buffer首地址
    buf_len = 8 * u8g2.getBufferTileHeight() * u8g2.getBufferTileWidth();

    x = 4;
    y = y_trg = 0;
    line_y = line_y_trg = 1;
    pid_line_y = pid_line_y_trg = 1;
    ui_select = pid_select = icon_select = 0;
    icon_x = icon_x_trg = 0;
    app_y = app_y_trg = 0;

    box_width = box_width_trg = u8g2.getStrWidth(list[ui_select].select) + x * 2;         // 两边各多2
    pid_box_width = pid_box_width_trg = u8g2.getStrWidth(pid[pid_select].select) + x * 2; // 两边各多2

    ui_index = M_LOGO;
    // ui_index=M_TEXT_EDIT;
    ui_state = S_NONE;
}

void loop()
{
    key_scan();
    ui_proc();
}
