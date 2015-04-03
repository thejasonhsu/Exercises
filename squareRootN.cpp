//================================================
//squareRootN.cpp
//Function to approximate the square root using a 
//fixed number of Newton's method iterations
//===============================================
#include <cassert>
using namespace std;

//================>> squareootN << ===============
//Returns approximation to the square root of x
//Arguments
//  x--number whose root is sought
//  N--number of iteraes to take
//=================================================
double squareRootN(double x, int N)
{
  assert(x>=0);

  double rold =1.0;//estimate of root
  int counter =0;//number of iterates completed

  while( counter < N )
   {
    rold=(rold*rold+x)/(2*rold);
    counter= counter+1;
   }
  return rold;
}

