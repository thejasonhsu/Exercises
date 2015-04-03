//========================================================
// getChars.cpp
// Echo characters from standard input to standard output
// ignoring whitespace until, a 'q' is seen.
//=========================================================
#include<iostream>
using namespace std;

//==============================>main<====================
int main(void)
{
  char c;
  cin>>c;
  while((not cin.fail())and(c!='q'))//quit if q
  {
   cout << "(" << c << ")";//write|c|
   cin>>c;
  }
}


    
