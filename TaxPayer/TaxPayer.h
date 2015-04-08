#ifndef TAXPLAYER_H
#define TAXPLAYER_H

#include "person.h"
#include <iostream>

using namespace std;

class TaxPayer : public Person
{
	protected:
		char marriedOrSingle;
		char ownAHouse;

	public:
		virtual int get_bracket_differential() = 0;


		TaxPayer();
		TaxPayer(char mors, char house, int s) : Person(s)
		{
			marriedOrSingle = mors;
			ownAHouse = house;
		}
};

class SingleHomeOwner : public TaxPayer
{
public:
	SingleHomeOwner(char mors, char house, int s) : TaxPayer(mors, house, s) { }

	int get_bracket_differential()
	{
		int diff = 2 - 1; // 2 = single, -1 for owning a house.
		if (this->salary < 20000)
			diff = diff - 1;
		else if (this->salary < 50000)
			diff = diff + 1;
		else if (this->salary < 100000)
			diff = diff + 2;
		else
			diff = diff + 4;
		if (diff < 0)
			return 0;
		else
			return diff;
	}
};

class MarriedHomeOwner : public TaxPayer
{
public:
	MarriedHomeOwner(char mors, char house, int s) : TaxPayer(mors, house, s) { }
	int get_bracket_differential()
	{
		int diff = -1 - 1; // -1 for married, -1 for owning a house.
		if (this->salary < 20000)
			diff = diff - 1;
		else if (this->salary < 50000)
			diff = diff + 1;
		else if (this->salary < 100000)
			diff = diff + 2;
		else
			diff = diff + 4;
		if (diff < 0)
			return 0;
		else
			return diff;
	}
};

class SinglePerson : public TaxPayer
{
public:
	SinglePerson(char mors, char house, int s) : TaxPayer(mors, house, s) {}
	int get_bracket_differential()
	{
		int diff = 2; // 2 = single
		if (this->salary < 20000)
			diff = diff - 1;
		else if (this->salary < 50000)
			diff = diff + 1;
		else if (this->salary < 100000)
			diff = diff + 2;
		else
			diff = diff + 4;
		if (diff < 0)
			return 0;
		else
			return diff;
	}
};

class MarriedPerson : public TaxPayer
{
public:
	MarriedPerson(char mors, char house, int s) : TaxPayer(mors, house, s) { }
	int get_bracket_differential()
	{
		int diff = -1; // -1 married, -1 for owning a house.
		if (this->salary < 20000)
			diff = diff - 1;
		else if (this->salary < 50000)
			diff = diff + 1;
		else if (this->salary < 100000)
			diff = diff + 2;
		else
			diff = diff + 4;
		if (diff < 0)
			return 0;
		else
			return diff;
	}
};

#endif