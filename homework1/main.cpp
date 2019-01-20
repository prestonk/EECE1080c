//Preston Knibbe
//September 2, 2015

#include <iostream>

using namespace std;



void squarePyramid() {
  double base_side_length;
  double pyramid_height;
  double slant_length;
  cout << "SQUARE PYRAMID\n\n";
  cout << "Enter the length of a side of the square base" << endl;
  cin >>  base_side_length;
  cout << "Enter the height of the pyramid" << endl;
  cin >> pyramid_height;
  cout << "Enter the length of the slanted side" << endl;
  cin >> slant_length;
  double surf = (base_side_length * base_side_length) + (2 * base_side_length * slant_length);
  double vol = (base_side_length * base_side_length * pyramid_height) / 3;
  cout << "The SURFACE AREA is " << surf << " and the VOLUME is " << vol << ".\n";
}

void rectangularPrism() {
  double height;
  double length;
  double width;
  cout << "RECTANGULAR PRISM\n\n";
  cout << "Enter the height" << endl;
  cin >> height;
  cout << "Enter the length" << endl;
  cin >> length;
  cout << "Enter the width" << endl;
  cin >> width;
  double surf = (2 * height * length) + (2 * height * width) + (2 * width * length);
  double vol = length * width * height;
  cout << "The SURFACE AREA is " << surf << " and the VOLUME is " << vol << ".\n";
}

void cylinderCalc() {
  double radius;
  double height;
  cout << "CYLINDER\n\n";
  cout << "Enter the radius" << endl;
  cin >> radius;
  cout << "Enter the height" << endl;
  cin >> height;
  double surf = 2 * 3.14 * radius * (radius + height);
  double vol = 3.14 * radius * radius * height;
  cout << "The SURFACE AREA is " << surf << " and the VOLUME is " << vol << ".\n";
}

int main() {
  squarePyramid();
  rectangularPrism();
  cylinderCalc();
}

