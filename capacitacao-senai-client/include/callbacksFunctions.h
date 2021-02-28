#ifndef __CALLBACKSFUNCTIONS_H__
#define __CALLBACKSFUNCTIONS_H__
#include <Arduino.h>

#include "esp_now.h"
#include "setupOled.h"

void OnDataSend(const uint8_t* macAddress, esp_now_send_status_t status) {
  char macAddressString[18];

  snprintf(macAddressString, sizeof(macAddressString),
           "%02x:%02x:%02x:%02x:%02x:%02x", macAddress[0], macAddress[1],
           macAddress[2], macAddress[3], macAddress[4], macAddress[5]);
  // display.println("Sent to: ");
  display.println(macAddressString);
  display.println("status: ");
  display.println(status);
}

#endif  // __CALLBACKSFUNCTIONS_H__