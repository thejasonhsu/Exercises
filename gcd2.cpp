#include <cassert>
using namespace std;

int gcd(int i, int j)
{
 //Requirements
 assert(j>0);
 assert(i>=0);

 int g=j;
 while(not((i%g)==0 and (j%g)==0 ))
  {
   g=g-1;
  }
 return g;
}

