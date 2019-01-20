// Name: Preston Knibbe
//
// Shape: Cube
//
// Equation:
//     Surface Area = 6 * (side)^2
//     Volume = (side)^3

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

class Cube
{
	public:
		Cube(double = 1);		// double is the Side
		void SetCube(double);		// double is the Side,
						// Should set volume, and area
						// too.
		double GetSide();		// Return the Side
		double SurfaceArea();		// Calculates the SufaceArea
		double Volume();			// Calculates the Volume
		void PrintCube();		// Prints Information about
						// the Cube
		void SideFromArea(double);	// Calculate the Side of
						// of a Cube given its Area
		void SideFromVolume(double);	// Calculate the Side of
						// of a Cube given its Volume
	private:
		double side;
		double volume;
		double surfacearea;

};

Cube::Cube(double s)
{
	SetCube(s);
}

void Cube::SetCube(double s)
{
	side = s;
	surfacearea = 6 * s * s;
	volume 	    = s * s * s;
}

double Cube::GetSide()
{
	return side;
}

double Cube::SurfaceArea()
{
	return surfacearea;
}

double Cube::Volume()
{
	return volume;
}

void Cube::PrintCube()
{
	cout << "Side: " << side << endl;
	cout << "Volume: " << volume << endl;
	cout << "Surface Area: " << surfacearea << endl;
}

void Cube::SideFromArea(double area)
{
	double new_side = sqrt(area/6);
	SetCube(new_side);
}

void Cube::SideFromVolume(double volume)
{
	double new_side = pow(volume/6, 1.0/3.0);
	SetCube(new_side);
}



main()
{
	Cube C1(32), C2, C3(60), C4, C5;


	C1.PrintCube();
	C2.PrintCube();
  C2.SideFromVolume(5);
	C2.PrintCube();
	C3.PrintCube();
	C4.SetCube(12);
	C4.PrintCube();
	C5.SideFromArea(16);
	C5.PrintCube();

}

