//Preston Knibbe
//October 15, 2015

#include <iostream>
#include <stdlib.h>
#include <time.h>



using namespace std;

// Seeds random number generator
void randSeed() {
  srand (time(NULL));
}

// Creates a random number between the minLimit and maxLimit provided
int randomNum(int minLimit, int maxLimit) {
  int randNum = rand() % maxLimit + minLimit;
  return randNum;
}

// Fills array with random numbers
void fillArray(int freq[], int length) {
  for (int i = 0; i <= length; i++) {
    freq[i] = 0;
  }
  for (int a = 0; a <= 100000; a++) {
   int random = randomNum(0,51);
   freq[random] ++;
  }
}

// Prints array
void printArray(int* freq) {
  for (int x = 0; x <= 50; x++) {
    cout << x << ": " << freq[x] << endl;
  }
}

// Creates histogram based on array
void showArray(int* freq) {
  for (int x = 0; x <= 50; x++) {
    if (x < 10) {
      cout << " ";
    }
    int b = freq[x] / 100;
    cout << x << ": ";
    for (int a = 0; a <= b; a++) {
      cout << "*";
    }
    cout << "" << endl;
  }
}


// Finds total sum of array components
int sumTotal(int* freq) {
  int total;
  for (int a = 0; a <= 50; a++) {
    total += freq[a];
  }
  return total;
}

// Finds minimum number in array
int minNum(int* freq) {
  int num = 100000000;
  for (int a = 0; a <= 50; a++) {
    if (freq[a] < num) {
      num = freq[a];
    }
  }
  return num;
}

// Finds maximum number in array
int maxNum(int* freq) {
  int num = 0;
  for (int a = 0; a <= 50; a++) {
    if (freq[a] > num) {
      num = freq[a];
    }
  }
  return num;
}



int main()
{
  const int length(50);
  int minLimit;
  int maxLimit;
  randSeed();
  int freqList[length];
  fillArray(freqList, length);
  printArray(freqList);
  cout << "\n";
  showArray(freqList);
  cout << "\n Sum: " << sumTotal(freqList) << endl;
  cout << "\n Min: " << minNum(freqList) << endl;
  cout << "\n Max: " << maxNum(freqList) << endl;
  return 0;
}
