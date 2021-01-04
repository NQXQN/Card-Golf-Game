#pragma once
#include <vector>
#include "Card.h"
//#include "Game_Actions.h"
#include <iostream>

using namespace std;

class PlayerHand
{
public:
	PlayerHand();
	void insertHandTop(Card c); // done
	void insertHandBottom(Card c); // done
	void displayHand(); // done
	Card& accessPlayerHandTop(int loc); // done
	Card& accessPlayerHandBottom(int loc); // done
	int handTotal();
	void flipAllCards();


private:
	vector<Card> playerHandTop; // nums 0 thru 2
	vector<Card> playerHandBottom; // nums 3 thru 5
};

