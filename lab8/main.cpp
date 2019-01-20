#include <iostream>
#include "ArrayClass.h"

using namespace std;

int main()
{
    ArrayClass Test;
    Test.randSeed();
    Test.createArray();
    Test.printArray();
    return 0;
}
