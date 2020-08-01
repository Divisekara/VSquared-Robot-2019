
void Turn_Rightninety()
{
  Righten_Count = 0;
  attachInterrupt(digitalPinToInterrupt(20), Right_Turns, RISING);
  while (Righten_Count >= -10000)
  {
    Right_Reverse_Base();
    //Serial.println(Leften_Count);
  }
  
  Brake();
  delay(3000);
}

void Right_Turns()
{
  
  if (digitalRead(Righten_A) && !digitalRead(Righten_B)) {
    
    Righten_Count-- ;
  }
  if (digitalRead(Righten_A) && digitalRead(Righten_B)) {
    Righten_Count++ ;
  } 
  //Serial.println(Righten_Count);
  //Righten_Count = Leften_Count + 1;
}
void Count()
{
  Righten_Count = Righten_Count + 1;
  //Serial.println(Righten_Count);
}

