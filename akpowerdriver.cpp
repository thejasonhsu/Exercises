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
double akpower(double x, int p);

//main body of code

int main()
{
   cout<< "Input the number which is to be raised to a power:> ";
   double x;
   cin>> x;

   cout<<"Input the integer power,pos or neg, to which the first number is to be raised:> ";
   int p;
   cin>> p;

   cout<< " The number " << x << " raised to the power " << p << " is "  << akpower(x, p)  << endl;
   
   return 0;
}
