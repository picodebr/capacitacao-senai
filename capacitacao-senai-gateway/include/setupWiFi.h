#ifndef __SETUPWIFI_H__
#define __SETUPWIFI_H__
#include <Arduino.h>
#include <WiFi.h>
#include "esp_now.h"

#include "callbacksFunctions.h"
#include "network-credentials.h"

#define clientsChannel 11

uint8_t clientsMacAddress[][6]={
  {0xA4, 0xCF, 0x12, 0x75, 0x28, 0x8C}
};

void initEspNow() {
  if (esp_now_init() == ESP_OK) {
    Serial.println("Esp Now Initialized");
  } else {
    Serial.println("Esp Now Failed");
    delay(500);
    ESP.restart();
  }
}

void peerToClients(){
  int clientsCount = sizeof(clientsMacAddress)/6/sizeof(uint8_t);

  for(int i=0; i < clientsCount; i++){
    esp_now_peer_info client;

    client.channel = clientsChannel;
    client.encrypt = 0;
    memcpy(client.peer_addr, clientsMacAddress[i], sizeof(clientsMacAddress[i]));
    esp_now_add_peer(&client);
  }
}

void setupWiFi(){
  WiFi.disconnect(true, true);
  WiFi.mode(WIFI_AP_STA);
  WiFi.begin(SSID, PASS);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected");
  Serial.print("Channel: ");
  Serial.println(WiFi.channel());
  Serial.println(WiFi.softAPmacAddress());
  initEspNow();
  // peerToClients();
  esp_now_register_recv_cb(OnDataReceived);
}


#endif // __SETUPWIFI_H__