#include <EspFirebase.h>

const char* ssid     = ""; // Put here the wifi ssid
const char* password = ""; // Put here the wifi password
String applicationCredential = ""; // Put here the name of application credential json file
String databaseURL = ""; // Put here your firebase database url
unsigned int cont = 0;

EspFirebase firebase(applicationCredential, databaseURL);

void setup()
{
    Serial.begin(115200);
    delay(10);

    // We start by connecting to a WiFi network

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

void loop()
{
    firebase.setValue("temperatura", String(cont));
    cont++;

    delay(500);
}