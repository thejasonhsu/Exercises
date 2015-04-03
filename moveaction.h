#ifndef MOVEACTION_H
#define MOVEACTION_H

#include <string>
#include "Action.h"

using namespace std;

class moveaction : public Action		// Create a class MoveAction, : public Action = means it inherits from the class Action.
{
	public:
		moveaction(string name);		// Constructor that will set amount to 0 and call the base class's name to name.
		void set_amount(int amt);		// Set the value of amount of amt.
		int get_amount();				// Get the value of amount.
		void executeAction();

	private:
		int amount;
};

#endif