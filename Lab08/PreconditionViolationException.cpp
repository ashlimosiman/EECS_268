/**
 *File: PreconditionViolationException.cpp
 *Author: Ashli Mosiman
 *KUID Number: 2819456
 *Date Last Updated: March,2016
 *Purpose: Defines he method from the header file, which will catch errors
**/

//EVERYTHING
#include "PreconditionViolationException.h"


PreconditionViolationException::PreconditionViolationException(const std::string& message): std::logic_error("\nInvalid XML file: " + message)
{
}  // end constructor
