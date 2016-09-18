/**
 *File: PreconditionViolationException.h
 *Author: Ashli Mosiman
 *KUID Number: 2819456
 *Date Last Updated: February 17,2016
 *Purpose: Header file for the PreconditionViolationException class inheriting from std::runtime_error
**/

#ifndef PRECONDITIONVIOLATIONEXCEPTION_H
#define PRECONDITIONVIOLATIONEXCEPTION_H

#include <stdexcept>
#include <string>

class PreconditionViolationException: public std::runtime_error
{
	public:
	/**
	*  @prean error was made
	*  @post prints out a message according to the error
	*  @return None
	*/
		PreconditionViolationException(const char* message);
};
#endif
