#include "a_pin_allocation.h"
#include "a_variables.h"
#include <Servo.h>

Servo gateServo;
Servo myservo1;
Servo myservo2;
Servo myservo4;

#include "h_encoders.h"
#include "a_functions.h"

void setup() 
{
  motor_driver_setup();
  sonar_sensor_setup();
  encoder_setup();
  servo_attach_setup();
  servo_position_setup();

  for(int i=0; i<10; i++) 
  {
    pinMode(ir[i], INPUT);
  }
  Serial.begin(9600);
}

int task=0;

void loop()
{
  Line_Follow();
  //Left_Forward_Base();
  //Right_Forward_Base();
  //Ir_Sensor();
  //Count_Mid();
  //Count_Right();
  //Serial.println();
  //Line_PID();
  //Forward();
  //Wall_Maze();
}
