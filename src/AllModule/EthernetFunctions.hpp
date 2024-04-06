// src\AllModule\EthernetFunctions.hpp
#ifndef ETHERNETFUNCTIONS_HPP
#define ETHERNETFUNCTIONS_HPP

void initializeEthernet()
{
    Ethernet.init(ETHERNET_SS_PIN);
    if (Ethernet.begin(mac))
    {
        Serial.println(STA_ETH_CONNECT_OK);
        Serial.print("Ethernet Connected. IP address: ");
        Serial.println(Ethernet.localIP());
        isConnected = true;
    }
    else
    {
        Serial.println(ERR_ETHERNET_CONNECT_FAIL);
        isConnected = false;
    }
}

void disconnectEthernet()
{
    client.stop();
}

bool isConnectedToEthernet()
{
    return Ethernet.localIP() != INADDR_NONE && Ethernet.localIP() != IPAddress(0, 0, 0, 0);
}

#endif // ETHERNETFUNCTIONS_HPP
