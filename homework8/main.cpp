// Preston Knibbe
// 11/20/15


#include "Binary.h"
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    Binary number1;
    Binary number2;
    cout << "Enter a binary number: " << endl;
    cin >> number1;
    cout << "Enter another binary number: " << endl;
    cin >> number2;
    Binary sum;
    Binary difference;
    Binary multTotal;
    Binary divTotal;
    sum = number1 + number2;
    cout << "Sum: " << sum << endl;
    difference = number1 - number2;
    cout << "Difference: " << difference << endl;
    multTotal = number1 * number2;
    cout << "Multiplied: " << multTotal << endl;
    divTotal = number1 / number2;
    cout << "Divided: " << divTotal << endl;
    /*cout << "Sum: " << sum.binaryToDecimal(sum.getBinary()) << endl;
    cout << "Difference: " << difference.binaryToDecimal(difference.getBinary()) << endl;
    cout << "Multiplication Total: " << multTotal.binaryToDecimal(multTotal.getBinary()) << endl;
    cout << "Division Total: " << divTotal.binaryToDecimal(divTotal.getBinary()) << endl;*/




    return 0;
}
