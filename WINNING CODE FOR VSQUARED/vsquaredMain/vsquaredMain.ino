#include "headers\vsquaredPinConfig.h"
#include "headers\vsquaredVariables.h"
#include "headers\vsquaredDirections.h"
#include "headers\vsquaredEncoders.h"
#include "headers\vsquaredIrSensor.h"
#include "headers\vsquaredSonarSensors.h"
#include "headers\vsquaredLinPid.h"
#include "headers\vsquaredColour.h"
#include <Servo.h>

Servo gateServo;
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;

#include "headers\vsquaredServo.h"
#include "headers\vsquaredLineMaze.h"
#include "headers\vsquaredWallMaze.h"
#include "headers\vsquaredWaterTrans.h"
#include "headers\vsquaredTaskComplete.h"

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
    
    pinMode(power_Led, OUTPUT);

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

    myservo4.attach(6);
    myservo4.write(pos4);

    setup_color_sensor();
    led_setup();
}


void loop()
{
    completeTask();
    
}