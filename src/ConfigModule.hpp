// src\ConfigModule.hpp
#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include <FS.h>
#include <ArduinoJson.h>
#include "ErrorDefinitions.h"
#include "StatusDefinitions.h"

#include <WiFi.h>
#include <Ethernet.h>

// SD
#define SS_PIN 4

// WiFi
#define JSON_FILE "/credentials/credentials.json"

struct NetworkCredentials
{
  String ssid;
  String password;
  bool priorityWiFi = true; // true for WiFi, false for Ethernet
};

NetworkCredentials credentials;
bool sdNotDetected;
bool wifiConnectFailed = false;
#define WIFI_CONNECT_TIMEOUT 8000

#define ETHERNET_SS_PIN 5
bool isConnected = false;

EthernetClient client;

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};

// Buttton
#define BUTTON_PIN 0

#define ONE_TIME_PUSH 50
#define SECOND_TIME_PUSH 2000
#define THIRD_TIME_PUSH 5000
#define FOURTH_TIME_PUSH 8000

// RGB
#define RED_PIN 25
#define GREEN_PIN 26
#define BLUE_PIN 27
