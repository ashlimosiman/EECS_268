/**
 *File: main.cpp
 *Author: Ashli Mosiman
 *Date Last Updated: February 7,2016
 *Purpose: takes in file provided. Then creates an Executive object and calls on the run method.
**/
#include <iostream>
#include "Executive.h"
#include "DriversLicenseRecord.h"

int main(int argc, char* argv[])
{
	//takes in the provided file
	std::string filename = argv[1];
	//creating an Executive object
	Executive e(filename);
	//performs the run method
	e.run();

	return(0);
}
