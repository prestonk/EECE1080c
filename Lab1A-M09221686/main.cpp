// Name: Preston Knibbe
// Laboratory 1: Introduction to C++ IDE


#include <iostream>

#include <cmath>

using namespace std;

int main()
{
        double number1, number3, number2, average;

        cout << "Enter Number 1:";
        cin  >> number1;
        cout << "Enter Number 2:";
        cin  >> number2;
        cout << "Enter Number 3:";
        cin  >> number3;

        average = ((number1+number2+number3)/3);
        cout    << "Average is: "
                << average
                << endl;

        return 0;
}
