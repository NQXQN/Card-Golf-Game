#include "PlayerHand.h"

PlayerHand::PlayerHand()
{
	playerHandTop.reserve(3);
	playerHandBottom.reserve(3);
}

void PlayerHand::insertHandTop(Card c)
{
	playerHandTop.push_back(c);
}

void PlayerHand::insertHandBottom(Card c)
{
	playerHandBottom.push_back(c);

}

void PlayerHand::displayHand() // display a grid of the players card
{
	cout << "Your hand:\n";

		for (int j{ 0 }; j < 3; j++) { // does top row
			if (playerHandTop.at(j).showStatus()) { //checks if the cards status is hidden or not.
				cout << playerHandTop.at(j).getValAndSuit() + "     "; // displays card if not hidden
			}
			else {
				cout << "HIDDEN       "; //displays this text if hidden
			}
		}

		cout << "\n";

		for (int j{ 0 }; j < 3; j++) { // does bottom row, same functionality as top
			if (playerHandBottom.at(j).showStatus()) {
				cout << playerHandBottom.at(j).getValAndSuit() + "      ";
			}
			else {
				cout << "HIDDEN       ";
			}
		}
		cout << "\n-------------------------------------------------------------\n";

}

Card& PlayerHand::accessPlayerHandTop(int loc) {
	return playerHandTop.at(loc);
}

Card& PlayerHand::accessPlayerHandBottom(int loc) {
	return playerHandBottom.at(loc);
}
