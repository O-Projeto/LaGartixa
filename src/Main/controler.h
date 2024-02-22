#include <Main/config.h>
#ifndef CONTROLER // include guard
#define CONTROLER

class Controler
{
private:
    float proporcional();
    float integrative();
    float derivative();
public:
    float input_values;
    float current_values;
    float KP;
    float KD;
    float KI;
    float error;
    float last_error;
    float delta_error;
    float output_value;
    float integral;
    unsigned long time; 
    unsigned long last_time;
    float  delta_time;
    void debug();

    Controler(float kp, float kd, float ki);
    float output(float input_value, float current_value);


};
#endif



