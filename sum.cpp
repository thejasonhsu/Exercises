//===========================================================
//sum.cpp
//Code to compute the sum of the integers which are the integer
//predecessors that lead up to a specific integer N on the positive
//real number line as defined in real space
//===========================================================
#include <iostream>
using namespace std;

int sum(int N);

//===========================================================
int main()
{
   //get the integer N as input from the human implementing the program
   cout<<"Input the integer N:> ";
   int N;
   cin>>N;

   //Results of the sum
   cout<< "==========================="//
       << endl;
   cout<< "The sum of the integers which are the integer"
       <<  " predecessors that lead up to the specific integer " <<N<< " is "
       << sum(N) <<endl;
  
   return 0;
}

//=================>>sum<<================================
//Returns the sum of the integers which are the integer
//predecessors that lead up to a specific integer N on the positive
//real number line as defined in real space
//============================================================
int sum(int N)
{
  int sum = 0;
  int counter = 1;
  while(counter<N+1)
   {
    sum=sum+counter;
    counter = counter+1;
   }
  return sum;
} 
