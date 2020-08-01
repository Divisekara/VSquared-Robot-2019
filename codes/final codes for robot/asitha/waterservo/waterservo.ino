#include <Servo.h>

Servo myservo4;

int pos4 = 0;

void setup() {
  myservo4.attach(6);
}

void watermotor(){
  myservo4.write(pos4);
  for(pos4 = 0; pos4 < 100; pos4 += 1){
    myservo4.write(pos4);
    delay(20);
  }
  delay(1000);
  for(pos4 = 100; pos4 > 0; pos4 -= 1){
    myservo4.write(pos4);
    delay(20);
  }
  delay(1000);
}

void loop() {
  watermotor();
}
