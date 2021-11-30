/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP8266 chip.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right ESP8266 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

#define BLYNK_FIRMWARE_VERSION "0.0.1"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMP1111111"  /* GET YOUR OWN */
#define BLYNK_DEVICE_NAME "ESP01S"      /* GET YOUR OWN */
#define BLYNK_AUTH_TOKEN  "......"      /* GET YOUR OWN */

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "WIFI_NAME";              /* GET YOUR OWN */
char pass[] = "WIFI_PASSWORD";          /* GET YOUR OWN */

// This function will be called every time Slider Widget
// in Blynk app writes values to the Virtual Pin V1
BLYNK_WRITE(V3){
  int pinValue = param.asInt(); 
  if(param.asInt() == 1){
    digitalWrite(0, HIGH);
    delay(2000);
    digitalWrite(0, LOW);
  } else {
    digitalWrite(0, HIGH);
    delay(2000);
    digitalWrite(0, LOW);
  }
}

BLYNK_WRITE(V0){
  // assigning incoming value from pin V1 to a variable
  int pinValue = param.asInt(); 
  if(param.asInt() == 1){
    digitalWrite(0, HIGH);
  } else {
    digitalWrite(0, LOW);
  }
}

BLYNK_WRITE(V2){
  // assigning incoming value from pin V1 to a variable
  int pinValue = param.asInt(); 
  if(param.asInt() == 1){
    digitalWrite(2, HIGH);
  } else {
    digitalWrite(2, LOW);
  }
}

void setup(){
  
  // GPIO0 controls relay
  pinMode(0, OUTPUT);

  // GPIO2 controls LED
  pinMode(2, OUTPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop(){
  Blynk.run();
}
