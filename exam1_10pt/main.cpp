// Preston Knibbe

#include <iostream>

using namespace std;

bool IsMultipleofX(int num, int x) {
  if ((x%num)==0) {
    return true;
  } else {
    return false;
  }
}

bool IsAnOddNumber(int num) {
  if ((num%2) != 0) {
    return true;
  } else {
    return false;
  }
}

bool IsAnEvenNumber(int num) {
  if ((num%2)==0) {
    return true;
  } else {
    return false;
  }
}


int main()
{
  for (int i = 1; i <= 100; i++) {
    cout << i << " - ";
    if (IsAnEvenNumber(i)) {
      cout << "Even";
    } else if(IsAnOddNumber(i)) {
      cout << "Odd";
    }
    if (IsMultipleofX(3,i)) {
      cout << ", Multiple of three";
    }
    if (IsMultipleofX(5,i)) {
      cout << ", Multiple of five";
    }
    cout << endl;
  }
  return 0;
}
