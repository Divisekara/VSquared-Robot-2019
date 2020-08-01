int Last_Read = 0;

float Kp = 8;   
float Ki = 0;
float Kd = 4;

float Error=0;
float previousError = 0;
float totalError = 0;
float power = 0;


void error_cal()
{ 
  Error = 0;
  for(int j=0; j<8; j++)
  {
    Error = Error + sensor_reading_array[j]*Error_values[j];}}

void line_pid()
{
  error_cal();
  power = (Kp*Error) + (Kd*(Error-previousError)) ;
  previousError = Error;

  right_speed = base_pwm - power;
  left_speed = base_pwm + power;
 
}
