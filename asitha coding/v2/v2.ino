#include "pins.h"
#include "variables.h"


//least pwm can be 70
//maximum can be 255
int base_pwm=120;

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
