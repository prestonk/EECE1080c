//Preston Knibbe
//October 15, 2015


//

#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>
# define M_PI           3.14159265358979323846

using namespace std;

double degreesToRadians(double angle_in_degrees);
double Factorial(double number);
double Sine(double angle_in_radians);
double Cosine(double angle_in_radians);
double Secant(double angle_in_radians);
double Cosecant(double angle_in_radians);
double Tangent(double angle_in_radians);
double CoTangent(double angle_in_radians);
void   PrintTrigTable();
void   PrintTrigTableHeader();
void   PrintTrigTableRecord(double angle_in_degrees);

// The function main() is complete you will need to implement PrintTrigTable which will print the table
int main()
{
	PrintTrigTable();
	return 0;
}

// Provided Stub functions - You will need to implement the function body

double degreesToRadians(double angle_in_degrees)
{
  double angle_in_radians = angle_in_degrees * M_PI / 180.0;
  return angle_in_radians;
}

double Factorial(double number)
{
  double total = 1.0;
  double other = number;
  for (double i = 0.0; i < other; i++) {
    total *= number;
    number--;
  }
  return total;
}

double Sine(double angle_in_radians)
{
  double diff = 1.0;
  double total = 0.0;
  double counter = 1.0;
  double temp = 1.0;
  double power;
  double fact;
  int negative = 1;
  // Using a difference between current an previous values will not produce accurate results
  // when using whole number x's. Because of this MyExp function won't match the exp function in results.
  // This could be fixed by comparing the values with the exp function values directly and continuing the
  // loop until it is within a certain range of that number
  while (abs(diff) >= 0.001) {
    if ((negative%2) == 0) {
      power = pow(angle_in_radians, counter);
      fact = Factorial(counter);
      diff = temp - (power / fact);
      temp = power / fact;
      total -= (power / fact);
    } else {
      power = pow(angle_in_radians, counter);
      fact = Factorial(counter);
      diff = temp - (power / fact);
      temp = power / fact;
      total += (power / fact);
    }
    counter += 2.0;
    negative ++;

  }
  return total;
}

double Cosine(double angle_in_radians)
{
  double diff = 1.0;
  double total = 1.0;
  double counter = 2.0;
  double temp = 1.0;
  double power;
  double fact;
  int negative = 1;
  // Using a difference between current an previous values will not produce accurate results
  // when using whole number x's. Because of this MyExp function won't match the exp function in results.
  // This could be fixed by comparing the values with the exp function values directly and continuing the
  // loop until it is within a certain range of that number
  while (abs(diff) >= 0.0001) {
    if ((negative%2) != 0) {
      power = pow(angle_in_radians, counter);
      fact = Factorial(counter);
      diff = temp - (power / fact);
      temp = power / fact;
      total -= (power / fact);
      counter += 2.0;
      negative ++;
    } else if ((negative%2) == 0) {
      power = pow(angle_in_radians, counter);
      fact = Factorial(counter);
      diff = temp - (power / fact);
      temp = power / fact;
      total += (power / fact);
      counter += 2.0;
      negative ++;
    }

  }
  return total;
}

double Secant(double angle_in_radians)
{
  return (1.0 / Cosine(angle_in_radians));
}

double CoTangent(double angle_in_radians)
{
  return (Cosine(angle_in_radians) / Sine(angle_in_radians));
}

// Here is couple of functions to get you going.
double Cosecant(double angle_in_radians)
{
	return (1.0/Sine(angle_in_radians));
}

double Tangent(double angle_in_radians)
{
	return(Sine(angle_in_radians)/Cosine(angle_in_radians));
}


void PrintTrigTable()
{
	// Display proper header
	PrintTrigTableHeader();
	// Than Add proper loop and call PrintTrigRecord() to display each record
	// Sample call to PrintTrigRecord()
	for (double x = 0.0; x <= 360.0; x+=15.0) {
    double angle_in_degrees = x;
    PrintTrigTableRecord(angle_in_degrees);
  }
}
// Displays the TRIG table header
void PrintTrigTableHeader(){
	// Finish me
	cout << "DEGREES" << fixed << setw(12) << setprecision(4);
	cout << "MY SINE" << fixed << setw(12) << setprecision(4);
	cout << "MATH SINE" << fixed << setw(12) << setprecision(4);
	cout << "COSINE" << fixed << setw(12) << setprecision(4);
	cout << "MATH COSINE" << fixed << setw(13) << setprecision(4);
	cout << "SECANT" << fixed << setw(13) << setprecision(4);
	cout << "COSECANT" << fixed << setw(13) << setprecision(4);
	cout << "TANGENT" << fixed << setw(12) << setprecision(4);
	cout << "COTANGENT" << fixed << setw(12) << setprecision(4) << endl;
}
// This function is not complete please add cout statements and proper formatting for the rest of the trig functions
void PrintTrigTableRecord(double angle_in_degrees)
{
	double angle_in_radians = degreesToRadians(angle_in_degrees);


	cout << fixed << setw(5) << setprecision(0) << angle_in_degrees;
	cout << fixed << setw(13) << setprecision(4) << Sine(angle_in_radians);
	cout << fixed << setw(13) << setprecision(4) << sin(angle_in_radians); // Math library sine
	cout << fixed << setw(13) << setprecision(4) << Cosine(angle_in_radians);
	cout << fixed << setw(13) << setprecision(4) << cos(angle_in_radians);
	cout << fixed << setw(13) << setprecision(4) << Secant(angle_in_radians);
	cout << fixed << setw(13) << setprecision(4) << Cosecant(angle_in_radians);
	cout << fixed << setw(13) << setprecision(4) << Tangent(angle_in_radians);
	cout << fixed << setw(13) << setprecision(4) << CoTangent(angle_in_radians);
	cout << endl;
}
