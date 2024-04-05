// src\main.cpp
#include "ConfigModule.hpp"
#include "AllModule/SDFunctions.hpp"
#include "AllModule/JSONFunctions.hpp"

void setup()
{
  Serial.begin(115200);
  Serial.println("Firmware Version: " + String(VERSION));
  initializeSD();
  if (!sdNotDetected)
  {
    readCredentialsFromJSON();
  }
}

void loop()
{
  // Lógica de programa principal aquí...
}
