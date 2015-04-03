#include <iostream>

using namespace std;

int main() {

int num;
cout << "Enter an integer between 0 and 999: ";
cin >> num;

int one;
int ten;
int hun;

one = num%10;
ten = (num%100-num%10)/10;
hun = (num%1000-((num%100-num%10)/10))/100;

cout << "1's digit is " << one << endl;
cout << "10's digit is " << ten << endl;
cout << "100's digit is " << hun << endl;

return 0;
}

