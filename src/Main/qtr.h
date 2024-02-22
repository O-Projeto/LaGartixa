#include "config.h"

#include <QTRSensors.h>
#include <Arduino.h>

QTRSensors qtr;

uint16_t sensorValues[SensorCount];

void setup_qtr()
{
  // configure the sensors
  qtr.setTypeAnalog();
  qtr.setSensorPins(SensorPins, SensorCount);
  qtr.setEmitterPin(2);

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

}

uint16_t robot_position()
{
  // read calibrated sensor values and obtain a measure of the line position
  // from 0 to 5000
  return uint16_t position = qtr.readLineWhite(sensorValues);


}
