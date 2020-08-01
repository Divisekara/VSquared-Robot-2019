void error_cal()
{ 
  Error = 0;
  black=0;
  for(int j=0; j<8; j++)
  {
    black=black+sensor_reading_array[j];
    Error = Error + sensor_reading_array[j]*Error_values[j];}
}
    
void line_pid()
{
  error_cal();
  power = (Kp*Error) + (Kd*(Error-previousError)) ;
  previousError = Error;
  
  right_speed = base_pwm - power+12;
  left_speed = base_pwm + power-25;

}
