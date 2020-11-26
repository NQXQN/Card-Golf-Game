#include "Game_Handler.h"

Game_Handler::Game_Handler()
{
	setup();
}

void Game_Handler::setup()
{
	theGame.createDeck(deck);

	theGame.shuffle(deck);

	theGame.deal(hand, deck);

	theGame.dealFlip(hand);

	//theGame.revealTopCard(deck);

	//hand.displayHand(); // only here for testing, remove for final implementation
	

}

void Game_Handler::playGame()
{
	//loop to play 9 rounds of the game
	for (int i{ 0 }; i < 9; i++) {
		cout << "*****************TURN " << i+1 << "*****************\n";

		theGame.revealTopCard(deck);
		hand.displayHand();
		cout << "Do you want to pick up the revealed card? ";
		string pickupAns;

		//loop to perform input validation
		while (true) {
			cin >> pickupAns;

			if (pickupAns == "Y" || pickupAns == "y") {
				theGame.takeRevealedCard(hand, deck); //runs method to let user select where they want the card to go in their hand
				break;
			}
			else if (pickupAns == "N" || pickupAns == "n") {
				deck.pop_back();  //revealed card is still in the deck vector at this point, so it must be removed since player doesn't want it 
				break;
			}
			else {
				cout << "Invalid input, please enter Y or N: "; //handles bad input
			}
		}
	}


}




