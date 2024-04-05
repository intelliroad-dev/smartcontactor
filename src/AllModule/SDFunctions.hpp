// src\AllModule\SDFunctions.hpp
#ifndef SDFUNCTIONS_HPP
#define SDFUNCTIONS_HPP

// Handles errors related to SD card initialization
// Prints an error message to the Serial monitor
void handleSDError()
{
    Serial.println(ERR_SD_NOT_DETECTED);
    sdNotDetected = true;
}

// Initializes the SD card
// Sets the global flag `sdNotDetected` to true if the SD card cannot be initialized
void initializeSD()
{
    if (!SD.begin(SS_PIN))
    {
        handleSDError();
    }
}

#endif // SDFUNCTIONS_HPP