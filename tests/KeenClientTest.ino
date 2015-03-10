#line 2 "KeenClientTest.ino"
#define private public
#define OFFLINE
#include <Arduino.h>
#include <ArduinoUnit.h>
#include <Bridge.h>
#include <ApiClient.h>
#include <KeenClient.h>

KeenClient keen;

void setup()
{
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Bridge.begin();
  digitalWrite(13, HIGH);

  Serial.begin(115200);

  while (!Serial); // wait for a serial connection
}

void loop()
{
  Test::run();
}

