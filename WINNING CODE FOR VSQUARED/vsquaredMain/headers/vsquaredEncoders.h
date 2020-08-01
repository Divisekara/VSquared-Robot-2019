void Left_Turns()
{
  if (digitalRead(18) == HIGH && digitalRead(19) == HIGH)
  {
    Leften_Count = Leften_Count -1;
  }
  if (digitalRead(18) == HIGH && digitalRead(19) == LOW)
  {
    Leften_Count = Leften_Count +1;
  }
}

void Right_Turns()
{
  if (digitalRead(2) == HIGH && digitalRead(3) == HIGH)
  {
    Righten_Count = Righten_Count -1;
  }
  if (digitalRead(2) == HIGH && digitalRead(3) == LOW)
  {
    Righten_Count = Righten_Count +1;
  }
}

void Forward_encoder_left()
{
  Leften_Count = 0;
  attachInterrupt(digitalPinToInterrupt(18), Left_Turns, RISING);
  int a = 0;
  while(a<5000)
  {
    Forward_Base();
    //Serial.println(a);
    a = a + 1;
  }
  Brake();
  delay(2000);
  Serial.println(Leften_Count);
  Leften_Count = 0;
}


void Forward_encoder_Right()
{
  Righten_Count = 0;
  attachInterrupt(digitalPinToInterrupt(2), Right_Turns, RISING);
  int a = 0;
  while(a<5000)
  {
    Forward_Base();
    //Serial.println(a);
    a = a + 1;
  }
  Brake();
  delay(2000);
  Serial.println(Righten_Count);
  Righten_Count = 0;
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
  while (Leften_Count < 490 )
  {
    if (Leften_Count < 490)
    {
      digitalWrite(Right_Dir1, LOW);
      digitalWrite(Right_Dir2, HIGH);
      analogWrite(Right_Speed, Left_Base);

      digitalWrite(Left_Dir1, HIGH);
      digitalWrite(Left_Dir2, LOW);
      analogWrite(Left_Speed, Right_Base);

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
  delay(50);
  //Serial.println(Leften_Count);
  Leften_Count = 0;
  Righten_Count = 0;
  taskCount+=1;
  
  
}

void Turn_Rightninety_Wall()
{
  Righten_Count = 0;
  Leften_Count = 0;
  attachInterrupt(digitalPinToInterrupt(18), Left_Turns, RISING);
  attachInterrupt(digitalPinToInterrupt(2), Right_Turns, RISING);
  while (Leften_Count < 480 )
  {
    if (Leften_Count < 480)
    {
      digitalWrite(Right_Dir1, LOW);
      digitalWrite(Right_Dir2, HIGH);
      analogWrite(Right_Speed, Left_Base);

      digitalWrite(Left_Dir1, HIGH);
      digitalWrite(Left_Dir2, LOW);
      analogWrite(Left_Speed, Right_Base);

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
  delay(50);
  //Serial.println(Leften_Count);
  Leften_Count = 0;
  Righten_Count = 0;
  taskCount+=1;
  
  
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
  delay(50);
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
  while (Righten_Count < 480)
  {
    if (Righten_Count < 480)
    {
      digitalWrite(Left_Dir1, LOW);
      digitalWrite(Left_Dir2, HIGH);
      analogWrite(Left_Speed, Right_Base);

      digitalWrite(Right_Dir1, HIGH);
      digitalWrite(Right_Dir2, LOW);
      analogWrite(Right_Speed, Left_Base);
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
  delay(50);
  //Serial.println(Leften_Count);
  Righten_Count = 0;
  Leften_Count = 0;
  
  
}


void Turn_Leftninety_Wall()
{
  Righten_Count = 0;
  Leften_Count = 0;
  attachInterrupt(digitalPinToInterrupt(18), Left_Turns, RISING);
  attachInterrupt(digitalPinToInterrupt(2), Right_Turns, RISING);
  while (Righten_Count < 470)
  {
    if (Righten_Count < 470)
    {
      digitalWrite(Left_Dir1, LOW);
      digitalWrite(Left_Dir2, HIGH);
      analogWrite(Left_Speed, Right_Base);

      digitalWrite(Right_Dir1, HIGH);
      digitalWrite(Right_Dir2, LOW);
      analogWrite(Right_Speed, Left_Base);
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
  delay(50);
  //Serial.println(Leften_Count);
  Righten_Count = 0;
  Leften_Count = 0;
  
  
}

void Turn_Half()
{
  Righten_Count = 0;
  Leften_Count = 0;
  attachInterrupt(digitalPinToInterrupt(18), Left_Turns, RISING);
  attachInterrupt(digitalPinToInterrupt(2), Right_Turns, RISING);
  while (Leften_Count < 1050 )
  {
    if (Leften_Count < 1050)
    {
      digitalWrite(Left_Dir1, HIGH);
      digitalWrite(Left_Dir2, LOW);
      analogWrite(Left_Speed, Left_Base);

      digitalWrite(Right_Dir1, LOW);
      digitalWrite(Right_Dir2, HIGH);
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
  delay(50);
  //Serial.println(Leften_Count);
  Leften_Count = 0;
  Righten_Count = 0;
  
  
}


void leftMotor()
{
  Leften_Count = 0;
  attachInterrupt(digitalPinToInterrupt(18), Left_Turns, RISING);
  attachInterrupt(digitalPinToInterrupt(2), Right_Turns, RISING);
  while (Leften_Count < encoderLeft )
  {
    if (Leften_Count < encoderLeft)
    {
      digitalWrite(Left_Dir2, LOW);
      digitalWrite(Left_Dir1, HIGH);
      analogWrite(Left_Speed, 60);

    }
    else
    {
      digitalWrite(Left_Dir1, HIGH);
      digitalWrite(Left_Dir2, HIGH); 
      digitalWrite(Left_Speed, HIGH);
    }
  
  }
  
  Brake();
  delay(50);
  //Serial.println(Leften_Count);
  Leften_Count = 0;
  Righten_Count = 0;
  
  
}

void rightMotor()
{
  Righten_Count = 0;
  attachInterrupt(digitalPinToInterrupt(18), Left_Turns, RISING);
  attachInterrupt(digitalPinToInterrupt(2), Right_Turns, RISING);
  while (Righten_Count < encoderRight )
  {
    if (Righten_Count < encoderRight)
    {
      digitalWrite(Right_Dir2, LOW);
      digitalWrite(Right_Dir1, HIGH);
      analogWrite(Right_Speed, 60);

    }
    else
    {
      digitalWrite(Right_Dir1, HIGH);
      digitalWrite(Right_Dir2, HIGH); 
      digitalWrite(Right_Speed, HIGH);
    }
  
  }
  
  Brake();
  delay(50);
  //Serial.println(Leften_Count);
  Leften_Count = 0;
  Righten_Count = 0;
  
  
}


void rightMotorReverse()
{
  Righten_Count = 0;
  attachInterrupt(digitalPinToInterrupt(18), Left_Turns, RISING);
  attachInterrupt(digitalPinToInterrupt(2), Right_Turns, RISING);
  while (Righten_Count > encoderRight )
  {
    if (Righten_Count > encoderRight)
    {
      digitalWrite(Right_Dir2, HIGH);
      digitalWrite(Right_Dir1, LOW);
      analogWrite(Right_Speed, 60);

    }
    else
    {
      digitalWrite(Right_Dir1, HIGH);
      digitalWrite(Right_Dir2, HIGH); 
      digitalWrite(Right_Speed, HIGH);
    }
  
  }
  
  Brake();
  delay(50);
  //Serial.println(Leften_Count);
  Leften_Count = 0;
  Righten_Count = 0;
  
  
}

void encoderForward()
{
  Righten_Count = 0;
  Leften_Count = 0;
  attachInterrupt(digitalPinToInterrupt(18), Left_Turns, RISING);
  while(Leften_Count < encoderCount)
  {
    if (Leften_Count < encoderCount)
    {
      digitalWrite(Right_Dir1, HIGH);
      digitalWrite(Right_Dir2, LOW);
      analogWrite(Right_Speed, 60);

      digitalWrite(Left_Dir1, HIGH);
      digitalWrite(Left_Dir2, LOW);
      analogWrite(Left_Speed, 60);

    }
    else
    {
      digitalWrite(Left_Dir1, HIGH);
      digitalWrite(Left_Dir2, HIGH); 

      digitalWrite(Right_Dir1, HIGH);
      digitalWrite(Right_Dir2, HIGH);  

    }
  }
  Brake();
  delay(50);
  //Serial.println(Leften_Count);
  Leften_Count = 0;
  Righten_Count = 0;
}

void encoderReverse()
{
  Righten_Count = 0;
  Leften_Count = 0;
  attachInterrupt(digitalPinToInterrupt(18), Left_Turns, RISING);
  while(Leften_Count > encoderCount)
  {
    if (Leften_Count > encoderCount)
    {
      digitalWrite(Right_Dir1, LOW);
      digitalWrite(Right_Dir2, HIGH);
      analogWrite(Right_Speed, 60);

      digitalWrite(Left_Dir1, LOW);
      digitalWrite(Left_Dir2, HIGH);
      analogWrite(Left_Speed, 60);

    }
    else
    {
      digitalWrite(Left_Dir1, HIGH);
      digitalWrite(Left_Dir2, HIGH); 

      digitalWrite(Right_Dir1, HIGH);
      digitalWrite(Right_Dir2, HIGH);  

    }
  }
  Brake();
  delay(50);
  //Serial.println(Leften_Count);
  Leften_Count = 0;
  Righten_Count = 0;
}