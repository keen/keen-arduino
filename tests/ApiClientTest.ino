#line 2 "ApiClientTest.ino"
#define private public
#define OFFLINE
#include <Arduino.h>
#include <ArduinoUnit.h>
#include <Bridge.h>
#include <ApiClient.h>

ApiClient client;

test(setAuthorizationHeader)
{
  const __FlashStringHelper *auth_header_flashstring = F("00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
  client.setAuthorizationHeader(auth_header_flashstring);
  assertEqual(client.auth_header.type, POINTER_UNION_TYPE_FLASHSTRING);
  assertEqual(client.auth_header.u.flashstring_ptr, auth_header_flashstring);
  
  String auth_header_string = String("00000000000000000000000000000000");
  client.setAuthorizationHeader(&auth_header_string);
  assertEqual(client.auth_header.type, POINTER_UNION_TYPE_STRING);
  assertEqual(*client.auth_header.u.string_ptr, auth_header_string);
  
  const char *auth_header_char = "00000000000000000000000000000000";
  client.setAuthorizationHeader(auth_header_char);
  assertEqual(client.auth_header.type, POINTER_UNION_TYPE_CHAR);
  assertEqual(client.auth_header.u.char_ptr, auth_header_char);
 
  StringPointer auth_header;
  auth_header.type = POINTER_UNION_TYPE_FLASHSTRING;
  auth_header.u.flashstring_ptr = auth_header_flashstring;
  client.setAuthorizationHeader(auth_header);
  assertEqual(client.auth_header.u.flashstring_ptr, auth_header_flashstring);
  
  auth_header.type = POINTER_UNION_TYPE_STRING;
  auth_header.u.string_ptr = &auth_header_string;
  client.setAuthorizationHeader(auth_header);
  assertEqual(*client.auth_header.u.string_ptr, auth_header_string);
  
  auth_header.type = POINTER_UNION_TYPE_CHAR;
  auth_header.u.char_ptr = auth_header_char;
  client.setAuthorizationHeader(auth_header);
  assertEqual(client.auth_header.u.char_ptr, auth_header_char);
  
}

test(setContentTypeHeader)
{
  const __FlashStringHelper *contenttype_header_flashstring = F("application/json");
  client.setContentTypeHeader(contenttype_header_flashstring);
  assertEqual(client.contenttype_header.type, POINTER_UNION_TYPE_FLASHSTRING);
  assertEqual(client.contenttype_header.u.flashstring_ptr, contenttype_header_flashstring);
  
  String contenttype_header_string = String("application/json");
  client.setContentTypeHeader(&contenttype_header_string);
  assertEqual(client.contenttype_header.type, POINTER_UNION_TYPE_STRING);
  assertEqual(*client.contenttype_header.u.string_ptr, contenttype_header_string);
  
  const char *contenttype_header_char = "application/json";
  client.setContentTypeHeader(contenttype_header_char);
  assertEqual(client.contenttype_header.type, POINTER_UNION_TYPE_CHAR);
  assertEqual(client.contenttype_header.u.char_ptr, contenttype_header_char);
  
}

test(setUserAgentHeader)
{
  const __FlashStringHelper *useragent_header_flashstring = F("Arduino/0.1a");
  client.setUserAgentHeader(useragent_header_flashstring);
  assertEqual(client.useragent_header.type, POINTER_UNION_TYPE_FLASHSTRING);
  assertEqual(client.useragent_header.u.flashstring_ptr, useragent_header_flashstring);
  
  String useragent_header_string = String("Arduino/0.1a");
  client.setUserAgentHeader(&useragent_header_string);
  assertEqual(client.useragent_header.type, POINTER_UNION_TYPE_STRING);
  assertEqual(*client.useragent_header.u.string_ptr, useragent_header_string);
  
  const char *useragent_header_char = "Arduino/0.1a";
  client.setUserAgentHeader(useragent_header_char);
  assertEqual(client.useragent_header.type, POINTER_UNION_TYPE_CHAR);
  assertEqual(client.useragent_header.u.char_ptr, useragent_header_char);
  
}

test(post)
{
  int retval = -1;
  
  client.setContentTypeHeader(F("application/json"));
  client.setAuthorizationHeader(F("00000000000000000000000000000000"));
  
  String request = "curl -X POST -H \"Authorization: 00000000000000000000000000000000\" -H \"Content-Type: application/json\" -d '{}' https://api.keen.io/3.0/projects/000000000000000000000000/events/sign_ups";
  
  retval = client.post(F("https://api.keen.io/3.0/projects/000000000000000000000000/events/sign_ups"), F("{}"));
  assertEqual(client.request_buffer, request);
  assertEqual(retval, 0);
  
  String url_string = "https://api.keen.io/3.0/projects/000000000000000000000000/events/sign_ups";
  String data_string = "{}";
  retval = client.post(url_string, data_string);
  assertEqual(client.request_buffer, request);
  assertEqual(retval, 0);
  
  char *url_char = "https://api.keen.io/3.0/projects/000000000000000000000000/events/sign_ups";
  char *data_char = "{}";
  retval = client.post(url_char, data_char);
  assertEqual(client.request_buffer, request);
  assertEqual(retval, 0);

}

test(get)
{
 int retval = -1;
 
 retval = client.get(F("https://api.keen.io"));
 assertEqual(retval, 0);
 
 String url_string = "https://api.keen.io";
 retval = client.get(url_string);
 assertEqual(retval, 0);
 
 char *url_char = "https://api.keen.io";
 retval = client.get(url_char);
 assertEqual(retval, 0);
}

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

