/**
 *File: Stack.h
 *Author: Ashli Mosiman
 *KUID Number: 2819456
 *Date Last Updated: February 24,2016
 *Purpose: Templated Header file for the Stack class inheriting from StackInterface.h
**/

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
#include <stdexcept>

#include "StackInterface.h"
#include "PrecondViolatedExcep.h"
#include"Node.h"


template <typename T>
class Stack: public StackInterface<T>
{
	private:
		int m_size;
		Node<T>* m_top;

	public:
	/**
	*  @pre private variables are established
	*  @post sets all private variables to their respective zeros
	*  @return None
	*/
		Stack();
		/**
	*  @pre Stack with Nodes within it
	*  @post removes all Nodes until the Stack is empty
	*  @return None
	*/
		~Stack();
	/**
	*  @pre A Stack class has been implemented
	*  @post checks i it hold any Nodes
	*  @return true/false based on whether any Nodes are on the Stack
	*/
		bool isEmpty() const;
	/**
	*  @pre a T type value has been provided
	*  @post adds the value to the top of the Stack
	*  @return None
	*/
		void push(const T& newEntry) throw(PrecondViolatedExcep);
	/**
	*  @pre A Stack with at least one Node on it
	*  @post removes the top Node or throws error if the Stack is empty
	*  @return None
	*/
		void pop() throw(PrecondViolatedExcep);
	/**
	*  @pre A Stack with at least one Node on it
	*  @post replies with the value held in the top Node or throws error if the Stack if empty
	*  @return a T value held in the top Node
	*/
		T peek() const throw(PrecondViolatedExcep);
		/**
			*  @pre Stack with Nodes within it
			*  @post prints out values in the Nodes
			*  @return None
			*/
		void printStack() const;
		/**
			*  @pre Stack with Nodes within it
			*  @post checks if there is a second Node on the Stack
			*  @return true/false based on whether another Node is in the Stack
			*/
		bool isAnother() const;
		/**
			*  @pre Stack with Nodes within it
			*  @post gives the nsecond Node in the Stack
			*  @return the value in the second Node
			*/
		T getNext() const throw(PrecondViolatedExcep);

};
#include "Stack.hpp"
#endif
