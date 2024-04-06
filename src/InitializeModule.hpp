#include "AllModule/SDFunctions.hpp"
#include "AllModule/JSONFunctions.hpp"
#include "AllModule/WiFiFunctions.hpp"
#include "AllModule/EthernetFunctions.hpp"
#include "AllModule/NetworkFunctions.hpp"
#include "AllModule/RGBFunctions.hpp"
#include "AllModule/ButtonFunctions.hpp"

void initializeModule()
{
  Serial.begin(115200);
  while (!Serial)
    ;
  Serial.println("Firmware Version: " + String(VERSION));

  initializeRGB();
  initializeButton();
  setColor(BLACK);

  initializeSD();
  if (!sdNotDetected)
  {
    readCredentialsFromJSON();
    if (credentials.priorityWiFi)
    {
      connectToWiFi(credentials);
      if (!isConnected)
      {
        initializeEthernet();
      }
    }
    else
    {
      initializeEthernet();
      if (!isConnected)
      {
        connectToWiFi(credentials);
      }
    }
  }

  if (isConnected)
  {
    Serial.println("Online");
  }
  else
  {
    Serial.println("Offline");
  }
}