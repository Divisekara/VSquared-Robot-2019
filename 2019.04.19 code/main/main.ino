#include "variables.h"

void setup() {
  Serial.begin(9600);
  pinMode(right_encoder_A,INPUT);
  pinMode(right_encoder_B,INPUT);
  pinMode(left_encoder_A,INPUT);
  pinMode(left_encoder_B,INPUT);
  
  attachInterrupt(0, leftEncoderEvent, CHANGE);
  attachInterrupt(1, rightEncoderEvent, CHANGE);

  digitalWrite(right_en,HIGH);
  digitalWrite(left_en,HIGH);
  
  pin_define();
}

void loop() {
  wall_follow_sense();
  wall_follow_algo();
 // go_forward();
 
/*
  Serial.print("Right Count: ");
  Serial.println(rightCount);
  Serial.print("Left Count: ");
  Serial.println(leftCount);
  Serial.println();
  delay(500);
  */

}
