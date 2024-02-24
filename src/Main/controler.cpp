#include "controler.h"
// #include <Main/tools.h>

Controler::Controler(float kp,float ki, float kd)
{   KP = kp;
    KD = kd;
    KI = ki;
    integral = 0;
    time = 0 ; 
    last_time = 0 ;
    delta_time= 0 ;
    last_error = 0;
    error = 0;
}

float Controler::output(float input_value, float current_value){
    input_values = input_value;
    current_values = current_value;
    error =  input_value - current_value ;
    time = millis();
    delta_time = (double)(time - last_time)/1000;
    last_error = error;
    last_time = time;
    if(input_value == 0){
        output_value =  proporcional() + derivative() ; // retirado "input value +" 
    }else{
        output_value =  proporcional() + integrative() + derivative();
    }

    // output_value = saturation(output_value,1000);
    return output_value;
}

float Controler::proporcional(){

    return error*KP; 

}

float Controler::integrative(){
    integral += error*delta_time;
    // integral = saturation(integral,1000);
    return integral*KI;

}

float Controler::derivative(){
    if (last_error - error!= 0){
        delta_error = (last_error - error)/delta_time;
    }
    else {
        delta_error = 0; 
    }
    return delta_error*KD;

}

void Controler::debug(){
    
     Serial.print(" |delta_time: ");
    Serial.print(delta_time);

    Serial.print(" |input_values: ");
    Serial.print(input_values);
    Serial.print(" |current_values: ");
    Serial.print(current_values);

    Serial.print(" ||error: ");
    Serial.print(error);
    Serial.print(" |P: ");
    Serial.print(proporcional());
    Serial.print(" |I: ");
    Serial.print(integrative());
    Serial.print(" |D: ");
    Serial.print(derivative());

    Serial.print(" |output_value: ");
    Serial.print(output_value);
    // Serial.println("");

}





