#ifndef ARRAYCLASS_H
#define ARRAYCLASS_H
#include <iostream>
#include <stdlib.h>
#include <time.h>


class ArrayClass
{
  public:
    ArrayClass();
    void setRowSize(int rowSize);
    void setColSize(int colSize);
    int getRowSize();
    int getColSize();
    void printArray();
    void randSeed();
    double RandomNumber(int maximum, int minimum);
    void createArray();
    ~ArrayClass();
  protected:
  private:
    int rowSize;
    int colSize;
    double *myList;
};

#endif // ARRAYCLASS_H
