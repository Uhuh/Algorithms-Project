

#ifndef AREA_H
#define AREA_H
#include "sensor.h"
#include <vector>

struct cords
{
  double x, y;
  cords(double paramx, double paramy): x(paramx), y(paramy) {}
  cords(): x(0), y(0) {}
};

const int SIZE = 50;

class area
{
  private:
    Sensor field[SIZE][SIZE];
    std::vector<cords> inter;
  public:
    void find_intersection_points();
    void initiate_Sensors();
    void givePoint();


};



#endif
