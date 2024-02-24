#include <Arduino.h>
#include <H_bridge_TB6612.hpp>
#include "Main/config.h"

#define channel2 1
#define resolution_channel2 10

Motor rightMotor = Motor(BIN1, BIN2, PWMB,  channel2, RESOLUTION);
Motor leftMotor = Motor(AIN1, AIN2, PWMA,  channel1, RESOLUTION);


void setup() {

  Serial.begin(9600);

}

void loop() {
  // rightMotor.drive(900);
  // leftMotor.drive(900);
  // //PWM for the right motor
  for(int i=0; i< 1000; i++) {
    rightMotor.drive(i);
    Serial.println(i);
    delay(10);
  }

  for(int j = 1000; j > - 1000; j--) {
    rightMotor.drive(j);
    Serial.println(j);
    delay(10);
  }

  for(int k = -1000; k < 0; k++) {
    rightMotor.drive(k);
    Serial.println(k);
    delay(10);
  }


  //PWM for the left motor
  for(int i=0; i< 1000; i++) {
    leftMotor.drive(i);
    Serial.println(i);
    delay(10);
  }

  for(int j = 1000; j > - 1000; j--) {
    leftMotor.drive(j);
    Serial.println(j);
    delay(10);
  }

  for(int k = -1000; k < 0; k++) {
    leftMotor.drive(k);
    Serial.println(k);
    delay(10);
  }


}