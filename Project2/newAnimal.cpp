/*************************************************
* Author: Emmet Cooke
* Date: 10/20/2017
* Description: This file contains the definitions for
* the NewAnimal class.
*************************************************/
#include "NewAnimal.hpp"

/*************************************************
* Description: Default Constructor. For babies.
*************************************************/
NewAnimal::NewAnimal() : Animal(1)
{
	NewAnimal::setNumBabies(0);
	NewAnimal::setCost(0.00);
	NewAnimal::setBaseFoodCost(0.0);
	NewAnimal::setPayoff(0.0);
}

/*************************************************
* Description: Constructor that takes in one int for
* age and passes it to the Animal constructor. For
* adults.
*************************************************/
NewAnimal::NewAnimal(int ageIn)
	: Animal(ageIn)
{
	NewAnimal::setNumBabies(0);
	NewAnimal::setCost(0.00);
	NewAnimal::setBaseFoodCost(0.0);
	NewAnimal::setPayoff(0.00);
}

/*************************************************
* Description: Destructor.
*************************************************/
NewAnimal::~NewAnimal()
{
}

/*************************************************
* Description: Overloading the postfix ++ operator
* so that it is easier to increase the NewAnimals age.
*************************************************/
NewAnimal NewAnimal::operator+(int)
{
	NewAnimal temp = *this;
	age++;
	return temp;
}
