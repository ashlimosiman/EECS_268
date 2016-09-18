/**
*File: main.cpp
*Author: Ashli Mosiman
*KUID Number: 2819456
*Date Last Updated: March 29,2016
*Purpose: Declares all necessary objects and passes said objects to other classes to result
*					with the correctly translated format and prints out said result
**/

#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>
#include <vector>

#include "FileReader.h"
#include "Translator.h"

int main(int argc, char *argv[])
{
	std::string userFile = argv[1];//taking in a file
	std::vector<std::string> xmlCode;//establishing vector
	FileReader Agnes;//declaring object of FileReader class
	Translator Herbert;//declaring object of Translator class

	try//attempt to read file and convert format of the file
	{
		Agnes.extractInfo(userFile, xmlCode);//passing provided file and original vector to ...
		Herbert.convert(xmlCode);//, 0);//passing populated, and valid, vector to translate the format
	}
	catch(PreconditionViolationException& pve)
	{
		std::cout<<pve.what();//print out any errors that pop up during the checking process via FileReader
	}

	return(0);//ends program
}//end main
