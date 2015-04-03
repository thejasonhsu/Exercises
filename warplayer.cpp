#include "warplayer.h"

WarPlayer::WarPlayer()
{
  _head = 0;
  _tail = 0;
  _size = 0;
}

void WarPlayer::addCard(Card c)
{
  _cards[_tail] = c;
  _tail = (_tail + 1) % 52;
  _size++;
}

Card WarPlayer::removeTopCard()
{
  Card c = _cards[_head];
  _head = (_head + 1) % 52;
  _size--;
  return c;
}

// Add the implementation of your two functions here

bool WarPlayer::hasCardsRemaining()
{
	return (_size > 0);
}

int WarPlayer::size()
{
	return _size;
}