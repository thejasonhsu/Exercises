#include<cassert>
using namespace std;

//Declare daysThisMonth for use in tomorrow
int daysThisMonth(int month,int year);


//===============>>tomorrow<<===============
//Returns the date of the day following the input date
//Arguments
//  day -input day of month (1-31,depending on month)
//  month -input month of year(1-12)
//  year -year
//  dayNext -day of month for following date
//  monthNext -month for the following date
//  yearNext -year for the following date
void tomorrow(int day,int month,int year,int & dayNext,
              int & monthNext,int & yearNext)
{
  int monthsInYear=12;
  int daysInMonth=daysThisMonth(month,year);

  assert(0<day and day<=daysInMonth);
  assert(0<month and month<=monthsInYear);
  assert(0<year);

  //typical case
  dayNext=day+1;
  monthNext=month;
  yearNext=year;

  //Month roll over
  if(dayNext>daysInMonth)
   {
     dayNext=1;
     monthNext=month+1;
   }

  //Year roll over
  if(monthNext>monthsInYear)
   {
     monthNext=1;
     yearNext=year+1;
   }
}

