#pragma once
#include "Game_Actions.h"


class Game_Handler
{

public:
	void setup(); //initialize & shuffle deck, deal initial cards to player, reveal top card of deck
	void playGame(); //loop that runs until player has played 9 rounds
	Game_Handler();


private:
	Game_Actions theGame;
	PlayerHand hand;
	vector<Card> deck;


};

