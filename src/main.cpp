/*
   Gamepad module provides three different mode namely Digital, JoyStick and Accerleometer.

   You can reduce the size of library compiled by enabling only those modules that you want to
   use. For this first define CUSTOM_SETTINGS followed by defining INCLUDE_modulename.

   Explore more on: https://thestempedia.com/docs/dabble/game-pad-module/
*/

#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>

// Pinos

const unsigned int motorA1 = 17;
const unsigned int motorA2 = 05;
const unsigned int PWM_A = 19;

const unsigned int motorB1 = 16;
const unsigned int motorB2 = 04;
const unsigned int PWM_B = 18;

const unsigned int PWM_A_Chan = 0;   // canal de PWM 1 - 16 disponíveis
const unsigned int PWM_A_Freq = 500;   // Frequência
const unsigned int PWM_A_Res = 8;    // Resolução 1 - 16 bits | 8 bits = valores de 0-255

const unsigned int PWM_B_Chan = 0;   
const unsigned int PWM_B_Freq = 500;
const unsigned int PWM_B_Res = 8;

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

  Serial.begin(9600);      // Certifique-se que seu Serial Monitor também está nesse baud rate.
  Dabble.begin("Lagartixa");       // Nome do dispositivo 

  pinMode(motorA1, OUTPUT); // Definição de cada tipo dos pins
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  ledcSetup(PWM_A_Chan, PWM_A_Freq, PWM_A_Res);   // configurando o PWM
  ledcSetup(PWM_B_Chan, PWM_B_Freq, PWM_B_Res);   


  ledcAttachPin(PWM_A, PWM_A_Chan);    // Linkando o  canal para os pinos
  ledcAttachPin(PWM_B, PWM_B_Chan);

}

void loop() {
  Dabble.processInput();             
  // Serial.println("KeyPressed: \n");

  if (GamePad.isUpPressed()){

    // Serial.print("Up");
    moveFrente(255);

  } else if (GamePad.isDownPressed()) {

    // Serial.print("Down");
    moveTras(255);

  } else if (GamePad.isRightPressed()) {

    // Serial.print("Right");
    movedireita(100);

  } else if (GamePad.isLeftPressed()) {

    // Serial.print("Left");
    moveesquerda(100);

  } else {

    parar();
    
  }

}
