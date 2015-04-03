#include <iostream>

using namespace std;

int main() {

int n;
int a;
int b;

cout << "Enter the number of rows: ";
cin >> n;

for (int a=0; a < n; a++) {
	for (int b=0; b <= a; b++) {
	cout << "*";
	}
cout << endl;
}

return 0;
}
