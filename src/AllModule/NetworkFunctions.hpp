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