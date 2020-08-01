int Errorval[10] = {0,-3, -2, -1, 0, 0, 1, 2, 3,0};
//7    4
float Kp = 7.5;   
float Ki = 0;
float Kd = 4;

float rp = 10;   
float rd = 4;

float redError=0;
float redPreError = 0;
                       

float Error=0;
float previousError = 0;
float totalError = 0;

float Power = 0;

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
