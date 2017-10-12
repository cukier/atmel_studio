#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char *ssid = "test";
const char *key = "PASS";
ESP8266WebServer server(80);

void handleRoot() {
  server.send(200, "text/html", "<h1>You are connected</h1>");
}

void setup() {
  Serial.begin(9600);
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, key);
  //WiFi.begin(ssid, key);
  server.on("/", handleRoot);
  server.begin();
}

void loop() {
  //WiFi.printDiag(Serial);
  server.handleClient();
  //delay(1000);
}
