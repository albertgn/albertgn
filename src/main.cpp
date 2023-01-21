#include <Arduino.h>
#include <SPI.h>
#include <Ethernet.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <Wire.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include "FastLED.h"
#include "color_palettes.h"

// Led related declarations
#define FASTLED_ESP8266_RAW_PIN_ORDER
#define FASTLED_INTERNAL // Suppress build banner
#define NUM_LEDS 100
#define LED_TYPE WS2812
#define COLOR_ORDER GRB
#define TIMES_PER_SECOND(x) EVERY_N_MILLISECONDS(1000 / x)
#define LED_PIN D2          // D4 on the board
#define SUNRISE_DURATION 30 // in minutes

CRGB smart_lamp_leds[NUM_LEDS];

// this has to be here because is uses constants from this file
#include "fire2012.h"
#include "pacifica.h"
#include "comet.h"
#include "lava.h"
#include "police.h"
int brightness = 128;
int g_PowerLimit = 900; // 900mW draw

// Network related declarations
const char *ssid = "andromeda2";
const char *password = "jam!5FBjam!5FB";
IPAddress ip(10, 0, 0, 16);
const int port = 80;
// Set up the WiFi connection
WiFiServer server(ip, port);

boolean fireflag, pacificaflag, cometflag;
String storedCommand = "nop";

unsigned long startTime;

// setup the OTA capability
void setupOTA()
{

  // Port defaults to 8266
  ArduinoOTA.setPort(8266);

  // Hostname defaults to esp8266-[ChipID]
  ArduinoOTA.setHostname("smartlamp_slave");

  // No authentication by default
  // ArduinoOTA.setPassword("tetraomega2019");

  // Password can be set with it's md5 value as well
  // MD5(admin) = 21232f297a57a5a743894a0e4a801fc3
  // ArduinoOTA.setPasswordHash("21232f297a57a5a743894a0e4a801fc3");

  ArduinoOTA.onStart([]()
                     {
                       String type;
                       if (ArduinoOTA.getCommand() == U_FLASH)
                       {
                         type = "sketch";
                       }
                       else
                       { // U_SPIFFS
                         type = "filesystem";
                       }

                       // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
                       Serial.println("Start updating " + type); });
  ArduinoOTA.onEnd([]()
                   { Serial.println("\nEnd"); });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total)
                        { Serial.printf("Progress: %u%%\r", (progress / (total / 100))); });
  ArduinoOTA.onError([](ota_error_t error)
                     {
                       Serial.printf("Error[%u]: ", error);
                       if (error == OTA_AUTH_ERROR)
                       {
                         Serial.println("Auth Failed");
                       }
                       else if (error == OTA_BEGIN_ERROR)
                       {
                         Serial.println("Begin Failed");
                       }
                       else if (error == OTA_CONNECT_ERROR)
                       {
                         Serial.println("Connect Failed");
                       }
                       else if (error == OTA_RECEIVE_ERROR)
                       {
                         Serial.println("Receive Failed");
                       }
                       else if (error == OTA_END_ERROR)
                       {
                         Serial.println("End Failed");
                       } });
  ArduinoOTA.begin();
}

void setup()
{
  startTime = millis();
  Serial.begin(115200);

  pinMode(LED_BUILTIN, OUTPUT);

  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\n");
  Serial.println("connected");
  Serial.println(WiFi.SSID());
  Serial.println(WiFi.localIP());
  delay(200);

  // setup the fastleds
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(smart_lamp_leds, NUM_LEDS); //.setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(brightness);
  set_max_power_indicator_LED(LED_BUILTIN); // FastLED will light LED if power limiting
  FastLED.setMaxPowerInMilliWatts(g_PowerLimit);

  // setup the server
  server.begin();

  // setup OTA capability
  setupOTA();
}

void turnOnLamp()
{
  // Turn on the lamp
  fill_solid(smart_lamp_leds, NUM_LEDS, CRGB(255, 87, 0));
  FastLED.show();
  FastLED.delay(30);
}

void turnOffLamp()
{
  // Turn off the lamp
  fill_solid(smart_lamp_leds, NUM_LEDS, CRGB(0, 0, 0));
  FastLED.show();
  FastLED.delay(30);
}

void setColor(uint8_t red, uint8_t green, uint8_t blue)
{
  // Set the color of the lamp
  fireflag = false;
  cometflag = false;
  pacificaflag = false;
  storedCommand = "nop";
  fill_solid(smart_lamp_leds, NUM_LEDS, CRGB(red, green, blue));
  FastLED.show();
  FastLED.delay(30);
}

void check_client()
{

  // Check for incoming connections
  WiFiClient client = server.available();
  if (client)
  {
    // Read the incoming command
    String command = client.readStringUntil('\r');
    Serial.println("Received command: " + command);
    if (command != "nop" | command != NULL)
    {
      fireflag = false;
      cometflag = false;
      pacificaflag = false;
      storedCommand = command;
    }
  }
}

void executeCommand(String command)
{

  // Process the command
  if (command == "on")
  {
    storedCommand = "nop";
    turnOnLamp();
  }
  else if (command == "off")
  {
    storedCommand = "nop";
    turnOffLamp();
  }
  else if (command == "red")
  {

    setColor(255, 0, 0);
  }
  else if (command == "green")
  {
    setColor(0, 255, 0);
  }
  else if (command == "blue")
  {
    setColor(0, 0, 255);
  }
  else if (command == "purple")
  {
    setColor(100, 0, 255);
  }
  else if (command == "orange")
  {
    setColor(255, 87, 0);
  }

  else if (command == "fire")
  {
    FastLED.clear();
    storedCommand = "nop";
    fireflag = true;
    // run fire
    while (fireflag)
    {
      EVERY_N_MILLISECONDS(50)
      {
        Fire2012();
        FastLED.show();
        FastLED.delay(1000 / FRAMES_PER_SECOND);
      }
      check_client();
    }
  }
  else if (command == "pacifica")
  {
    FastLED.clear();
    pacificaflag = true;
    storedCommand = "nop";

    // run pacirica
    Serial.println("pacifica");
    while (pacificaflag)
    {
      EVERY_N_MILLISECONDS(50)
      {
        pacifica_loop();
        FastLED.show();
        FastLED.delay(10);
      }
      check_client();
    }
  }
  else if (command == "comet")
  {

    FastLED.clear();
    cometflag = true;
    storedCommand = "nop";
    while (cometflag)
    {
      TIMES_PER_SECOND(50)
      {
        fadeToBlackBy(smart_lamp_leds, NUM_LEDS, 64);
        float pos = beatsin16(32, 0, NUM_LEDS - 10);

        DrawPixels(pos, 10, CHSV(30, 255, 255)); // H between 0 - 180, S:255, V:255
        DrawComet();

        FastLED.delay(10);
        FastLED.show();
      }

      check_client();
    }
  }
}

// loop funtion

void loop()
{
/*
  unsigned long currentTime = millis();
  unsigned long elapsedTime = (currentTime - startTime) / 60000; // convert to minutes

  if (elapsedTime <= SUNRISE_DURATION)
  {
    float progress = (float)elapsedTime / SUNRISE_DURATION;
    
    for (int i = 0; i < NUM_LEDS; i++)
    {
  
      smart_lamp_leds[i] = CHSV((int)(i * 2 * progress), 255, (int)(255 * progress));
      
    }
    FastLED.show();
    delay(30);
  }*/
  
    String command;
    if (storedCommand != "nop")
    {

      Serial.println("there is a stored command");
      Serial.println(command);
      command = storedCommand;
      executeCommand(command);
    }
    else
    {

      // Check for incoming connections
      WiFiClient client = server.available();
      if (client)
      {
        // Read the incoming command
        command = client.readStringUntil('\r');
        Serial.println("Received command: " + command);
        executeCommand(command);

        // Send a response to the client
        client.println("ACK");
      }
    }
  
  // Handle OTA updates
  ArduinoOTA.handle();
}
