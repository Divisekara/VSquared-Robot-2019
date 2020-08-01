void motor_driver_pinmodes(){
  //Motor driver pin modes
  pinMode(right_enable,OUTPUT);pinMode(left_enable,OUTPUT);
  pinMode(right_A,OUTPUT);pinMode(right_B,OUTPUT);
  pinMode(left_A,OUTPUT);pinMode(left_B,OUTPUT);
  //enabling the two motors into active
  digitalWrite(right_enable,HIGH);digitalWrite(left_enable,HIGH);
  }
void ultrasonic_pinmodes(){
  pinMode(right_echo,INPUT);pinMode(right_trig,OUTPUT);
  pinMode(left_echo,INPUT);pinMode(left_trig,OUTPUT);
  pinMode(forw_echo,INPUT);pinMode(forw_trig,OUTPUT);
  }

void distance_calculate(){
  digitalWrite(right_trig,LOW);delayMicroseconds(2);digitalWrite(right_trig,HIGH);delayMicroseconds(10);digitalWrite(right_trig,LOW);
  right_distance = pulseIn(right_echo,HIGH) * 0.034/2;

  digitalWrite(left_trig,LOW);delayMicroseconds(2);digitalWrite(left_trig,HIGH);delayMicroseconds(10);digitalWrite(left_trig,LOW);
  left_distance = pulseIn(left_echo,HIGH) * 0.034/2;

  digitalWrite(forw_trig,LOW);delayMicroseconds(2);digitalWrite(forw_trig,HIGH);delayMicroseconds(10);digitalWrite(forw_trig,LOW);
  forw_distance = pulseIn(forw_echo,HIGH) * 0.034/2;
  }

void distance_printing(){
  Serial.print("right distance ");Serial.print(right_distance);
  Serial.print(" left distance");Serial.print(left_distance);
  Serial.print(" forward distance");Serial.print(forw_distance);
  Serial.println();
  delay(1000);
  }

void forward(){
  digitalWrite(right_A,HIGH);
  digitalWrite(right_B,LOW);
  digitalWrite(left_A,HIGH);
  digitalWrite(left_B,LOW);
  analogWrite(right_pwm,80);
  analogWrite(left_pwm,80);
  delay(500);
  digitalWrite(right_A,HIGH);
  digitalWrite(right_B,HIGH);
  digitalWrite(left_A,HIGH);
  digitalWrite(left_B,HIGH);
  analogWrite(right_pwm,0);
  analogWrite(left_pwm,0);
  }

void right_forward_left_stop(){
  digitalWrite(right_A,HIGH);
  digitalWrite(right_B,LOW);
  digitalWrite(left_A,HIGH);
  digitalWrite(left_B,LOW);
  analogWrite(right_pwm,80);
  analogWrite(left_pwm,0);
  /*delay(200);
  digitalWrite(right_A,HIGH);
  digitalWrite(right_B,HIGH);
  digitalWrite(left_A,HIGH);
  digitalWrite(left_B,HIGH);
  analogWrite(right_pwm,0);
  analogWrite(left_pwm,0);*/
  }

void left_forward_right_stop(){
  digitalWrite(right_A,HIGH);
  digitalWrite(right_B,LOW);
  digitalWrite(left_A,HIGH);
  digitalWrite(left_B,LOW);
  analogWrite(right_pwm,0);
  analogWrite(left_pwm,80);
  /*delay(200);
  digitalWrite(right_A,HIGH);
  digitalWrite(right_B,HIGH);
  digitalWrite(left_A,HIGH);
  digitalWrite(left_B,HIGH);
  analogWrite(right_pwm,0);
  analogWrite(left_pwm,0);
  }

void brake(){digitalWrite(right_A,HIGH);digitalWrite(right_B,HIGH);digitalWrite(left_A,HIGH);digitalWrite(left_B,HIGH);
  analogWrite(left_pwm,0);
  analogWrite(right_pwm,0);}
