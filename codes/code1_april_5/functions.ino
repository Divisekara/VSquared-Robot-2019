void pin_define(){
  pinMode(right_1,OUTPUT);
  pinMode(right_2,OUTPUT);
  pinMode(left_1,OUTPUT);
  pinMode(left_2,OUTPUT);
  pinMode(right_pwm_pin,OUTPUT);
  pinMode(left_pwm_pin,OUTPUT);
  pinMode(right_en,OUTPUT);
  pinMode(left_en,OUTPUT); 
}

void go_forward(){
  digitalWrite(right_1,HIGH);
  digitalWrite(right_2,LOW);
  
  digitalWrite(left_1,HIGH);
  digitalWrite(left_2,LOW);
  
  digitalWrite(right_en,HIGH);
  digitalWrite(left_en,HIGH);
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
