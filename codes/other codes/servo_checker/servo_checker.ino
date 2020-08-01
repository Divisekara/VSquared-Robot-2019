#include <Servo.h>
int servo_pin=5;
Servo myservo;

void setup() {
  myservo.attach(servo_pin);
  pinMode(servo_pin,OUTPUT);
}

void loop() {
  /*
  digitalWrite(servo_pin,HIGH);
  delayMicroseconds(1450);
  digitalWrite(servo_pin,LOW);
  delayMicroseconds(18550);
  */
  
  myservo.write(0);
  delay(1000);
  myservo.write(90);
  delay(1000);
  myservo.write(180);
  delay(1000);


}
