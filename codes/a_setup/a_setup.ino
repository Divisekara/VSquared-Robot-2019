#include "a_pin_allocation.h"
#include <Servo.h>
Servo gateServo;

int Left_PWM, Right_PWM;
int Base_PWM = 60;
int Left_Base = 60;
int Right_Base = 60;

int Leften_Count = 0;
int Righten_Count = 0; 
int encoderCount = 0;
int encoderLeft = 0;
int encoderRight = 0;

int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;

int k=0;
int z=0;
int flag = 0;
String TEXT;

int color=0;

int gatePos = 0;

int ir[10] = { A14, A13, A12, A11, A10, A9, A8, A7, A6, A5};

int IR[10] = { 0 };


int Last_Read = 0;
int Left_Sens = 0;
int Right_Sens = 0;
int taskCount = 0;

Servo myservo1;
Servo myservo2;
Servo myservo3;

int pos1 = 0;
int pos2 = 0;
int pos3 = 0;


int y=0;


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
  
  for(int i=0; i<10; i++) 
  {
    pinMode(ir[i], INPUT);
  }
  
  Serial.begin(9600);
  myservo1.attach(5);
  myservo2.attach(7);
  myservo3.attach(4);

  myservo1.write(pos1);//lower arm
  myservo2.write(pos2);//magnet arm
  myservo3.write(pos3);//base gate

  setup_color_sensor();
  led_setup();
}
