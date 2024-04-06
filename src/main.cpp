// src\main.cpp
#include "ConfigModule.hpp"
#include "InitializeModule.hpp"

void setup()
{
  initializeModule();
}

void loop()
{
  checkButtonPress();
}
