#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
	int numbers[6] = {0, 0, 0, 0, 0, 0};
	int counter, numRolls;

	cout << "How many rolls of the die? ";
	cin >>  numRolls;

	srand(time(NULL));
	for (counter=0; counter < numRolls; counter++) {
		int roll = rand() % 6;
		numbers[roll] = numbers[roll] + 1;
	}

	for (counter=0; counter < 6; counter++) {
		cout << "The number " << (counter+1) << " was rolled " << numbers[counter] << " times. ";
		double percentage = ((double)numbers[counter] / (double)numRolls) * 100;
		cout << "(" << percentage << "%)" << endl;
	}
}

