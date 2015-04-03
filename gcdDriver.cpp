//=====================================================
//gcdDriver.cpp
//Test code for a greatest common divisor function
//=====================================================
#include <iostream>
using namespace std;

//External routine declarations
int gcd(int,int);//declare the gcd function

//=================>> main <<==========================
int main()
{
  cout<<"gcd(4, 2) = ";
  cout<<gcd(4, 2)<<endl;

  cout<<"gcd(2, 4) = ";
  cout<<gcd(2, 4)<<endl;

  cout<<"gcd(259, 111) = ";
  cout<<gcd(259, 111)<<endl;

  cout<<"gcd(1375, 218491) = ";
  cout<<gcd(1375, 218491)<<endl;

  cout<<"gcd(541, 3804853) = ";
  cout<<gcd(541, 3804853)<<endl;

  cout<<"gcd(0, 56) = ";
  cout<<gcd(56, 0)<<endl;

  return 0;
}

