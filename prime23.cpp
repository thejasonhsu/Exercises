#include <iostream>

using namespace std;

int main() {

int num;
int x;
int y;

cout << "Enter a natural number: ";
cin >> num;

if (num%2 != 0 && num%3 !=0) {
cout << "No. " << endl;
}

while (num % 2 == 0) {
num = num/2;
x = x + 1;
}

if (x >= 1) {
cout << "Yes. Twos=" << x << "." << endl;
}

while (num % 3 == 0) {
num = num/3;
y = y + 1;
}

if (y >= 1) {
cout << "Yes. Threes=" << y << "." << endl;
}

return 0;

}
