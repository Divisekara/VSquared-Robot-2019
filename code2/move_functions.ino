void breaking(){ //active break
  digitalWrite(right_1,HIGH);
  digitalWrite(right_2,HIGH);
  
  digitalWrite(left_1,HIGH);
  digitalWrite(left_2,HIGH);
  }
  
void turn_left(){ //turn left configurations
  digitalWrite(right_1,HIGH);
  digitalWrite(right_2,LOW);
  
  digitalWrite(left_1,HIGH);
  digitalWrite(left_2,HIGH);
  
  give_pwm();
  }

void turn_right(){ //turn right configurations
  digitalWrite(right_1,HIGH);
  digitalWrite(right_2,HIGH);
  
  digitalWrite(left_1,HIGH);
  digitalWrite(left_2,LOW);

  give_pwm();
  }

void go_forward(){ //go forawardd configurations
  digitalWrite(right_1,HIGH);
  digitalWrite(right_2,LOW);
  
  digitalWrite(left_1,HIGH);
  digitalWrite(left_2,LOW);

  give_pwm();
}

void give_pwm(){
  analogWrite(right_pwm_pin,right_pwm);
  analogWrite(left_pwm_pin,left_pwm);
  }
