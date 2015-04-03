//=====================================
//hiLo.cpp
//Plays the high low game
//=====================================
#include <iostream>
#include <cstdlib>
using namespace std;

int main(void)
{
  int max=100;//max number for guessing

  int seed;
  cout<< "Input a seed integer please :> ";
  cin>> seed;
  
  //get a somewhat random number between zero and max;
  srand(seed);
  int target=rand()%(max+1);

  cout<< "Guess a number between 0 and " << max << " :> ";
  int guess;
  cin>>guess;
  while(guess!=target)
   {
    cout<<guess<<" < target is "<< (guess<target)
        << endl;
    cout<<guess<<" > target is "<< (guess>target)
        << endl;
    cout<< "Guess a number between 0 and " << max << " :> ";
    cin>> guess;
   }
  cout<<"Congratulations.  "
      <<"You've just wasted a few minutes of your life";
  cout<<endl;
  return 0;
}

