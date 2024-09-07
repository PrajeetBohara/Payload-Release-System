#include <WiFi.h>
#include <ESP32Servo.h>
#include <WebServer.h>

const char* ssid = "Machi*ne";
// "Machi*ne";
const char* password = "granite-134-264";
// "granite-134-264";

Servo myservo; 
int position = 0;    
int servoPin = 5;

WebServer server(80);

void handleRoot() {
  String webpage = "<html>\
                    <head>\
                      <title>ESP32 LoRa Servo Control</title>\
                      <style>\
                        .slider-container {\
                          width: 50%;\
                          margin: auto;\
                        }\
                      </style>\
                      <script>\
                        function updateServo(val) {\
                          document.getElementById('servoValue').innerText = val;\
                          var xhr = new XMLHttpRequest();\
                          xhr.open('GET', '/setServo?position=' + val, true);\
                          xhr.send();\
                        }\
                      </script>\
                    </head>\
                    <body>\
                      <h1>Servo Slider</h1>\
                      <div class=\"slider-container\">\
                        <label for=\"position\">Servo Position (0-180):</label>\
                        <input type=\"range\" id=\"position\" name=\"position\" min=\"0\" max=\"180\" value=\"" + String(position) + "\" onchange=\"updateServo(this.value)\">\
                        <br>\
                        <output id=\"servoValue\">" + String(position) + "</output>\
                      </div>\
                    </body>\
                    </html>";
  
  server.send(200, "text/html", webpage);
}

void handleSetServo() {
  if (server.hasArg("position")) {
    String posArg = server.arg("position");
    position = posArg.toInt();
    if (position >= 0 && position <= 180) {
      myservo.write(position);
      server.send(200, "text/plain", "Servo position set to " + posArg);
    } else {
      server.send(400, "text/plain", "Invalid position. Must be between 0 and 180.");
    }
  } else {
    server.send(400, "text/plain", "Position argument missing.");
  }
}

void setup() {
  Serial.begin(115200);
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  
  // Print ESP32 IP address
  Serial.println("Connected to WiFi");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Start web server
  server.on("/", handleRoot);
  server.on("/setServo", handleSetServo);
  server.begin();
  Serial.println("Web server started");

  // Initialize the servo
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  myservo.setPeriodHertz(50);    
  myservo.attach(servoPin, 500, 2500); // Modified pulse width range
}

void loop() {
  server.handleClient();
}
