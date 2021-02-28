#include <Arduino.h>

#include "setupWiFi.h"

void setup() {
  Serial.begin(115200);
  Serial.println("Init Serial");
  setupWiFi();
}

void loop() {
  // put your main code here, to run repeatedly:
}