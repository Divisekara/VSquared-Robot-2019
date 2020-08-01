void motor_driver_pin_mode(){
  //Motor driver pin modes
  pinMode(right_enable,OUTPUT);pinMode(left_enable,OUTPUT);
  pinMode(right_A,OUTPUT);pinMode(right_B,OUTPUT);
  pinMode(left_A,OUTPUT);pinMode(left_B,OUTPUT);
  //enabling the two motors into active
  digitalWrite(right_enable,HIGH);digitalWrite(left_enable,HIGH);
  }

void line_sensor_pin_mode(){
  pinMode(A4,INPUT);pinMode(A5,INPUT);pinMode(A6,INPUT);pinMode(A7,INPUT);pinMode(A8,INPUT);pinMode(A9,INPUT);pinMode(A10,INPUT);pinMode(A11,INPUT);pinMode(A12,INPUT);pinMode(A13,INPUT);pinMode(A14,INPUT);
  }

int adc(int n){
  if (n<200){return 0;}
  else{return 1;}}


void forward_junction(){
  digitalWrite(right_A,HIGH);
  digitalWrite(right_B,LOW);
  digitalWrite(left_A,HIGH);
  digitalWrite(left_B,LOW);
  analogWrite(right_pwm,80);
  analogWrite(left_pwm,80);
  delay(300);
  digitalWrite(right_A,HIGH);
  digitalWrite(right_B,HIGH);
  digitalWrite(left_A,HIGH);
  digitalWrite(left_B,HIGH);
  analogWrite(left_pwm,0);
  analogWrite(right_pwm,0);
  }


void brake(){
  digitalWrite(right_A,HIGH);
  digitalWrite(right_B,HIGH);
  digitalWrite(left_A,HIGH);
  digitalWrite(left_B,HIGH);
  analogWrite(left_pwm,0);
  analogWrite(right_pwm,0);
  }

void go_forward(){
  digitalWrite(right_A,HIGH);
  digitalWrite(right_B,LOW);
  digitalWrite(left_A,HIGH);
  digitalWrite(left_B,LOW);
  analogWrite(right_pwm,right_speed);
  analogWrite(left_pwm,left_speed);
  }

void turn_right(){
  delay(200);
  digitalWrite(right_A,LOW);
  digitalWrite(right_B,HIGH);
  digitalWrite(left_A,HIGH);
  digitalWrite(left_B,LOW);
  analogWrite(right_pwm,100);
  analogWrite(left_pwm,100);
  delay(400);
  analogWrite(right_pwm,0);
  analogWrite(left_pwm,0);
  digitalWrite(right_A,HIGH);
  digitalWrite(right_B,HIGH);
  digitalWrite(left_A,HIGH);
  digitalWrite(left_B,HIGH);
  delay(1000);
  }
  
void turn_left(){
  delay(200);
  digitalWrite(right_A,HIGH);
  digitalWrite(right_B,LOW);
  digitalWrite(left_A,LOW);
  digitalWrite(left_B,HIGH);
  analogWrite(right_pwm,100);
  analogWrite(left_pwm,100);
  delay(400);
  analogWrite(right_pwm,0);
  analogWrite(left_pwm,0);
  digitalWrite(right_A,HIGH);
  digitalWrite(right_B,HIGH);
  digitalWrite(left_A,HIGH);
  digitalWrite(left_B,HIGH);
  delay(1000);
  }


void sensor_reading(){
  for (int i=1; i<9; i++){
      sensor_reading_array[i] = adc(analogRead(IR_pin[i]));
      }
}
  
void sensor_most(){
  S0=adc(analogRead(A4));
  S9=adc(analogRead(A14));
  }
