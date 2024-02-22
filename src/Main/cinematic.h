#include "config.h"
#include <Arduino.h>


#define L 10 
#define R 1 



float cinematic_right(float linear, float angular){

  float right_speed = (linear + angular*L)/R ; 

  if(right_speed > 100)
    right_speed = 100;

  if(right_speed < -100)
    right_speed = -100;

  return right_speed; 

}

float cinematic_left(float linear, float  angular){

  float left_speed = (linear - angular*L)/R ;

  if(left_speed > 100)
    left_speed = 100;

  if(left_speed < -100)
    left_speed = -100;

  //it reversed because of the mecaical assembly 
  return -1*left_speed; 

}