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

String inputString;
bool stopMeasuring=false;

NewPing sonar_1(TRIGGER_PIN_1, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing sonar_2(TRIGGER_PIN_2, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing sonar_3(TRIGGER_PIN_3, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.


void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  Serial.println("Messung des Füllstandes.");
  inputString.reserve(200);
  stopMeasuring ? Serial.println("Messung angehalten") : Serial.println("Messung wird gestartet. Messintervall: " + String(UserConfig.measuringInterval) + " ms");
  Serial.println("Setup fertig gehe in Loop");
}

void loop() {
  unsigned int uS = 0;
 
  Serial.println("Sende Ping - Sonar 1");
  delay(50);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Sonar 1 - ");
  uS = sonar_1.ping(); // Send ping, get ping time in microseconds (uS).
  Serial.print("Ping: ");
  
  Serial.print(uS / US_ROUNDTRIP_CM); // Convert ping time to distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");

  delay(50);
  Serial.println("Sende Ping - Sonar 2");
  Serial.print("Sonar 2 - ");
  uS = sonar_2.ping(); // Send ping, get ping time in microseconds (uS).
  Serial.print("Ping: ");
  Serial.print(uS / US_ROUNDTRIP_CM); // Convert ping time to distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
  
  delay(50);
  Serial.println("Sende Ping - Sonar 3");
  Serial.print("Sonar 3 - ");
  uS = sonar_3.ping(); // Send ping, get ping time in microseconds (uS).
  Serial.print("Ping: ");
  Serial.print(uS / US_ROUNDTRIP_CM); // Convert ping time to distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
  
  delay(UserConfig.measuringInterval);
}

void serialEvent()
{
  /*while(Serial.available())
  {
    char inChar = (char)Serial.read();
    inputString += inChar;
  }

  Serial.println(inputString);*/
}
