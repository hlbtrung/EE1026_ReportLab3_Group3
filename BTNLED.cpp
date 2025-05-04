#include "BTNLED.h"
#include "Arduino.h"

void initGpio(){
  pinMode(LED4,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(BTN1,INPUT_PULLUP);
  pinMode(BTN2,INPUT_PULLUP);
  pinMode(BTN3,INPUT_PULLUP);
  pinMode(BUZZER,OUTPUT);
  digitalWrite(BUZZER,HIGH);
}

void buzzer(int time_ms){
    digitalWrite(BUZZER,LOW);
    delay(time_ms);
    digitalWrite(BUZZER,HIGH);
}
void controlLed(int ledNumber, int stt){
  if(ledNumber==LED4)
    (stt == 1)? digitalWrite(LED4,HIGH):digitalWrite(LED4,LOW);
  else if(ledNumber==LED2)
    (stt == 1)? digitalWrite(LED3,HIGH):digitalWrite(LED3,LOW);
  else 
    (stt == 1)? digitalWrite(LED2,HIGH):digitalWrite(LED2,LOW);
}

bool btnPush(int btnNumber){
  if(btnNumber == BTN1){
      if(digitalRead(BTN1)==0){
        while(digitalRead(BTN1)==0);
        return true;
    }
   }
  else if(btnNumber == BTN2){
      if(digitalRead(BTN2)==0){
        while(digitalRead(BTN2)==0);
        return true;
    }
   }
  else if(btnNumber == BTN3){
      if(digitalRead(BTN3)==0){
        while(digitalRead(BTN3)==0);
        return true;
    }
  }
  return false;
}
