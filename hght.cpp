
//======================================================
//returns the height ball reaches when subject to constant
//gravitational acceleration
//Arguments:
//    g - gravitational acceleration
//    v - initial velocity
//    time - time at which height is desired
// =========================================================

#include <iostream>
using namespace std;

double hght(double g,double v,double time);

int main()
{
   // set acceleration due to gravity
   double g = 9.8;

   cout<< "Input the initial velocity (m/s):> ";
   double v0;
   cin>> v0;

   cout<<"Input the time (s):> ";
   double t;
   cin>> t;

   cout<< " The height at time " << t << " is "  << hght(g,v0,t) << endl;
   
   return 0;
}


double hght(double g,double v,double time)
{
  double h; //height ball will reach
  h=v*time-g*time*time*0.5;
  return h;

}







