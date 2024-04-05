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
    Serial.println("Loadded credentials:");
    Serial.println("SSID: " + credentials.ssid);
    Serial.println("Password: " + credentials.password);

    file.close();
}

#endif // JSONFUNCTIONS_HPP