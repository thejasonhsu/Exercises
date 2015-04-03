#include <iostream>
using namespace std;

int sumeven(int N);

int main()
{
cout<<"Input the integer N:> ";
int N;
cin>>N;

cout<< "==========================="//
<< endl;
cout<< "The sum of the first " <<N<< " even integers on the real number line is "
<< sumeven(N) <<endl;

return N;
}

int sumeven(int N)
{
int sum = 0;
int counter = 2;
while(counter<2*N+1)
{
sum=sum+counter;
counter = counter+2;
}
return sum;
}