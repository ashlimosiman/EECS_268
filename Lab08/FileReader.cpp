/**
*File: main.cpp
*Author: Ashli Mosiman
*KUID Number: 2819456
*Date Last Updated: March 29,2016
*Purpose: Reads the provided file into a vector.
*         Along with checking if it is within the rules defined in the lab instructions
**/


#include "FileReader.h"

FileReader::FileReader()
{
  fileLength=0;
  numOfP=0;
  numOfTab=0;
  numOfList=0;
}//end class definition

void FileReader::extractInfo(std::string info, std::vector<std::string>& populate) throw(PreconditionViolationException)
{
  std::ifstream content;
  content.open(info.c_str());//opening the file
  bool continuePrint=true;//continue to print the file if it's valid

  if(isEmpty(info)) //checks whether the file contains text of some sort. throws error
  {
    throw PreconditionViolationException("Provided file is empty\n\n");
  }
  else if(!(content.is_open()) || content.fail())//checking validity of the file: open or rotten?
  {                                                            //throws error
    throw PreconditionViolationException("Could Not Open The File\n\n");
  }
  else//continues testing otherwise
  {
    while(content>>info)//pushing file into a vector until end of the file is reached
    {
      if(isValid(info) && continuePrint)//pushes onto the vector if the string is within the defined rules and the previous inputs were okay
      {
        populate.push_back(info);
      }
      else//changes the bool to false if it hits an invalid input in order to stop validation/conversion process
      {
        continuePrint=false;
      }
    }

    content.close();//closing file

    if(numOfP > 0)//throws error if at least one 'p' tag is opened and not closed
    {
      throw PreconditionViolationException(" a paragraph tag was not closed.\n\n");
    }
    else if(numOfTab > 0)//throws error if at least one 'tab' tag is opened and not closed
    {
      throw PreconditionViolationException(" a tab tag was not closed.\n\n");
    }
    else if(numOfList > 0)//throws error if at least one 'listItem' tag is opened and not closed
    {
      throw PreconditionViolationException(" a listItem tag was not closed.\n\n");
    }
  }//end else
}//end extractInfo

bool FileReader::isEmpty(std::string file)
{
  std::ifstream content;
  content.open(file.c_str());//opening file

	content.seekg(0,content.end);//sending cursor to end of file
	fileLength=content.tellg();//claculating length of the file and inputting into an int variable

	content.close();//closing file

	if(fileLength == 0)//if the length of the file is 0, returns that the file is empty
	{
		return(true);
	}
	else//otherwise, says it contains information
	{
		return(false);
	}
}//end isEmpty

bool FileReader::isValid(std::string test) throw(PreconditionViolationException)
{
  char special[14]={'(', ')', '[', ']', '\'', ',', '!', '@', '#', '$', '%', '^', '&', '*'};//allowed symbols
  int check=1;
  if(test[0] != '<' && test.back() == '>')//no whitespace between content and tag
  {
    throw PreconditionViolationException("Whitespace is required before a closing tag.\n\n");
    return(false);
  }
  if(test[0] == '<')//checks if it's an open/close tag
  {
    if(!decentTag(test))//evaluates the validity of the tag
    {
      return(false);
    }
  }
  else if(test == ">")//string is just a closing angle bracket, meaning whitespace within a tag, throws error
  {
    throw PreconditionViolationException("Whitespace is not allowed within a tag's angle brackets.\n\n");
    return(false);
  }
  else//not a tag
  {
    for(unsigned int x=0;x<test.length();x++) //going through current string's characters, checking for validity
    {
      if(!(isalpha(test[x]) && !(isdigit(test[x]))))//rules out letters and numbers to check for legal symbols
      {
        check=0;
        for(int y=0; y<14; y++)//comparing to all allowed special characters
        {
          if(test[x] == special[y])
          {
            check++;//increasing established int, meaning it matches one of the characters in special[]
          }
        }//end second for loop
      }
    }//end first for loop

    if(check <= 0)//a non-alphanumeric character was found, but not allowed, throws
    {
      throw PreconditionViolationException("An inllegal character has snuck into your file.\n\n");
      return(false);
    }
  }//end else statement

  return(true);
}//end isValid

bool FileReader::decentTag(std::string test) throw(PreconditionViolationException)
{
  std::string openTag[3]={"<p>", "<tab>", "<listItem>"};
  std::string closeTag[3]={"</p>", "</tab>", "</listItem>"};

  if(test.length() < 3)//shortest possible tag length 3, if tag is less than three it contains whitespace, throws error
  {
    throw PreconditionViolationException("Whitespace is not allowed within a tag's angle brackets.\n\n");
    return(false);
  }

  if(test[0] == '<' && test[1] != '/')//checks only the open tags
  {
    if(test.back() != '>')
    {
      throw PreconditionViolationException("Whitespace is required after the open tag.\n\n");
    }

    if(test != openTag[0] && test != closeTag[0] && test != openTag[1] && test != closeTag[1] && test != openTag[2] && test != closeTag[2])
    { //illegal tag type, throws error
      throw PreconditionViolationException("Unknown open tag type used\n\n");
      return(false);
    }
    if(test == openTag[0] || test == openTag[1] || test == openTag[2])//checking if it's one of the three allowed tag types
    {
      if(test == openTag[0])//increase the count of 'p' tags currently open if it's a 'p' tag
      {
        numOfP++;
      }
      else if(test == openTag[1])//increase the count of 'tab' tags currently open if it's a 'tab' tag
      {
        numOfTab++;
      }
      else if(test == openTag[2])//increase the count of the 'listItem' tags currently open if it's a 'listItem' tag
      {
        numOfList++;
      }
      return(true);
    }
  }//end open tag if statement
  else if(test[0] == '<' && test[1] == '/')//checks only the closed tags
  {
    if(test.back() != '>')//whitespace within angle brackets, throws
    {
      throw PreconditionViolationException("Whitespace is required after the closing tag.\n\n");
      return(false);
    }
    if(test != openTag[0] && test != closeTag[0] && test != openTag[1] && test != closeTag[1] && test != openTag[2] && test != closeTag[2])
    { //illegal tag type, throws
      throw PreconditionViolationException("Unknown open tag type used\n\n");
      return(false);
    }

    if(test == closeTag[0] || test == closeTag[1] || test == closeTag[2])//checking if one of the three allowed closing tags
    {
      if(test == closeTag[0])//find out if 'p' tag
      {
        if(numOfP < 1)//no open 'p' tag detected before the current close tag, throws error
        {
          throw PreconditionViolationException("an opening \"paragraph\" tag must precede the closing tag.\n\n");
          return(false);
        }
        else//otherwise, decreases count of 'p' tags currently open
        {
          numOfP--;
        }
      }
      else if(test == closeTag[1])//find out if 'tab' tag
      {
        if(numOfTab < 1)//no open 'tab' tag detected before the current close tag, throws error
        {
          throw PreconditionViolationException("an opening \"tab\" tag must precede the closing tag.\n\n");
          return(false);
        }
        else//otherwise, decreases count of 'tab' tags currently open
        {
          numOfTab--;
        }
      }
      else if(test == closeTag[2])//find out if 'listItem' tag
      {
        if(numOfList < 1)//no open 'listItem' tag detected before the current close tag, throws error
        {
          throw PreconditionViolationException("an opening \"listItem\" tag must precede the closing tag.\n");
          return(false);
        }
        else//otherwise, decreases count of 'listItem' tags currently open
        {
          numOfList--;
        }
      }
    }//ends if statement for allowed three tag types
  }//ends else if statement for general close tags
  return(true);//passed all tests, it may move onto the next round towards receiving a whole new format!
}//end decentTag
