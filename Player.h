#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player
{
	public:
		Player();
		Player(int mon, string tok);

		void give_money(int mon);
		void setToken(string tok);
		void move(int spaces);
		
		int getMoney();
		int getPosition();
		string getToken();
		char getRepresentation();
		bool isAlive();

	private:
		int money, position;
		string token;
};

#endif