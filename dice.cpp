#include "dice.h"

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
using namespace std;





// Dice Default constructor that sets all instance variables to 0
Dice::Dice() : lastRoll(0), totalRolls(0), sumScore(0), numberOfDice(0), typesOfDice(0), modifier(0)
{}


//The dice roll method that takes an argument of type string ex "2d12[+3]
int Dice::Roll(string rollOfDice){


	//Parses 3 integer values and from the string and store them in instance variables
	Dice::parseNumberOfDice(rollOfDice);

	//Determines what kind of die is being used
	int kindOfDice = Dice::typeOfDice(typesOfDice);

	lastRoll = 0;
	totalRolls ++;

	//generates a random number depending on the type of the dice;
	for(int i = 0; i < numberOfDice; i ++){
		lastRoll = (rand() % kindOfDice) + 1;
		sumScore += lastRoll;
	cout << " Your " << (i+1) << " die toss = " << lastRoll << endl;

	}

	// Adds on the optional modifer
	if(modifier != 0){


		cout << "Your sum = " << sumScore << ", and with the +" << modifier<<" modifier" << endl;
		sumScore += modifier;
		cout << "Your total roll = " << sumScore << endl;


	}

	else{
	cout << "Your sum = " << sumScore << endl;
	}

	// Returns the sum total of the roll
	return sumScore;

	//Resets all values to 0
	Dice::Reset();
}


//Resets all Values to 0
void Dice::Reset(){
	lastRoll = 0;
	totalRolls = 0;
	sumScore = 0;
	numberOfDice = 0;
	typesOfDice = 0;
	modifier = 0;
}

//Uses a switch statement to determine the type of die being used and returns the corresponding value
int Dice::typeOfDice(int numberOfSides){

	switch(numberOfSides){
	case 4:
		return D_4;
		break;
	case 6:
		return D_6;
		break;
	case 8:
		return D_8;
		break;
	case 10:
		return D_10;
		break;
	case 12:
		return D_12;
		break;
	case 20:
		return D_20;
		break;
	case 100:
		return D_100;
		break;
	default:
		cout << "Invalid Dice" << endl;
		return 0;


	}
}

//Parses the integer value from a string
void Dice::parseNumberOfDice(string diceRoll){

	string delimiter = "d";
	string delimiter_2 = "[+";
	string delimiter_3 = "+";
	string delimiter_4 = "]";
	string token, token2, token3, token4;
	size_t pos;


	while ((pos = diceRoll.find(delimiter)) != std::string::npos) {
	    token = diceRoll.substr(0, pos);

	    diceRoll.erase(0, pos + delimiter.length());
	}


	token2 = diceRoll.substr(0, diceRoll.find(delimiter_2));

	int find = diceRoll.find(delimiter_3);


	token3 = diceRoll.substr(find + 1, diceRoll.find(delimiter_4));

	token4 = token3.substr(0, token3.length() - 1);



	numberOfDice = atoi(token.c_str());
	typesOfDice = atoi(token2.c_str());
	modifier = atoi(token4.c_str());


}



