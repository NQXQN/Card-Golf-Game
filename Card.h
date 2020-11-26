#pragma once
#include <iostream>
#include <string>

using namespace std;

class Card
{
	private:
		bool isShown;
		string suit;
		int val;


	public:
		Card(string suitIn, int valIn);
		bool showStatus(); //done
		int getVal(); //done
		string getSuit(); // done
		string getValAndSuit(); // done, returns combined suit & value
		void flip(); //done

};

