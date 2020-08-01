#include "pins.h"
#include "variables.h"
#include "functions.h"


void setup(){  
  motor_driver_pinmodes();
  ultrasonic_pinmodes(); 
  
  }

void loop(){
  distance_calculate();
  distance_printing();
  /*
  if (right_distance<5.5 && left_distance>5.5){
    right_forward_left_stop();  
    }
  else if(right_distance>5.5 && left_distance<5.5) {
     left_forward_right_stop();
    }
  else{
      forward();
    }*/
  }
