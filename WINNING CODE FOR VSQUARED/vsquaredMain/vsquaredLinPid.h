void Error_Cal()
{
  Error = 0;
  for(int ii=0; ii<10; ii++)
  {
    Error = Error + sens[ii]*Errorval[ii];
    //Serial.println(sens[ii]);
  }
  
}                                                                                                                                                                         


void Line_PID()
{
  Error_Cal();
  Power = (Kp*Error) + (Kd*(Error-previousError));
  previousError = Error;
  Right_PWM = Right_Base - Power;
  Left_PWM = Left_Base + Power;
}
                                                                                                                                              
void Red_Error_Cal()
{
  redError = 0;
  for(int ii=0; ii<10; ii++)
  {
    redError = redError + sens[ii]*Errorval[ii];
    //Serial.println(sens[ii]);
  }
  
} 


void Red_Line_PID()
{
  Red_Error_Cal();
  Power = (rp*redError) + (rd*(redError-redPreError));
  redPreError = redError;
  Right_PWM = Right_Base - Power;
  Left_PWM = Left_Base + Power;
}