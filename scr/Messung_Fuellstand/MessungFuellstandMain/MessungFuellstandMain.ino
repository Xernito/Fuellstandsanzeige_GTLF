#include <EEPROM.h>
#include <NewPing.h>
#include "UserConfig.h"


#define TRIGGER_PIN_1  10  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define TRIGGER_PIN_2  11  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define TRIGGER_PIN_3  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     9  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_VOLUME 20 // Maximum bei 20cm zum Senor --> Voll
#define MIN_VOLUME 120 // Minimum bei 120cm zum Senor --> leer 
#define MAX_DISTANCE 200
#define SONAR_NUM 3 //Numbers of Sonar
#define VERSION 1
#define SubVersion 0


String inputString;
bool stopMeasuring=false;

NewPing sonars[SONAR_NUM] = {

  NewPing (TRIGGER_PIN_1, ECHO_PIN, MAX_DISTANCE),  // NewPing setup of pins and maximum distance.
  NewPing (TRIGGER_PIN_2, ECHO_PIN, MAX_DISTANCE),  // NewPing setup of pins and maximum distance.
  NewPing (TRIGGER_PIN_3, ECHO_PIN, MAX_DISTANCE)   // NewPing setup of pins and maximum distance.

};

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  Serial.println("Messung des Füllstandes.\n\rVersion " + String(VERSION)+"."+SubVersion);
  inputString.reserve(200);
  stopMeasuring ? Serial.println("Messung angehalten") : Serial.println("Messung wird gestartet. Messintervall: " + String(UserConfig.measuringInterval) + " ms");
  Serial.println("Setup fertig gehe in Loop");
}

void loop() {
  unsigned int uS = 0;
  String ErgMessung="";
  delay(50);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  for(uint8_t i=0;i<SONAR_NUM;i++)
  {
    ErgMessung += "S"+String(i+1)+":"+sonars[i].ping_cm()+";";
    delay(50);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  }
 
  Serial.println(ErgMessung);
  
  delay(UserConfig.measuringInterval);
}

/*void serialEvent()
{
  while(Serial.available())
  {
    char inChar = (char)Serial.read();
    inputString += inChar;
  }

  Serial.println(inputString);
}*/
