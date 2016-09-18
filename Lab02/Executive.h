/**
 *File: Executive.h
 *Author: Ashli Mosiman
 *KUID Number: 2819456
 *Date Last Updated: February 7,2016
 *Purpose: Header file of the Executive class
**/

#ifndef EXECUTIVE_H
#define EXECTUIVE_H
#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include "DriversLicenseRecord.h"

class Executive
{
	private:
		DriversLicenseRecord *records;
		int numRecords;
		std::ifstream info;
	public:
	/**
	*  @pre a constant string, filename
	*  @post Opens the provided file. Along with making and filling an array pointer, records
	*  @return None
	*/
		Executive(const std::string filename);
	/**
	*  @pre None
	*  @post Deletes Heap-allocated objects. The DriversLicenseRecord pointer array, in the is case
	*  @return None
	*/
		~Executive();
	/**
	*  @pre None
	*  @post Gives user options and implements the correct method to run said option
	*  @return None
	*/
		void run();
	/**
	*  @pre a string name, the established and full pointer array, records
	*  @post runs through the array comparing each Last Name to the name received from the user. Prints every one that matches or an error message
	*  @return None
	*/
		void queryLastName(std::string name, DriversLicenseRecord *records);
	/**
	*  @pre two integers, min and max;the established and full pointer array, records
	*  @post runs through the array comparing each Age  to the Age range received from the user. Prints all that fit in the age range or an error message.
	*  @return None
	*/
		void queryAgeRange(int min, int max, DriversLicenseRecord *records);
	/**
	*  @pre a character, vote; the established and full pointer array, records
	*  @post runs through the array comparing each character (Y or N) to the character received from the user. Prints every corresponding person or an error message.
	*  @return
	*/
		void queryRegistered(char vote, DriversLicenseRecord *records);
};

#endif
