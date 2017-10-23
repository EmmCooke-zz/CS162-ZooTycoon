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
	double cash; // Starts with $100,000
	int currentDay;

	// Tigers
	Tiger * tigerArray;
	int tigerArraySize;
	int numTigers;

	// Penguins
	Penguin * penguinArray;
	int penguinArraySize;
	int numPenguins;

	// Turtles
	Turtle * turtleArray;
	int turtleArraySize;
	int numTurtles;

	// New Animal
	NewAnimal * newAnimalArray;
	int newAnimalArraySize;
	int numNewAnimals;
	bool newAnimalExists;

public:
	// Default Constructor
	Zoo();
	// Destructor
	~Zoo();

	// Getters

	// Tigers
	Tiger * getTigers() const { return tigerArray; }
	int getTigerArraySize() const { return tigerArraySize; }
	int getNumTigers() const { return numTigers; }

	// Penguins
	Penguin * getPenguins() const { return penguinArray; }
	int getPenguinArraySize() const { return penguinArraySize; }
	int getNumPenguins() const { return numPenguins; }

	// Turtles
	Turtle * getTurtles() const { return turtleArray; }
	int getTurtleArraySize() const { return turtleArraySize; }
	int getNumTurtles() const { return numTurtles; }

	// New Animals
	NewAnimal * getNewAnimals() const { return newAnimalArray; }
	int getNewAnimalArraySize() const { return newAnimalArraySize; }
	int getNumNewAnimals() const { return numNewAnimals; }

	// Setters

	// Tigers
	void setTigerArraySize(int arraySizeIn) { tigerArraySize = arraySizeIn; }
	void setNumTigers(int numTigersIn) { numTigers = numTigersIn; }
	void doubleTigerArray(int babiesIn);

	// Penguins
	void setPenguinArraySize(int arraySizeIn) { penguinArraySize = arraySizeIn; }
	void setNumPenguins(int numPenguinsIn) { numPenguins = numPenguinsIn; }
	void doublePenguinArray(int babiesIn);

	// Turtles
	void setTurtleArraySize(int arraySizeIn) { turtleArraySize = arraySizeIn; }
	void setNumTurtles(int numTurtlesIn) { numTurtles = numTurtlesIn; }
	void doubleTurtleArray(int babiesIn);

	// New Animals
	void setNewAnimalArraySize(int arraySizeIn) { newAnimalArraySize = arraySizeIn; }
	void setNumNewAnimals(int numNewAnimalsIn) { numNewAnimals = numNewAnimalsIn; }
	void doubleNewAnimalArray(int babiesIn);

	// Function to run the game
	void runGame();

	// Used to age the animals
	void ageAnimals();
	// Used to feed the animals
	void feedAnimals();
	// Cause random event to occur
	void performRandomEvent();
	// Function to display game start message
	void welcomeMessage();
	// Function to display end of day statistics
	bool endDay();

	// Functions to add animals to their arrays
	void addTiger(int tigersIn);
	void addPenguin(int penguinsIn);
	void addTurtle(int turtlesIn);
	void addNewAnimal(int newAnimalsIn);

	// Random event functions
	void sickAnimal();
	void attendanceBoom();
	void babyBorn();

	// Used to check the balance of the cash
	void calculateProfit();
	bool checkBalance();
};

#endif