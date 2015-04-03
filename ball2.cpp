//==================================================
//ball2.cpp
//Code to compute the eventual overall height and velocity of a ball
//launched with given initial velocity on Earth and Mars




#include <iostream>
using namespace std;

int main()
{
   double g=9.81;//acceleration due to gravity

   cout<<"Input the initial velocity (m/s):> ";
   double v0;
   cin>> v0 ;

   cout<< " Input the time (s):> ";
   double t;
   cin>> t;
   
   //Results on Earth
   cout<< "==========================="//
       << endl;
   cout<< "Earth:"<<endl;
   cout<< "The velocity at time " <<t<< " is "
       << v0 - g*t <<endl;

   cout<< "and the height is "
       << v0*t - (g*t*t)/2 << endl;

   //Results on Mars
   g=3.63;//Acceleration due to gravity on Mars
   cout<< "==========================="//
       << endl;
   cout<< "Mars:"<<endl;
   cout<< "The velocity at time " <<t<< " is "
       << v0 - g*t <<endl;

   cout<< "and the height is "
       << v0*t - (g*t*t)/2 << endl;

   return 0;
}
