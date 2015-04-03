#ifndef GOTOACTION_H
#define GOTOACTION_H

#include "Action.h"
#include <string>

class GotoAction : public Action
{
	public:
		GotoAction(string name);
		void executeAction();

	private:
		string goName;
};

#endif
