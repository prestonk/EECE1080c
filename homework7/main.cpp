#include <iostream>
#include "part1.h"


using namespace std;

int main()
{
    part1 test(10,5);
    test.calculateCurrent(test);
    test.calculatePower(test);
    test.displayValues();
    return 0;
}
