# figure_display_case

![alt text](image.png)

旋转编码器用法：需要两个状态一起判断
![alt text](image-1.png)

开发环境：

屏幕库：
WouoUI
注意u8g2库连接屏幕失败的话会堵塞

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
先在proc里处理按键判断，只修改目标值，然后进行动画处理，动画是一直在处理的，其实

参考工程：

<https://gitee.com/wenzhengclub/super_knob>

<https://github.com/xiaocainiao11111/ESP32_connect_XboxController>

<https://github.com/unlir/XDrive>

<https://github.com/peng-zhihui/Peak>

<https://github.com/FASTSHIFT/X-TRACK>

- select_ui_show变化：

line_y:1  line_y_trg:1  box_y:0  box_y_trg:0  y:0  y_trg:0  

line_y:4  line_y_trg:10  box_y:4  box_y_trg:16  y:0  y_trg:0  

line_y:7  line_y_trg:10  box_y:8  box_y_trg:16  y:0  y_trg:0

line_y:10  line_y_trg:10  box_y:12  box_y_trg:16  y:0  y_trg:0

line_y:10  line_y_trg:10  box_y:16  box_y_trg:16  y:0  y_trg:0  

前言：如何看懂一份代码
我的经验是按照做阅读理解的方式来看一份代码，速读全文，这时候义务教育发力了，
1、了解大概的结构，因为每个人的编程习惯不一样，了解结构是很重要的。
2、看头看尾，头看初始化，尾看main函数

开头是一堆的enum，对喽，就得是无穷无尽的enum
然后就是一堆的初始化参数
开头用了四五百行来定义屏幕的各种东西，因为是ui，所以参数巨多

接下来是eeprom和按键的初始化，这部分可以不看，有一说一，这部分写的不好，eeprom确实基本的校验和纠错环节，按键逻辑基本的滤抖和非阻塞计时都没有，而且完全不考虑接口的问题，换了别的交互方式必须完全重写输入。

然后是一堆初始化函数，这里有个技巧：每个函数都全局搜索一下，看在哪些地方用了，可以加深自己都全文的理解。

关于非线性平滑动画

- 动画算法

关于非阻塞的线性动画

着重讲下动画函数
看着只有几行，但
// 动画函数
void animation(float *a, float*a_trg, uint8_t n)
{
  if (*a !=*a_trg)
  {
    if (fabs(*a -*a_trg) < 0.15f)
      *a =*a_trg;
    else
      *a += (*a_trg - *a) / (ui.param[n] / 10.0f);
  }
}
