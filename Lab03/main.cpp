/**
 *File: main.cpp
 *Author: Ashli Mosiman
 *Date Last Updated: February 15,2016
 *Purpose: COMPLETE
**/
#include <iostream>
#include "Test_LinkedList.h"

int main(int argc, char *argv[])
{
	int testSize = std::stoi(argv[1]); //convert from char* to int
	Test_LinkedList tester(testSize); //create a tester
	tester.runTests(); //run tests
	return(0);
}
