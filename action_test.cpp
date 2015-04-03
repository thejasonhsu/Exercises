#include <iostream>
#include "Action.h"
#include "moveaction.h"
#include "Player.h"
#include "MoneyAction.h"

using namespace std;

int main()
{
	Action act;												// Create an Action via Default Constructor.
	Action act2("Transfer");								// Create an Action via Value Constructor (nm = "Transfer")

	act.print_name();										// Print the name of act.
	act2.print_name();										// Print the name of act2.

	cout << endl << " ---- END OF BASE CLASS TEST ---- " << endl << endl;

	moveaction move("Test");								// Create a MoveAction object with base name "Transfer"

	move.set_amount(50);									// Set the amount of the MoveAction move.
	move.print_name();										// Print the name of the MoveAction object move.
	cout << "MOVE VALUE: " << move.get_amount() << endl;	// Get the amount of the MoveAction move.

	cout << endl << " ---- END OF DERIVED MOVEACTION CLASS TEST ---- " << endl << endl;

	Player p2;												// Create a 2nd player.
	p2.give_money(500);										// Give Player 2, 500 for money.
	MoneyAction mAct("Player 1");							// Create a MoneyAction (Player 1).

	mAct.setMoney(500);										// Set the money for Player 1.
	mAct.print_name();										// Print the name of Player 1.
	cout << "PLAYER 1 MONEY: " << mAct.getMoney() << endl;	// Get the money for Player 1.
	mAct.pay_money(p2, 50);									// Player 1 pays Player 2, 50.
	cout << "PLAYER 1 MONEY: " << mAct.getMoney() << endl;	// Get the money for Player 1.
	cout << "PLAYER 2 MONEY: " << p2.getMoney() << endl;	// Get the money for Player 2.

	cout << endl << " ---- END OF DERIVED MONEYACTION CLASS TEST ---- " << endl << endl;

	return 0;
}
