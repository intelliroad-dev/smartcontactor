// src\AllModule\JSONFunctions.hpp
#ifndef JSONFUNCTIONS_HPP
#define JSONFUNCTIONS_HPP

// Reads network credentials from a JSON file on the SD card
// Parses the JSON file and loads the credentials into the global `credentials` structure
// Prints an error message to the Serial monitor if the file cannot be read or parsed
void readCredentialsFromJSON()
{
    File file = SD.open(JSON_FILE, FILE_READ);
    if (!file)
    {
        Serial.println(ERR_JSON_READ);
        return;
    }

    StaticJsonDocument<256> doc;
    DeserializationError error = deserializeJson(doc, file);
    if (error)
    {
        Serial.println(ERR_JSON_READ);
        return;
    }

    credentials.ssid = doc["ssid"].as<String>();
    credentials.password = doc["password"].as<String>();
    credentials.priorityWiFi = doc["prioWiFi"].as<bool>();

    file.close();
    Serial.println(STA_JSON_READ_OK);
}

#endif // JSONFUNCTIONS_HPP