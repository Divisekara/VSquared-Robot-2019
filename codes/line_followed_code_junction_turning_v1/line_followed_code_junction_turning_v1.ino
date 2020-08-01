#include "pins.h"
#include "variables.h"
int Last_Read = 0;

int Error_values[8] = {-3, -2, -1, 0, 0, 1, 2, 3};
#include <Servo.h>

Servo myservo1;
Servo myservo2;
Servo myservo3;

//BEST KP=10 KD=20
float Kp = 9;   
float Ki = 0;
float Kd = 19;

float Error=0;
float previousError = 0;
float totalError = 0;
float power = 0;

#include "func.h"
#include "pid.h"

void setup() {
  motor_driver_pin_mode();
  line_sensor_pin_mode();
  servo_motors_setup();
  servo_motors_position();
  //display_setup();
}

int task=0;

void loop(){
  sensor_most();
  sensor_reading();
  line_pid();
  //black=black+S0+S9;
  
  if (black==0){
    task+=1;
    }

  if (task==0){
    TEXT="1 line follow";
    line_follow();
  }
  
  else if(task==1){
    brake();
    TEXT="2 coin collecting";
    servo_motors();
    delay(1000);
    forward_coin_collect();
    brake();
    delay(1000);
    task += 1;
    }
    
  else if (task==2){
    line_follow();
    TEXT="3 line follow";
    }

  else{
    brake();
    TEXT="4 BRAKE";
    }
}
