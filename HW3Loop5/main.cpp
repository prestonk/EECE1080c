/*
Preston Knibbe
September 17, 2015
*/

#include <iostream>

using namespace std;

int main()
{
  int start;
  int end1;
  int step;
  int sum = 0;
  int sum1 = 0;
  int sum2 = 0;
  cout << "Start Number:" << endl;
  cin >> start;
  cout << "End Number:" << endl;
  cin >> end1;
  if (end1 <= start) {
    cout << "End number must be greater than start. Enter End Number:" << endl;
    cin >> end1;
  }
  cout << "Step:" << endl;
  cin >> step;

  for (start; start <= end1; start+=step) {
    sum += start;
    if ((start%2) == 0) {
      sum1 += start;
    } else {
      sum2 += start;
    }
  }
  cout << "Sum of odd numbers: " << sum2 << endl;
  cout << "Sum of even numbers: " << sum1 << endl;
  cout << "Sum of all numbers: " << sum << endl;


  return 0;
}
