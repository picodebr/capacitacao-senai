#ifndef __CALLBACKSFUNCTIONS_H__
#define __CALLBACKSFUNCTIONS_H__
#include <Arduino.h>

#include "api-credentiasl.h"
#include "network-credentials.h"

int value = 0;
bool send = false;



void OnDataReceived(const uint8_t* macAddress, const uint8_t* data, int dataLength) {
  char macAddressString[18];
  snprintf(macAddressString, sizeof(macAddressString),
           "%02x:%02x:%02x:%02x:%02x:%02x", macAddress[0], macAddress[1],
           macAddress[2], macAddress[3], macAddress[4], macAddress[5]);

  Serial.print("Received From: ");
  Serial.println(macAddressString);
  Serial.print("Data: ");
  Serial.println(data[0]);
  value = data[0];
  send =  true;
  // sendData("POT=" + (String)data[0]);
}

#endif // __CALLBACKSFUNCTIONS_H__