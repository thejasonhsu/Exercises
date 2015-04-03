#include <iostream>

using namespace std;

typedef struct {
	char *suit;
	int face;
} Card;

typedef struct {
	Card cards[52];
	bool is_shuffled;
} Deck;

void populate_deck(Deck &deck) {
	enum suits {SPADES, HEARTS, DIAMONDS, CLUBS};
	char *suit_names[] = {"Spades", "Hearts", "Diamonds", "Clubs"};
	for (int s=SPADES; s <= CLUBS; s++) {
		for (int i=0; i < 13; i++) {
			deck.cards[s * 13 + i].suit = suit_names[s];
			deck.cards[s * 13 + i].face = i + 1;
		}
	}
}

void print_deck(Deck deck) {
	for (int i=0; i < 52; i++) {
		cout << deck.cards[i].face << " of " << deck.cards[i].suit << endl;
	}
}

int main() {
	Deck d;
	populate_deck(d);
	print_deck(d);
	return 1;
}


