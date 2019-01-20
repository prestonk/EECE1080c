/*
Preston Knibbe
September 17, 2015
*/


#include <iostream>

using namespace std;

int main()
{
  //1. For Loop
  int i = 1;
  for (i; i <= 101; i++) {
    if ((i%2) == 0) {
      cout << i << endl;
    }
  }
  //1. While Loop
  int a = 1;
  while (a <= 101) {
    if ((a%2) == 0) {
      cout << a << endl;
    }
    a++;
  }

  //2. For Loop
  int sum = 0;
  for (int b = 2; b <= 35; b+=3) {
    sum += b;
  }
  cout << "Sum: " << sum << endl;

  //2. While Loop
  int sum2 = 0;
  int c = 2;
  while (c <= 35) {
    sum2 += c;
    c += 3;
  }
  cout << "Sum: " << sum2 << endl;

  //3. For Loop
  int counter = 0;
  int start = 2;
  int sum3 = 0;
  for (start; start <= 40; start+=2) {\
    sum3 += start;
    counter++;
  }
  int avg = sum3 / counter;
  cout << "Average: " << avg << endl;


  //3. While Loop
  int counter2 = 0;
  int sum4 = 0;
  int start2 = 2;
  while (start2 <= 40) {
    sum4 += start2;
    start2 += 2;
    counter2++;
  }
  int avg2 = sum4 / counter2;
  cout << "Average: " << avg2 << endl;
  return 0;

}
