//=============================================================
// stringExample.cpp
//Some games with strings
//==============================================================
#include <string>
#include <iostream>
using namespace std;

int main()
{
  // declare some strings
  string firstName;              // an empty string
  string lastName("Baggins");    // nonempty string
  string occupation = "Hobbit of leisure"; // initialize string

  cout<<"Name: " << firstName << " " << lastName <<
        ", " << occupation << endl;

  occupation = "Ringbearer"; //change his occupation

  cout<<"Name: " << firstName << " " << lastName<<
        ", " << occupation << endl;

  string drogoSon("Frodo"); //Frodo son of Drogo
  firstName = drogoSon;    // give him a first name

  cout<<"Name: " << firstName << " " << lastName <<
        ", " << occupation << endl;

  return 0;
}

