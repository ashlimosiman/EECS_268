/*
 * Pokemon.cpp
 * Ashli Mosiman
 * 2819456
 * Last edited: February 2, 2016
 *Purpose: creates an object called Pokemon. Takes in basic values(name, 
 *	hp,attack,defense)
 */

#include "Pokemon.h"

Pokemon::Pokemon()
{
	m_hp=0;
	m_attackLevel=0;
	m_defenseLevel=0;
	m_name="";
}

void Pokemon::reduceHP(int amount)
{
	int hp=m_hp;
//sets hp to zero if hp equals or is less than zero
	if(hp-amount <= 0)
	{
		hp=0;
	}
//otherwise it just subtracts
	else
	{
		hp=hp-amount;
	}
	m_hp=hp;
}

int Pokemon::getHP() const
{
	return(m_hp);
}

void Pokemon::setHP(int hp)
{
	m_hp=hp;
}

int Pokemon::getAttackLevel() const
{
	return(m_attackLevel);
}

void Pokemon::setAttackLevel(int atk)
{
	m_attackLevel=atk;
}

int Pokemon::getDefenseLevel() const
{
	return(m_defenseLevel);
}

void Pokemon::setDefenseLevel(int def)
{
	m_defenseLevel=def;
}

std::string Pokemon::getName() const
{
	return(m_name);
}

void Pokemon::setName(std::string choice)
{
	m_name=choice;
}
