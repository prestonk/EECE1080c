// Name: Preston Knibbe
//
// Shape: TriPyramid
//
// Equation:
//     Surface Area = side^2 * 2
//     Volume = side^2 * height / 6

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

class TriPyramid
{
	public:
		TriPyramid(double = 1);		// doubles are the side and height
		void SetTriPyramid(double);		// doubles are the side and height,
						// Should set volume, and area
						// too.
		double GetSide();		// Return the side
		double GetHeight();   // Return the height
		double SurfaceArea();		// Calculates the SufaceArea
		double Volume();			// Calculates the Volume
		void PrintTriPyramid();		// Prints Information about
						// the TriPyramid
		void SideFromArea(double);	// Calculate the side of
						// of a TriPyramid given its Area
		void SideFromVolume(double);	// Calculate the Side of
						// of a TriPyramid given its Volume and Height
	private:
		double side;
		double height;
		double volume;
		double surfacearea;

};

TriPyramid::TriPyramid(double side)
{
	SetTriPyramid(side);
}

void TriPyramid::SetTriPyramid(double s)
{
	side = s;
	height = sqrt((side*side)-((side*side)/4));
	surfacearea = side * side * 2;
	volume 	    = (side*side*height)/6;
}

double TriPyramid::GetSide()
{
	return side;
}

double TriPyramid::GetHeight() {
  return height;
}

double TriPyramid::SurfaceArea()
{
	return surfacearea;
}

double TriPyramid::Volume()
{
	return volume;
}

void TriPyramid::PrintTriPyramid()
{
	cout << "Side: " << side << endl;
	cout << "Height: " << height << endl;
	cout << "Volume: " << volume << endl;
	cout << "Surface Area: " << surfacearea << endl;
}

void TriPyramid::SideFromArea(double area)
{
	double new_side = sqrt(area/2);
	SetTriPyramid(new_side);
}





main()
{
	TriPyramid T1(43), T2(88), T3, T4;


	T1.PrintTriPyramid();
  T2.PrintTriPyramid();
	T3.SetTriPyramid(22);
	T3.PrintTriPyramid();
	T4.SideFromArea(565);
	T4.PrintTriPyramid();

}

