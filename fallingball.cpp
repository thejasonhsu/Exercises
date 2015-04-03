//==============================================================
//fallingball.cpp
//Simulates a ball falling through an atmosphere,subject
//to a constant gravitational force downward, and a quadratic
//friction force in a direction opposite to its velocity direction
//===============================================================
#include <iostream>
#include <fstream>
#include <cassert>
#include <cmath>
using namespace std;

void getInput(double & g, double & vTerm, double & v, double & dt, double & yFinal);
void oneStep(double g, double vTerm, double y, double v, double dt, double & yNext, double & vNext); 
double accel(double g, double vTerm, double v);

//==========>> main << =======================================
int main()
{
 double g;       //acceleration due to gravity
 double vTerm;   //terminal velocity
 double v;       //velocity
 double dt;      //time step
 double yFinal;  //final height of ball
 getInput(g, vTerm, v, dt, yFinal);

 // is data valid?
 assert(yFinal<0.0);

 //connect to a file
 ofstream out("trajectory.dat");

 double y=0.0;
 double t=0.0;
 while(y > yFinal)
  {
   out<<t<< " " <<y<< " " <<v<< endl;
   oneStep(g, vTerm, y, v, dt, y, v );
   t=t+dt;
  }
 cout<< "Done Output file written" <<endl;
 return 0;
}

//========================>> oneStep<<=========================================
//Takes one time step
//Arguments
//g - acceleration of gravity
//vTerm - terminal velocity
//y - current height
//v - current velocity
//dt - time step
//yNext - place to write next height
//vNext - place to write next velocity
//==============================================================================
void oneStep(double g, double vTerm, double y, double v, double dt, double & yNext, double & vNext)
{
 //compute velocity at half time step
 double vHalf = v+0.5*dt*accel(g, vTerm, v);

 //take a time step using data from half time step
 yNext=y+dt*vHalf;
 vNext=v+dt*accel(g, vTerm, vHalf);
}

//=====================>> accel <<=======================================
//Returns acceleration
//Arguments
// g    - acceleration due to gravity
// vTerm - terminal velocity of the object
// v     - velocity
//=========================================================================
double accel(double g, double vTerm, double v)
{
 return g*(-1.0 - v*v*v/(vTerm*vTerm*fabs(v)));
}

//=============>> getInput <<==============================================
//get input data
//Arguments
//g - acceleration of gravity
//vTerm - terminal velocity
//y - current height
//v - current velocity
//dt - time step size
//yFinal - height at which to stop simulation
//==========================================================================
void getInput(double & g, double & vTerm, double & v, double & dt, double & yFinal)
{
 cout<< "Input acceleration due to gravity :> ";
 cin>> g;

 cout<< "Input terminal velocity:> ";
 cin>> vTerm;

 cout<< "Input initial velocity:> ";
 cin>> v;

 cout<< "Input time step:> ";
 cin>> dt;

 cout<< "Input final height (negative):> ";
 cin>> yFinal;
}


