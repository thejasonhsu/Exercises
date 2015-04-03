//===========================================
//rootTesterN.cpp
//Code to test the first square root function
//===============================
#include <iostream>
#include <cmath>
using namespace std;

double squareRootN(double x, int N);

//============>> main << ====================
int main()
{
  cout.precision(15); // show lots of digits

  double x;
  int N;

  cout << "Input x and number of iterates [q to quit] :> ";
  cin >> x;
  cin >> N;
while( not cin.fail())
  {
  // we have valid input so give it a try

  cout<< "squareRootN(" << x << ", " << N << ") = ";
  cout<< squareRootN(x, N)<<endl;
  cout<< "sqrt(" << x << ") = " << sqrt(x) <<endl;
  cout <<"Difference = " << squareRootN(x, N) - sqrt(x)
       << endl;
  cout<<"====================================" <<endl;

  cout<< "Input x and number of iterates [q to quit] :> ";
  cin >> x >> N ;
  } 

  cout<< "Thanks for playing!" << endl;
  return 0;
}

