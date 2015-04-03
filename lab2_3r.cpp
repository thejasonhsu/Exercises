#include <iostream>

using namespace std;

int main() {

int num;
int counter;
counter = 1;
cout << "Enter any integer: ";
cin >> num;

while (num > 0) {
cout << counter << "'s digit is " << num%10 << endl;
num=num/10;

counter *= 10;
}

return 0;
}

