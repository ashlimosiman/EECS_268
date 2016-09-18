/*
 * Pokemon.h
 * Ashli Mosiman
 * 2819456
 * Last edited: February 2, 2016
 *Purpose: Pokemon's header file. Creates a Pokemon object with a name, 
 *	hp, attack, and defense values given by the user later on.
 */

#ifndef POKEMON_H
#define POKEMON_H
#include <string>

class Pokemon
{
	private:
		int m_hp;
		int m_attackLevel;
		int m_defenseLevel;
		std::string m_name;
	public:
	/**
	*  @pre None
	*  @post Creates and initializes a Pokemon instance
	*  @return Initializes all ints to zero and string to an empty string
	*/
		Pokemon();
	/**
	*  @pre an integer amount to subtract from the Pokemon's hp
	*  @post takes the Pokemon's hp down by amount
	*  @return None
	*/
		void reduceHP(int amount);
	/**
	*  @pre None
	*  @post gives the current HP of the Pokemon
	*  @return Pokemon's HP
	*/
		int getHP() const;
	/**
	*  @pre an integer of HP between 1 and 50
	*  @post establishes the Pokemon's HP received from the user
	*  @return None
	*/
		void setHP(int hp);
	/**
	*  @pre None
	*  @post gives the current Attack Level of the Pokemon
	*  @return Pokemon's Attack Level
	*/
		int getAttackLevel() const;
	/**
	*  @pre an integer of Attack between 1 and 49
	*  @post establishes Attack Level received from the user
	*  @return None
	*/
		void setAttackLevel(int atk);
	/**
	*  @pre None
	*  @post gives current Defense Level of the Pokemon
	*  @return Pokemon's Defense Level
	*/
		int getDefenseLevel() const;
	/**
	*  @pre an integer of Defense between 1 and (fifty minus Attack Level)
	*  @post establishes Defense Level received from the user
	*  @return None
	*/
		void setDefenseLevel(int def);
	/**
	*  @pre None
	*  @post gives the name of the Pokemon
	*  @return Pokemon's Name
	*/
		std::string getName() const;
	/**
	*  @pre a String
	*  @post establishes the Pokemon's name received from the user
	*  @return None
	*/
		void setName(std::string choice);
};
#endif
