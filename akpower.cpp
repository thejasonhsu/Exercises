// ===========================================================
// akpower.cpp
// Computes x to the non-negative integer power p using
// Al-Kashi's algorithm
// ===========================================================
#include <cassert>
using namespace std;
double akpower(double x, int p)
{
 int sign = 1;
 if(p < 0)
   {
    p = -p; // make power positive
    sign = -1; // but remember it's supposed to be neg   
   }
 int n = p;
 double xn = x;
 double result = 1.0;
 // Invariant established: pow(x, p) = result * pow(xn, n)
while(1 <= n)
 {
  if( n%2 == 0)
   {
    n = n/2;
    xn = xn * xn;
    // pow(xn, n) has not changed
   }
  else
   {
    n = n - 1;
    result = result * xn;
   // result * pow(xn, n) has not changed
  }
  // Invariant: pow(x, p) = result * pow(xn, n)
 }
// pow(x, p) = result * pow(xn, 0)
if(sign == -1)
 {
  result = 1.0/result;
 }
 return result;
}

