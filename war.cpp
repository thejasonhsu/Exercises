#include <iostream>
#include <cstdlib>
#include <ctime>
#include "deck.h"
#include "card.h"
#include "warplayer.h"

using namespace std;

void addCardsWon(WarPlayer &player, Card tiedCards[], int count);

int main(int argc, char* argv[])
{
  if(argc < 3){
    cout << "Provide number of games to simulate and 1=debug, 0=no debug " << endl;
    return 1;
  }
  srand(time(0));
  int numSims = atoi(argv[1]);
  bool debug = atoi(argv[2]);
  int numBattles = 0;
  int numWars = 0;
  int p1Wins = 0;
  int p2Wins = 0;
  for(int i=0; i < numSims; i++){

    // Write your single game of War code here (or decompose 
    // the single game into smaller functions that you write)
    // We've started things for you

    // Declare and prepare your deck then print it out to double check
    Deck d;
    d.shuffle();
    d.cut();
    if(debug){
      d.printDeck();
    }

    // Declare the two players and deal the cards to the two players

	WarPlayer player1, player2;
	for (int i = 0; i < 52; i += 2)
	{
		player1.addCard(d.getTop());
		player2.addCard(d.getTop());
	}

    // Write a loop that plays one turn at a time, until the game is over
    // Remember each player takes their top card, compares them, and the
    //  player with the greater-valued card gets back both
    // If there is a tie, each player flips one more card (provided they have
    //  one more), with the player with the greater-valued 2nd card getting
    //  all the cards.  If they don't have one more to flip, that player 
    //  immediately loses

    // Be sure to update the statistics variables, numBattles, numWars,
    //  p1Wins, p2Wins, etc.

	int count, handsPlayed = 0;
	Card tiedCards[52], c1, c2;
	while (player1.hasCardsRemaining() && player2.hasCardsRemaining())
	{
		count = 0;
		if (handsPlayed % 2 == 0)
		{
			c1 = tiedCards[count] = player1.removeTopCard();
			c2 = tiedCards[count + 1] = player2.removeTopCard();
		}
		else
		{
			c2 = tiedCards[count] = player2.removeTopCard();
			c1 = tiedCards[count + 1] = player1.removeTopCard();
		}
		handsPlayed++;
		count += 2;

		if (debug)
		{
			cout << " PLAY - " << c1.toString() << " " << c2.toString() << endl;
			cout << " SIZE - " << player1.size() << " " << player2.size() << endl;
		}

		if (c1.compare(c2) > 0)	// Player 1 Wins.
			addCardsWon(player1, tiedCards, count);
		else if (c1.compare(c2) < 0) // Player 2 Wins.
			addCardsWon(player2, tiedCards, count);
		else // TIE
		{
			while (player1.hasCardsRemaining() && player2.hasCardsRemaining() && c1.compare(c2) == 0)
			{
				numWars++;
				for (int j = 0; j < 3; j++)
				{
					c1 = tiedCards[count] = player1.removeTopCard();
					c2 = tiedCards[count + 1] = player2.removeTopCard();
					count += 2;
					if (debug)
					{
						cout << " TIE PLAY - " << c1.toString() << " " << c2.toString() << endl;
						cout << " TIE SIZE - " << player1.size() << " " << player2.size() << endl;
					}
				}

				if (!player1.hasCardsRemaining()) // NO MORE CARDS, PLAYER 1?
					addCardsWon(player2, tiedCards, count);
				else if (!player2.hasCardsRemaining()) // NO MORE CARDS, PLAYER 2?
					addCardsWon(player1, tiedCards, count);
				else // STILL A TIE WITH CARDS TO GO?
				{
					c1 = tiedCards[count] = player1.removeTopCard();
					c2 = tiedCards[count + 1] = player2.removeTopCard();
					count += 2;

					if (debug)
					{
						cout << " WAR PLAY - " << c1.toString() << " " << c2.toString() << endl;
						cout << " WAR SIZE - " << player1.size() << " " << player2.size() << endl;
					}

					if (c1.compare(c2) > 0)	// Player 1 Wins.
						addCardsWon(player1, tiedCards, count);
					else if (c1.compare(c2) < 0) // Player 2 Wins.
						addCardsWon(player2, tiedCards, count);
				}
			}
		}
		numBattles++;
	} 

	if (player1.hasCardsRemaining())
		p1Wins++;
	else
		p2Wins++;

  } // end for
  // Print statistics
  cout << "Total Battles = " << static_cast<double>(numBattles)/numSims << endl;
  cout << "Total Wars = " << static_cast<double>(numWars)/numSims << endl;
  cout << "P1 wins = " << p1Wins << endl;
  cout << "P2 wins = " << p2Wins << endl;
  return 0;
}

void addCardsWon(WarPlayer &player, Card tiedCards[], int count)
{
	for (int i = 0; i < count; i++)
		player.addCard(tiedCards[i]);
}
