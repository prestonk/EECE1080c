/*
Preston Knibbe
September 17, 2015
*/

#include <iostream>

using namespace std;

int main()
{
  float a = 1;
  float sum = 0;
  do {
    cout << "Enter a positive number with decimal to add or enter 0 or negative number to end" << endl;
    cin >> a;
    if (a > 0) {
      sum += a;
    }
  }
  while (a > 0);
  cout << "Sum: " << sum << endl;
  return 0;
}
