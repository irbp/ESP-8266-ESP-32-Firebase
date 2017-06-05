#include "EspFirebase.h"

String PHPREST = "http://arduino-firebase.000webhostapp.com/index.php?";

EspFirebase::EspFirebase(String credential, String url)
{
    applicationCredential = credential;
    databaseURL = url;
}

void EspFirebase::setValue(String path, String value)
{
    String url = PHPREST + "credential=/" + applicationCredential + "&url="
                + databaseURL + "&path=" + path + "&value=" + value;
    http.begin(url);
    http.GET();
}