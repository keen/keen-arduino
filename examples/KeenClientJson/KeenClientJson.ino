
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
  
  keen.addEvent("motion_detections", "{\"cat\": 1}");
  
  keen.printRequest();
  
  while (keen.available()) {
    char c = keen.read();
    Serial.print(c);
  }
  Serial.println();
  Serial.flush();

  delay(2000);
}
