//============================================================
//addem.cpp
// a code to add numbers provided via cin and report the 
// sum back via cout
// ==========================================================
#include <iostream>
using namespace std;

//Declaration of functions defined elsewhere
double sumNumbers(istream & dataSource);

//============>> main << =====================================
int main()
{
  double sum = sumNumbers(cin);// get the sum
  cout<< " The sum is " << sum << endl;

  return 0;
}

//sumNumbers is a function that sums a list of numbers 
//via a dataSource , until there are no more 
//numbers forthcoming
//===========================================================

double sumNumbers(istream & dataSource)
{
  double sum = 0.0;
  double number;
  dataSource >> number;
  while( not dataSource.fail() )
   {
     sum=sum+number;
     dataSource >> number; //try for another
   }

  return sum;
}




