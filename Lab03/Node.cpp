/**
 *File: Node.cpp
 *Author: Ashli Mosiman
 *KUID Number: 2819456
 *Date Last Updated: February 10,2016
 *Purpose: Creates an object, Node, to hold integers and for LinkedList to make a list of
**/

#include "Node.h"

Node::Node()
{
	//defines private variables to their respective 0s
	m_value=0;
	m_next=nullptr;
}

void Node::setValue(int val)
{
	//sets the private variable, m_value, to the provided value, value
	m_value=val;
}

int Node::getValue() const
{
	//returns the Node's value
	return(m_value);
}

void Node::setNext(Node* prev)
{
	//sets the private variable, m_next, to the provided value, prev
	m_next=prev;
}

Node* Node::getNext() const
{
	//returns the Node's Next Node it's pointing at
	return(m_next);
}
