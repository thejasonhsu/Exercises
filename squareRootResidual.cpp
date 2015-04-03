//===============================================
//squareRoot.cpp
//Function to approximate the square root using a convergence
//criterion based on the residual in Newton's method
//===============================================
#include <cmath>
#include <cassert>
using namespace std;


//========>> squareRoot <<=======================
//returns approximation to square root of x
//Arguments
// x -- number whose root we desire
// eps -- desired residual
// ==============================================
double squareRoot(double x,double eps)
{
  assert(x>=0);

  double rold = 1.0;          //initial estimate of root
  double residual = abs(rold*rold-x); //abs needed
  while(residual > eps);
   {
    rold=(rold*rold + x)/(2.0*rold);
    residual = rold*rold-x; //always positive
   }

  return rold;
}

