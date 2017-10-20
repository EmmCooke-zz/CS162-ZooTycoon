/*************************************************
* Author: Emmet Cooke
* Date: 10/20/2017
* Description: This is the header file for the newAnimal
* class.
*************************************************/
#ifndef NEW_ANIMAL_HPP
#define NEW_ANIMAL_HPP

#include "Animal.hpp"
class newAnimal :
	public Animal
{
public:
	// Default Constructor
	newAnimal();

	// Constructor that takes one int
	// Initializes an bought adult tiger
	newAnimal(int ageIn);

	// Destructor
	~newAnimal();

	// Getters
	virtual int getNumBabies() { return numBabies; }
	virtual double getCost() { return cost; }
	virtual double getBaseFoodCost() { return baseFoodCost; }
	virtual double getPayoff() { return payoff; }

	// Setters
	virtual void setNumBabies(int babiesIn) { numBabies = babiesIn; }
	virtual void setCost(double costIn) { cost = costIn; }
	virtual void setBaseFoodCost(double foodCostIn) { baseFoodCost = foodCostIn; }
	virtual void setPayoff(double payoffIn) { payoff = payoffIn; }

	// Increase age
	newAnimal operator+(int);
};

#endif