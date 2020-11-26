#include "Game_Actions.h"

//populates passed deck with cards
void Game_Actions::createDeck(vector<Card> &deck)
{

	//loop through 4 times to create cards for each suit
	for (int i{ 0 }; i < 4; i++) {
		//use switch statement to determine which suit is being created
		string suit;
		switch (i) {
			case 0:
				suit = "SPADE";
				break;
			
			case 1:
				suit = "HEART";
				break;

			case 2:
				suit = "DIAMOND";
				break;

			case 3:
				suit = "CLUB";
				break;
		}


		//nested loop to create each value (Ace=1 through King=13 for each suit
		for (int j{ 1 }; j <= 13; j++) {
			//string val = to_string(j);
			deck.emplace_back(Card (suit, j));
		}
	} // deck now filled with all suited cards

	//manually add two jokers
	deck.emplace_back(Card("JOKER", -3));
	deck.emplace_back(Card("JOKER", -3));


	//deck is now filled with cards

}

// random generator function to be used with shuffle
int myrandom(int i) { return std::rand() % i; }

//shuffle passed deck of cards using std shuffle
void Game_Actions::shuffle(vector<Card>& deck)
{
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();

	std::shuffle(deck.begin(), deck.end(), default_random_engine(seed));

}


//populates the players hand with cards from the deck
void Game_Actions::deal(PlayerHand &hand, vector<Card>& deck)
{
	//call stack pop multiple times & insert cards into player hand top & bottom
	for (int i{ 0 }; i < 3; i++) {
		hand.insertHandTop(deck.back());
		deck.pop_back();
		hand.insertHandBottom(deck.back());
		deck.pop_back();
	}

}

void Game_Actions::revealTopCard(vector<Card>& deck)
{
	//use stack peek
	cout << "Revealed card placed into discard pile is: " + deck.back().getValAndSuit() + "\n\n";
}

void Game_Actions::takeRevealedCard(PlayerHand& hand, vector<Card>& deck)
{
	//show user where they can place the card
	cout << "Where do you want to place the card?\n";
	cout << "Hand positions:\n";
	cout << "0   1   2\n3   4   5\n";
	cout << "\nSelection: ";

	int selection;

	//input validation loop to ensure user  enters integer
	for (;;) {
		cin >> selection;

		if (cin.fail()) {

			cout << "Please enter a valid integer\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;

		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}


		//only does something if user chooses valid hand location.  
		//changes card in deck to shown & then inserts into players hand
		//returns to beginning of loop if entered location is not valid
		if (selection < 3 && selection >= 0) {
			deck.back().flip();

			//check to see if back of deck matches target hand destination 
			if (hand.accessPlayerHandTop(selection).getVal() == deck.back().getVal() && !hand.accessPlayerHandBottom(selection).showStatus()) {
				//if a match, duplicate card removal rules comes into effect
				duplicateCardRemoval(hand, selection);
				deck.pop_back();
				break;
			}

			//inserts card into desired slot
			hand.accessPlayerHandTop(selection) = deck.back();
			deck.pop_back(); //card is technically still in deck, so it must be removed.  
			break;
		}
		else if (selection >= 3 && selection <= 5) {
			selection -= 3;
			deck.back().flip();

			//check to see if back of deck matches target hand destination 
			if (hand.accessPlayerHandBottom(selection).getVal() == deck.back().getVal() && !hand.accessPlayerHandTop(selection).showStatus()) {
				//if a match, duplicate card removal rules comes into effect
				duplicateCardRemoval(hand, selection); 
				deck.pop_back();
				break;
			}

			//inserts card into desired slot
			hand.accessPlayerHandBottom(selection) = deck.back();
			deck.pop_back(); //card is technically still in deck, so it must be removed.  
			break;
		}
		else {
			cout << "Selected location is not valid.\n";
		}
	}


}

//method to handle duplicate card removal rule
// activated in takerevealedcard method
void Game_Actions::duplicateCardRemoval(PlayerHand& hand, int loc)
{
	hand.accessPlayerHandBottom(loc) = Card("N/A", 0);
	hand.accessPlayerHandBottom(loc).flip();
	hand.accessPlayerHandTop(loc) = Card("N/A", 0);
	hand.accessPlayerHandTop(loc).flip();

}

void Game_Actions::dealFlip(PlayerHand& hand)
{
	cout << "Please select which cards you would like to flip over.\n"
		"Select by entering a number (0 thru 5)\n";

	int selection; // placeholder variable for user input
	int first;


	for (int i{ 0 }; i < 2; i++) {

		for (;;) {
			if (i == 0) {
				cout << "Select first card: ";
			}
			else {
				
				cout << "Select second card: ";
			}

			

			cin >> selection;

			if (cin.fail()) {
				
				cout << "Please enter a valid integer\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

			}
			else {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
		}

		if (i == 0) { first = selection; }

		if (i == 1 && selection == first) {
			i--;
			cout << "Card location already selected, select a different location.\n";
			continue;
		}

		if (selection < 3 && selection >= 0) {
			hand.accessPlayerHandTop(selection).flip();
		}
		else if (selection >= 3 && selection <= 5) {
			selection -= 3;
			hand.accessPlayerHandBottom(selection).flip();
		}
		else {
			cout << "Selected location is not valid\n";
			i--;
		}

	}
	
	cout << "-------------------------------------------------------------\n";
}
