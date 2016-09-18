/**
*File: main.cpp
*Author: Ashli Mosiman
*KUID Number: 2819456
*Date Last Updated: March 03,2016
*Purpose: Converts Postfix to Infix form
**/


#include <iostream>
#include <cctype>
#include <string>
#include <stdexcept>
#include <limits>
#include "Stack.h"
#include "PrecondViolatedExcep.h"

/**
*  @pre the user's input, type string
*  @post determines if the string passed through is valid
*  @return true/false based on whether the string is a valid postfix string
*/
bool isValid(std::string input);

/**
*  @pre the user's input, type string
*  @post prints out the input string manipulated into infix form
*  @return None
*/
void convert(std::string post);

int main(int argc, char *argv[])
{
	std::string input;
	std::cout<<'\n'<<"Enter # to end the program."<<'\n'<<'\n';
	while(input.find_first_of("#") == std::string::npos)//runs until user quits
	{
		//takes in a string
		std::cout<<"Enter a string: ";
		std::getline(std::cin, input, '\n');

		while(!isValid(input))//prompts for a valid input if received invalid input
		{
			std::cout<<"Enter a string: ";
			std::getline(std::cin, input, '\n');
		}//end while loop

		try
		{
			convert(input);//converts from Postfix to Infix
		}
		catch(PrecondViolatedExcep& pve)
		{
		std::cout<<pve.what();
		}
	}//end while loop



	std::cout<<"Have A Groovy Day and May The Force be With You!"<<endl; //Indicates end of Program

	return(0);//ends program
}//end main


bool isValid(std::string input)
{
	int alphaCnt=0;
	int operCnt=0;
	std::size_t found=0;
	found=input.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz#+-*/");//	Allowed Characters
	unsigned int firstOp=input.find_first_of("/*-+");//position of first operator


	if(input.length() > 50)//Limits Character intake to 50 characters
	{
		std::cout<<"You entered an invalid postfix string: it contains "<<input.length()<<"  characters instead of the allowed 50"<<endl;
		return(false);
	}

	for(unsigned int x=0; x<input.length(); x++)//rejecting pesky little spaces
	{
		if(input[x] == ' ')
		{
			std::cout<<"A space was detected, which is not allowed"<<endl;
			return(false);
		}
	}

	if(found != std::string::npos)//sniffs out rebel characters trying to crash the string party
	{
		std::cout<<"You entered an invalid postfix string: it contains the illegal character '"<<input[found]<<"'"<<endl;
		return(false);
	}

	for(unsigned int x=0;x<input.length();x++)//counting letters and operators
	{
		if(input[x] != '#')
		{
			if(isalpha(input[x]))//increasing letter count if char at index x is a letter
			{
				alphaCnt++;
			}
			else if(input[x] == '/' || input[x] == '*' || input[x] == '-' || input[x] == '+')//otherwise, adds to the operator count
			{
				operCnt++;
			}
		}//end if
	}//end for

	if(((alphaCnt == 0) || (operCnt == 0)) && (input.find_first_of("#") == std::string::npos))//if no characters were entered
	{
		std::cout<<"It looks like nothing was entered"<<endl;
		return(false);
	}
	else if(((alphaCnt-1) > operCnt))//prints error if not enough operators
	{
		if(input.find_first_of("#") == std::string::npos)//prevents '#' from printing out an error
		{
			std::cout<<"You entered an invalid postfix string: it is missing one or more operators"<<endl;
			return(false);
		}
	}

	if(firstOp < 2)//enforces Postfix form
	{
		std::cout<<"You entered an invalid postfix string: it needs at least two operands in the beginning"<<endl;
		return(false);
	}

	return(true);//returning true if it passes all above obstacles
}//end method

void convert(std::string post)
{
	Stack<std::string> theStack;
	std::string bit1;
	std::string bit2;
	std::string result;

	if(post.find_first_of("#") == std::string::npos)//prevents # from being manipulated, so it can just shut down the party and go home
	{
		for(unsigned int x=0; x < post.length(); x++)//runs through provided string character by character
		{
			if(isalpha(post[x]))//pushes variables onto the Stack
			{
				bit1=post[x];
				theStack.push(bit1);
			}
			else//compines pieces to form the Infix version of the provided equation
			{
				bit1=theStack.peek();//second piece
				theStack.pop();//removes from Stack

				bit2=theStack.peek();//first piece
				theStack.pop();//removes from Stack

				result="(" + bit2 + post[x] + bit1 + ")";//Frankesteins the bits together
				theStack.push(result);//puts on the Stack
			}
		}//end for loop
		std::cout<<"You entered a valid postfix string. The equivalent infix: "<<result<<endl;
		while(!theStack.isEmpty())
		{
			theStack.pop();
		}
	}//end if loop
}//end Method
