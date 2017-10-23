/*************************************************
* Author: Emmet Cooke
* Date: 10/20/2017
* Description: This is the header file for the newAnimal
* class.
*************************************************/
#ifndef NEW_ANIMAL_HPP
#define NEW_ANIMAL_HPP

#include <string>
using std::string;

#include "Animal.hpp"
class NewAnimal :
	public Animal
{
private:
	string name;
public:
	// Default Constructor
	NewAnimal();

	// Constructor that takes one int
	// Initializes an bought adult tiger
	NewAnimal(int ageIn);

	// Destructor
	~NewAnimal();

	// Getters
	virtual int getNumBabies() { return numBabies; }
	virtual double getCost() { return cost; }
	virtual double getBaseFoodCost() { return baseFoodCost; }
	virtual double getPayoff() { return payoff; }
	// NewAnimal specific
	string getName() { return name; }

	// Setters
	virtual void setNumBabies(int babiesIn) { numBabies = babiesIn; }
	virtual void setCost(double costIn) { cost = costIn; }
	virtual void setBaseFoodCost(double foodCostIn) { baseFoodCost = foodCostIn; }
	virtual void setPayoff(double payoffIn) { payoff = payoffIn; }
	// NewAnimal Specific
	void setName(string nameIn) { name = nameIn; }
};

#endif