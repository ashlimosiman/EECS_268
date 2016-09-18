/**
 *File: main.cpp
 *Author: Ashli Mosiman
 *KUID Number: 2819456
 *Date Last Updated: February 18,2016
 *Purpose: Takes in a number and determines whether it's a palindrome along with implementing the test
**/
#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
#include "Test_Stack.h"
#include "Stack.h"
#include "Node.h"
#include "StackInterface.h"
#include "PreconditionViolationException.h"

int main(int argc, char *argv[])
{
/*
	--------------------------------
		IMPLEMENTS TEST
	--------------------------------
*/
	int testSize = std::stoi(argv[1]); //convert from char* to int
	Test_Stack tester(testSize); //create a tester
	tester.runTests(); //run tests

/*
	-----------------------------------
		PALINDROME INQUIRY
	-----------------------------------
*/

	char choice='n';
	bool isCorrect=true;
	int num=0;
	int pushVal=0;
	int posNum=0;
	
	//continues the inquiry until the user puts 'y' for wants to quit
	while(choice == 'n')
	{

		//asking and receiving a number from user
		std::cout<<"Input a number: ";
		std::cin>>num;

		//keeps clearing bad inputs and  inquiring after a number until the user inputs an integer
		while(std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			std::cout<<"Apologies, but this requires numbers only. Please try again: ";
			std::cin>>num;
		}


		//making the normal Stack
		Stack<int> normStack;

		//three cases:

		//num is zero, will push zero onto stack
		if(num == 0)
		{
			normStack.push(num);
		}
		//num is positive, will push each integer onto stack starting at ones place and moving up
		else if(num > 0)
		{
			while(num > 0)
			{
				pushVal=num%10;
				normStack.push(pushVal);
				num=num/10;
			}
		}
		//num is negative, another integer set to equal num times -1 and added to the stack in the same way as a positive value
		else if(num < 0)
		{
			posNum=num*(-1);
			while(posNum > 0)
			{
				pushVal=posNum%10;
				normStack.push(pushVal);
				posNum=posNum/10;
			}
		}

		//making the reverse Stack of the normal Stack
		Stack<int> revStack=normStack.makeRevStack();

		//if isPalindrome() method comes back false, it will print out the given integer, the ineger backwards, 
		//and state the given integer is not a palindrome
		if(!normStack.isPalindrome(revStack))
		{
			normStack.printStack(num);
			std::cout<<" backwards is ";
			revStack.printStack(num);
			std::cout<<'\n';
			normStack.printStack(num);
			std::cout<<" is not a palindrome"<<'\n';
		}
		//if the method comes back true, it will print out the same as above, except say the given integer IS  a palindrome
		else
		{
			normStack.printStack(num);
			std::cout<<" backwards is ";
			revStack.printStack(num);
			std::cout<<'\n';
			normStack.printStack(num);
			std::cout<<" is a palindrome"<<'\n';
		}


		//asking user if they want to continue and responding accordingly
		std::cout<<"Do you want to quit? (y/n): ";
		std::cin>>choice;

		//allows uppercase and lowercase of y and n
		if(choice == 'N')
		{
			choice = 'n';
		}
		else if(choice == 'Y')
		{
			choice = 'y';
		}

		//checking that user put a y or n
		if(choice != 'n' && choice != 'y')
		{
			isCorrect=false;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		}
		else if(choice == 'n' || choice == 'y')
		{
			isCorrect=true;
		}

		//prints out error message and keeps asking if they want to quit until they put a correct response
		while(isCorrect == false)
		{
			std::cout<<"That is not an option. Plaese type y or n"<<'\n';
			std::cout<<"Do you want to quit? (y/n): ";
			std::cin>>choice;

			if(choice == 'N')
			{
				choice = 'n';
			}
			else if(choice == 'Y')
			{
				choice = 'y';
			}

			if(choice != 'n' && choice != 'y')
			{
				isCorrect=false;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			}
			else if(choice == 'n' || choice == 'y')
			{
				isCorrect=true;
			}
		}
	}
	//prints out exiting message
	std::cout<<"Thanks! Exiting..."<<'\n';

	return(0);
}
