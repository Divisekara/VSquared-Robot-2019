//Motor driver pin allocation
#define right_enable 24
#define right_A 29
#define right_B 28
#define left_enable 26
#define left_A 27
#define left_B 25

#define right_pwm 3
#define left_pwm 2

void setup() {
  //Motor driver pin modes
  pinMode(right_enable,OUTPUT);pinMode(left_enable,OUTPUT);
  pinMode(right_A,OUTPUT);pinMode(right_B,OUTPUT);
  pinMode(left_A,OUTPUT);pinMode(left_B,OUTPUT);
  //enabling the two motors into active
  digitalWrite(right_enable,HIGH);digitalWrite(left_enable,HIGH);

  digitalWrite(right_A,LOW);
  digitalWrite(right_B,HIGH);
  digitalWrite(left_A,LOW);
  digitalWrite(left_B,HIGH);
  analogWrite(right_pwm,80);
  analogWrite(left_pwm,80);

}

void loop() {



}
