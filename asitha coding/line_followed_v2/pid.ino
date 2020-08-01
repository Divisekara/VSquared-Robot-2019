float Kp = 15;   
float Kd = 7;

void error_cal()
{ 
  Error = 0;
  for(int j=0; j<8; j++)
  {Error = Error + sensor_reading_array[j]*Error_values[j];}}

void line_pid()
{
  error_cal();
  power = (Kp*Error) + (Kd*(Error-previousError)) ;
  previousError = Error;

  right_speed = base_pwm - power;
  left_speed = base_pwm + power;
 
}
