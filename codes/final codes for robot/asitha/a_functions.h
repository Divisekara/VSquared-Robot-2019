/**************************motor controlling functions******************************/
void Enable()
{
  digitalWrite(Left_en, HIGH);
  digitalWrite(Right_en, HIGH);
}

void Disenable()
{
  digitalWrite(Left_en, LOW);
  digitalWrite(Right_en, LOW);
}

void Left_Forward() 
{
  digitalWrite(Left_Dir1, HIGH);
  digitalWrite(Left_Dir2, LOW);
  analogWrite(Left_Speed, Left_PWM);
}

void Left_Forward_Base()
{
  Enable();
  digitalWrite(Left_Dir1, HIGH);
  digitalWrite(Left_Dir2, LOW);
  analogWrite(Left_Speed, Left_Base);
}

void Left_Reverse_Base() 
{
  Enable();
  digitalWrite(Left_Dir1, LOW);
  digitalWrite(Left_Dir2, HIGH);
  analogWrite(Left_Speed, 70);
}

void Right_Forward()
{
  digitalWrite(Right_Dir1, HIGH);
  digitalWrite(Right_Dir2, LOW);
  analogWrite(Right_Speed, Right_PWM); 
}

void Right_Forward_Base()
{
  Enable();
  digitalWrite(Right_Dir1, HIGH);
  digitalWrite(Right_Dir2, LOW);
  analogWrite(Right_Speed, Right_Base); 
}

void Right_Reverse_Base()
{
  Enable();
  digitalWrite(Right_Dir1, LOW);
  digitalWrite(Right_Dir2, HIGH);
  digitalWrite(Right_Speed, 50); 
}


void Left_Brake()
{
  digitalWrite(Left_Dir1, HIGH);
  digitalWrite(Left_Dir2, HIGH); 
  digitalWrite(Left_Speed, HIGH);
}

void Right_Brake()
{
  digitalWrite(Right_Dir1, HIGH);
  digitalWrite(Right_Dir2, HIGH);  
  analogWrite(Right_Speed, HIGH);
}

void Forward()
{
  Enable();
  Left_Forward();
  Right_Forward();
}

void Forward_Base()
{
  Enable();
  digitalWrite(Left_Dir1, HIGH);
  digitalWrite(Left_Dir2, LOW);
  analogWrite(Left_Speed, Left_Base);
  
  digitalWrite(Right_Dir1, HIGH);
  digitalWrite(Right_Dir2, LOW);
  analogWrite(Right_Speed, Right_Base); 
}

void Reverse() 
{
  digitalWrite(Right_Dir1, LOW);
  digitalWrite(Right_Dir2, HIGH);
  analogWrite(Right_Speed, Right_Base); 
  digitalWrite(Left_Dir1, LOW);
  digitalWrite(Left_Dir2, HIGH);
  analogWrite(Left_Speed, Left_Base);
}

void Brake()
{
  Disenable();
  Left_Brake();
  Right_Brake();
}


void Turn_Right() 
{
  digitalWrite(Left_Dir1, LOW);
  digitalWrite(Left_Dir2, HIGH);
  analogWrite(Left_Speed, Left_Base);
  digitalWrite(Right_Dir1, HIGH);
  digitalWrite(Right_Dir2, LOW);
  analogWrite(Right_Speed, Right_Base); 
}

void Turn_Left() 
{
  digitalWrite(Left_Dir1, HIGH);
  digitalWrite(Left_Dir2, LOW);
  analogWrite(Left_Speed, Left_Base);
  digitalWrite(Right_Dir1, LOW);
  digitalWrite(Right_Dir2, HIGH);
  analogWrite(Right_Speed, Right_Base); 
}



void Turn_Rightninety()
{
  Righten_Count = 0;
  Leften_Count = 0;
  attachInterrupt(digitalPinToInterrupt(18), Left_Turns, RISING);
  attachInterrupt(digitalPinToInterrupt(2), Right_Turns, RISING);
  while (Leften_Count < 440 || Righten_Count > -440)
  {
    if (Leften_Count < 440)
    {
      digitalWrite(Left_Dir1, LOW);
      digitalWrite(Left_Dir2, HIGH);
      analogWrite(Left_Speed, Left_Base);

    }
    else
    {
      digitalWrite(Left_Dir1, HIGH);
      digitalWrite(Left_Dir2, HIGH); 
      digitalWrite(Left_Speed, HIGH);

    }
    
    if (Righten_Count > -440)
    {
      digitalWrite(Right_Dir1, HIGH);
      digitalWrite(Right_Dir2, LOW);
      analogWrite(Right_Speed, Right_Base);
    }
    else
    {
      digitalWrite(Right_Dir1, HIGH);
      digitalWrite(Right_Dir2, HIGH);  
      digitalWrite(Right_Speed, HIGH);
    }
  
  }
  
  Brake();
  delay(2000);
  //Serial.println(Leften_Count);
  Leften_Count = 0;
  Righten_Count = 0;
  
  
}

void Turn_Rightninety_One()
{
  Righten_Count = 0;
  Leften_Count = 0;
  attachInterrupt(digitalPinToInterrupt(18), Left_Turns, RISING);
  attachInterrupt(digitalPinToInterrupt(2), Right_Turns, RISING);
  while (Leften_Count < 530 )
  {
    if (Leften_Count < 530)
    {
      digitalWrite(Left_Dir1, LOW);
      digitalWrite(Left_Dir2, HIGH);
      analogWrite(Left_Speed, Left_Base);

      digitalWrite(Right_Dir1, HIGH);
      digitalWrite(Right_Dir2, LOW);
      analogWrite(Right_Speed, Right_Base);

    }
    else
    {
      digitalWrite(Left_Dir1, HIGH);
      digitalWrite(Left_Dir2, HIGH); 
      digitalWrite(Left_Speed, HIGH);

      digitalWrite(Right_Dir1, HIGH);
      digitalWrite(Right_Dir2, HIGH);  
      digitalWrite(Right_Speed, HIGH);

    }
  
  }
  
  Brake();
  delay(2000);
  //Serial.println(Leften_Count);
  Leften_Count = 0;
  Righten_Count = 0;
}





void Turn_Leftninety()
{
  Righten_Count = 0;
  Leften_Count = 0;
  attachInterrupt(digitalPinToInterrupt(18), Left_Turns, RISING);
  attachInterrupt(digitalPinToInterrupt(2), Right_Turns, RISING);
  while (Righten_Count < 450 || Leften_Count > -450 )
  {
    if (Righten_Count < 450)
    {
      digitalWrite(Right_Dir1, LOW);
      digitalWrite(Right_Dir2, HIGH);
      analogWrite(Right_Speed, Right_Base);
    }
    else
    {
      digitalWrite(Right_Dir1, HIGH);
      digitalWrite(Right_Dir2, HIGH);  
      digitalWrite(Right_Speed, HIGH);
    }
    
    if (Leften_Count > -450)
    {
      digitalWrite(Left_Dir1, HIGH);
      digitalWrite(Left_Dir2, LOW);
      analogWrite(Left_Speed, Left_Base);
    }
    else
    {
      digitalWrite(Left_Dir1, HIGH);
      digitalWrite(Left_Dir2, HIGH); 
      digitalWrite(Left_Speed, HIGH);

    }
  
  }
  Brake();
  delay(2000);
  //Serial.println(Leften_Count);
  Righten_Count = 0;
  Leften_Count = 0;
  
  
}

void Turn_Leftninety_One()
{
  Righten_Count = 0;
  Leften_Count = 0;
  attachInterrupt(digitalPinToInterrupt(18), Left_Turns, RISING);
  attachInterrupt(digitalPinToInterrupt(2), Right_Turns, RISING);
  while (Righten_Count < 500)
  {
    if (Righten_Count < 500)
    {
      digitalWrite(Right_Dir1, LOW);
      digitalWrite(Right_Dir2, HIGH);
      analogWrite(Right_Speed, Right_Base);

      digitalWrite(Left_Dir1, HIGH);
      digitalWrite(Left_Dir2, LOW);
      analogWrite(Left_Speed, Left_Base);
    }
    else
    {
      digitalWrite(Right_Dir1, HIGH);
      digitalWrite(Right_Dir2, HIGH);  
      digitalWrite(Right_Speed, HIGH);

      digitalWrite(Left_Dir1, HIGH);
      digitalWrite(Left_Dir2, HIGH); 
      digitalWrite(Left_Speed, HIGH);
    }
  
  }
  Brake();
  delay(2000);
  //Serial.println(Leften_Count);
  Righten_Count = 0;
  Leften_Count = 0;
  
  
}




/*************************motor controoling functions over***************************/



/*****************************ir sensor reading function*************************/
void Ir_Sensor()
{
  for(int i=0; i<10; i++)
  {
    IR[i] = analogRead(ir[i]);
  }
  for (int i =0; i<10; i++)
  {
    if (IR[i]<=150) {
      sens[i]=1;
      }
    else if (IR[i]>=300) {
      sens[i]=0;
      }
    Serial.print(sens[i]);
  }
  Serial.println("");
}

/************************ir sensor reading function over********************************/


/*****************************line pid function****************************/
void Error_Cal()
{
  Error = 0;
  for(int ii=0; ii<10; ii++)
  {
    Error = Error + sens[ii]*Errorval[ii];
    //Serial.println(sens[ii]);
  }
}                                                                                                                                                                         

void Line_PID()
{
  Error_Cal();
  Power = (Kp*Error) + (Kd*(Error-previousError));
  previousError = Error;
  Right_PWM = Right_Base - Power;
  Left_PWM = Left_Base + Power;
}

/****************************line pid function*********************************/


void Line_Follow(){
  Ir_Sensor();
  Line_PID();
  if (sens[0]==1 && sens[9]==1){
    Serial.println("Brake");
    Brake();
  }
  
  else if(sens[0]==1 && sens[9]==0){
    Serial.println("turn left");
    Brake();
    delay(1000);
    Forward_Base();
    delay(400);
    Brake();
    delay(500);
    Turn_Leftninety_One();
   }
    
  else if(sens[0]==0 && sens[9]==1){
    Serial.println("turn right");
    Brake();
    delay(1000);
    Forward_Base();
    delay(400);
    Brake();
    delay(500);
    Turn_Rightninety_One();
    }
  else{
    Serial.println("line follow pid");
    Line_PID();
    Forward();
    }
  }


/**************************motor driver setup*****************************************/
void motor_driver_setup(){
  pinMode(Left_Dir1, OUTPUT);      // motor driver
  pinMode(Left_Dir2, OUTPUT);
  pinMode(Left_Speed, OUTPUT);
  pinMode(Right_Dir1, OUTPUT);
  pinMode(Right_Dir2, OUTPUT);
  pinMode(Right_Speed, OUTPUT);
}
/**************************motor driver setup over*****************************************/

/**************************sonar sensor setup*****************************************/
void sonar_sensor_setup(){
  pinMode(ftrigPin, OUTPUT);      // sonar sensors
  pinMode(fechoPin, INPUT);
  pinMode(ltrigPin, OUTPUT); 
  pinMode(lechoPin, INPUT);
  pinMode(rtrigPin, OUTPUT); 
  pinMode(rechoPin, INPUT);
}
/**************************sonar sensor setup over*****************************************/

/**************************encoder setup*****************************************/
void encoder_setup(){
  pinMode(Left_A, INPUT);
  pinMode(Left_B, INPUT);
  pinMode(Right_A, INPUT);
  pinMode(Right_B, INPUT);
}
/**************************encoder setup over*****************************************/


/**************************servo attaching pins setup*****************************************/
void servo_attach_setup(){
  gateServo.attach(gate_servo);
  myservo1.attach(coin_arm_servo);
  myservo2.attach(coin_magnet_servo);
  myservo4.attach(water_arm_servo);
}
/**************************servo attaching pins setup over*****************************************/

/**************************servo position setup*****************************************/
void servo_position_setup(){
  myservo1.write(pos1);
  myservo2.write(pos2);
  myservo4.write(pos4);
  gateServo.write(0);
}
/**************************servo position setup over*****************************************/


/***************************led indicator functions************************************/
//lighting the leds for 1000ms
void led_setup(){
  pinMode(green_led_pin,OUTPUT);
  pinMode(red_led_pin,OUTPUT);
  pinMode(blue_led_pin,OUTPUT);
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
/***************************led indicator functions over************************************/


/*****************************colour sensor functions*****************************/
void color_sensor_setup(){
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  
  pinMode(sensorOut, INPUT);
  
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  }

void color_sensor_out(){
  // Setting RED (R) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  
  // Reading the output frequency
  redFrequency = pulseIn(sensorOut, LOW);
  
   // Printing the RED (R) value
  Serial.print("R = ");
  Serial.print(redFrequency);
  delay(100);
  
  // Setting GREEN (G) filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  
  // Reading the output frequency
  greenFrequency = pulseIn(sensorOut, LOW);
  
  // Printing the GREEN (G) value  
  Serial.print(" G = ");
  Serial.print(greenFrequency);
  delay(100);
 
  // Setting BLUE (B) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  
  // Reading the output frequency
  blueFrequency = pulseIn(sensorOut, LOW);
  
  // Printing the BLUE (B) value 
  Serial.print(" B = ");
  Serial.print(blueFrequency);
  delay(100);

  if(blueFrequency<greenFrequency){
    if(blueFrequency<redFrequency){
      if(blueFrequency<100){
        Serial.println("  blue");
        light_blue();
        }
      if(blueFrequency>100){
        Serial.println("");
        }
      }
    }
  if(greenFrequency<blueFrequency){
    if(greenFrequency<redFrequency){
      if(greenFrequency<100){
        Serial.println("  green");
        light_green();
        }
      if(greenFrequency>100){
        Serial.println("");
        }
      }
    }
  if(redFrequency<greenFrequency){
    if(redFrequency<blueFrequency){
      if(redFrequency<100){
        Serial.println("  red");
        light_red();
        }
      if(redFrequency>100){
        Serial.println("");
        }
      }
    }
 else{
  Serial.println(" ");
  }  
  delay(100);
  }
/*****************************colour sensor functions over*****************************/

/*****************************water pump functions*****************************/
void water_pump_setup(){
  pinMode(water_pump_dir_1, OUTPUT);
  pinMode(water_pump_dir_2, OUTPUT);
  }

//water pump activate for 3 seconds
void water_pump(){
  digitalWrite(52,HIGH);
  digitalWrite(53,LOW); 
  delay(3000);
  digitalWrite(52,LOW);
  digitalWrite(53,LOW); 
  }
/*****************************water pump functions over*****************************/


/*****************************buzzer functions*****************************/
void buzzer_setup(){
  pinMode(pinTone, OUTPUT);
  }


//playing the knight rider melody at the destination
void buzzer_code(){
    curTime = millis();
    Serial.println(totalNotes);
    for (int i=0; i<5000; i++){
      noteIndex++;
      tonePrevTime = curTime;
      noTone(pinTone);
      tone(pinTone, aNotes[noteIndex].note, aNotes[noteIndex].tempo);
      noteDelay = aNotes[noteIndex].tempo;
      Serial.println(noteDelay);
      delay(noteDelay);
    }
}
/*****************************buzzer functions over*****************************/
