#include "aa_pin_allocation.h"


int Base_PWM = 60;
int Left_PWM , Right_PWM ;

int ir[8] = { A7,A8,A9,A10,A12,A13,A14,A15 };

int IR[8] = { 0 };


int Last_Read = 0;


void setup() 
{
  pinMode(Left_Dir1, OUTPUT);      // motor driver
  pinMode(Left_Dir2, OUTPUT);
  pinMode(Left_Speed, OUTPUT);
  pinMode(Right_Dir1, OUTPUT);
  pinMode(Right_Dir2, OUTPUT);
  pinMode(Right_Speed, OUTPUT);

  pinMode(ftrigPin, OUTPUT);      // sonar sensors
  pinMode(fechoPin, INPUT);
  pinMode(ltrigPin, OUTPUT); 
  pinMode(lechoPin, INPUT);
  pinMode(rtrigPin, OUTPUT); 
  pinMode(rechoPin, INPUT);
  
  for(int i=0; i<8; i++) 
  {
    pinMode(ir[i], INPUT);
  }

  Serial.begin(9600);
}


void loop()
{
  Line_Follow();
  //Ir_Sensor();
}

