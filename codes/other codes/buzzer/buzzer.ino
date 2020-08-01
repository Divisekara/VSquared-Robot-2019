#include "pins.h"
#include "variables.h"
#include "functions.h"

void setup() {
    pinMode(pinTone, OUTPUT); 
}

void loop() {
  buzzer_code();
} 
