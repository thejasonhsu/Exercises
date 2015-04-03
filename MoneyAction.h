#ifndef MONEYACTION_H
#define MONEYACTION_H

#include "Action.h"
#include "Player.h"
#include <string>

using namespace std;

class MoneyAction : public Action				// Class creation of MoneyAction, : public Action = inherits from the class Action.
{
	public:
		MoneyAction(string name);				// Value constructor that states money at 0, calls base class default constructor.
		void pay_money(Player &p, int amount);	// Pays the player p an amount. Also subtracts the amount from money (our money).
		void setMoney(int amount);				// Set an amount for the money.
		int getMoney();							// Get the money.
		void executeAction();

	private:
		int money;
};

#endif