#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

	cout << "Enter the first number: ";
	int num1;
	cin >> num1;

	cout << "Enter the second number: ";
	int num2;
	cin >> num2;

	cout << "(+) Addition" << endl;
	cout << "(-) Subtraction" << endl;
	cout << "(x) Multiplication" << endl;
	cout << "(/) Division" << endl;
	cout << "(%) Modulus" << endl;
	cout << "What operation would you like? ";
	char operation;
	cin >> operation;

	switch (operation) {
	  case '+':
		  cout << num1 << " + " << num2 << " = " << (num1 + num2) << endl;
		  break;
	  case '-':
		  cout << num1 << " - " << num2 << " = " << (num1 - num2) << endl;
		  break;
	  case 'x':
		  cout << num1 << " x " << num2 << " = " << (num1 * num2) << endl;
		  break;
	  case '/':
		  cout << num1 << " / " << num2 << " = " << (num1 / num2) << endl;
		  break;
	  case '%':
		  cout << num1 << " % " << num2 << " = " << (num1 % num2) << endl;
		  break;
	  default:
		  cout << "I don't know that operator." << endl;
	}

}
