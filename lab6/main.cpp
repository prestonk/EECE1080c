// Preston Knibbe
// October 22, 2015




#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int LENGTH = 10;
void randSeed();
int randomNum(int, int);
void fillArray(int [][LENGTH]);
void printArray(const int [][LENGTH]);
int sumTotal(const int [][LENGTH]);
int minNum(const int [][LENGTH]);
int maxNum(const int [][LENGTH]);
int arrayAvg(const int [][LENGTH]);
int findColSum(int, const int [][LENGTH]);






int main(void) {
  int nums[LENGTH][LENGTH];
  randSeed();
  fillArray(nums);
  printArray(nums);
  cout << "Sum: " << sumTotal(nums) << endl;
  cout << "Min: " << minNum(nums) << endl;
  cout << "Max: " << maxNum(nums) << endl;
  cout << "Average: " << arrayAvg(nums) << endl;
  cout << "Sum of column 3: " << findColSum(3,nums) << endl;
  return 0;
}




// Seeds random number generator
void randSeed() {
  srand(time(NULL));
}

// Creates a random number between the minLimit and maxLimit provided
int randomNum(int minLimit, int maxLimit) {
  int randNum = rand() % maxLimit + minLimit;
  return randNum;
}


// Fills array with random numbers
void fillArray(int nums[][LENGTH]) {
  for (int i = 0; i < LENGTH; i++) {
    for (int x = 0; x < LENGTH; x++) {
      nums[i][x] = randomNum(10,90);
    }
  }
}

void printArray(const int nums[][LENGTH]) {
  for (int x = 0; x < LENGTH; x++) {
    for (int i = 0; i < LENGTH; i++) {
      cout << nums[x][i] << "   ";
    }
    cout << endl;
  }
}


// Finds total sum of array components
int sumTotal(const int nums[][LENGTH]) {
  int totalSum = 0;
  for (int a = 0; a < LENGTH; a++) {
    for (int b = 0; b < LENGTH; b++) {
        totalSum += nums[a][b];
    }
  }
  return totalSum;
}

// Finds minimum number in array
int minNum(const int nums[][LENGTH]) {
  int num = 100000000;
  for (int a = 0; a < LENGTH; a++) {
    for (int b = 0; b < LENGTH; b++) {
      if (nums[a][b] < num) {
        num = nums[a][b];
      }
    }
  }
  return num;
}

// Finds maximum number in array
int maxNum(const int nums[][LENGTH]) {
  int num = 0;
  for (int a = 0; a < LENGTH; a++) {
    for (int b = 0; b < LENGTH; b++) {
      if (nums[a][b] > num) {
        num = nums[a][b];
      }
    }
  }
  return num;
}

// Finds array average
int arrayAvg(const int nums[][LENGTH]) {
  int sumAvg = 0;
  int counter = 0;
  for (int a = 0; a < LENGTH; a++) {
    for (int b = 0; b < LENGTH; b++) {
        sumAvg += nums[a][b];
        counter++;
    }
  }
  return (sumAvg/counter);
}

int findColSum(int col, const int nums[][LENGTH]) {
  int colSum = 0;
  for (int a = 0; a < LENGTH; a++) {
    colSum += nums[col][a];
  }
  return colSum;
}




