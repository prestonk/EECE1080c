// Name: Preston Knibbe
// Laboratory 1: Introduction to C++ IDE


#include <iostream>

#include <cmath>

using namespace std;

int main()
{
        double test1, test2, hw1, hw2, hw3, final1, average;

        cout << "Enter Test 1 Grade:";
        cin  >> test1;
        cout << "Enter Test 2 Grade:";
        cin  >> test2;
        cout << "Enter Homework 1 Grade:";
        cin  >> hw1;
        cout << "Enter Homework 2 Grade:";
        cin  >> hw2;
        cout << "Enter Homework 3 Grade:";
        cin  >> hw3;
        cout << "Enter Final Test Grade:";
        cin  >> final1;

        double avg1 = (hw1 + hw2 + hw3) / 3;


        average = ((avg1+test1+test2+final1)/4);
        cout    << "Average is: "
                << average
                << endl;

        return 0;
}
