
#include <Bridge.h>
#include <ApiClient.h>

ApiClient client;

void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Bridge.begin();
  digitalWrite(13, HIGH);

  Serial.begin(115200);

  while (!Serial);
}

void loop() {

  client.setContentTypeHeader(F("application/json"));
  client.setUserAgentHeader(F("Arduino/0.1a"));
  client.setAuthorizationHeader(F("YOUR_WRITE_KEY"));
  
  client.post(
    "https://api.keen.io/3.0/projects/YOUR_PROJECT_ID/events",
    "YOUR_JSON_DATA"
  );
  
  client.printRequest();
  
  while (client.available()) {
    char c = client.read();
    Serial.print(c);
  }
  Serial.println();
  Serial.flush();
  
  delay(2000);
}

