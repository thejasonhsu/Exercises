//===========================================================
//ball4.cpp
//Code to compute the height and velocity of a ball
//launched with a given velocity on earth and mars Using Functions
//===========================================================
#include <iostream>
using namespace std;

double height(double g, double v, double time);
double velocity(double g, double v, double time);

//===========================================================
int main()
{
   //define accelerations due to gravity
   double gEarth=9.81;//acc on Earth
   double gMars=3.63;//acc on Mars

   cout<<"Input the initial velocity (m/s):> ";
   double v0;
   cin>>v0;

   cout<<"Input the initial time (s):> ";
   double t;
   cin>>t;

   //Results on Earth
   cout<< "==========================="//
       << endl;
   cout<< "Earth:"<<endl;
   cout<< "The velocity at time " <<t<< " is "
       << velocity(gEarth,v0,t) <<endl;

   cout<< "and the height is "
       << height(gEarth,v0,t) << endl;

   //Results on Mars
   //Acceleration due to gravity on Mars
   cout<< "==========================="//
       << endl;
   cout<< "Mars:"<<endl;
   cout<< "The velocity at time " <<t<< " is "
       <<velocity(gMars,v0,t)  <<endl;

   cout<< "and the height is "
       << height(gMars,v0,t) << endl;

   return 0;
}

 
//=================>>height<<================================
//Returns height a ball reaches when subject to const GRAV ACC
//g - grav acc
//v - init vel
//time - time at which height is sought
//============================================================
double height(double g,double v,double time)
{
  double h; //height ball will reach
  h=v*time-g*time*time*0.5;
  return h;
}


//=================>>velocity<<================================
//Returns velocity a ball reaches when subject to const GRAV ACC
//g - grav acc
//v - init vel
//time - time at which velocity is sought
//============================================================
double velocity(double g,double v,double time)
{
  double vf; //final vel the ball will reach
  vf=v-g*time;
  return vf;
}

