// Card Game of War
// Jason Hsu

#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
#include <time.h>

using namespace std;

string cards[52] = {"Ace of Clubs","Ace of Diamonds","Ace of Hearts","Ace of Spades", "2 of Clubs", "2 of Diamonds", "2 of Hearts", "2 of Spades", "3 of Clubs", "3 of Diamonds", "3 of Hearts", "3 of Spades", "4 of Clubs", "4 of Diamonds", "4 of Hearts", "4 of Spades", "5 of Clubs", "5 of Diamonds", "5 of Hearts", "5 of Spades", "6 of Clubs", "6 of Diamonds", "6 of Hearts", "6 of Spades", "7 of Clubs", "7 of Diamonds", "7 of Hearts", "7 of Spades", "8 of Clubs", "8 of Diamonds", "8 of Hearts", "8 of Spades", "9 of Clubs", "9 of Diamonds", "9 of Hearts", "9 of Spades", "10 of Clubs", "10 of Diamonds", "10 of Hearts", "10 of Spades", "Jack of Clubs", "Jack of Diamonds", "Jack of Hearts", "Jack of Spades", "Queen of Clubs", "Queen of Diamonds", "Queen of Hearts", "Queen of Spades", "King of Clubs", "King of Diamonds", "King of Hearts", "King of Spades"};

void shuffle();

void shuffle(string *ncards, int size) {
    srand(time(NULL));
		for (int k=0; k < size; k++) {
			int a = rand()%(size);
			string temp=ncards[a];  //store random card in temp string
			ncards[a]=ncards[k];    //create new deck by placing the random card in one by one
			ncards[k]=temp;
		}
}

void deal(string *deck1, string *deck2, string *ncards, int size) {
    for (int l = 0; l < size/2; l++){
        deck1[l] = ncards[l];   //up to half of the shuffled deck gets stored in deck1
        deck2[l] = ncards[size-l-1];   //the half after the already stored deck1 gets stored in deck2
    }
}

int main() {

	int ndecks;
	int q = 0;  //counters for statistics at the end
	int w = 0;
	int e = 0;
	int r = 0;
	int t = 0;
	int y = 0;

	cout << "How many decks are being used? ";
	cin >> ndecks;
	if (ndecks == 0 || ndecks < 0) {
		cout << "Invalid number of decks." << endl;
		return 0;
    }

    string *ncards = new string[52*ndecks];
    
    int numdecks=0;
    for (int i=0; i < ndecks; i++) {
        for (int j=0; j < 52; j++) {
            ncards[numdecks]=cards[j];
            numdecks++;
        }
    }

    shuffle(ncards,52*ndecks);

    string *deck1 = new string[52*ndecks];  
    string *deck2 = new string[52*ndecks];
    //setting array size large so that new elements can always be stored
    
	int size1 = 26*ndecks;  
	int size2 = 26*ndecks;

    deal(deck1,deck2,ncards,52*ndecks);

    string ans;
    cout << "Would you like to watch the game? (y/n) ";
    cin >> ans;
    if (ans!="y" && ans!="n") {
    	cout << "Invalid input. " << endl;  //input error checking
    }
    if (ans=="y") {
        cout << "Player 1 now has " << size1 << " cards." << endl;
        cout << "Player 2 now has " << size2 << " cards." << endl;
        	while (size1 != 0 && size2 != 0) {
        		cout << "Hand #" << ++q << endl;
        		cout << "Player 1: " << deck1[q-1] << deck1[0] << endl;
        		cout << "Player 2: " << deck2[q-1] << deck2[0] << endl;
        		char d = deck1[q-1].at(0);  //pick out the first char of each element in the arrays
        		char f = deck2[q-1].at(0);
        			if (d=='A') {               //assign ascii values in correct order for comparison
        					d = '0';
        				}
        			else if (d=='K') {
        					d = 'L';
        				}
        			else if (d=='Q') {
        					d = 'K';
        				}
        			if (f=='A') {
        					f = '1';
        				}
        			else if (f=='K') {
        					f = 'L';
        				}
        			else if (f=='Q') {
        					f = 'K';
        				}
        			if (d>f) {
        				deck1[26*ndecks+q*ndecks-1]=deck2[q*ndecks-1];  //store current card from deck2 to new element in deck1
        				cout << "Player 1 wins." << endl;
        				cout << endl;
        				cout << "Player 1 now has " << size1+1 << " cards." << endl;
        				cout << "Player 2 now has " << size2-1 << " cards." << endl;
        				cout << endl;
        				cout << "--------------------------" << endl;
        				cout << endl;
        				e++;
        				size1 = size1 + 1;
        				size2 = size2 - 1;
        			}
        			else if (f>d) {
        				deck2[26*ndecks+q*ndecks-1]=deck1[q*ndecks-1];    //store current card from deck1 to new element in deck2
        				cout << "Player 2 wins." << endl;
        				cout << endl;
        				cout << "Player 1 now has " << size1-1 << " cards." << endl;
        				cout << "Player 2 now has " << size2+1 << " cards." << endl;
        				cout << endl;
        				cout << "--------------------------" << endl;
        				cout << endl;
        				r++;
        				size1 = size1 - 1;
        				size2 = size2 + 1;
        			}
        			else if (d==f) {
        				if (size1 < 3) { 
        					cout << "Player 1 does not have 3 cards to place down." << endl;
        					cout << endl;
        					cout << "Player 2 wins." << endl; 
        					cout << endl;
        					cout << "--------------------------" << endl;
        					cout << "Player 2 WINS the game!" << endl;
        					cout << "--------------------------" << endl;
        					cout << endl;
        					cout << "Statistics" << endl;
        					cout << endl;
        					cout << "Number of Hands: " << q << endl;
        					cout << "Number of Hands Player 1 Won: " << e << " (" << ((double)e/(double)q*100) << "%)" << endl;
        					cout << "Number of Hands Player 2 Won: " << r << " (" << ((double)r/(double)q*100) << "%)" << endl;
        					cout << "Number of War Hands: " << w << " (" << ((double)w/(double)q*100) << "%)" << endl;
        					cout << "Number of War Hands Player 1 Won: " << t << " (" << ((double)t/(double)w*100) << "%)" << endl;
        					cout << "Number of War Hands Player 2 Won: " << y << " (" << ((double)y/(double)w*100) << "%)" << endl;
        					return 0;
        				}
        				if (size2 < 3) { 
        					cout << "Player 2 does not have 3 cards to place down." << endl;
        					cout << endl;
        					cout << "Player 1 wins." << endl; 
        					cout << endl;
        					cout << "--------------------------" << endl;
        					cout << "Player 1 WINS the game!" << endl;
        					cout << "--------------------------" << endl;
        					cout << endl;
        					cout << "Statistics" << endl;
        					cout << endl;
        					cout << "Number of Hands: " << q << endl;
        					cout << "Number of Hands Player 1 Won: " << e << " (" << ((double)e/(double)q*100) << "%)" << endl;
        					cout << "Number of Hands Player 2 Won: " << r << " (" << ((double)r/(double)q*100) << "%)" << endl;
        					cout << "Number of War Hands: " << w << " (" << ((double)w/(double)q*100) << "%)" << endl;
        					cout << "Number of War Hands Player 1 Won: " << t << " (" << ((double)t/(double)w*100) << "%)" << endl;
        					cout << "Number of War Hands Player 2 Won: " << y << " (" << ((double)y/(double)w*100) << "%)" << endl;
        					return 0;
        				}
        				cout << endl;
        				cout << "War!" << endl;
        				cout << endl;
        				cout << "Player 1 places 3 cards down." << endl;
        				cout << "Player 2 places 3 cards down." << endl;
        				cout << endl;
        				while (d==f) {  //going to "war" loop
        					w++;
        					deck1[q++];
        					deck2[q++];
        	        		d = deck1[q].at(0);  //assign new chars for new cards being drawn
        	        		f = deck2[q].at(0); 
        					if (d>f) {
        						deck1[26*ndecks+q*ndecks-1]=deck2[q*ndecks-1];  //removing 1+3+1 cards from one array and storing them into the other array
        						deck1[26*ndecks+q*ndecks]=deck2[q*ndecks-2];
        						deck1[26*ndecks+q*ndecks+1]=deck2[q*ndecks-3];
        						deck1[26*ndecks+q*ndecks+2]=deck2[q*ndecks-4];
        						deck1[26*ndecks+q*ndecks+3]=deck2[q*ndecks-5];
        						cout << "Player 1: " << deck1[q] << endl;
        						cout << "Player 2: " << deck2[q] << endl;
        						cout << "Player 1 wins." << endl;
        						cout << endl;
        						cout << "Player 1 now has " << size1+2+3*w << endl;
        						cout << "Player 2 now has " << size2-2-3*w << endl;
        						cout << endl;
        						cout << "--------------------------" << endl;
        						cout << endl;
                				size1 = size1 + 2+3*w;
                				size2 = size2 - 2-3*w;
        						e++;
        						t++;
        					}
        					else if (f>d) {
        						deck2[26*ndecks+q*ndecks-1]=deck1[q*ndecks-1];
        						deck2[26*ndecks+q*ndecks]=deck1[q*ndecks-2];
        						deck2[26*ndecks+q*ndecks+1]=deck1[q*ndecks-3];
        						deck2[26*ndecks+q*ndecks+2]=deck1[q*ndecks-4];
        						deck2[26*ndecks+q*ndecks+3]=deck1[q*ndecks-5];
        						cout << "Player 1: " << deck1[q] << endl;
        						cout << "Player 2: " << deck2[q] << endl;
        						cout << "Player 2 wins." << endl;
        						cout << endl;
        						cout << "Player 1 now has " << size1-2-3*w << endl;
        						cout << "Player 2 now has " << size2+2+3*w << endl;
        						cout << endl;
        						cout << "--------------------------" << endl;
        						cout << endl;
                				size1 = size1 - 2-3*w;
                				size2 = size2 + 2+3*w;
        						r++;
        						y++;
        					}
        				}
        			}
        	}
        	if (size1 == 0 || size1 < 0) {
        		cout << endl;
        		cout << "--------------------------" << endl;
        		cout << "Player 2 WINS the game!" << endl;
        		cout << "--------------------------" << endl;
        		cout << endl;
        	}
        	if (size2 == 0 || size2 < 0) {
        		cout << endl;
        		cout << "--------------------------" << endl;
        		cout << "Player 1 WINS the game!" << endl;
        		cout << "--------------------------" << endl;
        		cout << endl;
        	}
        	cout << "Statistics" << endl;
        	cout << endl;
        	cout << "Number of Hands: " << q << endl;
        	cout << "Number of Hands Player 1 Won: " << e << " (" << ((double)e/(double)q*100) << "%)" << endl;
        	cout << "Number of Hands Player 2 Won: " << r << " (" << ((double)r/(double)q*100) << "%)" << endl;
        	cout << "Number of War Hands: " << w << " (" << ((double)w/(double)q*100) << "%)" << endl;
        	cout << "Number of War Hands Player 1 Won: " << t << " (" << ((double)t/(double)w*100) << "%)" << endl;
        	cout << "Number of War Hands Player 2 Won: " << y << " (" << ((double)y/(double)w*100) << "%)" << endl;
        	return 0;
    	}
    if (ans=="n") {
        	while (size1 != 0 && size2 != 0) {
        		char d = deck1[q-1].at(0);  
        		char f = deck2[q-1].at(0);
        			if (d=='A') {           
        					d = '0';
        				}
        			else if (d=='K') {
        					d = 'L';
        				}
        			else if (d=='Q') {
        					d = 'K';
        				}
        			if (f=='A') {
        					f = '1';
        				}
        			else if (f=='K') {
        					f = 'L';
        				}
        			else if (f=='Q') {
        					f = 'K';
        				}
        			if (d>f) {
        				deck1[26*ndecks+q*ndecks-1]=deck2[q*ndecks-1];
        				size1 = size1 + 1;
        				size2 = size2 - 1;
        				e++;
        			}
        			else if (f>d) {
        				deck2[26*ndecks+q*ndecks-1]=deck1[q*ndecks-1];
        				size1 = size1 - 1;
        				size2 = size2 + 1;
        				r++;
        			}
        			else if (d==f) {
        				if (size1 < 3) { 
        					cout << "--------------------------" << endl;
        					cout << "Player 2 WINS the game!" << endl;
        					cout << "--------------------------" << endl;
        					cout << endl;
        					cout << "Statistics" << endl;
        					cout << endl;
        					cout << "Number of Hands: " << q << endl;
        					cout << "Number of Hands Player 1 Won: " << e << " (" << ((double)e/(double)q*100) << "%)" << endl;
        					cout << "Number of Hands Player 2 Won: " << r << " (" << ((double)r/(double)q*100) << "%)" << endl;
        					cout << "Number of War Hands: " << w << " (" << ((double)w/(double)q*100) << "%)" << endl;
        					cout << "Number of War Hands Player 1 Won: " << t << " (" << ((double)t/(double)w*100) << "%)" << endl;
        					cout << "Number of War Hands Player 2 Won: " << y << " (" << ((double)y/(double)w*100) << "%)" << endl;
        					return 0;
        				}
        				if (size2 < 3) { 
        					cout << "--------------------------" << endl;
        					cout << "Player 1 WINS the game!" << endl;
        					cout << "--------------------------" << endl;
        					cout << endl;
        					cout << "Statistics" << endl;
        					cout << endl;
        					cout << "Number of Hands: " << q << endl;
        					cout << "Number of Hands Player 1 Won: " << e << " (" << ((double)e/(double)q*100) << "%)" << endl;
        					cout << "Number of Hands Player 2 Won: " << r << " (" << ((double)r/(double)q*100) << "%)" << endl;
        					cout << "Number of War Hands: " << w << " (" << ((double)w/(double)q*100) << "%)" << endl;
        					cout << "Number of War Hands Player 1 Won: " << t << " (" << ((double)t/(double)w*100) << "%)" << endl;
        					cout << "Number of War Hands Player 2 Won: " << y << " (" << ((double)y/(double)w*100) << "%)" << endl;
        					return 0;
        				}
        				while (d==f) {  //going to "war" loop
        	        		d = deck1[q].at(0);  
        	        		f = deck2[q].at(0); 
        					w++;
        					if (d>f) {
        						deck1[26*ndecks+q*ndecks-1]=deck2[q*ndecks-1]; 
        						deck1[26*ndecks+q*ndecks]=deck2[q*ndecks-2];
        						deck1[26*ndecks+q*ndecks+1]=deck2[q*ndecks-3];
        						deck1[26*ndecks+q*ndecks+2]=deck2[q*ndecks-4];
        						deck1[26*ndecks+q*ndecks+3]=deck2[q*ndecks-5];
                				size1 = size1 + 2+3*w;
                				size2 = size2 - 2-3*w;
        						e++;
        						t++;
        					}
        					else if (f>d) {
        						deck2[26*ndecks+q*ndecks-1]=deck1[q*ndecks-1];
        						deck2[26*ndecks+q*ndecks]=deck1[q*ndecks-2];
        						deck2[26*ndecks+q*ndecks+1]=deck1[q*ndecks-3];
        						deck2[26*ndecks+q*ndecks+2]=deck1[q*ndecks-4];
        						deck2[26*ndecks+q*ndecks+3]=deck1[q*ndecks-5];
                				size1 = size1 - 2-3*w;
                				size2 = size2 + 2+3*w;
        						r++;
        						y++;
        					}
        				}
        			}
        	}
        	if (size1 == 0 || size1 < 0) {
        		cout << endl;
        		cout << "--------------------------" << endl;
        		cout << "Player 2 WINS the game!" << endl;
        		cout << "--------------------------" << endl;
        		cout << endl;
        	}
        	if (size2 == 0 || size2 < 0) {
        		cout << endl;
        		cout << "--------------------------" << endl;
        		cout << "Player 1 WINS the game!" << endl;
        		cout << "--------------------------" << endl;
        		cout << endl;
        	}
        	cout << "Statistics" << endl;
        	cout << endl;
        	cout << "Number of Hands: " << q << endl;
        	cout << "Number of Hands Player 1 Won: " << e << " (" << ((double)e/(double)q*100) << "%)" << endl;
        	cout << "Number of Hands Player 2 Won: " << r << " (" << ((double)r/(double)q*100) << "%)" << endl;
        	cout << "Number of War Hands: " << w << " (" << ((double)w/(double)q*100) << "%)" << endl;
        	cout << "Number of War Hands Player 1 Won: " << t << " (" << ((double)t/(double)w*100) << "%)" << endl;
        	cout << "Number of War Hands Player 2 Won: " << y << " (" << ((double)y/(double)w*100) << "%)" << endl;
        	return 0;
    	}
}
