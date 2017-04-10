#include "sensor.h"
#include "area.h"
#include <iostream>
#include <math.h>

// Multidimensional array, so passing into funct declaration do **
// A vector of x and y, inter is short for interceptions.
// A sensor dud, or otherknown as si. The sensor we want to see if it's
// redundant or not.
bool Sensor::redundant(Sensor field[50][50], const std::vector<cords> inter, Sensor& dud)
{
  bool redund = true;
  /* Loop through field and make the sensor (dud); active = false; */
  int points = 0;
  Sensor user;
  cords spot;

  //found is being used to confirm the dud is a real sensor.
  bool found = false;

  for(int i = 0; i < 50; i++)
  {
    for(int j = 0; j < 50; j++)
    {
      if(field[i][j] == dud)
      {//If we find the "dud" make it act as if it was never in the set
      // this is our equivlent to A = A\si
      //  std::cout << "(i, j): " << i << "," << j << std::endl;
        field[i][j].placed = false;
        found = true; // We found it... Need to break out of loop.
        break;
      }
    }
    if(found)
      break;
  }


  for(int i = 0; i < inter.size(); i++)
  {

    spot = inter[i];
    //If there are points inside of the duds range.
    //We need to check if they are all covered by other sensors.
    if(dud.inside(spot))
    {
      for(int k = 0; k < 50; k++)
      {
        for(int j = 0; j < 50; j++)// sj
        {
          user = field[k][j];
          if(user.inside(spot))
          {

            break;
          }

          if(j == 50 && k == 50) // If j and k reach the end of the field.
          {// Thus we haven't found any points in which other sensors cover.
            redund = false;
          }
        }
      }
      points++;
    }

  }
  if(points == 0)
    redund = false;

  return redund;
}

bool Sensor::inside(const cords spot)
{
  float range;// DISTANCE FORMULA d = sqrt((x2-x1)^2+(y2-y1)^2)
  range = sqrt(pow(x_cord-spot.x, 2) + pow(y_cord-spot.y, 2));
  //Our raidus is 5, if a point is within the sensors bounds then we know to
  // check for redundancy.
  return (range < 5 ? true:false);
}

bool Sensor::operator==(const Sensor& item)
{
  //A basic overloaded operator; comparing cords to confirm.
  //cannot have more than one sensor on a spot.
  //std::cout << "(Calling ob (X,Y): " << x_cord << "," << y_cord << std::endl;
//  std::cout << "Item ob (X,Y): " << item.x_cord << "," << y_cord << std::endl;
  return (x_cord == item.x_cord && y_cord == item.y_cord?true:false);
}
