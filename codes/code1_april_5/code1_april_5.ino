#include "pins.h"

void setup() {
  Serial.begin(9600);
  pinMode(right_encoder_A,INPUT);
  pinMode(right_encoder_B,INPUT);
  pinMode(left_encoder_A,INPUT);
  pinMode(left_encoder_B,INPUT);
  
  attachInterrupt(0, leftEncoderEvent, CHANGE);
  attachInterrupt(1, rightEncoderEvent, CHANGE);

  pin_define();
}

void loop() {
  go_forward();
  analogWrite(right_pwm_pin,right_pwm);
  analogWrite(left_pwm_pin,left_pwm);

  Serial.print("Right Count: ");
  Serial.println(rightCount);
  Serial.print("Left Count: ");
  Serial.println(leftCount);
  Serial.println();
  delay(500);

}
