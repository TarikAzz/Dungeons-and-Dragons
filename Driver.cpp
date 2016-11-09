//! @file 
//! Driver for the character class
//! Basic driver file to allow for some manual testing. Users are given the choice
//! of creating a character randomly. If they refuse, they can input a level for
//! their character as well as the 6 scores from their die.
//! Note: Since exception handling has not been covered yet, I assume perfect user input
#include "Character.h"
#include <iostream>
using namespace std;

void checkCreation(Character input) {
	input.getScores();
	cout << endl;
	if (input.isValidCharacter() == true)
		cout << "The character is valid" << endl;
	else
		cout << "The character is not valid" << endl;
}
int main() {
	int lvl, s, d, c, i, w, h;
	int end, choice;
	cout <<"CREATE YOU CHARACTER"<< endl;
	cout << "If you wish to create a random character, enter 0 now. Any other digit to continue: " << endl;
	cin >> choice;
	if (choice == 0) {
		cout << "Enter the level of your character (1 to 5): " << endl;
		cin >> lvl;
		Character rando = Character(lvl);
		checkCreation(rando);
	}
	else {
		cout << "Enter the level of your character (1 to 5): " << endl;
		cin >> lvl;
		cout << "Enter your 6 dice scores from your rolls (values from 3 to 18):";
		cin >> s >> d >> c >> i >> w >> h;
		Character fighterGuy = Character(lvl, s, d, c, i, w, h);
		checkCreation(fighterGuy);
	}	
	cout << "Enter any digit to quit: ";
	cin >> end;
	return end;
	}
