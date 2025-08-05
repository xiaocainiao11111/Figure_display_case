# figure_display_case

开发环境：

屏幕库：
WouoUI


功能：

注意：烧录要按住拨轮

计划：

触摸
灯条
小程序
换屏幕




u8g2.drawRBox（绘制填充的圆角矩形）

x, y: 矩形左上角的坐标
   w, h: 矩形的宽度和高度
   r: 圆角的半径

drawRBox是填充的实心矩形，drawRFrame是空心的矩形框

u8g2.drawPixel画点
u8g2.drawVLine画线
u8g2.drawStr画文本

实际上都是在填充缓存区

std::ceil(x)
返回一个浮点值，表示不小于`x`的最小整数

long map(long x, long in_min, long in_max, long out_min, long out_max)
将一个数从一个范围线性映射到另一个范围

u8g2的缓存及瓦片机制


ui源码解析：
在proc里处理按键判断





参考工程：
https://gitee.com/wenzhengclub/super_knob

https://github.com/xiaocainiao11111/ESP32_connect_XboxController

https://github.com/unlir/XDrive

https://github.com/peng-zhihui/Peak


line_y:1  line_y_trg:1  box_y:0  box_y_trg:0  y:0  y_trg:0  

line_y:4  line_y_trg:10  box_y:4  box_y_trg:16  y:0  y_trg:0  

line_y:7  line_y_trg:10  box_y:8  box_y_trg:16  y:0  y_trg:0

line_y:10  line_y_trg:10  box_y:12  box_y_trg:16  y:0  y_trg:0

line_y:10  line_y_trg:10  box_y:16  box_y_trg:16  y:0  y_trg:0  