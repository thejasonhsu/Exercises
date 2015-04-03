//=================================================
//dayTomorrow.cpp
//Code reports the date following the input date,in
//day month year fromat. Loops until invalid input
//is provided
//==================================================
#include<iostream>
using namespace std;

void tomorrow(int day,int month,int year,
              int & dayNext,int & monthNext,int & yearNext);

//================>>main<<===========================
int main()
{
 //get initial input 
 cout<< "Input day month year (seperated by spaces) :>";
 int day;
 cin>>day; 
 int month;
 cin>>month; 
 int year;
 cin>>year; 

 while(not cin.fail())
  {
     //Figure out next day
     int dayNext;
     int monthNext;
     int yearNext;
     tomorrow(day,month,year,dayNext,monthNext,yearNext);

     //Show it to user
     cout<< " After "<<day<<" "<<month<<" "<<year;
     cout<< " there follows the glorious day ";                                
     cout<< dayNext <<" "<<monthNext<<" "<<yearNext; 
     cout<<endl<<endl;


     //get input for next go around
     cout<< " Input day month year (seperated by spaces) :> ";
     cin>>day;
     cin>>month;
     cin>>year;
  }
  cout<< "Thanks for the interest in the calendar."<<endl;

  return 0;
}



