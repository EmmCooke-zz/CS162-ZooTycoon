#include <iostream>
using std::cout;
using std::cin;

#include <string>
using std::string;
using std::to_string;

#include <climits>
#include <cfloat>

#include "validateInput.hpp"

/*************************************************************
 * Description: This function takes in a string and then checks
 * each character within the string to see if it is in the range
 * 0 to 9. If it is, it returns true. If it is not, it exits the
 * while loop and returns false.
 *************************************************************/
bool checkStringToInt(string stringIn)
{
	if (stringIn == "")
	{
		return false;
	}
	for (char c : stringIn)
	{
		int asciiValue = int(c);
		if (asciiValue < 48 || asciiValue > 57)
		{
			return false;
		}
	}
	return true;
}

/*************************************************************
* Description: This function takes in a string and then checks
* to see if the size of the int is within the valid size of an int.
* If it is not, it returns -1. Otherwise, it returns the int.
*************************************************************/
int getInt(string stringIn)
{
	if (checkStringToInt(stringIn))
	{
		string maxInt = to_string(INT_MAX);
		if (stringIn.length() < maxInt.length())
		{
			int validInt = stoi(stringIn);
			if (validInt > INT_MAX || validInt < INT_MIN)
			{
				return -1;
			}
			return validInt;
		}
	}
	return -1;
}

/*************************************************************
* Description: This function takes in a string and then checks
* to see if the size of the int is within the valid size of a double.
* If it is not, it returns -1. Otherwise, it returns the double.
*************************************************************/
double getDouble(string stringIn)
{
	int period = stringIn.find('.');
	string quotient = stringIn.substr(0, period),
		dividend = stringIn.substr(period + 1, stringIn.size() - period - 1);
	if (checkStringToInt(quotient) && checkStringToInt(dividend))
	{
		string maxDouble = to_string(DBL_MAX);
		if (stringIn.length() < maxDouble.length())
		{
			double validDouble = stod(stringIn);
			if (validDouble > DBL_MAX || validDouble < DBL_MIN)
			{
				return -1;
			}
			return validDouble;
		}
	}
	return -1;
}
