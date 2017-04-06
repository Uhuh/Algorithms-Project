

#ifndef SENSOR_H
#define SENSOR_H


class Sensor
{
  private:
    bool active, placed, dead;
    int radius, energy;

  public:
    Sensor(): active(true), placed(false), dead(false), energy(300), radius(5) {}
    bool redundant(const Sensor field, const points inter, const Sensor dud);

}
