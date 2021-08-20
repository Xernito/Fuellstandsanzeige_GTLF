#include <Wire.h>

void setup() {
  
  Wire.begin();
  
  //Expander 1 - set all of PINs to outputs
  Wire.beginTransmission(0x20); //A0 = A1 = A2 = 0
  Wire.write(0x00); // IODIRA register
  Wire.write(0x00); // set all of port A to outputs
  Wire.endTransmission();
  Wire.beginTransmission(0x20);
  Wire.write(0x01); // IODIRB register
  Wire.write(0x00); // set all of port B to outputs
  Wire.endTransmission();
  
  //Expander 2 - set all of PINs to outputs
  Wire.beginTransmission(0x24); //A0 = A1 = 0; A2 = 1
  Wire.write(0x00); // IODIRA register
  Wire.write(0x00); // set all of port A to outputs
  Wire.endTransmission();
  Wire.beginTransmission(0x24);
  Wire.write(0x01); // IODIRB register
  Wire.write(0x00); // set all of port B to outputs
  Wire.endTransmission();

  //Let all LEDs flash briefly 
  
  for(byte i=0;i<3;i++)
  {
    setAllPins(0x20,0xFF); //Expander 1
    setAllPins(0x24,0xFF); //Expander 2
    delay(500);
    setAllPins(0x20,0x00); //Expander 1
    setAllPins(0x24,0x00); //Expander 2
    delay(500);
  }
  
}

void setAllPins(uint8_t address, uint8_t value)
{
  setValueRegA(address, value);
  setValueRegB(address, value);
}

void setValueRegA(uint8_t address, uint8_t value)
{
  Wire.beginTransmission(address); //A0 = A1 = A2 = 0
  Wire.write(0x12); // address port A
  Wire.write(value); // set all Bit to 1
  Wire.endTransmission();
}

void setValueRegB(uint8_t address, uint8_t value)
{
  Wire.beginTransmission(address); //A0 = A1 = A2 = 0
  Wire.write(0x13); // address port B
  Wire.write(value); // set all Bit to 1
  Wire.endTransmission();
}

void setValueByPercent_S1(byte percent)
{
  switch (percent)
  {
    case 0:
      setValueRegA(0x20,0x00);  //0000 0000
      //setValueRegB(0x20,??);    //0000 0000
      break;
    
    case 10:
      setValueRegA(0x20,0x01);  //0000 0001
      //setValueRegB(0x20,??);    //0000 0000
      break;
      
     case 20:
      setValueRegA(0x20,0x03);  //0000 0011
      //setValueRegB(0x20,??);    //0000 0000
      break;
      
    case 30:
      setValueRegA(0x20,0x07);  //0000 0111
      setValueRegB(0x20,??);    //0000 0000
      break;
    
    case 40:
      setValueRegA(0x20,0x0F);  //0000 1111
      setValueRegB(0x20,??);    //0000 0000
      break;
      
     case 50:
      setValueRegA(0x20,0x1F);  //0001 1111
      //setValueRegB(0x20,??);    //0000 0000
      break;
      
    case 60:
      setValueRegA(0x20,0x3F);  //0011 1111
      //setValueRegB(0x20,??);    //0000 0000
      break;
    
    case 70:
      setValueRegA(0x20,0x7F);  //0111 1111
      //setValueRegB(0x20,??);    //0000 0000
      break;
      
     case 80:
      setValueRegA(0x20,0xFF);  //1111 1111
      setValueRegB(0x20,??);    //0000 0000
      break;
      
     case 90:
      setValueRegA(0x20,0xFF);  //1111 1111
      setValueRegB(0x20,??);    //0000 0001
      break;
      
     case 100:
      setValueRegA(0x20,0xFF);  //1111 1111
      setValueRegB(0x20,??);    //0000 0011
      break;
}

void loop()
{
  
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
