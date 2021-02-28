#ifndef __SETUPWIFI_H__
#define __SETUPWIFI_H__
#include <Arduino.h>
#include <WiFi.h>

#include "callbacksFunctions.h"
#include "esp_now.h"
#include "pins.h"
#include "setupOled.h"

#define gatewaychannel 11

esp_now_peer_info_t gateway;

// uint8_t gatewayMacAddress[6] = {0x24, 0x0A, 0xC4, 0x09, 0x46, 0x50};
uint8_t gatewayMacAddress[][6] = {{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};

void initEspNow() {
  if (esp_now_init() == ESP_OK) {
    display.println("Esp Now Initialized");
  } else {
    display.println("Esp Now Failed");
    delay(500);
    ESP.restart();
  }
}

void peerToGateway() {
  gateway.channel = gatewaychannel;
  gateway.encrypt = 0;
  memcpy(gateway.peer_addr, gatewayMacAddress[0], sizeof(gatewayMacAddress[0]));
  esp_now_add_peer(&gateway);
}

void setupWiFi() {
  WiFi.mode(WIFI_STA);
  display.println("MAC:");
  display.println(WiFi.macAddress());
  initEspNow();
  peerToGateway();
  esp_now_register_send_cb(OnDataSend);
}

void sendMessage() {
  int trimpotValue = analogRead(potentiometerPin);
  display.print("POT: ");
  display.println(trimpotValue);
  esp_err_t resulOfSend = esp_now_send(
      gatewayMacAddress[0], (uint8_t*)&trimpotValue, sizeof(trimpotValue));
  display.print("Send Status: ");
  display.println(resulOfSend == ESP_OK ? "OK" : "ERROR");
}

#endif  // __SETUPWIFI_H__