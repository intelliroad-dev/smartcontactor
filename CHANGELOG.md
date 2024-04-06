# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](http://semver.org/).

## [0.1.0] - 2024-03-05
### Added
- SD card handling functionality for reading JSON files.
- Functions implementation to read network credentials from a JSON file.

### Changed
- Improved error handling for SD card initialization.

### Fixed
- Minor bug fixes in JSON file reading.

## [0.1.5] - 2024-03-06

### Added
- Ethernet connectivity support using the Arduino Ethernet library for projects requiring wired connections.
- `initializeEthernet`, `disconnectEthernet`, and `isConnectedToEthernet` functions in `EthernetFunctions.hpp` to manage Ethernet connections.
- `switchNetworkInterface` function in `NetworkFunctions.hpp` to allow dynamic switching between Wi-Fi and Ethernet based on connection availability and priority settings.
- Error handling for failed Ethernet connections, with a new error code `ERR: ETH 01` defined in `ErrorDefinitions.h`.

### Changed
- Updated `ConfigModule.hpp` to include definitions and global variables supporting Ethernet connectivity and network switching logic.
- Modified the main application logic to attempt network connection using Ethernet if Wi-Fi is not available or prioritized.

### Fixed
- Minor bug fixes and performance improvements in network connection routines.

## [0.1.7] - 2024-03-06

### Added
- `RGBFunctions.hpp` with functionalities to control an RGB LED, enabling the device to display different colors (WHITE, MAGENTA, YELLOW, CYAN) based on specific conditions or actions.
- `ButtonFunctions.hpp` introduces advanced button handling that allows the device to trigger different actions based on the duration of the button press. This includes setting the RGB LED to different colors depending on how long the button is pressed and executing specific actions when the button is released.
- Function `handleChangeInterface()` in `NetworkFunctions.hpp`, allowing dynamic switching between WiFi and Ethernet network interfaces based on user input via a button press. This function also toggles the `priorityWiFi` flag to determine the network interface priority.

### Changed
- Enhanced button debounce logic in `ButtonFunctions.hpp` to improve the accuracy of press duration detection and prevent false triggers.
- Updated network connection handling to incorporate dynamic interface switching through the `handleChangeInterface()` function, enhancing the device's network flexibility.

### Fixed
- Minor bug fixes in network connection logic to ensure reliable switching between WiFi and Ethernet connections.
- Adjustments to RGB LED color display timing to synchronize with button press durations more accurately.

This update significantly enhances the device's interactive capabilities, offering users a more intuitive and responsive way to control its network connectivity and visual feedback through the RGB LED. The introduction of time-sensitive button actions opens up new possibilities for user interaction and device functionality.
