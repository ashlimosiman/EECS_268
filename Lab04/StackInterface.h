/**
 *File: StackIntrface.h
 *Author: Ashli Mosiman
 *KUID Number: 2819456
 *Date Last Updated: February 17,2016
 *Purpose: Templated, abstract Header file for StackInterface
**/


#ifndef STACKINTERFACE_H
#define STACKINTERFACE_H

#include <vector>
#include <string>
#include <iostream>
#include "PreconditionViolationException.h"

template <typename T>
class StackInterface
{
	public:
	/**
  	*  @pre an implementation of a stack was created
  	*  @post deletes all Nodes until the stack is empty
  	*  @return None
  	*/
		virtual ~StackInterface() {};
	/**
  	*  @pre a Stack object exists
  	*  @post checks the stack if it has any Nodes
  	*  @return boolean representing whether the Stack is empty
  	*/
		virtual bool isEmpty() const=0;
	/**
  	*  @pre a stack object exists
  	*  @post adds a Node containing T value in it to the top of the Stack
  	*  @return None
  	*/
		virtual void push(const T value)=0;
	/**
  	*  @pre the Stack is not empty
  	*  @post throws error if the stack is empty or pops off the top Node
  	*  @return None
  	*/
		virtual void pop() throw(PreconditionViolationException)=0;
	/**
  	*  @pre the Stack is not empty
  	*  @post throws error if the stack is empty or gives the value in the top Node
  	*  @return T value held within the top Node
  	*/
		virtual T peek() const throw(PreconditionViolationException)=0;
	/**
  	*  @pre m_size has some integer value within it
  	*  @post gives m_size which is the number of Nodes on the Stack
  	*  @return integer, m_size
  	*/
		virtual int size() const=0;
	/**
  	*  @pre a stack populated with Node(s)
  	*  @post puts all values within the Stack into a vector
  	*  @return a vector holding all values from the stack
  	*/
		virtual std::vector<T> toVector() const=0;

};

#endif
