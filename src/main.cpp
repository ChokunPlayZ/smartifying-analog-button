#include <Arduino.h>
#include <Servo.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#include "config.cpp"
#include "html/index.cpp"

Servo servo1;

ESP8266WebServer server(80);

void handleRoot()
{
  String s = indexpage;
  server.send(200, "text/html", s);
}

void handleTrig(){
  servo1.write(75);
  delay(100);
  servo1.write(1);
  Serial.println("Servo Triggered");
  server.send(200, "application/json","{\"status\":\"done\"}");
}

void setup()
{
  servo1.attach(D5);
  Serial.begin(115200);
  servo1.write(1);
  delay(1000);

  WiFi.begin(ssid, password);
  Serial.println("");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/t", handleTrig);
  server.begin();
}

void loop()
{
  server.handleClient();
}