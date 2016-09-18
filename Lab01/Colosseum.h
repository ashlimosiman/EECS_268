/*
 * Colosseum.h
 * Ashli Mosiman
 * 2819456
 * Last edited: February 2, 2016
 *Purpose: Colosseum's header file. Creates the game, by building
 *both Pokemon and taking turns attacking for up to ten rounds
 */

#ifndef COLOSSEUM_H
#define COLOSSEUM_H
#include<iostream>
#include "Dice.h"
#include "Pokemon.h"
#include <string>

class Colosseum
{
	private:
		Dice d20;
		Dice d6;
	public:
	/**
	*  @pre None
	*  @post Creates and initializes a Colosseum instance
	*  @return Initialzed Colosseum with a six-sided dice and twenty-sided dice
	*/
		Colosseum();
	/**
	*  @pre A Pokemon reference
	*  @post gets valid values for name, hp, attack, and defense and assigns them to a Pokemon
	*  @return None
	*/
		void userBuild(Pokemon& p);
	/**
	*  @pre two Pokemon references
	*  @post determines if the attacker's atack lands and, if so, subtracts a damage amount
	*  @return whether the Pokemon, defender, died or not
	*/
		bool attack(const Pokemon& attacker, Pokemon& defender);
	/**
	*  @pre two Pokemon references
	*  @post implements attack alternating attacking Pokemon 1 and attacking Pokemon 2 for a max of ten rounds
	*  @return None
	*/
		void play(Pokemon& p1, Pokemon& p2);

};
#endif
