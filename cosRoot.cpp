//============================================
//cosRoot.cpp
//Finds the root of cosine between 1.5 and 1.6 radians.
//============================================
#include <iostream>
#include <cmath>
using namespace std;

//Declare functions
double bisect(double xStart, double yStart, double tolerance,
              double f(double));

//==============>>main<<======================
int main()
{
 cout.precision(14); // show 14 decimal places  of resolution
 cout<<"The root of cosine between 1.5 and 1.6 is ";
 cout<<bisect(1.5,1.6,1e-6,cos)<<endl;
}
