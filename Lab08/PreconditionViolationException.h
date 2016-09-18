/**
 *File: PreconditionViolationException.h
 *Author: Ashli Mosiman
 *KUID Number: 2819456
 *Date Last Updated: March 23,2016
 *Purpose: Header file for the PreconditionViolationException class inheriting from std::runtime_error
**/




#ifndef PRECONDITIONVIOLATIONEXCEPTION_H
#define PRECONDITIONVIOLATIONEXCEPTION_H

#include <stdexcept>
#include <string>

class PreconditionViolationException: public std::logic_error
{
  public:
    PreconditionViolationException(const std::string& message="");
};
#endif
