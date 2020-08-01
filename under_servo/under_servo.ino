#include <Servo.h>
Servo under_servo;

void setup() {
  pinMode(10,OUTPUT);
 
}

void loop() {
  under_servo.write(90);
    
}
