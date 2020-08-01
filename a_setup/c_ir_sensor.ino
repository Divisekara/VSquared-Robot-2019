int sen[8] = { 0 };
void Ir_Sensor()
{
  for(int i=0; i<8; i++)
  {
    IR[i] = analogRead(ir[i]);
  }
  for (int i =0; i<8; i++)
  {
    if (IR[i]<=200) {sen[i]=1;}
    else if (IR[i]>=340) {sen[i]=0;}
    //Serial.print(sen[i]);
    //Serial.print("  ");
  }
  //Serial.println("");
  if (sen[0]==1) {Last_Read = 1;}
  if (sen[7]==1) {Last_Read = 2;}
}

