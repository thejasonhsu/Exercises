//============daysThisMonthsw with switch statements for selection========
//Returns the number of days in a given month
//========================================================================
#include <cassert>
using namespace std;

int daysThisMonth(int month, int year)
{
  assert(0 < month and month <=12);//is the month valid?
  assert(0<year);               //valid year?

  int days=0;

  switch(month)
   {
    case1:      //January
    case3:      //March
    case5:      //May
    case7:      //July
    case8:      //August
    case10:     //October
    case12:     //December
     days=31;
     break;

    case4:      //April
    case6:      //June
    case9:      //September
    case11:     //November
     days=30;
     break;

    case2:
     if(year%4==0 and (year%100!=0 or year%400==0))
      {
        days= 29;// a leap year
      }
     else
      {
        days= 28;//not a leap year
      }
     break;
 
     default:
      assert(false);  
   }

  return days;
}
