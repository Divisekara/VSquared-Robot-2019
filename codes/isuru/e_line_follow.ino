int All_Count = 0;
int Left_Count = 0;
int Right_Count = 0;
int Mid_Count = 0;
void Count_Mid()
{
  Mid_Count = 0;
  for(int i=1; i<9; i++)
  {
    if (sens[i] == 1) {Mid_Count += 1;}
  }
  Serial.print(Mid_Count);
  Serial.print("   ");
}
void Count_All()
{
  All_Count = 0;
  for(int i=0; i<10; i++)
  {
    if (sens[i] == 1) {All_Count += 1;}
  }
  //Serial.print(All_Count);
  //Serial.print("   ");
}

void Count_Left()
{
  Left_Count = 0;
  for(int i=0; i<5; i++)
  {
    if (sens[i] == 1) {Left_Count += 1;}
  }
  //Serial.print(Left_Count);
  //Serial.print("   ");
}

void Count_Right()
{
  Right_Count = 0;
  for(int i=5; i<10; i++)
  {
    if (sens[i] == 1) {Right_Count += 1;}
  }
  Serial.print(Right_Count);
  Serial.println("   ");
}

void Line_Follow()
{
  Last_Read = 0;
  if (sens[0]==1) {Last_Read = 1;}
  if (sens[9]==1) {Last_Read = 2;}
  Ir_Sensor();
  
  Count_All();
  Count_Left();
  Count_Right();
  Count_Mid();
  
  if (All_Count == 0 && Last_Read == 1)
  {
   while (sens[4] == 0)
   {
    Turn_Left(); 
    Ir_Sensor();
   }
    
  }
  
  else if (All_Count == 0 && Last_Read == 2)
  {
    while (sens[5] == 0)
    {
      Turn_Right();
      Ir_Sensor();
    }
  }
  
  else if (All_Count == 0)
  {
    Brake();
  }
  
  else if (Mid_Count == 8)
  {
    Brake();
    delay(1000);
    coinArm();
    delay(500);
    openGate();
    //Turn_Half();
  }
  
  else if (Right_Count == 5)
  {
    Brake();
    delay(1000);
    Forward_Base();
    delay(400);
    Brake();
    delay(500);
    Turn_Rightninety_One();
    
  }
  
  else if (Left_Count == 5)
  {
    Brake();
    delay(1000);
    Forward_Base();
    delay(400);
    Brake();
    delay(500);
    Turn_Leftninety_One();
  }
  
  else
  {
    Line_PID();
    Forward();
  }
 
}
