// Preston Knibbe
// 11/20/15

#include "Binary.h"
#include <iostream>
#include <math.h>
using namespace std;


Binary::Binary() {
}

Binary::Binary(string num)
{
  binaryNum = num;
}

string Binary::getBinary()
{
  return binaryNum;
}

void Binary::setBinary(string bin)
{
  binaryNum = bin;
}


int Binary::binaryToDecimal(string bin)
{
  int multiplier = 0;
  int total = 0;
  int length = bin.length() -1;
  for(int i = length; i >= 0; i--) {
    if (bin[i] == '1') {
      total += pow(2,multiplier);
      multiplier++;
    } else {
      multiplier++;
    }
  }
  return total;
}

string Binary::decimalToBinary(int dec1)
{
  string newBinary = "";
  bool startTest = true;
  double dec = dec1;
  double num = 4096.0;
  double startNum;
  while (startTest) {
    if (dec >= num && dec <= 511) {
      startNum = num;
      startTest = false;
    } else {
      num /= 2;
    }
  }
  while (dec > 0) {
    while (startNum >= 1) {
    if ((dec / startNum) >= 1) {
      newBinary += "1";
      dec -= startNum;
      startNum /= 2;
    } else {
      newBinary += "0";
      startNum /= 2;
    }
  }}
  return newBinary;
}


Binary Binary::operator+(Binary binary1)
{
  Binary newObject;
  int a = binaryToDecimal(binaryNum);
  int b = binaryToDecimal(binary1.binaryNum);
  int c = a + b;
  newObject.binaryNum = decimalToBinary(c);
  return(newObject);
}


Binary Binary::operator-(Binary binary1)
{
  Binary newObject;
  int a = binaryToDecimal(binaryNum);
  int b = binaryToDecimal(binary1.binaryNum);
  int c = a - b;
  newObject.binaryNum = decimalToBinary(c);
  return(newObject);
}

Binary Binary::operator*(Binary binary1)
{
  Binary newObject;
  double a = binaryToDecimal(binaryNum);
  double b = binaryToDecimal(binary1.binaryNum);
  double c = a * b;
  newObject.binaryNum = decimalToBinary(c);
  return(newObject);
}

Binary Binary::operator/(Binary binary1)
{
  Binary newObject;
  double a = binaryToDecimal(binaryNum);
  double b = binaryToDecimal(binary1.binaryNum);
  double c = a / b;
  newObject.binaryNum = decimalToBinary(c);
  return(newObject);
}


