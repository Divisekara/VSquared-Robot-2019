void coinArm(){  
  for(pos1 = 0; pos1 < 140; pos1 += 1){
    myservo1.write(pos1);
    delay(10);
  }
  Reverse();
  delay(400);
  Brake();
  delay(400);
  for(pos1 = 140; pos1 > 0; pos1 -= 1){
    myservo1.write(pos1);
    delay(10);
  }
  delay(1000);
  
  myservo2.write(60);
  delay(500);                                  
  myservo2.write(0);
  }
