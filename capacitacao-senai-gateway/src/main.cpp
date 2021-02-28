#include <Arduino.h>

#include "setupWiFi.h"

void setup() {
  Serial.begin(115200);
  Serial.println("Init Serial");
  setupWiFi();
  sendData("POT=201");
}

// bool send = false;
// int value = 0;

void loop() {
  if(send) {
    send = false;
    sendData("POT=" + (String)value);
  }
}