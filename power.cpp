//======= >> raising a number to an integer power >>  ===================================
//returns the greatest common denominator of two positive integers
//Arguments:
//    x - number which will be raised to a power
//    p - exponent or power  to which the number x is raised
// =========================================================

#include <iostream>
#include <stdlib.h>
#include <cassert>
using namespace std;

//Declaration of function so it can appear in the main body of code before it is defined
double power(double x, int p);

//main body of code

int main()
{
   cout<< "Input the number which is to be raised to a power:> ";
   double x;
   cin>> x;

   cout<<"Input the integer power to which the first number is to be raised:> ";
   int p;
   cin>> p;

   cout<< " The number " << x << " raised to the power " << p << " is "  <<  power(x, p)  << endl;
   
   return 0;
}

double power(double x, int p)
{
  //Computes x to a nonnegative integer power p.
  assert(p>=0);

  double result=1.0;
  int counter =0;
  //Invariant established: result=x^counter and counter<=p

  while(counter<p)
   {
    //invariant:result=x^counter and counter <= p
    result=result*x;
    counter=counter+1;
    //invariant:result=x^counter and counter<=p
   }
  return result;
}


