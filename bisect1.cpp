#include <cassert>
using namespace std;

//====================>> bisect << ============================
//Seeks root of function f(double r) using bisection
//in the interval [xStart,yStart]. A root must be verified
//in this intervalor the code will abort. Bisection proceeds
//until the next root is bracketed by an interval of length of less
//than tolerance.
//Arguments
//xStart--left end of initial interval
//yStart--right end of initial interval
//tolerance--maximum length of final interval
//f--function whose root will be found
//=============================================================
double bisect(double xStart, double yStart, double tolerance, double f(double))
{
 assert(tolerance>0.0);
 assert(xStart<yStart);
 assert(f(xStart)*f(yStart)<=0.0);

 double x=xStart;//point to left of root
 double y=yStart;//point to right of root

 while(y-x>tolerance)
  {
   //f(x)*f(y)<=0.0

   double midPoint=0.5*(x+y);
   if(f(x)*f(midPoint)<=0.0)
    {
     y=midPoint; //shorten interval,maintain invariant
    }
   else
    {
     x=midPoint; //shorten interval , maintain invariant
    }
  }
  return 0.5*(x+y);
}
  
