//Preston Knibbe
//September 8, 2015

#include <iostream>
#include <cmath>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

int main(){
  cout << "Degrees " << " Sine   " << "Cosine   " << "           Tangent" << endl;
  for (int i = 0; i <= 360; i+=10) {
    double rad = i * M_PI / 180.0;
    double s = sin(rad);
    double c = cos(rad);
    double t = tan(rad);
    cout << i<< fixed << setw(10) << setprecision(4) << s << fixed << setw(10) << setprecision(4) << c << fixed << setw(25) << setprecision(4) << t << endl;;
  }
  return 0;
}
