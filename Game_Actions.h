#pragma once
#include <vector>
#include <string>
#include "PlayerHand.h"
#include <algorithm>
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock




using namespace std;

class Game_Actions
{

	public:
		void createDeck(vector<Card> &deck); // done
		void shuffle(vector<Card>& deck); // done
		void deal(PlayerHand &hand, vector<Card>& deck); // done
		void revealTopCard(vector<Card>& deck); //done
		void takeRevealedCard(PlayerHand& hand, vector<Card>& deck); // done
		void duplicateCardRemoval(PlayerHand& hand, int loc); // done
		void dealFlip(PlayerHand& hand); // done

};

