#include "pins.h"
#include "variables.h"
#include "functions.h"

void setup() {
  setup_color_sensor();
  led_setup();
  Serial.begin(9600);

}


void loop() {  
  color_sensor_out();
}
