#include <Servo.h>

Servo myservo1;
Servo myservo2;
Servo myservo3;

int pos1 = 0;
int pos2 = 0;
int pos3 = 0;

void setup(){
  myservo1.attach(5);
  myservo2.attach(7);
  myservo3.attach(4);
  myservo1.write(pos1);
  myservo2.write(pos2);
  myservo3.write(pos3);
}

void motors(){
  
  for(pos1 = 0; pos1 < 140; pos1 += 1){
    myservo1.write(pos1);
    delay(10);
  }
  delay(1000);
  for(pos1 = 140; pos1 > 0; pos1 -= 1){
    myservo1.write(pos1);
    delay(10);
  }
  delay(1000);
  
  myservo2.write(60);
  delay(500);                                  
  myservo2.write(0);
  delay(1000);

  myservo3.write(90);
  delay(1000);                                  
  myservo3.write(0);  
  }
void loop() {
  motors();

}
