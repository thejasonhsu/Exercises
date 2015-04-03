// wscramble.cpp
// Word Scramble guessing game
// Illustrates string library functions, character arrays,
//  arrays of pointers, etc.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>
#include <vector>

#define MAX_CHARACTERS 41

using namespace std;

// Prototype
void permute(string & item);

// Define an array of strings (since a string is just a char array)
//  and since string are just char *'s, we really want an array of char *'s

const int numWords = 10;

int main()
{
	string wordBank[numWords];
	char filename[100];
	ifstream fin;
	cout << "Enter the filename of your wordbank: ";
	cin >> filename;
	fin.open(filename);
		if (fin.fail()) {
	       cout << "Failed to open file. " << endl;
	       return 0;
	    }
	if(fin.is_open())
	{
	
	for(int i = 0; i < numWords; i++){
		fin >> wordBank[i];
		//cout << wordBank[i] << " ";
	}
	}
	
	int size = atoi(wordBank[0].c_str());
	cout << wordBank[0] << endl;
	wordBank[0] = wordBank[(sizeof(wordBank)/sizeof(string))-1];

  srand(time(0));
  char guess[80];

  bool wordGuessed = false;
  int numTurns = 10;
 

  // Pick a random word from the wordBank
  int target = (rand() % size) + 1;
 
 // std::cout << target << endl;
  int targetLen = 41;//strlen(wordBank[target]);

  // More initialization code
  //char* word = new char[targetLen+1];
  string word;
 
  word = wordBank[target];
 
  permute(word);

  // An individual game continues until a word
  //  is guessed correctly or 10 turns have elapsed
  while ( !wordGuessed && numTurns > 0 ){
    cout << "\nCurrent word:  " << word << endl;
    cin >> guess;
    wordGuessed = (guess ==wordBank[target]);
    numTurns--;
  }
  
  if(wordGuessed) {
    cout << "You win!" << endl;
  }
  
  else {
    cout << "Too many turns...You lose!" << endl;
  }
  
  //delete [] word;
  return 0;
}

// Scramble the letters
void permute(string & str)
{
	int x = str.length();
    for(int y = x; y > 0; y--) 
    { 
        int pos = rand()%x;
        char tmp = str[y-1];
        str[y-1] = str[pos];
        str[pos] = tmp;
    }
}