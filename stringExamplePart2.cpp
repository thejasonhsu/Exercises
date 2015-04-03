//=======================================================
//stringExamplePart2.cpp
//More games with strings
//=======================================================
#include<string>
#include<iostream>
using namespace std;

//Declare procedures
void lookFor(const string & s, const string & pattern);

//=========================>> main <<======================
int main()
{
 //declare some strings
 string name("Eowyn");
 string fathername("Edmund");
 string relation;
 
 relation.append(name);
 relation.append(" daughter of "); 
 relation.append(fathername);

 cout<<relation<<endl;

 cout<<"There are "<<name.size()<<" characters in "
     <<name<<endl;

 string pattern("i");
 lookFor(name,pattern);

 pattern="e";
 lookFor(name,pattern);  

 pattern="E";
 lookFor(name,pattern); 
 
 pattern="bitter";
 lookFor(relation,pattern); 

 pattern="aug";
 lookFor(relation,pattern);

 return 0;
}

//====================>>lookFor<<======================
//Looks for a match to the pattern in the string s
void lookFor(const string & s, const string & pattern)
{
 if(s.npos==s.find(pattern))
  {
   cout<<"There is no \""<<pattern<<"\" in "<<s<<endl;  
  }
 else
  {
   cout<<"Found an  \""<<pattern<<"\" in "<<s<<endl;  
  }
}
          
