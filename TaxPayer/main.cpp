#include "person.h"
#include "TaxPayer.h"

#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <stdlib.h>
#include <iomanip>

using namespace std;

int main()
{
	char mors;
	char house;
	int s;
	cout << "Are you married(m) or single(s)? ";
	cin >> mors;
	cout << "Do you own a house (y/n)? ";
	cin >> house;
	cout << "What is your annual salary? ";
	cin >> s;
	TaxPayer *tp;
		if (mors == 's' && house == 'y') {
			tp = new SingleHomeOwner(mors, house, s);
		}
		else if (mors == 'm' && house == 'y') {
			tp = new MarriedHomeOwner(mors, house, s);
		}
		else if (mors == 's' && house == 'n') {
			tp = new SinglePerson(mors, house, s);
		}
		else {
			tp = new MarriedPerson(mors, house, s);
		}
		cout << "Your tax bracket differential is ";
		cout << tp->get_bracket_differential() << "." << endl;
}