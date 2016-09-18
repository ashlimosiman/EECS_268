/**
*File: FileReader.h
*Author: Ashli Mosiman
*KUID Number: 2819456
*Date Last Updated: March 23,2016
*Purpose:Header file for FileReader class
**/

#ifndef FILEREADER_H
#define FILEREADER_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>
#include <vector>

#include "PreconditionViolationException.h"

class FileReader
{
  private:
    int fileLength;
    int numOfP;
    int numOfTab;
    int numOfList;

  public:
    /**
  	*  @pre None
  	*  @post sets private member variables to respective zero
  	*  @return None
  	*/
    FileReader();

    /**
  	*  @pre a vector of strings and the file name, string, passed in
  	*  @post populates vector with info in the file, throws if invalid content is within or in wrong format
  	*  @return None
  	*/
    void extractInfo(std::string info, std::vector<std::string>& populate) throw(PreconditionViolationException);

    /**
  	*  @pre file name, a string, passed in
  	*  @post checks if the file contains characters or is empty
  	*  @return true/false whether the file is empty or not
  	*/
    bool isEmpty(std::string file);

    /**
  	*  @pre string passed in
  	*  @post correct tag with whitespace in allowed places or string containing allowed characters, throws if one of these is not true
  	*  @return true/false whether the string is indeed a valid string
  	*/
    bool isValid(std::string test) throw(PreconditionViolationException);

    /**
  	*  @pre a string passed in, specifically a tag
  	*  @post checks the tag if it's an allowed type and no whitespace within the angle brackets, throws if one of these is not true
  	*  @return true/false whether the tag passes the tests
  	*/
    bool decentTag(std::string test) throw(PreconditionViolationException);

};

#endif //FILEREADER_H
