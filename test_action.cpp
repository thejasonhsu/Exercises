#include <iostream>
#include "Action.h"
#include "moveaction.h"
#include "Player.h"
#include "MoneyAction.h"
#include "GotoAction.h"

using namespace std;

int main()
{
	moveaction move("withdraw");
	MoneyAction money("add");

	Action **actions = new Action*[3];
	actions[0] = new moveaction("MOVE");
	actions[1] = new MoneyAction("MONEY");
	actions[2] = new GotoAction("GOTO");

	for (int i = 0; i < 3; i++)
		actions[i]->executeAction();
	delete[] actions;
	return 0;
}