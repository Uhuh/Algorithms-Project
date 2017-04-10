#include "area.h"
#include "sensor.h"
#include <math.h>
#include <iostream>


// Since the calling object owns the field of sensors
// we don't need to pass it into it.
void area::find_intersection_points()
{
  // intersection points P = {}
  int x1, x2, y1, y2;
  int x_2, x_1, x_0, y_2, y_1, y_0, tot;
  int temp1, temp2, temp3, temp4;
  for(int i = 0; i < 50; i++)
  {
    for(int j = 0; j < 50; j++)
    {
      for(int k = 0; k < 50; k++)
      {
        for(int l = 0; l < 50; l++)
        {
          if(i != k && j != l && sqrt(pow(i-k, 2) + pow(j-l, 2)) < 10)
          {
            x_1 = (2 * i) + (2 * k);
            x_0 = (i * i) + (k * k);
            y_1 = (2 * j) + (2 * l);
            y_0 = (j * j) + (l * l);
            tot = 25*25;
            temp1 = y_1;
            temp2 = y_0;

            y_0 = (tot - x_0 - y_0) / x_1;
            temp3 = y_0;
            y_1 = -1 * y_1 / x_1;
            temp4 = y_1;

            y_2 = y_1 * y_1 + 1;
            y_1 = (2 * (y_1 * tot)) + (x_1 * y_1) + temp1;
            y_0 = (y_0 * y_0) + (x_1 * y_0 * y_0) + x_0 + temp2 - tot;
            y1 = (-1 * y_1 + sqrt(y_1 * y_1 - 4 * y_2 * y_0)) / 2 * y_2;
            y2 = (-1 * y_1 - sqrt(y_1 * y_1 - 4 * y_2 * y_0)) / 2 * y_2;

            x1 = temp3 + temp4 * y1;
            x2 = temp3 + temp4 * y2;

            // add (x1, y1) to P if they are both positive and same with (x2, y2)
            if(x1 > 0 && y1 > 0 && field[i][j].getPlace() == true)
            {
              inter.push_back(cords(x1, y1));
            }
            if(x2 > 0 && y2 > 0 && field[k][l].getPlace() == true)
            {
              inter.push_back(cords(x2, y2));
            }
          }
        }
      }
    }
  }
  return;
}

void area::initiate_Sensors()
{
  for(int i = 0; i < SIZE; i++)
  {
    for(int j = 0; j < SIZE; i++)
    {
      if(field[i][j].redundant(field, inter, field[i][j]))
      {
        field[i][j].setPlace(false);
      }
    }
  }
  return;
}




void area::givePoint()
{
  for(int i = 0; i < 50; i++)
  {
    for(int j = 0; j < 50; j++)
    {
      field[i][j].setX(i);
      field[i][j].setY(j);
    }
  }
  return;
}
