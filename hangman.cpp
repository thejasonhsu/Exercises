// hangman.cpp
// Hangman game illustrates string library functions, 
// character arrays, arrays of pointers, etc.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;
int num = 0;
// Prototype
bool processGuess(char* word, const char* targetWord, char guess);

// Define an array of strings (since a string is just a char array)
//  and since string are just char *'s, we really want an array of char *'s
const char *wordBank[] = {"computer","president","trojan","program","coffee",
			  "library","football","popcorn","science","engineer"};

const int numWords = 10;

int main()
{
  srand(time(0));
  char guess;
  bool wordGuessed = false;
  int n = 10;
 

  // Pick a random word from the wordBank
  const char* targetWord = wordBank[rand()%10];

  // More initialization code as needed
  char word[80];  // a blank array to use to build up the answer
                  // It should be initialized with *'s and then
                  //  change them to the actual letters when the 
                  //  user guesses the letter
  for (int i=0; i < strlen(targetWord); i++) {
	  word[i]='*';
  }
 
  
  while (strncmp(targetWord, word, strlen(targetWord))!=0 && n > 0) {
	  
	  cout << "Current word:" << word << " " << endl;
	  cout << n << " remain... Enter a letter to guess:" << endl;
	  cin >> guess;
	  if( ! processGuess(word, targetWord, guess))
		n--;
  }
  
  if (strncmp(targetWord, word, strlen(targetWord))==0 && n >= 0) {
	  cout << "The word was " << targetWord << ". You win!" << endl;
  }
  else if (n == 0) {
	  cout << "Too many turns... You lose!" << endl;
  }
  
  // An individual game continues until a word
  //  is guessed correctly or 10 turns have elapsed

  // Print out end of game status
  return 0;
}

// Given the current version of the word, target/selected word, and
// the character that the user just guessed, change the word to 
// "turn on" any occurrences the guess character and return a count
// of how many occurrences of 'guess' were found
bool processGuess(char* word, const char* targetWord, char guess) {
	bool t = false;
	for (int i=0; i < strlen(targetWord); i++) {
		if (guess == targetWord[i]) {
			word[i]=guess;
			t = true;
		}
	}
	return t;
}