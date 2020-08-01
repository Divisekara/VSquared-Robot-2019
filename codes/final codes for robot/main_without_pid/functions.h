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
