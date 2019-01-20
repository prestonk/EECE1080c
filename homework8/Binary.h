// Preston Knibbe
// 11/20/15
#ifndef BINARY_H
#define BINARY_H
#include <iostream>
using namespace std;

class Binary
{
  public:
    Binary();
    Binary(string);
    string getBinary();
    void setBinary(string bin);
    int binaryToDecimal(string);
    string decimalToBinary(int);
    Binary operator+(Binary binary1);
    Binary operator-(Binary binary1);
    Binary operator/(Binary);
    Binary operator*(Binary);
  private:
    string binaryNum;
  friend istream& operator>>(istream&, Binary&);
  friend ostream& operator<<(ostream&, Binary&);
};
inline istream& operator>>(istream& input, Binary& info) {
  input >> info.binaryNum;
  return input;
}
inline ostream& operator<<(ostream& output, Binary& info) {
  output << info.binaryNum;
  return output;
}



#endif // BINARY_H
