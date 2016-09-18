/**
*File: Translator.cpp
*Author: Ashli Mosiman
*KUID Number: 2819456
*Date Last Updated: April 4,2016
*Purpose: translating the content in the xml Code to regular format based on the three allowed tags
**/

#include "Translator.h"

Translator::Translator()
{
  pTag=0;
  tabTag=0;
  listTag=0;
}//end general class definition

void Translator::convert(std::vector<std::string>& inputs)
{
  std::cout<<'\n';//prints empty line (just for personal preference)
  for(unsigned int i=0; i<inputs.size();i++)//running through the populated vector
  {
    if(!isTag(inputs.at(i)))//means it is text to print and not a tag
    {
      if((inputs.at(i-1) == "<p>") || (inputs.at(i-1) == "<tab>") || (inputs.at(i-1) == "<listItem>"))
      {
        if(tabTag > 0)//at least one 'tab' tag open
        {
          for(int x=0; x<tabTag; x++)//prints a tab for however many tabs are open
          {
            std::cout<<'\t';
          }
        }
        if(listTag > 0)//at least one 'listItem' tag open
        {
          for(int x=0;x<listTag;x++)//prints astericks(*) for however many tabs are open
          {
            std::cout<<'*';
          }
        }
      }
      if((inputs.at(i-1) != "<p>") && (inputs.at(i-1) != "<tab>") && (inputs.at(i-1) != "<listItem>"))
      { //prints space prior to current string if the previous string is not a tag as well
        std::cout<<' '<<inputs.at(i);
      }
      else//indeed the previous string was a tag, so no space is printed before the current string is printed
      {
        std::cout<<inputs.at(i);
      }
      if(inputs.at(i+1) == "</listItem>")//goes to new line only when the listItem tag is closed
      {
        if(listTag > 0)//prints a new line if at least one 'listItem' tag is open
        {
          std::cout<<'\n';
        }
      }
    }//end else statement
  }//end for loop
  //std::cout<<'\n';//prints empty line (just for personal preference)
}//end convert method

bool Translator::isTag(std::string compare)
{
  if(compare == "<tab>")//opening tab tag
  {
    tabTag++;
    return(true);
  }
  if(compare == "<p>")//opening p tag
  {
    pTag++;
    return(true);
  }
  if(compare == "<listItem>")//opening listItem tag
  {
    listTag++;
    return(true);
  }

  if(compare == "</tab>")//closing tab tag
  {
    tabTag--;
    return(true);
  }
  if(compare == "</p>")//closing p tag and will print out a blank line
  {
    pTag--;
    std::cout<<"\n\n";
    return(true);
  }
  if(compare == "</listItem>")//closing listItem tag
  {
    listTag--;
    return(true);
  }

  return(false);//not a tag
}//end isTag method
