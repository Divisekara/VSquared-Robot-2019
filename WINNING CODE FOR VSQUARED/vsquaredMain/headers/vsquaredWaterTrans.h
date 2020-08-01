void water_pump(){
  pinMode(water_pump_dir_1, OUTPUT);
  pinMode(water_pump_dir_2, OUTPUT);
  digitalWrite(52,HIGH);
  digitalWrite(53,LOW); 
  delay(10000);
  digitalWrite(52,LOW);
  digitalWrite(53,LOW); 
  }

void water_Servo() {
  for(pos4 = 0; pos4 < 125; pos4 += 1){
    myservo4.write(pos4);
    delay(10);
  }
  /* 
  water_pump();
  delay(1000);
  water_pump();
  delay(1000);
  water_pump();
  delay(1000);
  water_pump();
  delay(500);
  */
  //lower arm up
  delay(2000);
  for(pos4 = 125; pos4 > 0; pos4 -= 1){
    myservo4.write(pos4);
    delay(10);
  }
  delay(500);
}

void Water_Line_Follow()
{
  while (waterCount == 0)
  {
    Ir_Sensor();
    Count_Right();
    Count_Left();
    Count_Mid();
    if (Left_Sens == 0 && Right_Sens == 1 && Right_Count ==4)
    {
      Brake();
      delay(50);
      encoderCount = 450;
      encoderForward();
      Brake();
      delay(50);
      Turn_Rightninety_One();
      Brake();
      delay(50);
      //taskCount+=1;
    }
    else if (Left_Sens == 1 && Right_Sens ==0 && Left_Count == 4)
    {
      Brake();
      delay(50);
      
      encoderCount = 170;
      encoderForward();
      Brake();
      delay(50);
      encoderRight = 940;
      rightMotor();
      Brake();
      delay(1000);
      encoderCount = -550;
      encoderReverse();
      smallCount = 0;
      while (smallCount <493)  // line following small line before water cups
      {
        Ir_Sensor();
        Line_PID();
        Forward();
        smallCount += 1;
      }

      Brake();
      delay(1000);
      Turn_Half();
      delay(1000);
      encoderCount = -435;
      encoderReverse();
      delay(1000);
      water_Servo();  //  pumps water
      waterCount +=1;

    }
    else
    {
      Line_PID();
      Forward();
    }
    
  }
  while (waterCount == 1)
  {
    Ir_Sensor();
    Count_Right();
    Count_Left();
    Count_Mid();
    if (Left_Sens == 0 && Right_Sens == 1 && Right_Count ==4)
    {
      Brake();
      delay(50);
      encoderCount = 410;
      encoderForward();
      Brake();
      delay(50);
      Turn_Rightninety_Wall();
      Brake();
      delay(50);
      waterCount +=1;
    }
    else
    {
      Line_PID();
      Forward();
    }
  }

  while (waterCount == 2)
  {
    Ir_Sensor();
    Count_Right();
    Count_Left();
    Count_Mid();
    if (Right_Sens == 1 && Right_Count ==4)
    {
      Brake();
      delay(50);
      encoderCount = 450;
      encoderForward();
      Brake();
      delay(50);
      Turn_Rightninety_One();
      Brake();
      delay(50);
      waterCount +=1;
    }
    else
    {
      Line_PID();
      Forward();
    }
  }

  while (waterCount == 3)
  {
    Ir_Sensor();
    if (Left_Sens == 1 && Right_Sens ==1)
    {
      encoderCount = 500;
      encoderForward();
      while(1)
      {
        Brake();
        delay(100);
      }
    }
    else
    {
      Line_PID();
      Forward();
    }
  }
    
}
  