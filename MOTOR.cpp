#include "MOTOR.h"
#include "Arduino.h" 
 
void speedMotorLeft(int Speed){
  if(Speed>255)
     Speed=255;
  else if(Speed<-255)
     Speed =-255;
     
  if(Speed>=0){
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  analogWrite(9,Speed);
  }
  else if(Speed<0){
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  analogWrite(9,-Speed);
  }
}
void speedMotorRight(int Speed){
  if(Speed>255)
     Speed=255;
  else if(Speed<-255)
     Speed =-255;
     
  if(Speed>=0){
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  analogWrite(3,Speed);
  }
  if(Speed<0){
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  analogWrite(3,-Speed);
  }
}
void speedBothMotor(int Speed1,int Speed2){
  speedMotorRight(Speed1);
  speedMotorLeft(Speed2);
}
void speedBothMotorTime(int Speed1,int Speed2,unsigned int Time){
  speedMotorRight(Speed1);
  speedMotorLeft(Speed2);
  delay(Time);
  speedBothMotor(0,0);
}
