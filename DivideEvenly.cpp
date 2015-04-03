#include <iostream>

using namespace std;

// function prototypes
int get_number();

// function implementations
int get_number() {
	int value;
	cout << "Enter a positive integer: ";
	cin >> value;

	// error checking needed here

	return value;
}

// if divide_even==1, check to see if the number divides evenly
// if divide_even==0, check to see numbers that do not divide evenly
void print_divide_evenly(int number, int divide_even) {
	cout << "Numbers that ";
	if (divide_even == 0) {
		cout << " do not ";
	}
	cout << "divide " << number << " evenly: ";
	for (int i=1; i < number; i++) {
		// if this is true, i divides number evenly
		if ((divide_even == 1 && number % i == 0) || (divide_even == 0 && number % i != 0)) {
			cout << i << ", ";
		}
	}
	cout << endl;
}

int main() {

	int num = get_number();

    print_divide_evenly(num, 1);
    print_divide_evenly(num, 0);
	return 1;
}
