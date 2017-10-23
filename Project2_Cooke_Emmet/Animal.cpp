/*************************************************
* Author: Emmet Cooke
* Date: 10/20/2017
* Description: This file contains the definitions for
* the Animal class.
*************************************************/
#include "Animal.hpp"

/*************************************************
* Description: Default Constructor.
*************************************************/
Animal::Animal()
{
	setAge(0);
}

/*************************************************
* Description: Constructor that takes in one int for
* the age of the animal.
*************************************************/
Animal::Animal(int ageIn)
{
	setAge(ageIn);
}

/*************************************************
* Description: Destructor.
*************************************************/
Animal::~Animal()
{
}
