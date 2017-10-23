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

#include <ctime>

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
	tigerArraySize = 10;
	tigerArray = new Tiger[tigerArraySize];
	numTigers = 0;

	// Penguins
	penguinArraySize = 10;
	penguinArray = new Penguin[penguinArraySize];
	numPenguins = 0;

	// Turtles
	turtleArraySize = 10;
	turtleArray = new Turtle[turtleArraySize];
	numTurtles = 0;

	// New Animals
	newAnimalArraySize = 10;
	newAnimalArray = new NewAnimal[newAnimalArraySize];
	numNewAnimals = 0;
	newAnimalExists = false;

	// Seed for random event
	srand(time(0));
}

/*************************************************
* Description: Destructor.
*************************************************/
Zoo::~Zoo()
{
	// Delete the Tiger objects
	delete[] tigerArray;
	// Delete the Penguin objects
	delete[] penguinArray;
	// Delete the Turtle objects
	delete[] turtleArray;
	// Delete the NewAnimal objects
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

	bool endOfDayContinue;

	do
	{
		ageAnimals();
		feedAnimals();
		calculateProfit();
		performRandomEvent();
		endOfDayContinue = endDay();
		currentDay++;
		
	} while (endOfDayContinue);

}

/*************************************************
* Description: This function goes through the animal
* arrays and ages the available animals.
*************************************************/
void Zoo::ageAnimals()
{
	// Tigers
	for (int i = 0; i < numTigers; i++)
	{
		tigerArray[i].setAge(tigerArray[i].getAge() + 1);
	}
	// Penguins
	for (int i = 0; i < numPenguins; i++)
	{
		penguinArray[i].setAge(penguinArray[i].getAge() + 1);
	}
	// Turtles
	for (int i = 0; i < numTurtles; i++)
	{
		turtleArray[i].setAge(turtleArray[i].getAge() + 1);
	}
	// New Animal
	if (newAnimalExists)
	{
		for (int i = 0; i < numNewAnimals; i++)
		{
			newAnimalArray[i].setAge(newAnimalArray[i].getAge() + 1);
		}
	}
}

/*************************************************
* Description: This function goes through the animal
* arrays and feeds the animals. This cost is then subtracted
* from cash.
*************************************************/
void Zoo::feedAnimals()
{
	// Feed the tigers
	if (numTigers != 0)
	{
		cash -= numTigers * tigerArray[0].getBaseFoodCost();
	}
	// Feed the penguins
	if (numPenguins != 0)
	{
		cash -= numPenguins * penguinArray[0].getBaseFoodCost();
	}
	// Feed the turtles
	if (numTurtles != 0)
	{
		cash -= numTurtles * turtleArray[0].getBaseFoodCost();
	}
	// Feed the new Animals
	if (newAnimalExists)
	{
		if (numNewAnimals != 0)
		{
			cash -= numNewAnimals * newAnimalArray[0].getBaseFoodCost();
		}
	}
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
* Description: This function displays at the end of the day
* and informs the user about how much cash they currently have
* and how many animals there are in the zoo. It then asks
* then if they want to continue and returns a boolean value
* with their choice.
*************************************************/
bool Zoo::endDay()
{
	cout << "Day " << currentDay << endl;
	                                                      
	cout << "---------------------------------------------" << endl;
	cout << "Current Cash Balance: $" << setw(8) << showpoint;
	cout << fixed << setprecision(2) << cash << endl;
	cout << "Tiger Population    : " << this->getNumTigers() << endl;
	cout << "Penguin Population  : " << this->getNumPenguins() << endl;
	cout << "Turtle Population   : " << this->getNumTurtles() << endl;
	if (newAnimalExists)
	{
		cout << newAnimalArray->getName() << " Population    :  ";
		cout << this->getNumNewAnimals() << endl;
	}
	if (!newAnimalExists)
	{
		cout << "Would you like to add a new animal to the Zoo (y/n)? ";
		string newAnimalYes;
		getline(cin, newAnimalYes);
		if (newAnimalYes == "y")
		{
			string newAnimalName,		// Variables for input validation
				costString,
				baseFoodCostString,
				payoffString,
				numBabiesString;
			int cost,
				numBabies;
			double baseFoodCost,
				payoff;
			// Get the name of the new animal
			cout << "What is the name of the new animal? " << endl;
			getline(cin, newAnimalName);
			newAnimalArray->setName(newAnimalName);

			// Get the cost of the animal
			do
			{
				cout << "What is the cost of the animal? " << endl;
				getline(cin, costString);
				cost = getInt(costString);
				if (cost < 0)
				{
					cout << "Please enter a valid cost." << endl;
				} 
			} while (cost < 0);
			newAnimalArray->setCost(cost);

			// Get how many babies it has at one
			do
			{
				cout << "How many babies does this animal have at once? " << endl;
				getline(cin, numBabiesString);
				numBabies = getInt(numBabiesString);
				if (numBabies < 1)
				{
					cout << "Please enter a valid integer that is 1 or greater." << endl;
				}
			} while (numBabies < 1);
			newAnimalArray->setNumBabies(numBabies);

			// Get the baseFoodCost of the animal
			do
			{
				cout << "What is the base food cost of the animal? Please enter it as a multiple (e.g. 5, 0.5, 0.05)." << endl;
				getline(cin, baseFoodCostString);
				baseFoodCost = getDouble(baseFoodCostString);
				if (baseFoodCost < 0)
				{
					cout << "Please enter a valid base food cost." << endl;
				}
			} while (baseFoodCost < 0);
			newAnimalArray->setBaseFoodCost(baseFoodCost);

			// Get the Payoff of the animal
			do
			{
				cout << "What is the payoff of the animal? Please enter it as a multiple (e.g. 5, 0.5, 0.05)." << endl;
				getline(cin, payoffString);
				payoff = getDouble(payoffString);
				if (payoff < 0)
				{
					cout << "Please enter a valid payoff." << endl;
				}
			} while (payoff < 0);
			newAnimalArray->setPayoff(payoff);

			// This question will not be asked again
			newAnimalExists = true;
			addNewAnimal(1);
		}
	}
	cout << "Would you like to continue to tomorrow (y/n)? ";
	string answer;
	getline(cin, answer);
	if (answer == "y")
	{
		return true;
	}
	return false;
}

/*************************************************
* Description: This function  adds a tiger to the number
* of tigers available at the zoo. If the number of tigers goes
* over the allotted amount of space available in the array,
* a second will be made that is double the size.
*************************************************/
void Zoo::addTiger(int tigersIn)
{
	int numTigers = this->getNumTigers() + tigersIn;
	this->setNumTigers(numTigers);
	if (numTigers > this->getTigerArraySize() - 1)
	{
		doubleTigerArray(tigersIn);
	}
	cash -= tigerArray[0].getCost() * tigersIn;
}

/*************************************************
* Description: This function doubles the size of 
* the dynamic array, tigerArray. It keeps the ages
* of the current tigers in an int array and then
* deletes and recreates the array.
*************************************************/
void Zoo::doubleTigerArray(int babiesIn)
{
	tigerArraySize *= 2;
	int currentTigers = numTigers - babiesIn;
	int * ageArray = new int[currentTigers];
	for (int i = 0; i < currentTigers; i++)
	{
		ageArray[i] = tigerArray[i].getAge();
	}
	delete[] tigerArray;
	tigerArray = new Tiger[tigerArraySize];
	for (int i = 0; i < currentTigers; i++)
	{
		tigerArray[i].setAge(ageArray[i]);
	}
	delete[] ageArray;
}

/*************************************************
* Description: This function  adds a penguin to the number
* of penguins available at the zoo. If the number of penguins goes
* over the allotted amount of space available in the array,
* a second will be made that is double the size.
*************************************************/
void Zoo::addPenguin(int penguinsIn)
{
	int numPenguins = this->getNumPenguins() + penguinsIn;
	this->setNumPenguins(numPenguins);
	if (numPenguins > this->getPenguinArraySize() - 1)
	{
		doublePenguinArray(penguinsIn);
	}
	cash -= penguinArray[0].getCost() * penguinsIn;
}

/*************************************************
* Description: This function doubles the size of 
* the dynamic array, penguinArray. It keeps the ages
* of the current penguins in an int array and then
* deletes and recreates the array.
*************************************************/
void Zoo::doublePenguinArray(int babiesIn)
{
	penguinArraySize *= 2;
	int currentPenguins = numPenguins - babiesIn;
	int * ageArray = new int[currentPenguins];
	for (int i = 0; i < currentPenguins; i++)
	{
		ageArray[i] = penguinArray[i].getAge();
	}
	delete[] penguinArray;
	penguinArray = new Penguin[penguinArraySize];
	for (int i = 0; i < currentPenguins; i++)
	{
		penguinArray[i].setAge(ageArray[i]);
	}
	delete[] ageArray;
}

/*************************************************
* Description: This function  adds a turtle to the number
* of turtles available at the zoo. If the number of turtles goes
* over the allotted amount of space available in the array,
* a second will be made that is double the size.
*************************************************/
void Zoo::addTurtle(int turtlesIn)
{
	int numTurtles = this->getNumTurtles() + turtlesIn;
	this->setNumTurtles(numTurtles);
	if (numTurtles > this->getTurtleArraySize() - 1)
	{
		doubleTurtleArray(turtlesIn);
	}
	cash -= turtleArray[0].getCost() * turtlesIn;
}

/*************************************************
* Description: This function doubles the size of 
* the dynamic array, turtleArray. It keeps the ages
* of the current turtles in an int array and then
* deletes and recreates the array.
*************************************************/
void Zoo::doubleTurtleArray(int babiesIn)
{
	turtleArraySize *= 2;
	int currentTurtles = numTurtles - babiesIn;
	cout << numTurtles << endl;
	int * ageArray = new int[currentTurtles];
	for (int i = 0; i < currentTurtles; i++)
	{
		ageArray[i] = turtleArray[i].getAge();
	}
	delete[] turtleArray;
	turtleArray = new Turtle[turtleArraySize]();
	for (int i = 0; i < currentTurtles; i++)
	{
		turtleArray[i].setAge(ageArray[i]);
	}
	delete[] ageArray;
}

/*************************************************
* Description: This function  adds a new animal to the number
* of new animals available at the zoo. If the number of new animals goes
* over the allotted amount of space available in the array,
* a second will be made that is double the size.
*************************************************/
void Zoo::addNewAnimal(int newAnimalsIn)
{
	int numNewAnimals = this->getNumNewAnimals() + newAnimalsIn;
	this->setNumNewAnimals(numNewAnimals);
	if (numNewAnimals > this-> getNewAnimalArraySize() - 1)
	{
		doubleNewAnimalArray(newAnimalsIn);
	}
	cash -= newAnimalArray[0].getCost() * newAnimalsIn;
}

/*************************************************
* Description: This function doubles the size of 
* the dynamic array, newAnimalArray. It keeps the ages
* of the current NewAnimals in an int array and then
* deletes and recreates the array.
*************************************************/
void Zoo::doubleNewAnimalArray(int babiesIn)
{
	newAnimalArraySize *= 2;
	int currentNewAnimals = numNewAnimals - babiesIn;
	int * ageArray = new int[currentNewAnimals];
	for (int i = 0; i < currentNewAnimals; i++)
	{
		ageArray[i] = newAnimalArray[i].getAge();
	}
	delete[] newAnimalArray;
	newAnimalArray = new NewAnimal[newAnimalArraySize];
	for (int i = 0; i < currentNewAnimals; i++)
	{
		newAnimalArray[i].setAge(ageArray[i]);
	}
	delete[] ageArray;
}

/*************************************************
* Description: Random Event. One of the animals 
* has become sick and died. This chooses a species 
* at random and decreases the number of that animal
* at the zoo and resets that spot to a 1 day old 
* version of that animal.
*************************************************/
void Zoo::sickAnimal()
{
	int randomSpecies;
	if (newAnimalExists)
	{
		randomSpecies = rand() % 4 + 1;
	}
	else
	{
		randomSpecies = rand() % 3 + 1;
	}

	// A tiger dies
	if (randomSpecies == 1)
	{
		if (numTigers > 0)
		{
			cout << "Oh no, a Tiger has died." << endl;
			tigerArray[numTigers - 1].setAge(0);
			numTigers--;
		}
	}
	// A penguin dies
	else if (randomSpecies == 2)
	{
		if (numPenguins > 0)
		{
			cout << "Oh no, a Penguin has died." << endl;
			penguinArray[numPenguins - 1].setAge(0);
			numPenguins--;
		}
	}
	// A turtle dies
	else if (randomSpecies == 3)
	{
		if (numTurtles > 0)
		{
			cout << "Oh no, a Turtle has died." << endl;
			turtleArray[numTurtles - 1].setAge(0);
			numTurtles--;
		}
	}
	// A newAnimal dies
	else if (randomSpecies == 4)
	{
		if (numNewAnimals > 0)
		{
			cout << "Oh no, a " << newAnimalArray->getName() << " has died." << endl;
			newAnimalArray[numNewAnimals - 1].setAge(0);
			numNewAnimals--;
		}
	}
}

/*************************************************
* Description: Random Event. There has been an attendance
* boom at the zoo and extra money is added to the
* zoo. 
*************************************************/
void Zoo::attendanceBoom()
{
	int newCash = rand() % 500 + 250;
	newCash += numTigers * tigerArray->getPayoff();
	cout << "Congratulations, attendance has soared! You earned an additional ";
	cout << newCash << " dollars!" << endl;
	cash += newCash;
}

/*************************************************
* Description: Random Event. One of the species is
* chosen at random and has a new baby. The number
* of that species available at the zoo is increased
* by one. The animal must be at least 3 years old
* and the new animal starts at age 0.
*************************************************/
void Zoo::babyBorn()
{
	int randomSpecies,
		age,
		i = 0;
	bool adultSpecies = false;

	if (newAnimalExists)
	{
		randomSpecies = rand() % 4 + 1;
	}
	else
	{
		randomSpecies = rand() % 3 + 1;
	}
	// A tiger has a baby
	if (randomSpecies == 1)
	{
		while (!adultSpecies && i < numTigers && numTigers > 0)
		{
			age = tigerArray[0].getAge();
			if (age >= 3)
			{
				adultSpecies = true;
				cout << "Congratulations, a Tiger was born!" << endl;
				addTiger(tigerArray->getNumBabies());
			}
			i++;
		}
		
	}
	// A penguin has a baby
	else if (randomSpecies == 2)
	{
		while (!adultSpecies && i < numPenguins && numPenguins > 0)
		{
			age = penguinArray[0].getAge();
			if (age >= 3)
			{
				adultSpecies = true;
				cout << "Congratulations, five Penguins were born!" << endl;
				addPenguin(penguinArray->getNumBabies());
			}
			i++;
		}
	}
	// A turtle has a baby
	else if (randomSpecies == 3)
	{
		while (!adultSpecies && i < numTurtles && numTurtles > 0)
		{
			age = turtleArray[0].getAge();
			if (age >= 3)
			{
				adultSpecies = true;
				cout << "Congratulations, ten Turtles were born!" << endl;
				addTurtle(turtleArray->getNumBabies());
			}
			i++;
		}
	}
	// A newAnimal has a baby
	else if (randomSpecies == 4)
	{
		while (!adultSpecies && i < numNewAnimals && numNewAnimals > 0)
		{
			age = newAnimalArray[0].getAge();
			if (age >= 3)
			{
				adultSpecies = true;
				cout << "Congratulations, " << newAnimalArray->getNumBabies();
				cout << " " << newAnimalArray->getName() << " were born!" << endl;
				addNewAnimal(newAnimalArray->getNumBabies());
			}
			i++;
		}
	}
}

/*************************************************
* Description: This function randomly chooses one
* of the events to occur.
*************************************************/
void Zoo::performRandomEvent()
{
	int eventSelection = rand() % 3 + 1;
	if (eventSelection == 1)
	{
		sickAnimal();
	}
	else if (eventSelection == 2)
	{
		attendanceBoom();
	}
	else if (eventSelection == 3)
	{
		babyBorn();
	}
}

/*************************************************
* Description: This function calculates the amount
* of money the zoo recieves based upon the number
* of animals available.
*************************************************/
void Zoo::calculateProfit()
{
	// Get profit from tigers
	cash += numTigers * tigerArray->getPayoff();

	// Get profit from penguins
	cash += numPenguins * penguinArray->getPayoff();

	// Get profit from Turtles
	cash += numTurtles * turtleArray->getPayoff();

	// Get profit from New Animal
	if (newAnimalExists)
	{
		cash += numNewAnimals * newAnimalArray->getPayoff();
	}
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