//===========================================================
//ball5.cpp
//Code to compute the height and velocity of a ball
//launched with a given velocity on earth and mars Using Procedures
//===========================================================
#include <iostream>
using namespace std;

void trajectory(double g, double v0, double time,double&h,double&v);
void printVelocityHeight(double t, double v, double h);
void printSeparator();

//=====================>>main<<======================================
int main()
{                                          
   double gEarth=9.81;//acc on Earth
   double gMars=3.63;//acc on Mars

   cout<<"Input the initial velocity (m/s):> ";
   double v0;
   cin>>v0;

   cout<<"Input the initial time (s):> ";
   double t;
   cin>>t;

   //Results on Earth
   double v;//final velocity
   double h;//final height
   trajectory(gEarth,v0,t,h,v);

   printSeparator();
   cout<<"Earth:"<<endl;
   printVelocityHeight(t,v,h);

   //Results on Mars
   trajectory(gMars,v0,t,h,v);

   printSeparator();
   cout<<"Mars:"<<endl;
   printVelocityHeight(t,v,h);

   return 0;
}

 
//=================>>trajectory<<================================
//Computes heightand velocity a ball reaches when subject to const GRAV ACC
//Arguments
//g - grav acc  
//v0 - init vel
//time - time at which final velocity and height is sought
//h-final height (reference to container in caller)
//v-final velocity (reference to container in caller)
//============================================================
void trajectory(double g,double v0,double time,double&h,double&v)
{
  h=v0*time-g*time*time*0.5;
  v=v0-g*time;
}


//=================>>printVelocityHeight<<=====================
void printVelocityHeight(double t, double v, double h)

{
 cout<< "The velocity at time " <<t<< " is "<< v <<endl;
 cout<< "and the height is "<< h <<endl;
 return;
}

//===================>>printSeperator<<==========================
void printSeparator()
{
 cout<<"===================================================="<<endl;
 return;
}




