#include "ArrayClass.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

ArrayClass::ArrayClass()
{
  setColSize(RandomNumber(20,1));
  setRowSize(RandomNumber(20,1));
  int col = getColSize();
  int row = getRowSize();
  myList = new double[2][2];
}

void ArrayClass::createArray()
{
  std::cout<<getColSize() << "\n";
  std::cout<<getRowSize() << "\n";
  for (int i = 0; i < getColSize(); i++) {
    for (int x = 0; x < getRowSize(); x++) {
      myList[i][x] = RandomNumber(50,1);
    }
  }
}

void ArrayClass::setRowSize(int rows) {
  rowSize = rows;
}

void ArrayClass::setColSize(int cols) {
  colSize = cols;
}

int ArrayClass::getRowSize(){
  return rowSize;
}

int ArrayClass::getColSize(){
  return colSize;
}

void ArrayClass::randSeed() {
  srand (time(NULL));
}



double ArrayClass::RandomNumber(int maximum, int minimum) {
  double randNum = rand() % maximum + minimum;
  return randNum;
}



void ArrayClass::printArray()
{
  for (int i = 0; i < getColSize(); i++) {
    for (int x = 0; x < getRowSize(); x++) {
      std::cout << myList[i][x] << "  ";
    }
    std::cout << "\n";
  }
}



ArrayClass::~ArrayClass()
{
  //dtor
}
