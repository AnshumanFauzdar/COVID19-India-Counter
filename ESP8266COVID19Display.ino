/*        _   _  _____ _    _ _    _ __  __          _   _     ______     _    _ ___________          _____  
    /\   | \ | |/ ____| |  | | |  | |  \/  |   /\   | \ | |   |  ____/\  | |  | |___  /  __ \   /\   |  __ \ 
   /  \  |  \| | (___ | |__| | |  | | \  / |  /  \  |  \| |   | |__ /  \ | |  | |  / /| |  | | /  \  | |__) |
  / /\ \ | . ` |\___ \|  __  | |  | | |\/| | / /\ \ | . ` |   |  __/ /\ \| |  | | / / | |  | |/ /\ \ |  _  / 
 / ____ \| |\  |____) | |  | | |__| | |  | |/ ____ \| |\  |   | | / ____ \ |__| |/ /__| |__| / ____ \| | \ \ 
/_/    \_\_| \_|_____/|_|  |_|\____/|_|  |_/_/    \_\_| \_|   |_|/_/    \_\____//_____|_____/_/    \_\_|  \_\  */

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

const char* ssid = "SSID";
const char* password =  "PASS";
 
const String endpoint = "http://api.thingspeak.com/apps/thinghttp/send_request?api_key=";
const String key = "API-KEY";

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
 
  Serial.begin(115200);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi network");
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
 
}
 
void loop() {
 
  if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status
 
    HTTPClient http;
 
    http.begin(endpoint + key); //Specify the URL
    int httpCode = http.GET();  //Make the request
 
    if (httpCode > 0) { //Check for the returning code
 
        String payload = http.getString();
        String firstThree = payload.substring(0,4);

        // To get only digits for total patients

        Serial.println(firstThree);
        
        display.clearDisplay();

  display.setTextSize(1.5);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.println("India COVID-19 Cases ");
  display.display(); 
  
   display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(45, 35);
  // Display static text
  display.println(firstThree);
  display.display();
  
      }
 
    else {
      Serial.println("Error on HTTP request");
    }
 
    http.end(); 
  }
 
  delay(60000);
 
}
