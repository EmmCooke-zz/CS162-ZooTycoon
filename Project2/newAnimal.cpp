/*************************************************
* Author: Emmet Cooke
* Date: 10/20/2017
* Description: This file contains the definitions for
* the newAnimal class.
*************************************************/
#include "newAnimal.hpp"

/*************************************************
* Description: Default Constructor. For babies.
*************************************************/
newAnimal::newAnimal() : Animal(1)
{
	newAnimal::setNumBabies(0);
	newAnimal::setCost(0.00);
	newAnimal::setBaseFoodCost(0.0);
	newAnimal::setPayoff(0.0);
}

/*************************************************
* Description: Constructor that takes in one int for
* age and passes it to the Animal constructor. For
* adults.
*************************************************/
newAnimal::newAnimal(int ageIn)
	: Animal(ageIn)
{
	newAnimal::setNumBabies(0);
	newAnimal::setCost(0.00);
	newAnimal::setBaseFoodCost(0.0);
	newAnimal::setPayoff(0.00);
}

/*************************************************
* Description: Destructor.
*************************************************/
newAnimal::~newAnimal()
{
}

/*************************************************
* Description: Overloading the postfix ++ operator
* so that it is easier to increase the newAnimals age.
*************************************************/
newAnimal newAnimal::operator+(int)
{
	newAnimal temp = *this;
	age++;
	return temp;
}
