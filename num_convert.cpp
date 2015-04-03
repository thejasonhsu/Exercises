#include <iostream>
#include <cmath>

using namespace std;
int main(int argc, char *argv[])
{
  // Declare any other variables you need here
  // and/or delete the integer declared below 
  double deF;
  double deC;

  // Prompt the user
  cout << "Enter degrees in Fahrenheit:  ";

  // get input  
  cin >> deF;

  // Do some operations
  deC = (deF-32)*5/9;

  // Print the result to the user
  cout << "Degrees in Celsius: " << deC << endl;
  
  // You're done
  return 0;
  
}

