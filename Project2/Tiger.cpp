/*************************************************
* Author: Emmet Cooke
* Date: 10/20/2017
* Description: This file contains the definitions for
* the Tiger class.
*************************************************/
#include "Tiger.hpp"

/*************************************************
* Description: Default Constructor. For babies.
*************************************************/
Tiger::Tiger() : Animal(1)
{
	Tiger::setNumBabies(1);
	Tiger::setCost(10000.00);
	Tiger::setBaseFoodCost(5);
	Tiger::setPayoff(0.2);
}

/*************************************************
* Description: Constructor that takes in one int for
* age and passes it to the Animal constructor. For 
* adults.
*************************************************/
Tiger::Tiger(int ageIn)
	: Animal(ageIn)
{
	Tiger::setNumBabies(1);
	Tiger::setCost(10000.00);
	Tiger::setBaseFoodCost(5);
	Tiger::setPayoff(0.2);
}

/*************************************************
* Description: Destructor.
*************************************************/
Tiger::~Tiger()
{
}

/*************************************************
* Description: Overloading the postfix ++ operator
* so that it is easier to increase the tigers age.
*************************************************/
Tiger Tiger::operator+(int)
{
	Tiger temp = *this;
	age++;
	return temp;
}
