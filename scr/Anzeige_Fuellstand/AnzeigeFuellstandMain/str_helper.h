String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++)
  {
    if(data.charAt(i)==separator || i==maxIndex)
    {
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}

byte getPercent(byte min_Value, byte max_Value, byte Value)
{
  byte percent=0;
  double val1, val2;
  
  val1 = Value - min_Value;

  val2 = max_Value-min_Value;

  percent = 100 - (((val1)/(val2))*100);

  return percent;
}
