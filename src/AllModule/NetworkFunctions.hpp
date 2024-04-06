// src\AllModule\NetworkFunctions.hpp
#ifndef NETWORKFUNCTIONS_HPP
#define NETWORKFUNCTIONS_HPP

void switchNetworkInterface()
{
    disconnectEthernet();
    disconnectWiFi();

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

    isConnected = credentials.priorityWiFi ? isConnectedToWiFi() : isConnectedToEthernet();

    Serial.println(isConnected ? "Online" : "Offline");
}

void handleChangeInterface()
{
    credentials.priorityWiFi = !credentials.priorityWiFi;
    switchNetworkInterface();
}

#endif src\AllModule\NetworkFunctions.hpp