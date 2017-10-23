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
Tiger::Tiger() : Animal(0)
{
	Tiger::setNumBabies(1);
	Tiger::setCost(10000.00);
	Tiger::setBaseFoodCost(5 * BASE_FOOD_COST);
	Tiger::setPayoff(0.2 * 10000.00);
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
	Tiger::setBaseFoodCost(5 * BASE_FOOD_COST);
	Tiger::setPayoff(0.2 * 10000.00);
}

/*************************************************
* Description: Destructor.
*************************************************/
Tiger::~Tiger()
{
}