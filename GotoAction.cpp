#include "GotoAction.h"
#include <iostream>

GotoAction::GotoAction(string name)
{
	goName = name;
}

void GotoAction::executeAction()
{
	cout << "GO TO ACTION" << endl;
}
