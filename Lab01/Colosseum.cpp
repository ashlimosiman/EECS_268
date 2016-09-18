/*
 * Colosseum.cpp
 * Ashli Mosiman
 * 2819456
 * Last edited: February 2, 2016
 *Purpose: This has three methods to run the game.
 */

#include "Colosseum.h"

Colosseum::Colosseum()
{
	d20=Dice(20);
	d6=Dice(6);
}

void Colosseum::userBuild(Pokemon& p)
{
	std::string name="";
	int hp=0;
	int attack=0;
	int defense=0;
	int x=0;

	std::cout<<"Please name your Pokemon: ";
	std::cin>>name;

	std::cout<<"How many hit points will it have? (1-50): ";
	std::cin>>hp;
//prompts user until they put a valid hp value within the range
	while(hp < 1 || hp > 50)
	{
		std::cout<<"Sorry. Your hit points need to be between 1 and 50: ";
		std::cin>>hp;
	}

	std::cout<<"Split fifty points between attack level and defense level\nEnter your attack level (1-49): ";
	std::cin>>attack;
//prompts user until they put a valid attack value within the range
	while(attack < 1 || attack > 49)
	{
		std::cout<<"Sorry. Your attack needs to be between 1 and 49: ";
		std::cin>>attack;
	}
//subtracts attack value to give a range for the defense
	x=50-attack;
	std::cout<<"Enter your defense level (1-"<< x <<"): ";
	std::cin>>defense;
//prompts user until they put a valid defense value within the range
	while(defense < 1 || defense > x)
	{
		std::cout<<"Sorry. Your defense level needs to be between 1 and "<< x <<": ";
		std::cin>>defense;
	}
//sets values to the Pokemon
	p.setName(name);
	p.setHP(hp);
	p.setAttackLevel(attack);
	p.setDefenseLevel(defense);

}

bool Colosseum::attack(const Pokemon& attacker, Pokemon& defender)
{
	int attackBonus=0;
	int defenseBonus=0;
	int att=0;
	int def=0;
	int roll1=0;
	int roll2=0;
	int roll3=0;
	std::string nameA=attacker.getName();
	std::string nameD=defender.getName();

	attackBonus=d20.roll();
	defenseBonus=d20.roll();
	att=attacker.getAttackLevel() + attackBonus;
	def=defender.getDefenseLevel() + defenseBonus;

	std::cout<< nameA <<" is attacking "<< nameD <<'\n';
	std::cout<< nameA <<" rolls an attack bonus of "<< attackBonus <<'\n';
	std::cout<< nameD <<" rolls a defense bonus of "<< defenseBonus <<'\n';
//compares the sum of the attacker's attack and the sum of the defender's defense
	if(att > def)
	{
//rolls three six-sided die and subtracts the sum of the rolls from the defender's hp
		std::cout<<"The attack hits dealing 3-D6 damage!\n";
		roll1=d6.roll();
		roll2=d6.roll();
		roll3=d6.roll();
		int total=roll1+roll2+roll3;
		std::cout<<"The rolls are "<< roll1 <<", "<< roll2 <<", and "<< roll3 <<" totaling: "<< total <<" damage!\n";
		defender.reduceHP(total);
//determining if the defender died
		if(defender.getHP() <= 0)
		{
			return(true);
		}
		else
		{
			return(false);
		}
	}
//stating the attack missed in the defender's defense is greater than the attacker's attack
	else
	{
		std::cout<<"The attack missed!\n";
		return(false);
	}
}

void Colosseum::play(Pokemon& p1, Pokemon& p2)
{
	int round=0;
	Dice d2(2);
	int first=d2.roll();//"rolls" two-sided dice to determine which Pokemon goes first
	bool p1Beat;
	bool p2Beat;

	std::cout<<"\nChoosing which player will go first:\n";
	//Player 1 goes first
	if(first == 1)
	{
		std::cout<<"Player 1 will go first.\n";
//keeps the rounds limited to ten
		while(round <= 10)
		{
			std::cout<<"\nRound "<< ++ round <<"!\n\n";
			p2Beat=attack(p1,p2);
//ends game if Pokemon 2 dies
			if(p2Beat)
			{
				std::cout<< p2.getName() <<" has been defeated!\nBrilliant work, "<< p1.getName() <<"!\n";
				break;
			}
//continues game and states Pokemon 2's hp after damage is subtracted
			else
			{
				std::cout<< p2.getName() <<" has "<< p2.getHP() <<" hit points left\n";
				p1Beat=attack(p2,p1);
//end game if Pokemon 1 dies
				if(p1Beat)
				{
					std::cout<< p1.getName() <<" has been defeated!\nBrilliant work, "<<p2.getName() <<"!\n";
					break;
				}
//states the game is a draw if both Pokemon are still alive after round ten
				else if(round == 10)
				{
					std::cout<<"Blast it! Both Pokemon are too strong! It's a draw....this time.\n";
					break;
				}
//continues game and states Pokemon 1's hp after damage is subtracted
				else
				{
					std::cout<< p1.getName() <<" has "<< p1.getHP() <<" hit points left\n";
				}
			}

		}
	}
	//Player 2 goes first
	else
	{
		std::cout<<"Player 2 will go first.\n";
//keeps the rounds limited to ten
		while(round <= 10)
		{
			std::cout<<"\nRound "<< ++ round <<"!\n\n";
			p1Beat=attack(p2,p1);
//end game if Pokemon 1 dies
			if(p1Beat)
			{
				std::cout<< p1.getName() <<" has been defeated!\nBrilliant work, "<< p2.getName() <<"!\n";
				break;
			}
//continues game and states Pokemon 1's hp after damage is subtracted
			else
			{
				std::cout<< p1.getName() <<" has "<< p1.getHP() <<" hit points left\n";
				p2Beat=attack(p2,p1);
//ends game if Pokemon 2 dies
				if(p2Beat)
				{
					std::cout<< p2.getName() <<" has been defeated!\nBrilliant work, "<<p1.getName() <<"!\n";
					break;
				}
//states the game is a draw if both Pokemon are still alive after round ten
				else if(round == 10)
				{
					std::cout<<"Blast it! Both Pokemon are too strong! It's a draw....this time.\n";
					break;
				}
//continues game and states Pokemon 2's hp after damage is subtracted
				else
				{
					std::cout<< p2.getName() <<" has "<< p2.getHP() <<" hit points left\n";
				}
			}

		}
	}

}
