/**
 *File: PreconditionViolationException.cpp
 *Author: Ashli Mosiman
 *KUID Number: 2819456
 *Date Last Updated: February 17,2016
 *Purpose: Defines he method from the header file, which will catch errors
**/

#include "PreconditionViolationException.h"

PreconditionViolationException::PreconditionViolationException(const char* message): std::runtime_error(message)
{
  
}
