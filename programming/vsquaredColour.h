void setup_color_sensor(){
  pinMode(S0_, OUTPUT);
  pinMode(S1_, OUTPUT);
  pinMode(S2_, OUTPUT);
  pinMode(S3_, OUTPUT);
  
  pinMode(sensorOut, INPUT);
  
  digitalWrite(S0_,HIGH);
  digitalWrite(S1_,LOW);
  }
/*
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
*/

void color_sensor_out()
{
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
