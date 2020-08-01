void reverse_coin_collect()
{
  encoderCount = -300;
  encoderReverse();
  Brake();
  delay(100);
}
  
void forward_coin_collect()
{
  encoderCount = 500;
  encoderForward();
  Brake();
  delay(100);
}
 

void forward_coin_drop()
{
  encoderCount = 300;
  encoderForward();
  Brake();
  delay(100);
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
  myservo2.write(70);
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