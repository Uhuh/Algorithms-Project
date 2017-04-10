#include <iostream>
#include "area.h"
#include "sensor.h"

int main()
{
  area a;
  a.givePoint();
  a.find_intersection_points();
  a.initiate_Sensors();

  return 0;
}
