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
