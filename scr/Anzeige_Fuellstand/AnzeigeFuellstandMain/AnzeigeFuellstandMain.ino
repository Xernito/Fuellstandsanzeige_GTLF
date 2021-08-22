#include "helpers.h"
#include "str_helper.h"


String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
String val;
int fuellstand;
long wert;

#define Max_Level 20
#define Min_Level 130

void setup()
{
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  delay(250);
  Wire.begin();
  delay(250);
  // put your setup code here, to run once:
  Serial.print("MCP1 - aktivieren - ");
  initMCP(0x20);
  Serial.println("done");
  Serial.print("MCP2 - aktivieren - ");
  initMCP(0x24);
  Serial.println("done");
  
  for(byte i=0;i<3;i++)
  {
    Serial.println("Pins an");
    setAllPins(0x20,0xFF); //Expander 1
    setAllPins(0x24,0xFF); //Expander 2
    delay(150);
    Serial.println("Pins aus");
    setAllPins(0x20,0x00); //Expander 1
    setAllPins(0x24,0x00); //Expander 2
    delay(250);
  }
}



void loop() {
  double count, count_alt;
  byte wert;
  if (stringComplete) 
  {
    //Serial.print(inputString);

    //decodiere String:
    for(int i=0;i<3;i++)
    {
      val = getValue(inputString,';',i);
      fuellstand = getValue(val,':',1).toInt();
      Serial.println(val +" : "+ String(fuellstand));
      wert = getPercent(Max_Level, Min_Level,fuellstand);
      switch(i)
      {
        case 0:

          setValueByPercent_S1(wert);
          break;
        case 1:
          setValueByPercent_S2(wert);
          break;
        case 2:
          setValueByPercent_S3(wert);
          break;
      }
     }

    // clear the string:
    inputString = "";
    stringComplete = false;
  }

}
 

void serialEvent()
{
  while(Serial.available())
  {
    char inChar = (char)Serial.read();
    
    if (inChar == '\n') {
      stringComplete = true;
    }
    inputString += inChar;  
  }

}
