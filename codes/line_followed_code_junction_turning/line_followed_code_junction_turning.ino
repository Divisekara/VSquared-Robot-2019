#include "pins.h"
#include "variables.h"
int Last_Read = 0;

int Error_values[8] = {-3, -2, -1, 0, 0, 1, 2, 3};
#include <Servo.h>

Servo myservo1;
Servo myservo2;
Servo myservo3;

//BEST KP=10 KD=20
//BEST BEST KP=9 KD=19
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
  setup_color_sensor();
  led_setup();
}

//int task=0;


void loop(){
  sensor_most();
  edge=S0+S9;
  
  sensor_reading();

  all=black+edge;
  line_pid();
  //white=1=0  black=1
  
  
  if (black==0 && edge==2){
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
    
  else if (task==2){ //line follow after coin collecting
    line_follow();
    TEXT="3 line follow";
    }

  else if(task==3){ //detecting color paths
    if (color==1){//blue
      brake();delay(500);
      forward_junction();
      brake();delay(500);
      turn_left_45();
      brake();delay(500);
      }
      
    else if (color==2){//green
      brake();delay(500);
      forward_junction();
      brake();delay(500);
      forward_junction();
      brake();delay(500);
      }

    else if (color==3){//red
      brake();delay(500);
      forward_junction();
      brake();delay(500);
      turn_right_45();
      brake();delay(500);
      }
    task+=1;
    }

  else if(task==4){//color line follow
    color_line_follow();
    }
  
  else if (task==5){ //droping the coin
    brake();
    delay(500);
    forward_coin_drop();
    brake();
    delay(500);
    gate_servo();
    delay(500);
    task+=1;
    }
    
  else if(task==6){//color line folllow after dropiing the coin
    color_line_follow();
    if (S0==0 || S9==0){
      task+=1;
      if (color==1){     //blue
        brake();delay(500);
        forward_5cm();
        brake();delay(500);
        turn_left_45();
        brake();delay(500);
        }
      
      else if (color==2){  //green
        brake();delay(500);
        forward_junction();
        brake();delay(500);
        forward_junction();
        brake();delay(500);
        }

      else if (color==3){  //red
        brake();delay(500);
        forward_5cm();
        brake();delay(500);
        turn_right_45();
        brake();delay(500);
        }
    }
  }

  else if(task==7){
    line_follow();
    if(black==8){
      task+=1;
      light_blue();
      brake();
      delay(2000);
      }
    }
  
  else if(task==8) {
    brake();
    }
  else{
    brake();
    }
}
