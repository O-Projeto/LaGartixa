#include <Arduino.h>

#define PIN 5000
#define TRESHOLD 600 

int counter = 0;
int read_infra = 0 ;

void setup(){

    pinMode(PIN,OUTPUT);
    Serial.begin(112500);

}

void loop(){

    read_infra = analogRead(PIN);

    if(read_infra > TRESHOLD){
        counter++ ; 
    }

    Serial.print("READ : ");
    Serial.print(read_infra);
    Serial.print(" | Counter :");
    Serial.print(counter);
    Serial.println("");

}