#ifndef __PINS_H__
#define __PINS_H__
#include <Arduino.h>

#define potentiometerPin 39  // VN

#define interruptPin 23

void setupPins(void) {
  pinMode(interruptPin, INPUT);
  pinMode(potentiometerPin, INPUT);
}

#endif  // __PINS_H__