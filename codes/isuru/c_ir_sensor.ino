int sens[10] = { 0 };
void Ir_Sensor()
{
  for(int i=0; i<10; i++)
  {
    IR[i] = analogRead(ir[i]);
    //Serial.print(IR[i]);
    //Serial.print("  ");
  }
  for (int i =0; i<10; i++)
  {
    if (IR[i]<=150) {sens[i]=1;}
    else if (IR[i]>=300) {sens[i]=0;}
    //Serial.print(sens[i]);
    //Serial.print("  ");
  }
  Serial.println("");
  //if (sens[0]==1) {Last_Read = 1;}
  //if (sens[9]==1) {Last_Read = 2;}
}
