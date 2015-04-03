#include "moveaction.h"
#include "Action.h"
#include <iostream>

using namespace std;

moveaction::moveaction(string name)		// Constructor that will set amount to 0 and call the base class's name to name.
: Action(name)
{
	amount = 0;
}

void moveaction::set_amount(int amt)	// Set the value of amount of amt.
{
	amount = amt;
}

int moveaction::get_amount()			// Get the value of amount.
{
	return amount;
}

void moveaction::executeAction()
{
	cout << "MOVE ACTION" << endl;
}