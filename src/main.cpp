#include <Arduino.h>
#include <WiFi.h>

// LED azul embutido na placa DOIT ESP32 DevKit v1
const int LED_PIN = 2;

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(200);
  digitalWrite(LED_PIN, LOW);
  delay(500);

  int n = WiFi.scanNetworks();
  for (int i = 0; i < n; i++) {
    Serial.printf("%s (%d dBm) canal %d\n\r", WiFi.SSID(i).c_str(), WiFi.RSSI(i), WiFi.channel(i));
  }
  delay(5000);
}
