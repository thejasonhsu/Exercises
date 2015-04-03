#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

int main() {

int n = 30;
int x;
double theta;
int i;

cout << "Enter the value of theta between 15 and 75: ";
cin >> x;
if (x < 15 || x > 75) {
cout << "Invalid theta value." << endl;
return 0;
}

theta=x*3.14159/180;

for (int a=0; a < n; a++) {
	i = floor(a*tan(theta));
	if (i >= 20 && i <= 30) {
		cout << "********************";
		}
	else {
		for (int b=0; b <= i; b++) {		
			cout << "*";
			}
	}
cout << endl;
}

return 0;
}
