#include "pins.h"
#include "variables.h"


int Last_Read = 0;

int Error_values[8] = {-3, -2, -1, 0, 0, 1, 2, 3};

//BEST KP=10 KD=20
float Kp = 10;   
float Ki = 0;
float Kd = 5;

float Error=0;
float previousError = 0;
float totalError = 0;
float power = 0;

#include "func.h"
#include "pid.h"

void setup() {
  motor_driver_pin_mode();
  line_sensor_pin_mode();
}

void loop() {
  sensor_most();
  sensor_reading();
  line_pid();
  
  //task 0 
  if(S0==1 & S9==1){
    go_forward();
    }
    
  else if(S0==0 && S9==1){
    brake();
    delay(1000);
    forward_junction();
    brake();
    delay(1000);
    turn_right();
    brake();
    delay(1000);
    }
    
  else if(S0==1 && S9==0){
    brake();
    delay(1000);
    forward_junction();
    brake();
    delay(1000);
    turn_left();
    brake();
    delay(1000);
    }
    
  if (black==8){
    brake();
    }
    
}
