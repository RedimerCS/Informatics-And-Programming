#pragma once
#include "Player.h";
#include "Computer.h";

class Game
{
public:
	Game();
	Game(int size_, int step_, Player user_, Computer comp_);
	Game(const Game& c);

	~Game();

	void play();			// Zapusk igry
	bool check();			// Proverka na bykov/korov/vyigrish

private:
	int size;				
	int step;				
	Player user;			
	Computer comp;			
};
