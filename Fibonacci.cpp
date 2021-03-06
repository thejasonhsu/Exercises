// ===>> Fibonacci << ================================
// Computes the nth  number in the given sequence
// ===============================================
#include <cassert>
using namespace std;

double Fibonacci(int n)
{
  assert(n>=0);

  double value = 0.0;
  switch(n)
    { 
        case(0):
           value = 0.0;  //F0 = 0
           break;           // Go to end of switch

         case(1):
           value = 1;    // F1 = 1 
           break;           // Go to end of switch


         default:
             value = Fibonacci(n-1) + Fibonacci(n-2);
     }

     return value;
}


