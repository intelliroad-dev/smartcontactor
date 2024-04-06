// src\main.cpp
#include "ConfigModule.hpp"
#include "InitializeModule.hpp"

void handleButtonPress()
{
  credentials.priorityWiFi = !credentials.priorityWiFi;
  switchNetworkInterface();
}

void setup()
{
  initializeModule();
}

void loop()
{
  static unsigned long lastDebounceTime = 0;
  static bool lastButtonState = HIGH;
  unsigned long debounceDelay = 50;

  bool currentButtonState = digitalRead(BUTTON_PIN);

  if (currentButtonState == LOW && lastButtonState == HIGH && (millis() - lastDebounceTime) > debounceDelay)
  {
    handleButtonPress();

    lastDebounceTime = millis();
  }

  lastButtonState = currentButtonState;
}
