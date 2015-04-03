//==================>>factorial<<==================
//computes the factorial of n
//===============================================
#include<cassert>
using namespace std;

int fact(int n)
{
  assert(n>=0);
  if(n==0)
   {
    return 1;
   }
  return n*fact(n-1);
}

  

