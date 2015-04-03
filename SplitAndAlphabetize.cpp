#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int main() {

	char str_teams[100];
	cout << "Enter a list of teams: ";
//	cin >> str_teams;
	fgets(str_teams, sizeof(str_teams), stdin);

	cout << strtok(str_teams, " ") << endl;
	cout << strtok(NULL, " ") << endl;
	cout << strtok(NULL, " ") << endl;
	cout << strtok(NULL, " ") << endl;
	cout << strtok(NULL, " ") << endl;



	return 1;
}