#ifndef PART1_H
#define PART1_H
#include <iostream>


class part1
{
  public:
    part1();
    part1(int resistor_value, int voltage_value);
    int getCurrent();
    void setCurrent(int current_value);
    void calculatePower(part1 test);
    void calculateCurrent(part1 test);
    void displayValues();
    int getVoltage();
    int getResistance();
    void setPart(int resistor_value, int voltage_value);
    void setPower(int power_val);
    virtual ~part1();
  protected:
  private:
    int voltage;
    int resistance;
    int current;
    int power;
};

#endif // PART1_H
