// src\ConfigModule.hpp
#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include <FS.h>
#include <ArduinoJson.h>
#include "ErrorDefinitions.h"

#define SS_PIN 4
#define JSON_FILE "/credentials/credentials.json"

struct NetworkCredentials
{
  String ssid;
  String password;
};

NetworkCredentials credentials;
bool sdNotDetected;

