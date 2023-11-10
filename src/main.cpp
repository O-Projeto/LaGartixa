/*
   Gamepad module provides three different mode namely Digital, JoyStick and Accerleometer.

   You can reduce the size of library compiled by enabling only those modules that you want to
   use. For this first define CUSTOM_SETTINGS followed by defining INCLUDE_modulename.

   Explore more on: https://thestempedia.com/docs/dabble/game-pad-module/
*/
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>

const int motorA1 = 17;
const int motorA2 = 05;
const int PWM_A = 19;
const int motorB1 = 16;
const int motorB2 = 04;
const int PWM_B = 18;


const int PWM_A_Chan = 0;
const int PWM_A_Freq = 500;
const int PWM_A_Res = 8;
const int PWM_B_Chan = 0;
const int PWM_B_Freq = 500;
const int PWM_B_Res = 8;




void moveFrente(int vel) {
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
  ledcWrite(PWM_A_Chan, vel);
  ledcWrite(PWM_B_Chan, vel);

}

void moveTras(int vel) {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
  ledcWrite(PWM_A_Chan, vel);
  ledcWrite(PWM_B_Chan, vel);

}

void movedireita( int vel ) {
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
  ledcWrite(PWM_A_Chan, vel);
  ledcWrite(PWM_B_Chan, vel);

}

void moveesquerda( int vel ) {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
  ledcWrite(PWM_A_Chan, vel);
  ledcWrite(PWM_B_Chan, vel);

}

void parar() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  ledcWrite(PWM_A_Chan, 0);
  ledcWrite(PWM_B_Chan, 0);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);      // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin("Lagartixa");       //set bluetooth name of your device

  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  ledcSetup(PWM_A_Chan, PWM_A_Freq, PWM_A_Res);
  ledcSetup(PWM_B_Chan, PWM_B_Freq, PWM_B_Res);


  ledcAttachPin(PWM_A, PWM_A_Chan);
  ledcAttachPin(PWM_B, PWM_B_Chan);
}

void loop() {
  Dabble.processInput();             //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.
  Serial.println("KeyPressed: \n");

  if (GamePad.isUpPressed())
  {
    Serial.print("Up");
    moveFrente(255);
  } else if (GamePad.isDownPressed()) {
    Serial.print("Down");
    moveTras(255);
  } else if (GamePad.isRightPressed()) {
    Serial.print("Right");
    movedireita(100);
  } else if (GamePad.isLeftPressed()) {
    Serial.print("Left");
    moveesquerda(100);
  } else {
    parar();
  }

}
