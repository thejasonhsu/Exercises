#include <iostream>
using namespace std;

int main()
{
   double g=9.81;//acceleration due to gravity

   cout<<"Input the initial velocity (m/s):> ";
   double v0;
   cin>> v0 ;

   cout<< " Input the time (s):> ";
   double t;
   cin>> t;

   cout<< "==========================="//
       << endl;
   cout<< "The velocity at time " <<t<< " is "
       << v0 - g*t <<endl;

   cout<< "and the height is "
       << v0*t - (g*t*t)/2 << endl;

   return 0;
}
