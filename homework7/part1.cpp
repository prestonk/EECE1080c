#include <iostream>
#include "part1.h"
using namespace std;

part1::part1()
{
  cout << "Resistance: " << endl;
  cin >> resistance;
  cout << "Voltage: " << endl;
  cin >> voltage;
}
part1::part1(int resistor_value, int voltage_value)
{
  setPart(resistor_value, voltage_value);
}
void part1::setPower(int power_val)
{
  power = power_val;
}
void part1::setCurrent(int current_value)
{
  current = current_value;
}
void part1::setPart(int resistor_val, int voltage_val)
{
  resistance = resistor_val;
  voltage = voltage_val;
}
int part1::getResistance()
{
  return resistance;
}
int part1::getVoltage()
{
  return voltage;
}
void part1::displayValues()
{
  cout << "Resistance: " << resistance << endl;
  cout << "Voltage: " << voltage << endl;
  cout << "Current: " << current << endl;
  cout << "Power: " << power << endl;
}
void part1::calculateCurrent(part1 test)
{
  current = test.getVoltage() / test.getResistance();
  test.setCurrent(current);
}
int part1::getCurrent()
{
  return current;
}
void part1::calculatePower(part1 test)
{
  int power_val = test.getVoltage() * test.getCurrent();
  test.setPower(power_val);
}
part1::~part1()
{
  cout << "Circuit Destroyed" << endl;
}

