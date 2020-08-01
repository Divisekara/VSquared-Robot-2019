
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
  analogWrite(Left_Speed, Left_Base);
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
  digitalWrite(Right_Speed, Right_Base); 
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
  Left_Reverse_Base();
  Right_Reverse_Base();
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
