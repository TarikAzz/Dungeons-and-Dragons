#ifndef DICE_H_
#define DICE_H_
#include <string>

using namespace std;

/*!
 * constant integer values corresponding to how many sides a die has
 * */
const int	D_4 = 4;
const int   D_6 = 6;
const int	D_8 = 8;
const int	D_10 = 10;
const int	D_12 = 12;
const int	D_20 = 20;
const int   D_100 = 100;


//! A DND Dice Rolling Program
/*!
 *      Author: RichardMcCaughey
 *      Student ID: 27399022
 *      COMP 345 - Assignment 1
 *
 *     In D&D there are 7 different types of dice each with a different number of sides
 *     There is the: d4 = 4 sided die
 *     				 d6 = 6 sided die
 *     				 d8 = 8 sided die
 *     				 d10 = 10 sided die
 *     				 d12 = 12 sided die
 *     				 d20 = 20 sided die
 *     				 d100 = 100 sided die, in the actual game there is one die to represent the 10s place and 1 die to represent the 1s place
 *
 *    1) For each dice roll, the player can select how many of one type of die they want to roll:
 *     			So for example, an input of of "2d4" means that you want to roll the 4 sided die twice
 *     			"3d6" = roll a 6 sided die three times.
 *
 *     			After the rolls are complete a sum is calculated based off of each of the rolls of the dice.
 *
 *     			There is an optional modifier that can be added onto the total sum after it has been calculated, denoted [+z]
 *     				So a roll of "2d4[+3]"  = 2 rolls of the 4 sided die, where the total is calculated and afterwards a modifier of +3 is added on.
 *
 *
 *     2) 	- I set up each type of dice as a global constants corresponding to the number of sides it has, which allows for them to be accessed anywhere without being changed.
 *     		- Since we have to parse the number of dice, type of dice, and the modifier from a string there is a parse method which takes the user input string
 *     			and breaks it down into 3 integer values which correspond integer values.
 *     		- These integer values are placed in their respective instance variables
 *     		- There are also instance variables to:
 *     				- keep track of the last number the user has rolled
 *     				- the total number of rolls
 *     				- the sum of the resulting rolls
 *     		- After parsing the integer values, the second Number(the type of die used) is passed to a method which determines which die is being used.
 *     			it returns one of the constant int values corresponding to the type of die passed as an argument
 *     		-Further inside the roll method, a for loop calculates the die 'roll(s)' to the number of times the user wanted to roll.
 *     			it uses the instance variables to determine how many times to loop and what kind of die to loop for. It then returns a sum of the dice rolls which is an integer.
 *     		-It takes into account if there is a modifier entered and adds it onto the int sum vale afterwards.
 *     		-At the end there is a reset method that sets all the number of die, the type of dice, and the modifier back to 0 so no values are left over for the next roll.
 *
 *		3) I used the standard libraries included in C++,
 *			- String library
 *			- Iostream
 *			- Both of these are being used for the standard i/o functions
 *			- I included the csdt.lib library to use the rand() function to generate random numbers for the die as well as the ctime library
 **/

class Dice{



public:
	//!Default constructor for dice object
	Dice();

	//!Roll method which takes a string argument that will later be parsed for integer values
	/*!
	 * param rollOfDice a string argument
	 * return sumScore
	 */
	int Roll(string rollOfDice);

	//!Reset method that resets all values back to 0, so no value will be left over
	void Reset();

	//!A method to determine what type of die is being used
	/*!
	 * param numberOfSides an int argument to determine which die is being used
	 * return const int die value
	 */
	int typeOfDice(int numeberOfSides);

	//!A method to parse int values from a given string
	/*!
	 * param diceRoll takes a string argument and parses 3 int values
	 * return numberOfDice, typesOfDice, modifier
	 */
	void parseNumberOfDice(string diceRoll);

//! Private Instance Variables
private:
	int lastRoll;
	int totalRolls;
	int sumScore;
	int numberOfDice;
	int typesOfDice;
	int modifier;


};



#endif /* DICE_H_ */
