#include "MainMenu.h"
#include <iostream>

//useful documentation
//https://docs.microsoft.com/en-us/cpp/cpp/header-files-cpp?view=vs-2019

using namespace std;

//displays core game options & leaderboard
//Forces user to choose between starting a new game & exiting game
void MainMenu::Menu() {
	string in;

	cout << "**********WELCOME TO CARD GOLF**********\n";
	cout << "****************************************\n";
	cout << "Please choose one of the following options:\n";

	//loops to force valid input
	while (true)
	{
		cout << "1. New game\n"
			"2. Exit\n"
			"3. Leaderboard\n\n"
			"Input: ";
		cin >> in;

		if (in == "1") {
			//leaves loop to launch game
			break;
		}else if (in == "2") {
			cout << "\nThanks for playing, goodbye.\n";
			break;
		}
		else if (in == "3") {
			//launch leaderboard class
			break;
		}
		else {
			cout << "Invalid input.  Please enter 1, 2, or 3\n\n";
		}

	}
	cout << "\n-------------------------------------------------------------\n";
	//Reaches this point if user chose new game (1)
	//launch game instance HERE
	Game_Handler handler;
	handler.playGame();




}

