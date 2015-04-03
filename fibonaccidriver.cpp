//===========fibonaccidriver.cpp==============
//takes as in put an integer and calls on the function fibonacci
//=======  ===================================
//Returns the nth number of the fibonacci sequence

// =========================================================

#include <iostream>
#include <stdlib.h>
#include <cassert>
using namespace std;

//Declaration of function so it can appear in the main body of code before it 
//is defined
double Fibonacci( int n);

//main body of code

int main()
{
   cout<< "Input the nth term sought in the sequence:> ";
   int n;
   cin>> n;

   

   cout<< " The term in the fibonacci sequence is "  << Fibonacci(n)  << endl;
   
   return 0;
}
