//========================================================
//areaFun.cpp
//Code to compute the area under a number of functions
//=========================================================
#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

double trapArea(double f(double), double a, double b, int N);

//===========================>> cosSin <<====================
double cosSin(double x)
{
 return cos(x)*sin(x);
}

//=======================>> main <<===========================
int main()
{
 cout<<"Please specify the interval [a, b] :> ";
 double a;
 cin>>a;
 double b;
 cin>>b;

 cout<<"Please specify the number of intervals :> ";
 int N;
 cin>>N;

 cout<<"Area under cos: "<<trapArea(cos, a, b, N)<<endl;
 cout<<"Area under sin: "<<trapArea(sin, a, b, N)<<endl;
 cout<<"Area under cos*sin: "<<trapArea(cosSin, a, b, N) 
     <<endl;

 return 0;
}



