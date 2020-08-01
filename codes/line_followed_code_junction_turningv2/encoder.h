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

void Forward_Base()
{
  digitalWrite(right_A, HIGH);
  digitalWrite(right_B, LOW);
  analogWrite(right_pwm, 60);
  
  digitalWrite(left_A, HIGH);
  digitalWrite(left_B, LOW);
  analogWrite(left_pwm, 60); 
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
  brake();
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
  brake();
  delay(2000);
  Serial.println(Righten_Count);
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
      digitalWrite(left_A, LOW);
      digitalWrite(left_B, HIGH);
      analogWrite(left_pwm, 60);

      digitalWrite(right_B, HIGH);
      digitalWrite(right_A, LOW);
      analogWrite(right_pwm, 60);

    }
    else
    {
      digitalWrite(right_A, HIGH);
      digitalWrite(right_B, HIGH); 
      digitalWrite(right_pwm, HIGH);

      digitalWrite(left_A, HIGH);
      digitalWrite(left_A, HIGH);  
      digitalWrite(left_pwm, HIGH);
    }
  
  }
  
  brake();
  delay(2000);
  //Serial.println(Leften_Count);
  Leften_Count = 0;
  Righten_Count = 0;
  
  
}

void Turn_Lefttninety_One()
{
  Righten_Count = 0;
  Leften_Count = 0;
  attachInterrupt(digitalPinToInterrupt(18), Left_Turns, RISING);
  attachInterrupt(digitalPinToInterrupt(2), Right_Turns, RISING);
  while (Right_en_Count < 530 )
  {
    if (Righten_Count < 530)
    {
      digitalWrite(left_A, LOW);
      digitalWrite(left_B, HIGH);
      analogWrite(left_pwm, 60);

      digitalWrite(right_B, HIGH);
      digitalWrite(right_A, LOW);
      analogWrite(right_pwm, 60);

    }
    else
    {
      digitalWrite(right_A, HIGH);
      digitalWrite(right_B, HIGH); 
      digitalWrite(right_pwm, HIGH);

      digitalWrite(left_A, HIGH);
      digitalWrite(left_A, HIGH);  
      digitalWrite(left_pwm, HIGH);
    }
  
  }
  
  brake();
  delay(2000);
  //Serial.println(Leften_Count);
  Leften_Count = 0;
  Righten_Count = 0;
 
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
      digitalWrite(right_A, LOW);
      digitalWrite(right_B, HIGH);
      analogWrite(right_pwm, 60);
      digitalWrite(left_A, HIGH);
      digitalWrite(left_B, LOW);
      analogWrite(left_pwm, 60);
    }
    else
    {
      digitalWrite(left_A, HIGH);
      digitalWrite(left_B, HIGH); 
      digitalWrite(left_pwm, HIGH);

      digitalWrite(right_A, HIGH);
      digitalWrite(right_B, HIGH);  
      digitalWrite(right_pwm, HIGH);
    }
  }
  brake();
  delay(2000);
  Leften_Count = 0;
  Righten_Count = 0;
}

int n;
int encoder_turn_right(n);
  Righten_Count = 0;
  //Leften_Count = 0;
  attachInterrupt(digitalPinToInterrupt(18), Left_Turns, RISING);
  attachInterrupt(digitalPinToInterrupt(2), Right_Turns, RISING);
  while (Righten_Count < n )
  {
    if (Righten_Count < n)
    {
      digitalWrite(right_A, LOW);
      digitalWrite(right_B, HIGH);
      analogWrite(right_pwm, 60);
      /*digitalWrite(left_A, HIGH);
      digitalWrite(left_B, LOW);
      analogWrite(left_pwm, 60);*/
    }
    else
    {
      /*digitalWrite(left_A, HIGH);
      digitalWrite(left_B, HIGH); 
      digitalWrite(left_pwm, HIGH);*/

      digitalWrite(right_A, HIGH);
      digitalWrite(right_B, HIGH);  
      digitalWrite(right_pwm, HIGH);
    }
  }
  brake();
  delay(1000);
  //Leften_Count = 0;
  Righten_Count = 0;
}


int encoder_turn_left(n);
  //Righten_Count = 0;
  Leften_Count = 0;
  attachInterrupt(digitalPinToInterrupt(18), Left_Turns, RISING);
  attachInterrupt(digitalPinToInterrupt(2), Right_Turns, RISING);
  while (Leften_Count < n )
  {
    if (Leften_Count < n)
    {
      /*digitalWrite(right_A, LOW);
      digitalWrite(right_B, HIGH);
      analogWrite(right_pwm, 60);*/
      digitalWrite(left_A, HIGH);
      digitalWrite(left_B, LOW);
      analogWrite(left_pwm, 60);
    }
    else
    {
      digitalWrite(left_A, HIGH);
      digitalWrite(left_B, HIGH); 
      digitalWrite(left_pwm, HIGH);

      /*digitalWrite(right_A, HIGH);
      digitalWrite(right_B, HIGH);  
      digitalWrite(right_pwm, HIGH);*/
    }
  }
  brake();
  delay(1000);
  //Leften_Count = 0;
  Righten_Count = 0;
}
