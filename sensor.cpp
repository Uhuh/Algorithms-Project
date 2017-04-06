#include "sensor.h"
#include <iostream>


bool redundant(const Sensor field, const points inter, const Sensor dud)
{
  bool redund = true;
  /* Loop through field and make the sensor (dud); active = false; */
  int points = 0;

  for(int i = 0; i <= /*size of inter*/; i++)
  {
    if(inter[i] == inside(dud))
    {
      for(int j = 0; j <= /*size of field*/; j++)
      {
        if(inter[i] == inside(field[j]))
        {
          break;
        }
        if(j == /*size of field*/)
        {
          redund = false;
        }
      }
      points++;
    }

  }
  if(points == 0)
    redund = true;
  return redund;
}
