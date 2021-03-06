#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;
double squareRoot(double, double);
int main()
{
    double x, eps;
    cout << "Input a number and a residual: ";
    cin >> x >> eps;
    double ans = squareRoot(x, eps);
    cout << "Answer: " << ans << endl;
    return 0;
}
double squareRoot(double x, double eps)
{
    assert(x >= 0);
    double rold = 1.0;
    double rold2 = (rold * rold + x)/(2.0 * rold);
    double residual = abs(rold2 - rold);
    while(residual > eps)
    {
        rold2 = (rold * rold + x)/(2.0 * rold);
        residual = abs(rold2 - rold);
        rold = rold2;
    }
    return rold;
}