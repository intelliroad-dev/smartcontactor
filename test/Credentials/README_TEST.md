## Hardware Setup for Testing

To perform real hardware tests, ensure you have the following setup:

1. **ESP32 DevKit:** Ensure your ESP32 is correctly connected to your computer via a USB cable.

2. **SD Card:** Format an SD card to FAT32 and create a JSON file with network credentials at the specified path `/credentials/credentials.json`. The file's content should look like this:

    ```json
    {
      "ssid": "YourWiFiNetwork",
      "password": "YourPassword"
    }
    ```

3. **SD Card Connection:** Insert the SD card into the SD card module and ensure it is properly connected to the ESP32 according to your defined pinout (SS_PIN set to 4).
