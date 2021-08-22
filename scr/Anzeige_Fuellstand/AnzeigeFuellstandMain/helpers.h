#include <Wire.h>

uint8_t MCP_1_GPB_1 = 0x00; // Bit 0 & 1
uint8_t MCP_1_GPB_2 = 0x00; // Bit 2 - 7
uint8_t MCP_2_GPA_1 = 0x00; // Bit 0 - 4
uint8_t MCP_2_GPA_2 = 0x00; // Bit 5 - 7

void initMCP(uint8_t address)
{
  Wire.beginTransmission(address); //A0 = A1 = A2 = 0
  Wire.write(0x00); // IODIRA register
  Wire.write(0x00); // set all of port A to outputs
  Wire.endTransmission();
  
  Wire.beginTransmission(address);
  Wire.write(0x01); // IODIRB register
  Wire.write(0x00); // set all of port B to outputs
  Wire.endTransmission();
  
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

void setAllPins(uint8_t address, uint8_t value)
{
  setValueRegA(address, value);
  setValueRegB(address, value);
}

void setValueByPercent_S1(byte percent)
{
  uint8_t currentRegB = 0x00;

  if(percent < 0) percent=0;
  if(percent > 100) percent=100;

  percent = (percent / 10)*10;

  switch (percent)
  {
    case 0:
      MCP_1_GPB_1 = 0x00;
      currentRegB = MCP_1_GPB_1^MCP_1_GPB_2;
      setValueRegA(0x20,0x00);  //0000 0000
      setValueRegB(0x20,currentRegB);    //0000 0000
      break;
    
    case 10:
      MCP_1_GPB_1 = 0x00;
      currentRegB = MCP_1_GPB_1^MCP_1_GPB_2;
      setValueRegA(0x20,0x01);  //0000 0001
      setValueRegB(0x20,currentRegB);    //0000 0000
      break;
      
     case 20:
      MCP_1_GPB_1 = 0x00;
      currentRegB = MCP_1_GPB_1^MCP_1_GPB_2;
      setValueRegA(0x20,0x03);  //0000 0011
      setValueRegB(0x20,currentRegB);    //0000 0000
      break;
      
    case 30:
      MCP_1_GPB_1 = 0x00;
      currentRegB = MCP_1_GPB_1^MCP_1_GPB_2;
      setValueRegA(0x20,0x07);  //0000 0111
      setValueRegB(0x20,currentRegB);    //0000 0000
      break;
    
    case 40:
      MCP_1_GPB_1 = 0x00;
      currentRegB = MCP_1_GPB_1^MCP_1_GPB_2;
      setValueRegA(0x20,0x0F);  //0000 1111
      setValueRegB(0x20,currentRegB);    //0000 0000
      break;
      
     case 50:
      MCP_1_GPB_1 = 0x00;
      currentRegB = MCP_1_GPB_1^MCP_1_GPB_2;
      setValueRegA(0x20,0x1F);  //0001 1111
      setValueRegB(0x20,currentRegB);    //0000 0000
      break;
      
    case 60:
      MCP_1_GPB_1 = 0x00;
      currentRegB = MCP_1_GPB_1^MCP_1_GPB_2;
      setValueRegA(0x20,0x3F);  //0011 1111
      setValueRegB(0x20,currentRegB);    //0000 0000
      break;
    
    case 70:
      MCP_1_GPB_1 = 0x00;
      currentRegB = MCP_1_GPB_1^MCP_1_GPB_2;
      setValueRegA(0x20,0x7F);  //0111 1111
      setValueRegB(0x20,currentRegB);    //0000 0000
      break;
      
     case 80:
      MCP_1_GPB_1 = 0x00;
      currentRegB = MCP_1_GPB_1^MCP_1_GPB_2;
      setValueRegA(0x20,0xFF);  //1111 1111
      setValueRegB(0x20,currentRegB);    //0000 0000
      break;
      
     case 90:
      MCP_1_GPB_1 = 0x01;
      currentRegB = MCP_1_GPB_1^MCP_1_GPB_2;
      
      setValueRegA(0x20,0xFF);  //1111 1111
      
      setValueRegB(0x20,currentRegB);    //0000 0001
      break;
      
     case 100:
      MCP_1_GPB_1 = 0x03;
      currentRegB = MCP_1_GPB_1^MCP_1_GPB_2;
      
      setValueRegA(0x20,0xFF);  //1111 1111
      setValueRegB(0x20,currentRegB);    //0000 0011
      break;
  }
}

void setValueByPercent_S2(byte percent)
{
  uint8_t currentRegB_1 = 0x00;
  uint8_t currentRegA_2 = 0x00;
  if(percent < 0) percent=0;
  if(percent > 100) percent=100;
  
  percent = (percent / 10)*10;
  
  switch (percent)
  {
    case 0:

      MCP_1_GPB_2 = 0x00; 
      currentRegB_1 = MCP_1_GPB_1^MCP_1_GPB_2;
      setValueRegB(0x20,currentRegB_1);

      MCP_2_GPA_1 = 0x00;
      currentRegA_2 = MCP_2_GPA_1^MCP_2_GPA_2;
      setValueRegA(0x24,currentRegA_2);
      
      break;
    
    case 10:
      MCP_1_GPB_2 = 0x04; 
      currentRegB_1 = MCP_1_GPB_1^MCP_1_GPB_2;
      setValueRegB(0x20,currentRegB_1);
      
      MCP_2_GPA_1 = 0x00;
      currentRegA_2 = MCP_2_GPA_1^MCP_2_GPA_2;
      setValueRegA(0x24,currentRegA_2);

      break;
      
     case 20:
      MCP_1_GPB_2 = 0x0C; 
      currentRegB_1 = MCP_1_GPB_1^MCP_1_GPB_2;
      setValueRegB(0x20,currentRegB_1);

      MCP_2_GPA_1 = 0x00;
      currentRegA_2 = MCP_2_GPA_1^MCP_2_GPA_2;
      setValueRegA(0x24,currentRegA_2);

      break;
      
    case 30:
      MCP_1_GPB_2 = 0x1C; 
      currentRegB_1 = MCP_1_GPB_1^MCP_1_GPB_2;
      setValueRegB(0x20,currentRegB_1);
      
      MCP_2_GPA_1 = 0x00;
      currentRegA_2 = MCP_2_GPA_1^MCP_2_GPA_2;
      setValueRegA(0x24,currentRegA_2);
      break;
    
    case 40:
      MCP_1_GPB_2 = 0x3C; 
      currentRegB_1 = MCP_1_GPB_1^MCP_1_GPB_2;
      setValueRegB(0x20,currentRegB_1);
      
      MCP_2_GPA_1 = 0x00;
      currentRegA_2 = MCP_2_GPA_1^MCP_2_GPA_2;
      setValueRegA(0x24,currentRegA_2);
      break;
      
     case 50:
      MCP_1_GPB_2 = 0x7C; 
      currentRegB_1 = MCP_1_GPB_1^MCP_1_GPB_2;
      setValueRegB(0x20,currentRegB_1);

      MCP_2_GPA_1 = 0x00;
      currentRegA_2 = MCP_2_GPA_1^MCP_2_GPA_2;
      setValueRegA(0x24,currentRegA_2);
 
      break;
      
    case 60:
      MCP_1_GPB_2 = 0x7C; 
      currentRegB_1 = MCP_1_GPB_1^MCP_1_GPB_2;
      setValueRegB(0x20,currentRegB_1);

      MCP_2_GPA_1 = 0x01;
      currentRegA_2 = MCP_2_GPA_1^MCP_2_GPA_2;
      setValueRegA(0x24,currentRegA_2);

      break;
    
    case 70:
      MCP_1_GPB_2 = 0x7C; 
      currentRegB_1 = MCP_1_GPB_1^MCP_1_GPB_2;
      setValueRegB(0x20,currentRegB_1);
      
      MCP_2_GPA_1 = 0x03;
      currentRegA_2 = MCP_2_GPA_1^MCP_2_GPA_2;
      setValueRegA(0x24,currentRegA_2);
      break;
      
     case 80:
      MCP_1_GPB_2 = 0x7C; 
      currentRegB_1 = MCP_1_GPB_1^MCP_1_GPB_2;
      setValueRegB(0x20,currentRegB_1);
      
      MCP_2_GPA_1 = 0x07;
      currentRegA_2 = MCP_2_GPA_1^MCP_2_GPA_2;
      setValueRegA(0x24,currentRegA_2);
      break;
      
     case 90:
      MCP_1_GPB_2 = 0x7C; 
      currentRegB_1 = MCP_1_GPB_1^MCP_1_GPB_2;
      setValueRegB(0x20,currentRegB_1);

      MCP_2_GPA_1 = 0x0F;
      currentRegA_2 = MCP_2_GPA_1^MCP_2_GPA_2;
      setValueRegA(0x24,currentRegA_2);
      break;
      
     case 100:
      MCP_1_GPB_2 = 0x7C; 
      currentRegB_1 = MCP_1_GPB_1^MCP_1_GPB_2;
      setValueRegB(0x20,currentRegB_1);

      MCP_2_GPA_1 = 0x1F;
      currentRegA_2 = MCP_2_GPA_1^MCP_2_GPA_2;
      setValueRegA(0x24,currentRegA_2);
      break;
  }
}
  void setValueByPercent_S3(byte percent)
{
  uint8_t currentRegA_2 = 0x00;
  if(percent < 0) percent=0;
  if(percent > 100) percent=100;
  
  percent = (percent / 10)*10;
  
  switch (percent)
  {
    case 0:

      MCP_2_GPA_2 = 0x00;
      currentRegA_2 = MCP_2_GPA_1^MCP_2_GPA_2;
      setValueRegA(0x24,currentRegA_2);

      setValueRegB(0x24,0x00); 
      
      break;
    
    case 10:
      
      MCP_2_GPA_2 = 0x20;
      currentRegA_2 = MCP_2_GPA_1^MCP_2_GPA_2;
      setValueRegA(0x24,currentRegA_2);

      setValueRegB(0x24,0x00);

      break;
      
     case 20:

      MCP_2_GPA_2 = 0x60;
      currentRegA_2 = MCP_2_GPA_1^MCP_2_GPA_2;
      setValueRegA(0x24,currentRegA_2);

      setValueRegB(0x24,0x00);

      break;
      
    case 30:

      MCP_2_GPA_2 = 0xE0;
      currentRegA_2 = MCP_2_GPA_1^MCP_2_GPA_2;
      setValueRegA(0x24,currentRegA_2);

      setValueRegB(0x24,0x00);
      
      break;
    
    case 40:

      MCP_2_GPA_2 = 0xE0;
      currentRegA_2 = MCP_2_GPA_1^MCP_2_GPA_2;
      setValueRegA(0x24,currentRegA_2);

      setValueRegB(0x24,0x01);
      
      break;
      
     case 50:

      MCP_2_GPA_2 = 0xE0;
      currentRegA_2 = MCP_2_GPA_1^MCP_2_GPA_2;
      setValueRegA(0x24,currentRegA_2);

      setValueRegB(0x24,0x03);
 
      break;
      
    case 60:

      MCP_2_GPA_2 = 0xE0;
      currentRegA_2 = MCP_2_GPA_1^MCP_2_GPA_2;
      setValueRegA(0x24,currentRegA_2);

      setValueRegB(0x24,0x07);

      break;
    
    case 70:

      MCP_2_GPA_2 = 0xE0;
      currentRegA_2 = MCP_2_GPA_1^MCP_2_GPA_2;
      setValueRegA(0x24,currentRegA_2);

      setValueRegB(0x24,0x0F);
      
      break;
      
     case 80:
      
      MCP_2_GPA_2 = 0xE0;
      currentRegA_2 = MCP_2_GPA_1^MCP_2_GPA_2;
      setValueRegA(0x24,currentRegA_2);

      setValueRegB(0x24,0x1F);
      
      break;
      
     case 90:

      MCP_2_GPA_2 = 0xE0;
      currentRegA_2 = MCP_2_GPA_1^MCP_2_GPA_2;
      setValueRegA(0x24,currentRegA_2);

      setValueRegB(0x24,0x3F);
      
      break;
      
     case 100:

      MCP_2_GPA_2 = 0xE0;
      currentRegA_2 = MCP_2_GPA_1^MCP_2_GPA_2;
      setValueRegA(0x24,currentRegA_2);

      setValueRegB(0x24,0x7F);
      
      break;
  }
}
