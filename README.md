# keen-arduino

This library allows you to push events from the Arduino Yun to [https://keen.io](https://keen.io).

## Library Reference

## Installation

Copy or unzip the contents of `keen-arduino` to `~/sketchbook/libraries/KeenClient/` and restart the Arduino IDE. The examples directory provides a good starting point.

## Supported Hardware

The `keen-arduino` library supports the Arduino Yun, as [TLS](https://en.wikipedia.org/wiki/Transport_Layer_Security) is required to use [https://keen.io](https://keen.io)'s API.
Currently, no other Arduino board has the power or the memory to handle the cryptographic functions required by a TLS implementation. The Arduino Yun's TLS implementation makes use of the on board AR9331 WIFI/SOC which runs embedded Linux.

## Notes
