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

void forward_5cm(){
  digitalWrite(right_A,HIGH);
  digitalWrite(right_B,LOW);
  digitalWrite(left_A,HIGH);
  digitalWrite(left_B,LOW);
  analogWrite(right_pwm,80);
  analogWrite(left_pwm,80);
  delay(400);
  digitalWrite(right_A,HIGH);
  digitalWrite(right_B,HIGH);
  digitalWrite(left_A,HIGH);
  digitalWrite(left_B,HIGH);
  analogWrite(left_pwm,0);
  analogWrite(right_pwm,0);
  }
  

void reverse_coin_collect(){
  digitalWrite(right_A,LOW);
  digitalWrite(right_B,HIGH);
  digitalWrite(left_A,LOW);
  digitalWrite(left_B,HIGH);
  analogWrite(right_pwm,80);
  analogWrite(left_pwm,80);
  delay(200);
  digitalWrite(right_A,HIGH);
  digitalWrite(right_B,HIGH);
  digitalWrite(left_A,HIGH);
  digitalWrite(left_B,HIGH);
  analogWrite(left_pwm,0);
  analogWrite(right_pwm,0);
  }
  
void forward_coin_collect(){
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
  analogWrite(left_pwm,0);
  analogWrite(right_pwm,0);
  }

void forward_coin_drop(){
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
  delay(200);
  }

void turn_right_45(){
  delay(200);
  digitalWrite(right_A,LOW);
  digitalWrite(right_B,HIGH);
  digitalWrite(left_A,HIGH);
  digitalWrite(left_B,LOW);
  analogWrite(right_pwm,100);
  analogWrite(left_pwm,100);
  delay(200);
  analogWrite(right_pwm,0);
  analogWrite(left_pwm,0);
  digitalWrite(right_A,HIGH);
  digitalWrite(right_B,HIGH);
  digitalWrite(left_A,HIGH);
  digitalWrite(left_B,HIGH);
  delay(200);
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
  delay(200);
  }

void turn_left_45(){
  delay(200);
  digitalWrite(right_A,HIGH);
  digitalWrite(right_B,LOW);
  digitalWrite(left_A,LOW);
  digitalWrite(left_B,HIGH);
  analogWrite(right_pwm,100);
  analogWrite(left_pwm,100);
  delay(200);
  analogWrite(right_pwm,0);
  analogWrite(left_pwm,0);
  digitalWrite(right_A,HIGH);
  digitalWrite(right_B,HIGH);
  digitalWrite(left_A,HIGH);
  digitalWrite(left_B,HIGH);
  delay(200);
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


void line_follow(){
  if(S0==1 & S9==1){
    go_forward();
    }
    
  else if(S0==0 && S9==1){
    brake();
    delay(500);
    forward_junction();
    brake();
    delay(500);
    turn_right();
    brake();
    delay(500);
    }
    
  else if(S0==1 && S9==0){
    brake();
    delay(500);
    forward_junction();
    brake();
    delay(500);
    turn_left();
    brake();
    delay(500);
    }
    
}


void color_line_follow(){
  if(S0==1 & S9==1){
    go_forward();
    }

  else if(S0==0 && S9==1){
    brake();
    delay(500);
    forward_junction();
    brake();
    delay(500);
    turn_right_45();
    brake();
    delay(500);
    }
    
  else if(S0==1 && S9==0){
    brake();
    delay(500);
    forward_junction();
    brake();
    delay(500);
    turn_left_45();
    brake();
    delay(500);
    }
  
}


void servo_motors_setup(){
  myservo1.attach(5);
  myservo2.attach(7);
  myservo3.attach(4);
  }
void servo_motors_position(){
  myservo1.write(pos1);//lower arm
  myservo2.write(pos2);//magnet arm
  myservo3.write(pos3);//base gate
  }



void light_red(){
  digitalWrite(red_led_pin,HIGH);
  delay(1000);
  digitalWrite(red_led_pin,LOW);
  }
  
void light_blue(){
  digitalWrite(blue_led_pin,HIGH);
  delay(1000);
  digitalWrite(blue_led_pin,LOW);
  }
  
void light_green(){
  digitalWrite(green_led_pin,HIGH);
  delay(1000);
  digitalWrite(green_led_pin,LOW);
  }


void color_sensor_out(){
  // Setting RED (R) filtered photodiodes to be read
  digitalWrite(S2_,LOW);
  digitalWrite(S3_,LOW);
  
  // Reading the output frequency
  redFrequency = pulseIn(sensorOut, LOW);
  
   // Printing the RED (R) value
  Serial.print("R = ");
  Serial.print(redFrequency);
  delay(100);
  
  // Setting GREEN (G) filtered photodiodes to be read
  digitalWrite(S2_,HIGH);
  digitalWrite(S3_,HIGH);
  
  // Reading the output frequency
  greenFrequency = pulseIn(sensorOut, LOW);
  
  // Printing the GREEN (G) value  
  Serial.print(" G = ");
  Serial.print(greenFrequency);
  delay(100);
 
  // Setting BLUE (B) filtered photodiodes to be read
  digitalWrite(S2_,LOW);
  digitalWrite(S3_,HIGH);
  
  // Reading the output frequency
  blueFrequency = pulseIn(sensorOut, LOW);
  
  // Printing the BLUE (B) value 
  Serial.print(" B = ");
  Serial.print(blueFrequency);
  delay(100);
  if(redFrequency<70){
    light_red();
    color=3;
    //Serial.println("  red");
    
    }
  else if(blueFrequency<70){
    light_blue();
    color=1;
    //Serial.println("  blue");
    }
  else{
    light_green();
    color=2;
    //Serial.println("  green");
    }
  }



void servo_motors(){

  //lower arm down
  for(pos1 = 0; pos1 < 140; pos1 += 1){
    myservo1.write(pos1);
    delay(10);
  }
  reverse_coin_collect();
  
  delay(500);
  
  //lower arm up
  for(pos1 = 140; pos1 > 0; pos1 -= 1){
    myservo1.write(pos1);
    delay(10);
  }
  delay(500);

  //magnet servo displace
  myservo2.write(60);
  delay(500);                                  
  myservo2.write(0);

  delay(500);
  color_sensor_out();
  }

void gate_servo(){
  myservo3.write(90);
  delay(1000);                                  
  myservo3.write(0);  
  }

/*
//setup the display settings
void display_setup(){
  delay(100);  // This delay is needed to let the display to initialize
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Initialize display with the I2C address of 0x3C
  display.clearDisplay();  // Clear the buffer
  display.setTextColor(WHITE);  // Set color of the text
  display.setRotation(0);  // Set orientation. Goes from 0, 1, 2 or 3
  display.setTextWrap(false);  
  display.dim(0);  //Set brightness (0 is maximun and 1 is a little dim)
  display.setFont(&FreeMono9pt7b);
  display.setTextSize(0); 
  display.setCursor(0, 35);  // (x,y)
  display.println("KINAD");
  delay(10000);
  
  }
  
void printing_text(){
 // Set text size. We are using a custom font so you should always use the text size of 0
  display.clearDisplay();
  display.setCursor(0, 35);  // (x,y)
  display.println(TEXT);
  display.display();
  display.clearDisplay();
  }
  */


void setup_color_sensor(){
  pinMode(S0_, OUTPUT);
  pinMode(S1_, OUTPUT);
  pinMode(S2_, OUTPUT);
  pinMode(S3_, OUTPUT);
  
  pinMode(sensorOut, INPUT);
  
  digitalWrite(S0_,HIGH);
  digitalWrite(S1_,LOW);
  }

//lighting the leds for 1000ms
void led_setup(){
  pinMode(green_led_pin,OUTPUT);
  pinMode(red_led_pin,OUTPUT);
  pinMode(blue_led_pin,OUTPUT);
  }



  
