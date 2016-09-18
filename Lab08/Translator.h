/**
*File: Translator.h
*Author: Ashli Mosiman
*KUID Number: 2819456
*Date Last Updated: April 4,2016
*Purpose:Header file for Translator class
**/

#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>


class Translator
{
  private:
    int pTag;
    int tabTag;
    int listTag;

  public:
    /**
  	*  @pre None
  	*  @post sets all private member variables to respective zero
  	*  @return None
  	*/
    Translator();

    /**
  	*  @pre vector of strings passed in and populated and an integer representing position within the vector
  	*  @post prints content in correct format, relating to the tags
  	*  @return None
  	*/
    void convert(std::vector<std::string>& inputs);//, unsigned int pos);

    /**
  	*  @pre string passed in
  	*  @post compares to allowed tags, open or closed
  	*  @return true/false based on whether it's a tag
  	*/
    bool isTag(std::string compare);

};
#endif //TRANSLATOR_H
