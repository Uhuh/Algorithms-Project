#ifndef SENSOR_H
#define SENSOR_H
#include <vector>

class area;
struct cords;

class Sensor
{
  private:
    bool active, placed, dead;
    int radius, energy;
    int x_cord, y_cord;

  public:
    Sensor(): active(true), placed(true), dead(false), energy(300), radius(5) {}
    bool redundant(Sensor field[50][50], const std::vector<cords> inter, Sensor& dud);
    bool inside(const cords spot);
    bool operator==(const Sensor& item);
    bool getPlace() { return placed; }
    void setPlace(const bool p) { placed = p; }
    void setX(int x) { x_cord = x; }
    void setY(int y) { y_cord = y; }
    int getX() { return x_cord; }
    int getY() { return y_cord; }
  };




#endif
