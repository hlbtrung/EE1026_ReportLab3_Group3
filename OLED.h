#define OLED_H
#include <Wire.h>
//#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// function init LCD 
void initOled();


// function write text on screen
void writeText(int16_t x, int16_t y, String str,int Size);

// function clear display
void clearDisplay();

// function display on screen
void show();
