#include <cassert>
using namespace std;

//==========================>>trapArea<<==================
//Estimates the area under f(x) for x between a and b
//Arguments
// f - function to use
// a - left endpoint
// b - right endpoint
// N - number of intervals to use
//========================================================
double trapArea(double f(double), double a, double b, int N)
{
 assert(a<=b);
 assert(N>0);

 double h=(b-a)/N;
 double A =0.5*f(a);
 for(int i=1;i<N;i=i+1) //i:number of points used
  {
   double x = a+i*h;
   A=A+f(x);
  }
 A=A+0.5*f(b);

 return h*A;
}
 
