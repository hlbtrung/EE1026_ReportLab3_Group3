#include "OLED.h"

Adafruit_SSD1306 display(12);


void writeText(int16_t x, int16_t y, String string, int size){
  display.setTextSize(size);
  display.setTextColor(WHITE);
  display.setCursor(x,y);
  display.println(string);
  
}
void initOled(){
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}
void clearDisplay(){
  display.clearDisplay();
}
void show(){
  display.display();
}
