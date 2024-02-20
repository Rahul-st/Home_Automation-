// This Code for control relays via mobile using HTML 
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "  "; // Enter the host name
const char* password = "   ";// Enter the password

ESP8266WebServer server(80);

const int relayPin1 = D1; 
const int relayPin2 = D2;
const int relayPin3 = D3;
const int relayPin4 = D4;
const int relayPin5 = D5;
const int relayPin6 = D6;
const int relayPin7 = D7;
const int relayPin8 = D8;

void setup() {
  Serial.begin(115200);
  delay(10);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Connected to the WiFi network");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  // Print the IP address to the Serial Monitor

  server.on("/", HTTP_GET, []() {
    server.send(200, "text/html", getHTML());
  });
  // you can see the output of the relay in Serial Monitor

  server.on("/relay1/on", HTTP_GET, []() {
    digitalWrite(relayPin1, HIGH);
    server.send(200, "text/html", getHTML());
    Serial.print("Relay 1 ON\n");
  });

  server.on("/relay1/off", HTTP_GET, []() {
    digitalWrite(relayPin1, LOW);
    server.send(200, "text/html", getHTML());
    Serial.print("Relay 1 OFF\n");
  });

  server.on("/relay2/on", HTTP_GET, []() {
    digitalWrite(relayPin2, HIGH);
    server.send(200, "text/html", getHTML());
    Serial.print("Relay 2 ON\n");
  });

  server.on("/relay2/off", HTTP_GET, []() {
    digitalWrite(relayPin2, LOW);
    server.send(200, "text/html", getHTML());
    Serial.print("Relay 2 OFF\n");
  });

  server.on("/relay3/on", HTTP_GET, []() {
    digitalWrite(relayPin3, HIGH);
    server.send(200, "text/html", getHTML());
    Serial.print("Relay 3 ON\n");
  });

  server.on("/relay3/off", HTTP_GET, []() {
    digitalWrite(relayPin3, LOW);
    server.send(200, "text/html", getHTML());
    Serial.print("Relay 3 OFF\n");
  });

  server.on("/relay4/on", HTTP_GET, []() {
    digitalWrite(relayPin4, HIGH);
    server.send(200, "text/html", getHTML());
    Serial.print("Relay 4 ON\n");
  });

  server.on("/relay4/off", HTTP_GET, []() {
    digitalWrite(relayPin4, LOW);
    server.send(200, "text/html", getHTML());
    Serial.print("Relay 4 OFF\n");
  });
   server.on("/relay5/on", HTTP_GET, []() {
    digitalWrite(relayPin5, HIGH);
    server.send(200, "text/html", getHTML());
    Serial.print("Relay 5 ON \n");
  });

  server.on("/relay5/off", HTTP_GET, []() {
    digitalWrite(relayPin5, LOW);
    server.send(200, "text/html", getHTML());
    Serial.print("Relay 5 OFF \n ");
  });
   server.on("/relay6/on", HTTP_GET, []() {
    digitalWrite(relayPin6, HIGH);
    server.send(200, "text/html", getHTML());
    Serial.print("Relay 6 ON\n");
  });

  server.on("/relay6/off", HTTP_GET, []() {
    digitalWrite(relayPin6, LOW);
    server.send(200, "text/html", getHTML());
    Serial.print("Relay 6 OFF \n");
  });
   server.on("/relay7/on", HTTP_GET, []() {
    digitalWrite(relayPin7, HIGH);
    server.send(200, "text/html", getHTML());
    Serial.print("Relay 7 ON \n");
  });

  server.on("/relay7/off", HTTP_GET, []() {
    digitalWrite(relayPin7, LOW);
    server.send(200, "text/html", getHTML());
    Serial.print("Relay 7 OFF \n");
  });
   server.on("/relay8/on", HTTP_GET, []() {
    digitalWrite(relayPin8, HIGH);
    server.send(200, "text/html", getHTML());
    Serial.print("Relay 8 ON \n");
  });

  server.on("/relay8/off", HTTP_GET, []() {
    digitalWrite(relayPin8, LOW);
    server.send(200, "text/html", getHTML());
    Serial.print("Relay 8 OFF \n");
  });

  server.begin();
}

void loop() {
  server.handleClient();
}
// You can change the style of this Code for your Think
String getHTML() {
  String html = "<!DOCTYPE html>\
<html>\
<head>\
  <style>\
     body, html {margin: 0;padding: 0;height: 100%;}\
     body {background-color:#000;font-family: Arial, sans-serif; text-align: center;background-position: center;background-size: cover;background-repeat: no-repeat;}\
    h1 {color: #fff;}\
    h2 {color: #888;  font-family: 'Comic Sans MS', 'Comic Sans', cursive}\
    a {\
      box-shadow: 0 0 10px 5px #ffffff;\
      display: inline-flex;\
      padding: 10px 20px;\
      margin: 10px;\
      text-decoration: none;\
      color: #000;\
      background-color: #2ee0d1;\
      border-radius: 5px;\
      font-size: 20px;\
      font-weight: 100px;\
      height: 50px;\
      overflow: hidden;\
      position: relative;\
      font-family: 'Copperplate', Fantasy;\
    }\
    a:hover { background: transparent; color:#000; background-color:#37ff00}\
  </style>\
</head>\
<body>\
  <h1>HOME AUTOMATION</h1>\
  <h2>Rahul_Stark</h2>\
  <a href=\"/relay1/on\">Turn On Relay 1</a>\
  <a href=\"/relay1/off\">Turn Off Relay 1</a><br>\
  <a href=\"/relay2/on\">Turn On Relay 2</a>\
  <a href=\"/relay2/off\">Turn Off Relay 2</a><br>\
  <a href=\"/relay3/on\">Turn On Relay 3</a>\
  <a href=\"/relay3/off\">Turn Off Relay 3</a><br>\
  <a href=\"/relay4/on\">Turn On Relay 4</a>\
  <a href=\"/relay4/off\">Turn Off Relay 4</a><br>\
  <a href=\"/relay5/on\">Turn On Relay 5</a>\
  <a href=\"/relay5/off\">Turn Off Relay 5</a><br>\
  <a href=\"/relay6/on\">Turn On Relay 6</a>\
  <a href=\"/relay6/off\">Turn Off Relay 6</a><br>\
  <a href=\"/relay7/on\">Turn On Relay 7</a>\
  <a href=\"/relay7/off\">Turn Off Relay 7</a><br>\
  <a href=\"/relay8/on\">Turn On Relay 8</a>\
  <a href=\"/relay8/off\">Turn Off Relay 8</a>\
</body>\
</html>";
  return html;
}
