// Name: Preston Knibbe
//
// Shape: Cylinder
//
// Equation:
//     Surface Area = 2 * PI * r * (r+h)
//     Volume = PI * r^2 * h

#include <cmath>
#include <iostream>
using std::cout;
using std::endl;
using std::fixed;

#include <iomanip>

using std::setw;
using std::setprecision;
using std::showpoint;
using std::setfill;

#define PI            3.14159265358979323846

// Fully implement the following class

class Cylinder
{
	public:
		Cylinder(double = 1, double = 1);		// double is the Side
		void SetCylinder(double, double);		// double is the Side,
						// Should set volume, and area
						// too.
		double GetRadius();		// Return the Radius
		double GetHeight();   // Return the Height
		double SurfaceArea();		// Calculates the SufaceArea
		double Volume();			// Calculates the Volume
		void PrintCylinder();		// Prints Information about
						// the Cylinder
		void HeightFromAreaAndRadius(double, double);	// Calculate the Height of
						// of a Cylinder given its Area and Radius
		void HeightFromVolumeAndRadius(double, double);	// Calculate the Height of
						// of a Cylinder given its Volume and Radius
	private:
		double radius;
		double height;
		double volume;
		double surfacearea;

};

Cylinder::Cylinder(double r, double h)
{
	SetCylinder(r, h);
}

void Cylinder::SetCylinder(double r, double h)
{
	radius = r;
	height = h;
	surfacearea = 2*PI*r*(r+h);
	volume 	    = PI*r*r*h;
}

double Cylinder::GetRadius()
{
	return radius;
}

double Cylinder::GetHeight() {
  return height;
}

double Cylinder::SurfaceArea()
{
	return surfacearea;
}

double Cylinder::Volume()
{
	return volume;
}

void Cylinder::PrintCylinder()
{
	cout << "Radius: " << radius << endl;
	cout << "Height: " << height << endl;
	cout << "Volume: " << volume << endl;
	cout << "Surface Area: " << surfacearea << endl;
}

void Cylinder::HeightFromAreaAndRadius(double area, double radius)
{
	double new_height = area/(2*PI*radius) - radius;
	SetCylinder(radius, new_height);
}

void Cylinder::HeightFromVolumeAndRadius(double volume, double radius)
{
	double new_height = volume/(PI * radius * radius);
	SetCylinder(radius, new_height);
}




main()
{
	Cylinder C1(8, 12), C2, C3(25, 39), C4, C5;


	C1.PrintCylinder();
	C2.PrintCylinder();
  C2.HeightFromVolumeAndRadius(28, 2);
	C2.PrintCylinder();
	C3.PrintCylinder();
	C4.SetCylinder(5, 31);
	C4.PrintCylinder();
	C5.HeightFromAreaAndRadius(350, 2);
	C5.PrintCylinder();

}

