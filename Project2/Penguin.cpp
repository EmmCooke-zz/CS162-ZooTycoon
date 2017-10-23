/*************************************************
* Author: Emmet Cooke
* Date: 10/20/2017
* Description: This file contains the definitions for
* the Penguin class.
*************************************************/
#include "Penguin.hpp"

/*************************************************
* Description: Default Constructor. For babies.
*************************************************/
Penguin::Penguin() : Animal(0)
{
	Penguin::setNumBabies(5);
	Penguin::setCost(1000.00);
	Penguin::setBaseFoodCost(1 * BASE_FOOD_COST);
	Penguin::setPayoff(0.1 * 1000.00);
}

/*************************************************
* Description: Constructor that takes in one int for
* age and passes it to the Animal constructor. For
* adults.
*************************************************/
Penguin::Penguin(int ageIn)
	: Animal(ageIn)
{
	Penguin::setNumBabies(5);
	Penguin::setCost(1000.00);
	Penguin::setBaseFoodCost(1 * BASE_FOOD_COST);
	Penguin::setPayoff(0.1);
}

/*************************************************
* Description: Destructor.
*************************************************/
Penguin::~Penguin()
{
}

/*************************************************
* Description: Overloading the postfix ++ operator
* so that it is easier to increase the Penguins age.
*************************************************/
Penguin Penguin::operator+(int)
{
	Penguin temp = *this;
	age++;
	return temp;
}
