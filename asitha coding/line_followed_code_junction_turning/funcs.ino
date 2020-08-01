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


void forward(){digitalWrite(right_A,HIGH);digitalWrite(right_B,LOW);digitalWrite(left_A,HIGH);digitalWrite(left_B,LOW);}

void right_forward_left_stop(){digitalWrite(right_A,HIGH);digitalWrite(right_B,LOW);digitalWrite(left_A,HIGH);digitalWrite(left_B,HIGH);}

void left_forward_right_stop(){digitalWrite(right_A,HIGH);digitalWrite(right_B,HIGH);digitalWrite(left_A,HIGH);digitalWrite(left_B,LOW);}

void brake(){digitalWrite(right_A,HIGH);digitalWrite(right_B,HIGH);digitalWrite(left_A,HIGH);digitalWrite(left_B,HIGH);}

void sensor_reading(){
  for (int i=0; i<8; i++){
      sensor_reading_array[i] = adc(analogRead(IR_pin[i])); }}

void sensor_most(){
  S0=adc(analogRead(A4));
  S9=adc(analogRead(A14));
  }
