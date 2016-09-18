/**
*File: main.cpp
*Author: Ashli Mosiman
*KUID Number: 2819456
*Date Last Updated: March 08,2016
*Purpose: checks for valid inputs, and runs the program
**/

#include <iostream>
#include <string>

//including Knight class
#include "Knight.h"

/**
*  @pre received four numbers when executing the program
*  @post checks the four integers are valid inputs
*  @return true/false based on if the values are valid integers
*/
bool isValid(int boardRow, int boardCol, int posRow, int posCol);

int main(int argc, char *argv[])
{
	int row = std::stoi(argv[1]);//number of rows on the board
	int col = std::stoi(argv[2]);//number of columns on the board
	int startRow = std::stoi(argv[3]);//row index for Knight's starting position
	int startCol = std::stoi(argv[4]);//column index for Knight's starting position

	if(isValid(row, col, startRow, startCol))//enters statement if valid integers were passed in
	{
		Knight herman(row, col, startRow, startCol);//declares object of Knight class
		herman.tracker();//calling method to run the program with the four given values
	}//ends if

	return(0);//ends program
}//end main

bool isValid(int boardRow, int boardCol, int posRow, int posCol)
{
	//claculates how off the starting position compared to the dimensions of the board
	int rowGauge=posRow-boardRow;
	int colGauge=posCol-boardCol;

	if(rowGauge < 0)//turns negative number to positive
	{
		rowGauge=rowGauge*(-1);
	}
	if(colGauge < 0)//turns negative number to positive
	{
		colGauge=colGauge*(-1);
	}


	if(boardRow == 0 || boardCol == 0)//error message if zero passed in as parameter for board size
	{
		std::cout<<"Error: The board must be at least 1x1, but I bet a bigger board would be more interesting.... just saying."<<'\n'<<'\n';
		return(false);
	}
	else if(boardRow < 0 || boardCol < 0)//error message if a negative number passed in as parameter for board size
	{
		std::cout<<"Error: The board must be at least 1x1, but I b.... how am I supposed to make a board with negative parameters?!"<<'\n';
		std::cout<<"Good Grief!"<<'\n'<<'\n';
		return(false);
	}

	if(posRow < 0 || posRow >= boardRow || posCol < 0 || posCol >= boardCol)//checks the starting position for the Knight is on the board
	{
		std::cout<<"Error: The Knight must start on the board."<<'\n'<<'\n';

		if(rowGauge >= 100 || colGauge >= 100)//prints an extra statement if the starting position is excessively off the board
		{
			std::cout<<"Woah, Nelly! That is just too dang far off! How about you peruse the following advise:"<<'\n'<<'\n';
		}

		std::cout<<"In this case, the initial row position must be equal to or between 0 and "<<(boardRow-1)<<","<<'\n';
		std::cout<<'\t'<<"and the initial column position must be equal to or between 0 and "<<(boardCol-1)<<"."<<'\n'<<'\n';
		return(false);
	}//end if

	return(true);//returns true if passed all above tests
}//end isValid method
