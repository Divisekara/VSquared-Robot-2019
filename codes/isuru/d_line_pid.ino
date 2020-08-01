int Errorval[10] = {0,-3, -2, -1, 0, 0, 1, 2, 3,0};

float Kp = 10;   
float Ki = 0;
float Kd = 20;

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
