#include<cassert>
using namespace std;

//=============>>daysThisMonth<<================
int daysThisMonth(int month,int year)
{
  assert(0<month and month<=12);//valid month?
  assert(0<year);               //valid year?

  if(month==1 or month==3 or month==5 or month==7 or
     month==8 or month==10 or month==12)
  {
     return 31;
  }
 
  if(month==4 or month==6 or month==9 or month==11)
  {
     return 30;
  }

  if(month==2)
   {
     if(year%4==0 and (year%100!=0 or year%400==0))
      {
        return 29;// a leap year
      }
     else
      {
        return 28;//not a leap year
      }
    }

  //should not get here, so fail if we do
   assert(false);
}



