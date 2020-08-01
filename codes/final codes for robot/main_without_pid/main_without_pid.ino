#include "pins.h"
#include "variables.h"
#include "functions.h"

void setup() {
  water_pump();
  color_sensor_setup();
  led_setup();
  water_pump_setup();
  water_pump();
  buzzer_setup();
}

void loop() {
  color_sensor_out();
  buzzer_code();

}
