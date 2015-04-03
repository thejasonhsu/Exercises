//===========================================================
//gcd3.cpp
//Computes the greatest common divisor of two non-negative 
//integers a and b without dividing numbers
//===========================================================
#include <cassert>
using namespace std;

int gcd(int a, int b)
{
 assert(not(a==0 and b==0));//they can't both be zero
 assert(a>=0);
 assert(b>=0);

 int i=a;//make local copies
 int j=b;

 while((i!=j) and (j!=0) and (i!=0))
  {
   //loop invariant gcd(i,j)=gcd(a,b)
   if(i>j)
    {
     i=i-j;//reduce i but leave GCD unchanged
    }
   else
    {
     j=j-i;//reduce j but leave GCD unchanged
    }
  }

  //Now only special cases are possible
  if(i==0)  //GCD(0,j)=j
   {
    return j;
   }
   return i;   //GCD(i,i)=i or GCD(i,0)=i
}

