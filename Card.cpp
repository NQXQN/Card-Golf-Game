#include "Card.h"


//Object class for a card
//Will record if card is hidden or shown & its value


Card::Card(string suitIn, int valIn)
{
	isShown = false;
	suit = suitIn;
	val = valIn;
}

bool Card::showStatus()
{
	return isShown;
}

int Card::getVal()
{
	return val;
}

string Card::getSuit()
{
	return suit;
}

string Card::getValAndSuit()
{
	string s = suit + ", " + to_string(val);
	return s;
}

void Card::flip()
{
	if (isShown == false) {
		isShown = true;
	}
	else {
		isShown = false;
	}
}
