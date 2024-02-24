#include "config.h"
#include <Arduino.h>


#define L 0.72 
#define R 0.36



float cinematic_right(float linear, float angular){

  float right_speed = (linear + angular*L)/R ; 

  if(right_speed > 1000)
    right_speed = 1000;

  if(right_speed < -1000)
    right_speed = -1000;

  return right_speed; 

}

float cinematic_left(float linear, float  angular){

  float left_speed = (linear - angular*L)/R ;

  if(left_speed > 1000)
    left_speed = 1000;

  if(left_speed < -1000)
    left_speed = -1000;

  //it reversed because of the mecaical assembly 
  return left_speed; 

}