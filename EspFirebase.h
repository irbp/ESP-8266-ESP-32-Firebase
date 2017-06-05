#ifndef EspFirebase_h
#define EspFirebase_h

#if defined(ESP_PLATFORM)
    #include <HTTPClient.h>
    #include <WiFi.h>
#elif defined(ARDUINO_ESP8266_NODEMCU)
    #include <ESP8266HTTPClient.h>
    #include <ESP8266WiFi.h>
#endif

class EspFirebase
{
public:
    EspFirebase(String applicationCredential, String databaseURL);
    void setValue(String path, String value);

private:
    String applicationCredential;
    String databaseURL;
    HTTPClient http;
};

#endif