/**
*File: main.cpp
*Author: Ashli Mosiman
*KUID Number: 2819456
*Date Last Updated: February 28,2016
*Purpose: Runs Lydia's Latte by taking in a file and adding customers/making orders.
**/

#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>
#include <vector>
#include "Stack.h"
#include "Queue.h"
#include "PrecondViolatedExcep.h"

/**
*  @pre a file is provided
*  @post checks if the file is empty
*  @return true/false based on whether it's empty or not
*/
bool emptiness(std::string filename);

/**
*  @pre a file is provided
*  @post reads a file in. Will put strings into a vector
*  @return None
*	@throw if the file provided is empty, a bad file, or not open
*/
void readFile(const std::string filename, std::vector<std::string>& tada) throw(PrecondViolatedExcep);

/**
*  @pre a vector with strings within it
*  @post prints out messages corresponding to the string within the vector. runs the Cafe.
*  @return None
*/
void run(std::vector<std::string>& tada) throw(PrecondViolatedExcep);

int main(int argc, char *argv[])
{

	std::string providedFile = argv[1];//takes in file
	std::vector<std::string> list;//declaring a vector object
	try
	{
		readFile(providedFile, list);//populating provided vector with strings from the provided file
	}
	catch(PrecondViolatedExcep& pve)
	{
		std::cout<<pve.what();
	}

	run(list);//printing correct messages based on strings in the vector provided

	list.clear();//clears vector of strings filled in from the file read in

	return(0);//ends program
}

bool emptiness(std::string filename)
{
	std::ifstream info;
	int length=0;

	info.open(filename.c_str());//opening file

	info.seekg(0,ios::end);//sending cursor to end of file
	length=info.tellg();//claculating length of the file and inputting into an int variable

	info.close();//closing file

	//if the length of the file is 0, returns that the file is empty
	if(length == 0)
	{
		return(true);
	}
	//otherwise, says it contains information
	else
	{
		return(false);
	}
}

void readFile(const std::string filename, std::vector<std::string>& tada) throw(PrecondViolatedExcep)
{
	std::ifstream info;
	bool nothing=emptiness(filename);//checking if the file is empty
	std::string takeIn="";

	info.open(filename.c_str());//opens file

	//throws error if the file isn't open, it's a bad file, or it's an empty file
	if(!(info.is_open()) || info.fail() || nothing)
	{
		throw PrecondViolatedExcep("Cannot read the file");
	}
	else//populates a vector with strings from the file if the file passes the above conditions
	{
		while(info>>takeIn)
		{
			tada.push_back(takeIn);
		}
	}

	info.close();//closing file
}

void run(std::vector<std::string>& tada) throw(PrecondViolatedExcep)
{
	Stack<std::string> vip;
	Queue<std::string> nobodies;

	//runs through the vector printing out correct corresponding sentences
	for(unsigned int x=0; x<tada.size(); x++)
	{
		if(tada[x] == "done")//if the value is "done"
		{
			try
			{
				if(vip.isEmpty() && nobodies.isEmpty())//No customers
				{
					std::cout<<"No customers are present, so Lydia is taking a break.";
				}
				else if(vip.isEmpty())//no VIPs, but regular customers are waiting
				{
					//completes the order and removes person from the Queue
					std::cout<<"Lydia finished "<<nobodies.peekFront()<<"'s order.";
					nobodies.dequeue();
					if(nobodies.isEmpty())//nobody is in line after finishing the previous customer's order
					{
						std::cout<<"No customers are present, so Lydia is taking a break.";
					}
					else//helps the next regular customer
					{
						std::cout<<"She works on "<<nobodies.peekFront()<<"'s order.";
					}
				}
				else if(!(vip.isEmpty()))//VIPs are present
				{
					//completes durrent VIP's order and pops them off the stack
					std::cout<<"Lydia finished "<<vip.peek()<<"'s order.";
						vip.pop();

					if(!(vip.isEmpty()))//Another VIP is waiting and starts their order
					{
						std::cout<<"Lydia works on "<<vip.peek()<<"'s order.";
					}
					else if(!(nobodies.isEmpty()))//No VIPs, but regular customers waiting and starts their order
					{
						std::cout<<"Lydia works on "<<nobodies.peekFront()<<"'s order.";
					}
					else//No VIPs nor any regular customers
					{
						std::cout<<"No customers are present, so Lydia is taking a break.";
					}
				}
				std::cout<<'\n';
			}
			catch(PrecondViolatedExcep& pve)//catching an error if thrown and prints corresponding message
			{
				std::cout<<pve.what();
			}
		}
		else if(tada[x] == "show")//if the value equals "show"
		{
			try
			{
				std::cout<<'\n'<<"Current Status: ";
				if(!(vip.isEmpty()))//VIP(s) in line
				{
					std::cout<<vip.peek()<<" is currently being served. ";//printing VIP currently being helped
					if(vip.isAnother())//checking if another VIP is waiting and states they are next
					{
						std::cout<<vip.getNext()<<" will be served next.";
					}
					if(!(nobodies.isEmpty()))//if a regular customer is in line, states they are the front of the line
					{
						std::cout<<nobodies.peekFront()<<" is in front of the queue.";
					}
					else if(!(vip.isAnother()) && nobodies.isEmpty())//if not another VIP and no regular customers, says current customer is the last one
					{
						std::cout<<"She will be Lydia's last customer.";
					}
				}
				else if(vip.isEmpty() && !(nobodies.isEmpty()))//No VIPs, but there are regular customers, says first customer is being served
				{
					std::cout<<"There's no VIPs. "<<nobodies.peekFront()<<" is currently being served. ";
					if(nobodies.isAnother())//if another regular customer is waiting behind the current one, says they're next
					{
						std::cout<<nobodies.nextCustomer()<<" is next in line.";
					}
				}
				else//No VIPs and no regular customers waiting
				{
					std::cout<<"Lydia currently has no customers nor any VIPs.";
				}
				std::cout<<'\n'<<'\n';
			}
			catch(PrecondViolatedExcep& pve)//catches any errors and prints message
			{
				std::cout<<pve.what();
			}
		}
		else if(tada[x].substr(0,3) == "VIP")// if first three characters are "VIP"
		{
			try
			{
				if(tada[x] > "VIP9")
				{
					throw PrecondViolatedExcep("Imma need to ask you to leave!\n");
				}
				else if(vip.isEmpty())//No VIPs currently present
				{
					vip.push(tada[x]);//adds the VIP walking up to the stack
					if(nobodies.isEmpty())//no regular customers, just states she starts the VIP's order
					{
						std::cout<<tada[x]<<" walks up, and Lydia starts her order.";
					}
					else//a regular customer present, suspends their order and starts VIP's order
					{
						std::cout<<tada[x]<<" walks up, so Lydia suspends "<<nobodies.peekFront()<<"'s order and starts "<<tada[x]<<"'s order.";
					}
				}
				else//at least one VIP present
				{
					if(tada[x] < (vip.peek()))//if VIP walking up is lower than current VIP, they lower one walks away
					{
						std::cout<<tada[x]<<" sees Lydia helping "<<vip.peek()<<" and walks away.";
					}
					else if(tada[x] > (vip.peek())) //if a higher VIP walks up, suspends lower VIP's order and starts the higher one's order
					{
						try
						{
							std::cout<<tada[x]<<" walks up, so Lydia suspends "<<vip.peek()<<"'s order and starts "<<tada[x]<<"'s order.";
							vip.push(tada[x]);//adds VIP to stack
						}
						catch(PrecondViolatedExcep& pve)
						{
							std::cout<<pve.what();
						}
					}
				}
				std::cout<<'\n';
			}
			catch(PrecondViolatedExcep& pve)//prints error message if error thrown
			{
				std::cout<<pve.what();
			}
		}
		else//if value is something else, assumed to be a name of a regular customer
		{
			try
			{
				if(!(vip.isEmpty()))//VIP currently being helped
				{
					if(!(nobodies.isEmpty()))//regular customer(s) waiting, states they join the line
					{
						std::cout<<tada[x]<<" joins the back of the line.";
						nobodies.enqueue(tada[x]);//adds them to Queue
					}
					else//no regular customers, states they start a line
					{
						std::cout<<tada[x]<<" starts a line while Lydia helps "<<vip.peek()<<".";
						nobodies.enqueue(tada[x]);//adds them to Queue
					}
				}
				else//No VIPs
				{
					if(!(nobodies.isEmpty()))//regular customer(s) waiting, states they joined the line
					{
						std::cout<<tada[x]<<" joins the back of the line.";
						nobodies.enqueue(tada[x]);//adds them to Queue
					}
					else//no regular customers, immediately walks up and Lydia starts their order
					{
						std::cout<<tada[x]<<" walks up and Lydia starts their order.";
						nobodies.enqueue(tada[x]);//adds them to Queue
					}
				}
				std::cout<<'\n';
			}
			catch(PrecondViolatedExcep& pve)//catches any errors thrown and prints error message
			{
				std::cout<<pve.what();
			}
		}
	}

	if(!(vip.isEmpty()) || !(nobodies.isEmpty()))//will finish off any VIPs and any customers left after the end of the file
	{
		while(!(vip.isEmpty()))//will finish off any VIPs still waiting
		{
			std::cout<<"Lydia finished "<<vip.peek()<<"'s order.";
			vip.pop();//pops VIP off the stack

			if(!(vip.isEmpty()))//another VIP is waiting, she starts their order
			{

				std::cout<<" and starts "<<vip.peek()<<"'s order.";
			}
			else if(!(nobodies.isEmpty()))//No more VIPs but still at least one regular customer, she starts their order
			{
				std::cout<<"She starts "<<nobodies.peekFront()<<"'s order.";
			}
			else//no More customers at all, she takes a break
			{
				std::cout<<'\n'<<"No customers are present, so Lydia is taking a break.";
			}
			std::cout<<'\n';

		}
		while(!(nobodies.isEmpty()))//will finish off any Regular customers waiting, since all VIPs are completed
		{
			std::cout<<"Lydia finished "<<nobodies.peekFront()<<"'s order.";
			nobodies.dequeue();//removes customer from the Queue

			if(!(nobodies.isEmpty()))//another regular customer is waiting. She starts their order
			{
				std::cout<<"She starts "<<nobodies.peekFront()<<"'s order.";
			}
			else//no more regular customers, she takes a break
			{
				std::cout<<'\n'<<"No customers are present, so Lydia is taking a break.";
			}
			std::cout<<'\n';
		}
	}
	else//No VIPs and no regular customers by the end of the vector, states she is still enjoying her break
	{
		std::cout<<'\n'<<"Lydia still has no customers and is enjoying the nice break."<<'\n';
	}
}
