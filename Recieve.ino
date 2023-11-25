#include <Wire.h>
#include <ESP8266WiFi.h>
#include <espnow.h>
#include<SoftwareSerial.h>
SoftwareSerial mySUART(4, 5);
int prev=0;
int receivedData;
void onDataReceived(uint8_t *mac, uint8_t *data, uint8_t len) {
  if (len == sizeof(int)) {
    memcpy(&receivedData, data, sizeof(int));
  }
}

void setup() {
  Serial.begin(115200);
  mySUART.begin(115200);

  Wire.begin();
  pinMode(A0, INPUT);
  WiFi.mode(WIFI_STA);
  if (esp_now_init() == 0) {
    esp_now_register_recv_cb(onDataReceived);
    uint8_t recipientMac[] = {0x3C, 0x61, 0x05, 0xE9, 0x67, 0x14};
    esp_now_add_peer(recipientMac, ESP_NOW_ROLE_COMBO, 1, nullptr, 0);
    while (!Serial) {
    }
  }
}
void loop() {
  if(receivedData!=0&&receivedData!=prev)
  {
    
  prev=receivedData;
  Serial.println(receivedData);
  if(Serial.available()>0)
  {
    byte x = receivedData;
    mySUART.write(x);
  }
  if(mySUART.available()>0)
  {
    Serial.write((char)mySUART.read());
  }
  }
  
  delay(100);
}
