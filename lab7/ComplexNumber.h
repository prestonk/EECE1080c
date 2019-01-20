#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H
#include <iostream>


class ComplexNumber
{
  public:
    ComplexNumber();
    ComplexNumber(double real, double imaginary);
    void Print();
    void Addition(ComplexNumber add1, ComplexNumber add2);
    void Subtraction(ComplexNumber subtr1, ComplexNumber subtr2);
    void Multiplication(ComplexNumber mult1, ComplexNumber mult2);
    void Division(ComplexNumber div1, ComplexNumber div2);
    void Polar(ComplexNumber pol);
    double getRealPart();
    double getImaginaryPart();
    void setCompNum(double real, double imaginary);
  private:
    double real_part;
    double imaginary_part;
};

#endif // COMPLEXNUMBER_H
