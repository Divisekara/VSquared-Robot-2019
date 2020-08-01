void pin_define(){
  pinMode(right_1,OUTPUT);
  pinMode(right_2,OUTPUT);
  pinMode(left_1,OUTPUT);
  pinMode(left_2,OUTPUT);
  pinMode(right_pwm_pin,OUTPUT);
  pinMode(left_pwm_pin,OUTPUT);
  pinMode(right_en,OUTPUT);
  pinMode(left_en,OUTPUT); 

  pinMode(right_trig,OUTPUT);
  pinMode(right_echo,INPUT);
  pinMode(left_trig,OUTPUT);
  pinMode(left_echo,INPUT);
  pinMode(front_trig,OUTPUT);
  pinMode(front_echo,INPUT);
  
}

void wall_follow_sense(){
  digitalWrite(left_trig,LOW);
  digitalWrite(right_trig,LOW);
  digitalWrite(front_trig,LOW);
  
  delayMicroseconds(2);
  
  digitalWrite(left_trig,HIGH);
  digitalWrite(right_trig,HIGH);
  digitalWrite(front_trig,HIGH);

  delayMicroseconds(5);
  
  digitalWrite(left_trig,LOW);
  digitalWrite(right_trig,LOW);
  digitalWrite(front_trig,LOW);
  
  left_duration=pulseIn(left_echo,HIGH);
  right_duration=pulseIn(right_echo,HIGH);
  front_duration=pulseIn(front_echo,HIGH);

  left_distance=left_duration*0.034/2;
  right_distance=right_duration*0.034/2;
  front_distance=front_duration*0.034/2;
  }

void wall_follow_algo(){
  if (left_distance<3){
    turn_right();
    }
   else if(left_distance>8){
    turn_left();
    }
   else{
    go_forward();    
    }
  }

// encoder event for the interrupt call
void leftEncoderEvent() {
  if (digitalRead(left_encoder_A) == HIGH) {
    if (digitalRead(left_encoder_B) == LOW) {
      leftCount++;
    } else {
      leftCount--;
    }
  } else {
    if (digitalRead(left_encoder_B) == LOW) {
      leftCount--;
    } else {
      leftCount++;
    }
  }
}
 
// encoder event for the interrupt call
void rightEncoderEvent() {
  if (digitalRead(right_encoder_A) == HIGH) {
    if (digitalRead(right_encoder_B) == LOW) {
      rightCount++;
    } else {
      rightCount--;
    }
  } else {
    if (digitalRead(right_encoder_B) == LOW) {
      rightCount--;
    } else {
      rightCount++;
    }
  }
}
