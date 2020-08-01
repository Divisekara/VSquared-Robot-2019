#include "a_pin_allocation.h"
#include <Servo.h>
Servo gateServo;
Servo myservo1;
Servo myservo2;
Servo myservo4;

int Left_PWM, Right_PWM;
int Base_PWM = 150;
int Left_Base = 70; //76;
int Right_Base = 70; //80;

int Leften_Count = 0;
int Righten_Count = 0; 

int gatePos = 0;
int pos1 = 0;
int pos2 = 0;
int pos4 = 0;

int ir[10] = { A14, A13, A12, A11, A10, A9, A8, A7, A6, A5};

int IR[10] = { 0 };


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

  pinMode(Left_A, INPUT);
  pinMode(Left_B, INPUT);
  pinMode(Right_A, INPUT);
  pinMode(Right_B, INPUT);


  gateServo.attach(4);
  myservo1.attach(5);
  myservo2.attach(7);
  myservo4.attach(6);

  myservo1.write(pos1);
  myservo2.write(pos2);
  myservo4.write(pos4);
  gateServo.write(0);
  
  for(int i=0; i<10; i++) 
  {
    pinMode(ir[i], INPUT);
  }
  
  Serial.begin(9600);
}


void loop()
{
  //Line_Follow();
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
