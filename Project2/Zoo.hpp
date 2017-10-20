/*************************************************
* Author: Emmet Cooke
* Date: 10/20/2017
* Description: This is the header file for the Zoo
* class.
*************************************************/
#ifndef ZOO_HPP
#define ZOO_HPP

#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include "NewAnimal.hpp"

class Zoo
{
private:
	double cash = 100000.00; // Starts with $100,000
	int currentDay = 1;
	Tiger * tigerArray;
	Penguin * penguinArray;
	Turtle * turtleArray;
	NewAnimal * newAnimalArray;

public:
	// Default Constructor
	Zoo();
	// Destructor
	~Zoo();

	// Function to run the game
	void runGame();

	// Function to display game start message
	void welcomeMessage();

	// Functions to add animals to their arrays
	void addTiger(int tigersIn);
	void addPenguin(int penguinsIn);
	void addTurtle(int turtlesIn);
	void addNewAnimal(int newAnimalsIn);

	// Random event functions
	void sickAnimal();
	void attendanceBoom();
	void babyBorn();
	void calculateProfit();
};

#endif