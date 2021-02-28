#include <Arduino.h>

#include "pins.h"
#include "setupOled.h"
#include "setupWiFi.h"

void setup() {
  setupPins();
  setupOled();
  setupWiFi();
}

void loop() {
  if (digitalRead(interruptPin)) {
    sendMessage();
    while (digitalRead(interruptPin))
      ;
  }
}