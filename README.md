# keen-arduino

This library allows you to push events from the Arduino Yun to [https://keen.io](https://keen.io).

## tl;dr

```ino

#include <Bridge.h>
#include <ApiClient.h>
#include <KeenClient.h>

KeenClient keen;

void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Bridge.begin();
  digitalWrite(13, HIGH);

  Serial.begin(115200);

  while (!Serial);
}

void loop() {

  keen.setApiVersion(F("3.0"));
  keen.setProjectId(F("YOUR_PROJECT_ID"));
  keen.setWriteKey(F("YOUR_WRITE_KEY"));
  
  keen.addEvent("YOUR_JSON_DATA");
  
  keen.printRequest();
  
  while (keen.available()) {
    char c = keen.read();
    Serial.print(c);
  }
  Serial.println();
  Serial.flush();

  delay(2000);
}
```

## Library Reference

## Installation

Copy or unzip the contents of `keen-arduino` to `~/sketchbook/libraries/KeenClient/` and restart the Arduino IDE. The examples directory provides a good starting point.

## Supported Hardware

The `keen-arduino` library supports the Arduino Yun, as [TLS](https://en.wikipedia.org/wiki/Transport_Layer_Security) is required to use [https://keen.io](https://keen.io)'s API.
Currently, no other Arduino board has the power or the memory to handle the cryptographic functions required by a TLS implementation. The Arduino Yun's TLS implementation makes use of the on board AR9331 WIFI/SOC which runs embedded Linux.

## Notes
