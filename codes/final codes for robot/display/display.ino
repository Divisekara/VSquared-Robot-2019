#include <Adafruit_GFX.h>  // Include core graphics library for the display
#include <Adafruit_SSD1306.h>  // Include Adafruit_SSD1306 library to drive the display
#include <Fonts/FreeMono9pt7b.h>  // Add a custom font

Adafruit_SSD1306 display(128, 64);  // Create display

#include "pins.h"
#include "functions.h"

void setup() {
  display_setup();
}

void loop() {
  //sample printing to be executed
  printing_name();
  printing_line_follow_data();
  printing_wall_follow_data();
}
