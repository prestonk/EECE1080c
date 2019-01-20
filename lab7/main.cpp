#include <iostream>
#include "ComplexNumber.h"


using namespace std;



int main()
{
	ComplexNumber Number1(3, 7);
	ComplexNumber Number2(50, 2);
	ComplexNumber Result;
  cout << "Number 1: " << endl;
  Number1.Print();
  cout << endl;
  cout << "Number 2: " << endl;
  Number2.Print();
  cout << endl;
	Result.Addition(Number1, Number2);
	cout << "Addition total: " << endl;
	Result.Print();
	cout << endl;
	Result.Subtraction(Number1, Number2);
	cout << "Subtraction result: " << endl;
	Result.Print();
	cout << endl;
	Result.Multiplication(Number1, Number2);
	cout << "Multiplication total: " << endl;
	Result.Print();
	cout << endl;
	Result.Division(Number1, Number2);
	cout << "Division result: " << endl;
	Result.Print();







	return 0;
}
