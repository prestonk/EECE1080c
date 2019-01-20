//Preston Knibbe
//October 1, 2015

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double Factorial(double number) {
  double total = 1.0;
  double other = number;
  for (double i = 0.0; i < other; i++) {
    total *= number;
    number--;
  }
  return total;
}
double MyExp(double x) {
  double diff = 1.0;
  double total = 1.0;
  double counter = 1.0;
  double temp = 1.0;
  double power;
  double fact;
  // Using a difference between current an previous values will not produce accurate results
  // when using whole number x's. Because of this MyExp function won't match the exp function in results.
  // This could be fixed by comparing the values with the exp function values directly and continuing the
  // loop until it is within a certain range of that number
  while (abs(diff) >= 0.0001) {
    power = pow(x, counter);
    fact = Factorial(counter);
    diff = temp - (power / fact);
    temp = power / fact;
    total += (power / fact);
    counter++;
  }
  return total;
}


int main()
{
  double x = 0;
  cout << "           X" << fixed << setw(12) << setprecision(4)
  << "MyExp()" << fixed << setw(12) << setprecision(4)
  << "Exp()" << fixed << setw(12) << setprecision(4) << endl;
  for (x; x <= 10; x += 0.5) {
    cout << x << fixed << setw(12) << setprecision(4)
    << MyExp(x) << fixed << setw(12) << setprecision(4)
    << exp(x) << fixed << setw(12) << setprecision(4) << endl;
  }
  return 0;
}
