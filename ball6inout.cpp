//===========================================================
//ball6.cpp
//Code to compute the height and velocity of a ball
//launched with a given velocity on earth and mars Using Procedures
//and writing the output to an external file called "finaldataball6"
//===========================================================
#include <iostream>
#include <fstream>
using namespace std;

void trajectory(double g, double v0, double time,double&h,double&v);
void printVelocityHeight(double t, double v, double h,ostream&out);
void printSeparator(ostream & out);

//=====================>>main<<======================================
int main()
{                                          
   double gEarth=9.81;//acc on Earth
   double gMars=3.63;//acc on Mars

   ifstream infile("initDataball6"); // assume this worked
   double v0;
   infile >> v0;
   double t;
   infile >> t;
   infile.close(); // really should do this.

  

   //Open a file
   ofstream outfile("finaldataball6inout");

   //Results on Earth
   double v;//final velocity
   double h;//final height
   trajectory(gEarth,v0,t,h,v);

   printSeparator(outfile);
   outfile<<"Earth:"<<endl;
   printVelocityHeight(t,v,h,outfile);

   //Results on Mars
   trajectory(gMars,v0,t,h,v);

   printSeparator(outfile);
   outfile<<"Mars:"<<endl;
   printVelocityHeight(t,v,h,outfile);

   outfile.close(); // really should do this
   return 0;
}

 
//=================>>trajectory<<================================
//Computes height and velocity a ball reaches when subject to const GRAV ACC
//Arguments:
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
void printVelocityHeight(double t, double v, double h,ostream&out)

{
 out<< "The velocity at time " <<t<< " is "<< v <<endl;
 out<< "and the height is "<< h <<endl;
 return;
}

//===================>>printSeperator<<==========================
void printSeparator(ostream&out )
{
 out<<"===================================================="<<endl;
 return;
}
