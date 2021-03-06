#include "pins.h"

int left_speed,right_speed;

//least pwm can be 70
//maximum can be 255
int base_pwm=100;

int Error_values[8] = {-3, -2, -1, 0, 0, 1, 2, 3};
//sensor values
int S0,S1,S2,S3,S4,S5,S6,S7,S8,S9;
int IR_pin[8]={A6,A7,A8,A9,A10,A11,A12,A13};
int sensor_reading_array[8] = { 0 };


void setup() {
  motor_driver_pin_mode();
  line_sensor_pin_mode();
}

void loop() {
  forward();
  sensor_reading();
  line_pid();
  analogWrite(right_pwm,right_speed);
  analogWrite(left_pwm,left_speed);

 
}
