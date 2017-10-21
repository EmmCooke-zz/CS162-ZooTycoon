/*************************************************
* Author: Emmet Cooke
* Date: 10/20/2017
* Description: This file contains the definitions for
* the Zoo class.
*************************************************/
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <iomanip>
using std::setw;
using std::fixed;
using std::showpoint;
using std::setprecision;

#include <string>
using std::string;

#include "Zoo.hpp"
#include "validateInput.hpp"

/*************************************************
* Description: Default Constructor.
*************************************************/
Zoo::Zoo()
{
	// Starting variables
	cash = 100000; // Starts with $100,000
	currentDay = 1;

	// Tigers
	tigerArray = new Tiger[10];
	tigerArraySize = 10;
	numTigers = 0;


	// Penguins
	penguinArray = new Penguin[10];
	penguinArraySize = 10;
	numPenguins = 0;

	// Turtles
	turtleArray = new Turtle[10];
	turtleArraySize = 10;
	numTurtles = 0;

	// New Animals
	newAnimalArray = new NewAnimal[10];
	newAnimalArraySize = 10;
	numNewAnimals = 0;
}

/*************************************************
* Description: Destructor.
*************************************************/
Zoo::~Zoo()
{
	delete[] tigerArray;
	delete[] penguinArray;
	delete[] turtleArray;
	delete[] newAnimalArray;
}

/*************************************************
* Description: This functions runs the zoo tycoon game.
* It will loop through a series of random events until
* either the zoo runs out of money or the player decides to
* quit.
*************************************************/
void Zoo::runGame()
{
	string validateInput;
	welcomeMessage();

	bool endOfDayContinue = true;
	do
	{
		endOfDayContinue = endDay();
	} while (endOfDayContinue);

}

/*************************************************
* Description: Function to hold the welcome message 
* and base requests to the user for the start of the 
* game.
*************************************************/
void Zoo::welcomeMessage()
{
	string validateInput;
	int numAnimals;
	bool exitChoice = false;
	// Fun intro message from the owner
	cout << "Owner: There is no time for games, this zoo is a mess!" << endl;
	cout << "I'm going you one last chance; have this zoo making a profit" << endl;
	cout << "in a year or you'll never work in this industry again! I'll give" << endl;
	cout << "you $100,000 to start over and get some new animals. Don't fail me!" << endl;
	cout << endl << endl;

	cout << "Welcome to Zoo Tycoon!" << endl << endl;

	cout << "Today is the first day of a new year. Can you turn this zoo around?" << endl;
	cout << endl;
	
	// Get the number of tigers for day 1
	while (!exitChoice)
	{

		cout << "Would you like to add 1 or 2 tigers to the zoo?" << endl;
		getline(cin, validateInput);
		numAnimals = getInt(validateInput);
		
		switch(numAnimals)
		{
		case 1: addTiger(1);
			exitChoice = true;
			break;
		case 2: addTiger(2);
			exitChoice = true;
			break;
		default: cout << "Please choose 1 or 2." << endl;
		}
	}

	// Get the number of penguins for day 1
	exitChoice = false;
	while (!exitChoice)
	{

		cout << "Would you like to add 1 or 2 penguins to the zoo?" << endl;
		getline(cin, validateInput);
		numAnimals = getInt(validateInput);

		switch (numAnimals)
		{
		case 1: addPenguin(1);
			exitChoice = true;
			break;
		case 2: addPenguin(2);
			exitChoice = true;
			break;
		default: cout << "Please choose 1 or 2." << endl;
		}
	}

	// Get the number of turtles for day 1
	exitChoice = false;
	while (!exitChoice)
	{

		cout << "Would you like to add 1 or 2 turtles to the zoo?" << endl;
		getline(cin, validateInput);
		numAnimals = getInt(validateInput);

		switch (numAnimals)
		{
		case 1: addTurtle(1);
			exitChoice = true;
			break;
		case 2: addTurtle(2);
			exitChoice = true;
			break;
		default: cout << "Please choose 1 or 2." << endl;
		}
	}

	cout << "Good luck!" << endl << endl;
}
/*************************************************
* Description:
*************************************************/
bool Zoo::endDay()
{
	cout << "----------------" << endl;
	cout << "Current Cash Balance: $" << setw(8) << showpoint << fixed << setprecision(2) << cash << endl;
	cout << "Tiger Population    : " << this->getNumTigers() << endl;
	//cout << "Penguin Population  :  " << penguinArray->getNumPenguins() << endl;
	//cout << "Turtle Population   :  " << turtleArray->getNumTurtles() << endl;
	// if (newAnimalExists)
	// cout << newAnimalArray->getName() << " Population   :  " << newAnimalArray->getNumNewAnimals() << endl;
	cout << "Would you like to continue to tomorrow (y/n)? " << endl;
	string answer;
	getline(cin, answer);
	if (answer == "y")
	{
		return true;
	}
	return false;
}
/*************************************************
* Description:
*************************************************/
void Zoo::addTiger(int tigersIn)
{
	int numTigers = this->getNumTigers() + tigersIn;
	this->setNumTigers(numTigers);
	if (numTigers > this->getTigerArraySize() - 1)
	{
		//doubleTigerArray();
	}
	cash -= tigerArray->getCost() * tigersIn;
}

/*************************************************
* Description:
*************************************************/
void Zoo::addPenguin(int penguinsIn)
{
	
}

/*************************************************
* Description:
*************************************************/
void Zoo::addTurtle(int turtlesIn)
{
	
}

/*************************************************
* Description:
*************************************************/
void Zoo::addNewAnimal(int newAnimalsIn)
{
	
}

/*************************************************
* Description:
*************************************************/
void Zoo::sickAnimal()
{
	
}

/*************************************************
* Description:
*************************************************/
void Zoo::attendanceBoom()
{
	
}

/*************************************************
* Description:
*************************************************/
void Zoo::babyBorn()
{
	
}

/*************************************************
* Description:
*************************************************/
void Zoo::calculateProfit()
{
	
}

/*************************************************
* Description: Checks to see if the cash balance is
* less than 0. If it is, it returns false and the game ends.
* Otherwise, it returns true.
*************************************************/
bool Zoo::checkBalance()
{
	if (this->cash < 0)
	{
		return false;
	}
	return true;
}