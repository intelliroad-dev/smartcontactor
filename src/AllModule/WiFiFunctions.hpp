// src\AllModule\WiFiFunctions.hpp
#ifndef WIFIFUNCTIONS_HPP
#define WIFIFUNCTIONS_HPP

// Attempts to connect to the WiFi network using provided credentials.
// If the connection is not established within the defined timeout (WIFI_CONNECT_TIMEOUT),
// it sets the global flag `wifiConnectFailed` to true and prints an error message.
// Parameters:
// - credentials: A struct containing the SSID and password of the WiFi network.
void connectToWiFi(const NetworkCredentials &credentials)
{
    WiFi.begin(credentials.ssid.c_str(), credentials.password.c_str());

    unsigned long startTime = millis();
    while (WiFi.status() != WL_CONNECTED)
    {
        if (millis() - startTime >= WIFI_CONNECT_TIMEOUT)
        {
            Serial.println(ERR_WIFI_CONNECT_FAIL);
            wifiConnectFailed = true;
            isConnected = false;
            return;
        }
    }
    wifiConnectFailed = false;
    isConnected = true;
    Serial.println(STA_WIFI_CONNECT_OK);
    Serial.print("WiFi Connected. IP address: ");
    Serial.println(WiFi.localIP());
}

// Checks if the device is currently connected to a WiFi network.
// Returns true if connected, false otherwise.
bool isConnectedToWiFi()
{
    return WiFi.status() == WL_CONNECTED;
}

void disconnectWiFi()
{
    WiFi.disconnect();
}

#endif // WIFIFUNCTIONS_HPP
