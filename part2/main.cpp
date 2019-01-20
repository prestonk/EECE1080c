// Preston Knibbe
// Final Exam Part 2

#include <iostream>
#include <math.h>

using namespace std;


class Tube {
  public:
    Tube();
    Tube(double, double, double);
    //Prints data about the tube
    void displayData();
  private:
    double innerRadius;
    double outerRadius;
    double tubeHeight;
    //Defines PI for use in program
    const double PI = 3.14159;
    //Calculates Surface Area
    double surfaceArea();
    //Calculates Tube Volume
    double tubeVolume();
    //Calculates Tube Thickness
    double tubeThickness();
};

Tube::Tube() {
}

Tube::Tube(double inner, double outer, double height) {
  innerRadius = inner;
  outerRadius = outer;
  tubeHeight = height;
}

void Tube::displayData() {
  cout << "Inner Radius: " << innerRadius << endl;
  cout << "Outer Radius: " << outerRadius << endl;
  cout << "Tube Height: " << tubeHeight << endl;
  cout << "Surface Area: " << surfaceArea() << endl;
  cout << "Volume: " << tubeVolume() << endl;
  cout << "Tube Thickness: " << tubeThickness() << endl;
}

double Tube::surfaceArea() {
  double p1 = 2 * PI * ((outerRadius*outerRadius)-(innerRadius*innerRadius));
  double p2 = (2*PI*outerRadius*tubeHeight) + (2*PI*innerRadius*tubeHeight);
  return p1 + p2;
}

double Tube::tubeVolume() {
   return PI * ((outerRadius*outerRadius) - (innerRadius*innerRadius)) * tubeHeight;
}

double Tube::tubeThickness() {
  return outerRadius - innerRadius;
}


int main()
{
    Tube Tube1(20, 30, 500);
    Tube1.displayData();
    return 0;
}
