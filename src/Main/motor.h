#include <Main/config.h>

class motor
{
private:
  
public:
    int In_A ;
    int In_B ; 
    int Pwm  ;
    int Canal ; 
    motor(int In_A, int In_B,int Pwm, int Canal);
   
};

motor::motor(int IN_A, int IN_B,int PWM, int CANAL)
{   
    In_A = IN_A ;
    In_B = IN_B ;
    Pwm = PWM ; 
    Canal = CANAL;

    pinMode(In_A,OUTPUT);
    pinMode(In_B,OUTPUT);
    ledcAttachPin(Pwm, Canal);
    ledcSetup(Canal, FREQUENCY, 10);
    digitalWrite(In_A, LOW);
    digitalWrite(In_B, LOW);

};

