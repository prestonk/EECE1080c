#include <iostream>
#include "ComplexNumber.h"
#include "math.h"
using namespace std;

ComplexNumber::ComplexNumber() {
  real_part = 0;
  imaginary_part = 0;
}

ComplexNumber::ComplexNumber(double real, double imaginary)
{
  setCompNum(real, imaginary);
}
void ComplexNumber::Print() {
  cout << "Real part: " << real_part << endl;
  cout << "Imaginary part: " << imaginary_part << endl;
}
void ComplexNumber::Addition(ComplexNumber add1, ComplexNumber add2) {
  real_part = add1.getRealPart() + add2.getRealPart();
  imaginary_part = add1.getImaginaryPart() + add2.getImaginaryPart();
}
void ComplexNumber::Subtraction(ComplexNumber subtr1, ComplexNumber subtr2) {
  real_part = subtr1.getRealPart() - subtr2.getRealPart();
  imaginary_part = subtr1.getImaginaryPart() - subtr2.getImaginaryPart();
}
void ComplexNumber::Multiplication(ComplexNumber mult1, ComplexNumber mult2) {
  real_part = (mult1.getRealPart() * mult2.getRealPart()) - (mult1.getImaginaryPart() * mult2.getImaginaryPart());
  imaginary_part = (mult1.getRealPart() * mult2.getImaginaryPart()) + (mult1.getImaginaryPart() * mult2.getRealPart());
}
void ComplexNumber::Division(ComplexNumber div1, ComplexNumber div2) {
  real_part = ((div1.getRealPart()*div2.getRealPart()) + (div1.getImaginaryPart()*div2.getImaginaryPart())) / ((div2.getImaginaryPart() * div2.getImaginaryPart()) + (div2.getRealPart()*div2.getRealPart()));
  imaginary_part = ((div2.getRealPart()*div1.getImaginaryPart())-(div1.getRealPart()*div2.getImaginaryPart()))/((div2.getRealPart()*div2.getRealPart())+(div2.getImaginaryPart()*div2.getImaginaryPart()));
}
void ComplexNumber::Polar(ComplexNumber pol) {
  cout << "Magnitude: " << sqrt((pol.getRealPart()*pol.getRealPart())+(pol.getImaginaryPart()*pol.getImaginaryPart())) << endl;
  cout << "Angle: " << atan(pol.getImaginaryPart()/pol.getRealPart()) << endl;
}
double ComplexNumber::getRealPart() {
  return real_part;
}
double ComplexNumber::getImaginaryPart() {
  return imaginary_part;
}
void ComplexNumber::setCompNum(double real, double imaginary) {
  real_part = real;
  imaginary_part = imaginary;
}

