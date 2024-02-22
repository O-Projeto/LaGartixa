#include "config.h"
#include "config.h"
// #include "qtr.h"
#include <QTRSensors.h>

const uint8_t SensorPins[] = {36, 39, 34, 35, 32, 33, 25, 26};
const uint8_t SensorCount = sizeof(SensorPins) / sizeof(SensorPins[0]);
uint16_t sensorValues[SensorCount];


#include <H_bridge_TB6612.hpp>
#define channel2 1
#define resolution_channel2 10

Motor rightMotor = Motor(BIN1, BIN2, PWMB,  channel2, RESOLUTION);
Motor leftMotor = Motor(AIN1, AIN2, PWMA,  channel1, RESOLUTION);

 



QTRSensors qtr;

uint16_t position;

float speed_left = 0;
float speed_right = 0; 
float speed_angular = 0 ;
float speed_linear = 10; 

#include "controler.h"
Controler  main_PID(1, 0, 0);  //(p,i,d)

const int SET_POINT = 3500;

#include "cinematic.h"

void debug();

void setup() {
    Serial.begin(115200);


    // configure the sensors
    qtr.setTypeAnalog();
    qtr.setSensorPins(SensorPins, SensorCount);
    qtr.setEmitterPin(4);


    delay(500);
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH); // turn on Arduino's LED to indicate we are in calibration mode

    // analogRead() takes about 0.1 ms on an AVR.
    // 0.1 ms per sensor * 4 samples per sensor read (default) * 6 sensors
    // * 10 reads per calibrate() call = ~24 ms per calibrate() call.
    // Call calibrate() 400 times to make calibration take about 10 seconds.
    for (uint16_t i = 0; i < 400; i++)
    {
        qtr.calibrate();
    }
    digitalWrite(LED_BUILTIN, LOW); // turn off Arduino's LED to indicate we are through with calibration

    // print the calibration minimum values measured when emitters were on
    for (uint8_t i = 0; i < SensorCount; i++)
    {
        Serial.print(qtr.calibrationOn.minimum[i]);
        Serial.print(' ');
    }
    Serial.println();

    // print the calibration maximum values measured when emitters were on
    for (uint8_t i = 0; i < SensorCount; i++)
    {
        Serial.print(qtr.calibrationOn.maximum[i]);
        Serial.print(' ');
    }
    Serial.println();
    Serial.println();
    delay(1000);


}


void loop(){

    position = qtr.readLineBlack(sensorValues);

    speed_angular = main_PID.output(SET_POINT,position);

    speed_angular = map(speed_angular, 2500,4500,-100,100);

    speed_left = cinematic_left(speed_linear,speed_angular);
    speed_right = cinematic_right(speed_linear,speed_angular);

    leftMotor.drive(speed_left);
    rightMotor.drive(speed_right);

    debug();
    // main_PID.debug();
    Serial.println("");

}


void debug(){

    Serial.print("POS: ");
    Serial.print(position);
    Serial.print(" Speed_angular: ");
    Serial.print(speed_angular);
    Serial.print(" Speed_left: ");
    Serial.print(speed_left);
    Serial.print("Speed Right");
    Serial.print(speed_right);
    // Serial.println("");
}