/*************************************************
* Author: Emmet Cooke
* Date: 10/20/2017
* Description: This file contains the definitions for
* the Turtle class.
*************************************************/
#include "Turtle.hpp"

/*************************************************
* Description: Default Constructor. For babies.
*************************************************/
Turtle::Turtle() : Animal(0)
{
	Turtle::setNumBabies(10);
	Turtle::setCost(100.00);
	Turtle::setBaseFoodCost(0.5 * BASE_FOOD_COST);
	Turtle::setPayoff(0.05 * 100.00);
}

/*************************************************
* Description: Constructor that takes in one int for
* age and passes it to the Animal constructor. For
* adults.
*************************************************/
Turtle::Turtle(int ageIn)
	: Animal(ageIn)
{
	Turtle::setNumBabies(10);
	Turtle::setCost(100.00);
	Turtle::setBaseFoodCost(0.5 * BASE_FOOD_COST);
	Turtle::setPayoff(0.05 * 100.00);
}

/*************************************************
* Description: Destructor.
*************************************************/
Turtle::~Turtle()
{
}

/*************************************************
* Description: Overloading the postfix ++ operator
* so that it is easier to increase the Turtles age.
*************************************************/
Turtle Turtle::operator+(int)
{
	Turtle temp = *this;
	age++;
	return temp;
}
