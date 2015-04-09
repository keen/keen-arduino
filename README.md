# keen-arduino

This library allows you to push events from the Arduino Yun to [https://keen.io](https://keen.io).

## Examples

Example usage of the `keen-arduino` library can be found in the `examples` directory.

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
  
  keen.addEvent("YOUR_EVENT_COLLECTION", "YOUR_JSON_DATA");
  
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

The ATmega32U4 microcontroller on the Arduino Yun has very little RAM. As such, the `KeenClient` API exposes methods that accept `char *`, `String *`, and `__FlashStringHelper *`. The inclusion of `__FlashStringHelper *` allows users to wrap their string literals in the [F() macro](http://playground.arduino.cc/Learning/Memory), which will in turn store the data in the more plentiful flash memory instead of RAM.

`KeenClient()`

The Arduino Yun has very limited RAM. Additionally, there are few use cases for which all of the API keys are necessary. Because of this, the constructor does not take any API key parameters, but rather exposes setter methods to set them.

The constructor does, however, set the default API version to `3.0`.

```cpp
void setApiVersion(const __FlashStringHelper *api_version)
void setApiVersion(const String *api_version)
void setApiVersion(const char *api_version)
```

```cpp
void setProjectId(const __FlashStringHelper *project_id)
void setProjectId(const String *project_id)
void setProjectId(const char *project_id)
```

```cpp
void setWriteKey(const __FlashStringHelper *write_key)
void setWriteKey(const String *write_key)
void setWriteKey(const char *write_key)
```

```cpp
void setReadKey(const __FlashStringHelper *read_key)
void setReadKey(const String *read_key)
void setReadKey(const char *read_key)
```

```cpp
void setMasterKey(const __FlashStringHelper *master_key)
void setMasterKey(const String *master_key)
void setMasterKey(const char *master_key)
```

```cpp
unsigned int addEvent(const __FlashStringHelper *event_collection, const __FlashStringHelper *event_body)
unsigned int addEvent(const String &event_collection, const String &event_body)
unsigned int addEvent(const char *event_collection, const char *event_body)
```

```cpp
unsigned int addEvents(const __FlashStringHelper *events)
unsigned int addEvents(const String &events)
unsigned int addEvents(const char *events)
```

## Installation

Copy or unzip the contents of `keen-arduino` to `~/sketchbook/libraries/KeenClient/` and restart the Arduino IDE. The examples directory provides a good starting point.

### Upload Certificate Authority

In order to verify the identity of the remote host, [https://api.keen.io](https://api.keen.io)'s root certificate authority must be uploaded to the AR9331 on board the Arduino Yun. Instructions for uploading the root certificate authority can be found [here](https://bitbucket.org/kinsolresearch/keen-arduino/src/HEAD/tools/README.md?at=master).

## Supported Hardware

The `keen-arduino` library supports the Arduino Yun, as [TLS](https://en.wikipedia.org/wiki/Transport_Layer_Security) is required to use [https://keen.io](https://keen.io)'s API.
Currently, no other Arduino board has the power or the memory to handle the cryptographic functions required by a TLS implementation. The Arduino Yun's TLS implementation makes use of the on board AR9331 WIFI/SOC which runs embedded Linux.

## Notes
