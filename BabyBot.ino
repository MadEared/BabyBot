/*

  BabyBot code
  
  Please put a description here...
  
  21 Nov 2015
  
  
*/

#include "Maxbotix.h"
Maxbotix rangeSensorPW(8, Maxbotix::PW, Maxbotix::LV);
#ifdef MAXBOTIX_WITH_SOFTWARE_SERIAL
  Maxbotix rangeSensorTX(6, Maxbotix::TX, Maxbotix::LV);
#endif
Maxbotix rangeSensorAD(A0, Maxbotix::AN, Maxbotix::LV);

#define forwardPin 9
#define reversePin 6
#define leftPin 11
#define rightPin 10
#define triggerPin 12

int motorSpeed = 0; // how fast the motor spins
int rightTurnSpeed = 0; // how fast right turns
int leftTurnSpeed = 0; // how fast left turns


void setup() {
  pinMode(forwardPin, OUTPUT);
  pinMode(rightPin, OUTPUT);
  pinMode(triggerPin, INPUT);
  Serial.begin(9600); // Maxbotix information transfer band width 
}

void loop() {
 motorSpeed = 120;
 rightTurnSpeed = 255;
 leftTurnSpeed = 255;
 // analogWrite(rightPin,rightTurnSpeed);
 if (digitalRead(triggerPin))
 {
   analogWrite(forwardPin, 0);
   analogWrite(reversePin, 0);
   analogWrite(rightPin, 0);
   analogWrite(leftPin, 0);
 }
// else if (rangeSensorPW.getRange() > 80 && rangeSensorPW.getRange() < 100)
// {
//   analogWrite(leftPin, leftTurnSpeed);
//   analogWrite(forwardPin, motorSpeed);
//   while(rangeSensorPW.getRange() > 80);
//   analogWrite(forwardPin, 0);
//   analogWrite(leftPin, 0);
// }
 else if (rangeSensorPW.getRange() < 50) 
 {
   analogWrite(forwardPin, 0);
   analogWrite(rightPin, rightTurnSpeed);   
   analogWrite(reversePin, motorSpeed);
   while(rangeSensorPW.getRange() < 70);
   analogWrite(reversePin, 0);
   analogWrite(rightPin, 0);      
 } 
 else
 {
   analogWrite(forwardPin, motorSpeed);
 }
 //else delay(500);
 //analogWrite(forwardPin,0);
 //delay(1000);
}
