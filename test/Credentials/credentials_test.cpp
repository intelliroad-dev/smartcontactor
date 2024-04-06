// test\Credentials\credentials_test.cpp
#include "../../src/ConfigModule.hpp"
#include "../../src/AllModule/SDFunctions.hpp"
#include "../../src/AllModule/JSONFunctions.hpp"

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
}