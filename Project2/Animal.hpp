/*************************************************
* Author: Emmet Cooke
* Date: 10/20/2017
* Description: This is the header file for the Animal
* class.
*************************************************/
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{
private:
	int age;
	int numBabies;
	double cost;
	double baseFoodCost;
	double payoff;

public:
	// Default Constructor
	Animal();

	// Constructor that takes in one int for age
	Animal(int ageIn);

	// Destructor
	~Animal();

	// Getters
	int getAge() const { return age; }
	virtual int getNumBabies() = 0;
	virtual double getCost() = 0;
	virtual double getBaseFoodCost() = 0;
	virtual double getPayoff() = 0;

	// Setters
	void setAge(int ageIn) { age = ageIn; }
	virtual void setNumBabies(int babiesIn) = 0;
	virtual void setCost(double costIn) = 0;
	virtual void setBaseFoodCost(double foodCostIn) = 0;
	virtual void setPayoff(double payoffIn) = 0;
};

#endif