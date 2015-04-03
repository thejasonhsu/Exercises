// Midterm 1 - Company Salaries
// Jason Hsu
// 2580964804

#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <stdlib.h>
#include <fstream>  //read file as input

using namespace std;

bool readFile(int &count);
void highsalary(int count);
double totalsalary(int count);

struct employee
{
	string firstname;
	string lastname;
	int salary;
};

employee *allemployee = NULL;

int main()
{
	bool isGoodData = false;
	cout << "Welcome to the employee program." << endl;
	int count=0;
	while (!isGoodData)
		isGoodData = readFile(count);
	cout << "(1) Find employee with highest salary" << endl;
	cout << "(2) Find employee with lowest salary" << endl;
	cout << "(3) Calculate average salary" << endl;
	cout << "(4) Calculate total salary" << endl;
	cout << "(5) Exit" << endl;
	int ans;
	highsalary(count);
	double tsalary = totalsalary(count);
	cout << "Enter a choice: ";
	cin >> ans;
	while (ans != 5)
	{
		switch (ans)
		{
			case 1:	cout << allemployee[count - 1].firstname << " " << allemployee[count - 1].lastname << " has the highest salary of " << allemployee[count - 1].salary << "." << endl;
				break;
			case 2:	cout << allemployee[0].firstname << " " << allemployee[0].lastname << " has the lowest salary of " << allemployee[0].salary << "." << endl;
				break;
			case 3:	cout << "The average salary is " << tsalary / count << "." << endl;
				break;
			case 4:	cout << "The total salary is " << tsalary << "." << endl;
				break;
		}
		cout << "Enter a choice: ";
		cin >> ans;
	}
	if (ans == 5 ) {
		cout << "Thank you for using the employee program." << endl;
		return 0;
	}
}

//readFile function; re-prompts user to input if input is invalid
bool readFile(int &count)
{
	char filename[100];

	ifstream fin;
	cout << "Enter the input file: ";
	cin >> filename;   //no longer limits the input to be input.txt only
	fin.open(filename);
	if (fin.fail())
	{
		cout << "Failed to open file. " << endl;
		return false;
	}
	char buf[100];
	string input;
	getline(fin, input);
	while (input != "" && !fin.fail())
	{
		getline(fin, input);
		count++;
	}
	if (allemployee != NULL)   //check if bad input is in memory
		delete[] allemployee;
	allemployee = new employee[count];
	
	fin.close();
	fin.open(filename);
	
	int i=0;
	while (!fin.fail())
	{
		if (!(fin >> allemployee[i].firstname >> allemployee[i].lastname >> allemployee[i].salary))
		{
			cout << "ERROR -- BAD DATA" << endl;
			return false;
		}
		fin.ignore(100, '\n');
		i++;
	}
return true;
}

void highsalary(int count)   //bubblesort the salaries
{
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count - 1; j++)
		{
			if (allemployee[j].salary > allemployee[j + 1].salary)
			{
				int temp = allemployee[j].salary;
				allemployee[j].salary = allemployee[j + 1].salary;
				allemployee[j + 1].salary = temp;
				string tempName = allemployee[j].firstname;
				allemployee[j].firstname = allemployee[j + 1].firstname;
				allemployee[j + 1].firstname = tempName;
				tempName = allemployee[j].lastname;
				allemployee[j].lastname = allemployee[j + 1].lastname;
				allemployee[j + 1].lastname = tempName;
			}
		}
	}
}

double totalsalary(int count)
{
	double totalsalary=0;
	for (int i=0; i < count; i++)
	{
		totalsalary += allemployee[i].salary;
	}
	return totalsalary;
}