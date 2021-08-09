#include <Adafruit_MCP23X17.h>

Adafruit_MCP23X17 mcp_1;
Adafruit_MCP23X17 mcp_2;

void setup() {
  // put your setup code here, to run once:
  mcp_1.begin_I2C(0x20);
  mcp_2.begin_I2C(0x24);
  for(int i=0;i<=15;i++)
  {
    mcp_1.pinMode(i,OUTPUT);
    mcp_1.digitalWrite(i,LOW);
    mcp_2.pinMode(i,OUTPUT);
    mcp_1.digitalWrite(i,LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
    for(int i=0;i<=14;i++)
  {
    mcp_1.digitalWrite(i,HIGH);
    delay(250);
  }
    for(int i=0;i<=14;i++)
  {
    mcp_2.digitalWrite(i,HIGH);
    delay(250);
  }

  delay(1000);

      for(int i=0;i<=14;i++)
  {
    mcp_1.digitalWrite(i,LOW);
    delay(250);
  }
    for(int i=0;i<=14;i++)
  {
    mcp_2.digitalWrite(i,LOW);
    delay(250);
  }
}


void serialEvent()
{
  while(Serial.available())
  {
    char inChar = (char)Serial.read();
    inputString += inChar;
  }

  Serial.println(inputString);
}

/*
  Entfernung = uS/US_ROUNDTRIP_CM;

  //120 cm == leer
  //20 cm == voll
  //100 cm Füllstand

  
  
  Count = Entfernung / 10;
  
  if(Entfernung !=0) 
  {
    //alle je cm 1 LED - max. 10cm
    if(Count_alt != Count)
    {
    
      for(int i=0;i<=Count;i++)
      {
        mcp.digitalWrite(i, LOW);
      }
      if(Count <= 10)
      {
        for(int i=Count;i<=10;i++)
        {
          mcp.digitalWrite(i, HIGH);
        }
      }

      Count_alt = Count;
    }
    
  }
  else
  {
    if(Count_alt != Count)
    {
      for(int i=0;i<=10;i++)
      {
        if(i%2)
        {
          mcp.digitalWrite(i, HIGH);
        }
        else
        {
          mcp.digitalWrite(i, LOW);
        }
      }
      //Count_alt = Count;
    }
  }
*/
