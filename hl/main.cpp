#include <iostream>

using namespace std;

int main()
{
int x = 14, y = 17, z = 5, w = 7;
int *ptr1, *ptr2, *ptr3, *ptr4;

ptr1 = &x;
ptr2 = &y;
ptr3 = &w;
ptr4 = &z
*ptr4 = *ptr2;
ptr3 = ptr4;
cout << *ptr1 << "\t"	<< *ptr2 << "\t" << *ptr3 << "\t" << *ptr4 << endl;
cout << x << "\t" << y << "\t" << z << "\t" << w << endl;


    return 0;
}
