//========================================
//rootTesterResidual.cpp
// Code to test my second square root function.
//========================================
#include <iostream>
#include <cmath>
using namespace std;

double squareRoot(double x, double eps);

//=====================>> main << ==============
int main(void)
{
 cout.precision(15); //resolution of digits shown

 double x;
 double eps;

 cout<< "Input x and the desired residual [q to quit]:> ";
 cin >>x;
 cin >>eps;
 while(not cin.fail())
 {
  //we have valid input, so give it a try
  double root = squareRoot(x, eps);

  cout << " squareRoot("<<x<<", " <<eps<<") = ";
  cout <<root<<endl;
  cout<<"sqrt(" <<x<< ") = " <<sqrt(x)<<endl;
  cout<<"Difference = " << root-sqrt(x)<<endl;
  cout<<"Residual = "<<root*root-x<<endl;
  cout<<"===================================="<<endl;

  cout<<"Input x and the desired residual [q to quit]:> ";
  cin>>x;
  cin>>eps;
 }
 cout<< "Thanks for playing!" <<endl;
 return 0;
}



