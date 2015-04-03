#ifndef WARPLAYER_H
#define WARPLAYER_H

#include "card.h"

class WarPlayer
{
 public: 
  WarPlayer();
  void addCard(Card c);
  Card removeTopCard();
  bool hasCardsRemaining();
  int size();

  // Add your two functions here


 private:
  Card _cards[52];
  int _head;
  int _tail;
  int _size;

};

#endif