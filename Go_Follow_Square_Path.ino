/*
  Report Lab 3 (Week 19) - Group 03
  Purposes: 
    + Get started with the engineering field
    + Control the car going the square path
    + Understand how to use Arduino Nano Board
  Members:
    Huynh Lam Bao Trung - 2451186 (leader)
    Nguyen Trung Hieu - 2451051
    Phan Trung Nhan - 2451127
    Le Nam Thang - 2451161
*/


#include "BTNLED.h"
#include "MOTOR.h"
#include "OLED.h"
// ********************************** //
#define ON 1
#define OFF 2
// ********************************** //
bool Running;

void oledStart() {clearDisplay();writeText(0, 0, "You Ready?", 2);writeText(0, 22, "     Press BT2 !", 1);show();}
void oled(String status) {clearDisplay();writeText(0, 0, status, 2);show();}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup() {
  initOled();
  initGpio();
  oledStart();
  Running = false;
}
////////loop main system //////////
void loop() {
begin:
  if (btnPush(BTN2)) {
    oled("Running..!");
    Running = true;
  }
  while (!Running) goto begin;

  ////////////// Student write here//////////////////
  // Notifying that the car starts going
  buzzer(1000);
  controlLed(LED3, ON);
  
  for (int i = 0; i < 4; i++) {
    // By trying many times, we identified that the left motor has 1.55 times power as the right motor.
    speedBothMotorTime(100, 155, 3000);
    
    speedBothMotor(0, 0);    
    controlLed(LED3, OFF);
    oled("Stop...!");
    buzzer(1000);

    //  To turn left , the 1.1 second is the perfect time to turn left completely
    controlLed(LED2, ON);
    speedBothMotorTime(0, 200, 1100);
    speedBothMotor(0, 0);
  }
  // Stop going
  controlLed(LED2, OFF);
  oled("Stop...!");
  buzzer(1000);
  // Reset the state
  oledStart();
  Running = false;
}
