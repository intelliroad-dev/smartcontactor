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

