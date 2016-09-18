/*
 * main.cpp
 * Ashli Mosiman
 * 2819456
 * Last edited: February 2, 2016
 *Purpose: implements the classes to create the game as well as loops it
 *	as long as the user wants to play again
 */

#include <iostream>
#include <string>
#include "Dice.h"
#include "Pokemon.h"
#include "Colosseum.h"

int main()
{
	Pokemon p1;
	Pokemon p2;
	Colosseum field;
	char replay='y';

//loops the game as long as the user wants to play again
	while(replay == 'y')
	{
//building the Pokemon
		std::cout<<"Player 1, build your Pokemon!\n======================\n";
		field.userBuild(p1);
		std::cout<<"Player 2, build your Pokemon!\n======================\n";
		field.userBuild(p2);
//implements play
		field.play(p1,p2);
//asking if they want to play again
		std::cout<<"\nDo you want to play again? (y/n): ";
		std::cin>>replay;
		std::cout<<'\n';

	}
//exits loop and ends the game
	if(replay == 'n')
	{
		std::cout<<"Thanks for playing!\n\n";
	}
	else
	{
		std::cout<<"That is not an option, but thank you for playing! Ending ...\n\n";
	}

	return(0);
}
