// Name: Preston Knibbe
//
// Shape: Torus
//
// Equation:
//     Surface Area = 4 * PI^2 * R * r
//     Volume = 2 * PI^2 * R * r^2

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

class Torus
{
	public:
		Torus(double = 1, double = 1);		// doubles are the BigR and r
		void SetTorus(double, double);		// doubles are the BigR and r,
						// Should set volume, and area
						// too.
		double GetBigRadius();		// Return the Radius
		double GetLittleRadius();   // Return the
		double SurfaceArea();		// Calculates the SufaceArea
		double Volume();			// Calculates the Volume
		void PrintTorus();		// Prints Information about
						// the Torus
		void BigRadiusFromAreaAndLittleRadius(double, double);	// Calculate the BigRadius of
						// of a Torus given its Area and LittleRadius
		void BigRadiusFromVolumeAndLittleRadius(double, double);	// Calculate the BigRadius of
						// of a Torus given its Volume and LittleRadius
	private:
		double big_radius;
		double little_radius;
		double volume;
		double surfacearea;

};

Torus::Torus(double bigR, double litR)
{
	SetTorus(bigR, litR);
}

void Torus::SetTorus(double bigR, double litR)
{
	big_radius = bigR;
	little_radius = litR;
	surfacearea = 4*PI*PI*bigR*litR;
	volume 	    = 2*PI*PI*litR*litR*bigR;
}

double Torus::GetBigRadius()
{
	return big_radius;
}

double Torus::GetLittleRadius() {
  return little_radius;
}

double Torus::SurfaceArea()
{
	return surfacearea;
}

double Torus::Volume()
{
	return volume;
}

void Torus::PrintTorus()
{
	cout << "Big Radius: " << big_radius << endl;
	cout << "Little Radius: " << little_radius << endl;
	cout << "Volume: " << volume << endl;
	cout << "Surface Area: " << surfacearea << endl;
}

void Torus::BigRadiusFromAreaAndLittleRadius(double area, double litR)
{
	double new_big_radius = area/(4*PI*PI*litR);
	SetTorus(new_big_radius, litR);
}

void Torus::BigRadiusFromVolumeAndLittleRadius(double volume, double litR)
{
	double new_big_radius = volume/(2*PI*PI*litR*litR);
	SetTorus(new_big_radius, litR);
}




main()
{
	Torus T1(5, 97), T2, T3(6, 9), T4, T5;


	T1.PrintTorus();
	T2.PrintTorus();
  T2.BigRadiusFromVolumeAndLittleRadius(4, 19);
  T2.PrintTorus();
	T3.PrintTorus();
	T4.SetTorus(12, 36);
	T4.PrintTorus();
	T5.BigRadiusFromAreaAndLittleRadius(87, 100);
	T5.PrintTorus();

}

