#include "Player.h"
#include <string>

using namespace std;

Player::Player()
{
	position = 0;
	money = 0;
	token = " ";
}

Player::Player(int mon, string tok)
{
	position = 0;
	money = mon;
	token = tok;
}

void Player::give_money(int mon)
{
	money += mon;
}

void Player::setToken(string tok)
{
	token = tok;
}

void Player::move(int spaces)
{
	position = (position + spaces) % 40;
}

int Player::getMoney()
{
	return money;
}

int Player::getPosition()
{
	return position;
}

string Player::getToken()
{
	return token;
}

char Player::getRepresentation()
{
	return token[0];
}

bool Player::isAlive()
{
	return (money > 0);
}