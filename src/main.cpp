#include <Arduino.h>

void setup() {
  pinMode(D4, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  digitalWrite(D4, 1);
  Serial.println("LED is ON!!!");
  delay(500);
  digitalWrite(D4, 0);
  Serial.println("LED is OFF!!!");
  delay(500);
}