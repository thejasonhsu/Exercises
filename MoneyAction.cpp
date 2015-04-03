#include <iostream>
#include "MoneyAction.h"
#include "Action.h"
#include "Player.h"
#include <string>

using namespace std;

MoneyAction::MoneyAction(string name)					// Value constructor that states money at 0, calls base class default constructor.
: Action(name)
{
	money = 0;
}

void MoneyAction::pay_money(Player &p, int amount)		// Pays the player p an amount. Also subtracts the amount from money (our money).
{
	p.give_money(amount);
	money -= amount;
}

void MoneyAction::setMoney(int amount)				// Set an amount for the money.
{
	money = amount;
}

int MoneyAction::getMoney()							// Get the money.
{
	return money;
}

void MoneyAction::executeAction()
{
	cout << "MONEY ACTION" << endl;
}