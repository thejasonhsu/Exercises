#include "Action.h"
#include <string>
#include <iostream>

using namespace std;

Action::Action()				// Default constructor for the class.
{
	name = "";
}

Action::Action(string nm)		// Value constructor that assigns nm to name variable.
{
	name = nm;
}

void Action::print_name()		// Print the name of the Action.
{
	cout << "Name: " << name << endl;
}