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

void Turn_Half()
{
  Righten_Count = 0;
  Leften_Count = 0;
  attachInterrupt(digitalPinToInterrupt(18), Left_Turns, RISING);
  attachInterrupt(digitalPinToInterrupt(2), Right_Turns, RISING);
  while (Leften_Count < 1000 )
  {
    if (Leften_Count < 1000)
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
