# Nombre del Proyecto

Descripción breve del proyecto, incluyendo su finalidad y características principales.

#### SD Handling Functions

| Function          | Description                                                   |
|-------------------|---------------------------------------------------------------|
| `initializeSD()`  | Initializes the SD card. Sets `sdNotDetected` to true if the SD card cannot be initialized. |
| `handleSDError()` | Prints an error message to the Serial monitor if an error occurs during SD card initialization. |

#### JSON Handling Functions

| Function                      | Description                                                                                   |
|-------------------------------|-----------------------------------------------------------------------------------------------|
| `readCredentialsFromJSON()`  | Reads network credentials (SSID and password) from a JSON file stored on the SD card. Loads these credentials into the `credentials` structure. Prints an error message if the file cannot be read or parsed correctly. |

#### WiFi Handling Functions

The project includes functionalities to manage WiFi connections, allowing the device to connect to a network using credentials stored on the SD card. These functionalities are crucial for projects requiring internet access or network communication.

| Function                | Description                                                   |
|-------------------------|---------------------------------------------------------------|
| `connectToWiFi()`       | Tries to connect to the WiFi network using the credentials provided in the `NetworkCredentials` structure. It waits for a connection to be established up to a specified timeout (`WIFI_CONNECT_TIMEOUT`). If the connection fails within this period, it prints an error message and sets a global flag (`wifiConnectFailed`) to true, indicating the failure. |
| `isConnectedToWiFi()`   | Checks the current connection status and returns true if the device is connected to a WiFi network. Useful for reconnection strategies or network status checks in your application logic. |

These functions support the creation of IoT applications with the ESP32 that require reliable network connectivity to function correctly.

#### Ethernet Handling Functions

The project includes functionalities to manage Ethernet connections, providing an alternative to Wi-Fi for network connectivity. These functions are essential for applications that can benefit from the reliability of a wired connection.

| Function                  | Description                                                   |
|---------------------------|---------------------------------------------------------------|
| `initializeEthernet()`    | Initializes the Ethernet module using the specified MAC address and attempts to establish a connection. Prints "Connected to Ethernet" and the IP address upon success, or an error message upon failure. |
| `disconnectEthernet()`    | Although the Ethernet library may not provide an explicit `end()` method, this function is intended to stop all Ethernet activities and prepare the system to switch to Wi-Fi if needed. |
| `isConnectedToEthernet()` | Checks if the device is currently connected to a network via Ethernet by verifying the IP address is valid and not self-assigned (0.0.0.0). |

#### Network Handling Functions

The project supports dynamic switching between Wi-Fi and Ethernet connections based on predefined priorities or user input, ensuring continuous network connectivity.

| Function                 | Description                                                   |
|--------------------------|---------------------------------------------------------------|
| `switchNetworkInterface()` | Based on the `priorityWiFi` flag within the `NetworkCredentials` structure, this function attempts to switch the network interface from Wi-Fi to Ethernet or vice versa. It ensures the device remains online by switching to the alternative interface if the preferred one fails to connect. |
