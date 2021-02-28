#ifndef __CALLBACKSFUNCTIONS_H__
#define __CALLBACKSFUNCTIONS_H__
#include <Arduino.h>

#include "api-credentiasl.h"
#include "network-credentials.h"

void OnDataReceived(const uint8_t* macAddress, const uint8_t* data, int dataLength) {
  char macAddressString[18];
  snprintf(macAddressString, sizeof(macAddressString),
           "%02x:%02x:%02x:%02x:%02x:%02x", macAddress[0], macAddress[1],
           macAddress[2], macAddress[3], macAddress[4], macAddress[5]);

  Serial.print("Received From: ");
  Serial.println(macAddressString);
  Serial.print("Data: ");
  Serial.println(data[0]);
  WiFi.begin(SSID, PASS);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected");
  Serial.print("Sending Data...");
  String stringToSend = "POT=";
  stringToSend += (String)data[0];
  sendData(stringToSend);
  WiFi.disconnect();
  Serial.println("Data Send");
}

#endif // __CALLBACKSFUNCTIONS_H__