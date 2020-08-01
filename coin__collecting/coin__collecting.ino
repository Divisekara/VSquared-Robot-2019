#include <Servo.h>
Servo myservo1;
Servo myservo2;
int pos1 = 130;
int pos2 = 5;

void definition_coin_collect(){
  pinMode(7,LOW);
  pinMode(8,LOW);
  int pos1 = 00;
  int pos2 = 30;
  myservo1.attach(7);
  myservo2.attach(8);
  pinMode(7,HIGH);
  pinMode(8,HIGH);
  }

void coin_collecting(){
  myservo1.write(pos1);
  myservo2.write(pos2);
  for(pos1 = 120; pos1 > 10; pos1 -= 1){
    myservo1.write(pos1);
    delay(20);
  }
  delay(1000);
  for(pos1 = 10; pos1 < 120; pos1 += 1){
    myservo1.write(pos1);
    delay(20);
  }
  delay(1000);
  for(pos2 = 5; pos2 < 30; pos2 += 1){
    myservo2.write(pos2);
    delay(20);
  }
  delay(1000);
  for(pos2 = 30; pos2 > 5; pos2 -= 1){
    myservo2.write(pos2);
    delay(20);
  }
  delay(1000);
  }
