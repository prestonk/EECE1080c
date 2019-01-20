// Preston Knibbe

#include <iostream>

using namespace std;

void printFactors(int num) {
  cout << "Factors are: ";
  for(int i = 1; i <= 60; i++) {
    if ((num%i)==0) {
      cout << i << " ";
    }
  }
  cout << endl;
}

int maxFactor(int num){
  int max_num = 0;
  for(int i = 1; i <= 60; i++) {
    if (((num%i)==0)&&(i!=num)) {
      if (i>max_num) {
        max_num = i;
      }
    }
  }
  return max_num;
}

int sumOfFactors(int num) {
  int sum = 0;
  for(int i = 1; i <= 60; i++) {
    if ((num%i)==0) {
      sum += i;
    }
  }
  return sum;
}




int main()
{
    for (int i = 1; i <= 60; i++) {
      cout << "For " << i << ": " << endl;
      printFactors(i);
      cout << "Largest factor: " << maxFactor(i) << endl;
      cout << "Sum of factors: " << sumOfFactors(i) << endl;
      cout << endl;
    }
    return 0;
}
