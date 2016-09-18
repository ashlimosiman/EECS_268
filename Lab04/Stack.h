/**
 *File: Stack.h
 *Author: Ashli Mosiman
 *KUID Number: 2819456
 *Date Last Updated: February 18,2016
 *Purpose: Templated Header file for the Stack class inheriting from StackInterface.h
**/

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

#include "StackInterface.h"
#include "Node.h"
#include "PreconditionViolationException.h"

template <typename T>
class Stack:public StackInterface<T>
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
		void push(const T value);
	/**
	*  @pre A Stack with at least one Node on it
	*  @post removes the top Node or throws error if the Stack is empty
	*  @return None
	*/
		void pop() throw(PreconditionViolationException);
	/**
	*  @pre A Stack with at least one Node on it
	*  @post replies with the value held in the top Node or throws error if the Stack if empty
	*  @return a T value held in the top Node
	*/
		T peek() const throw(PreconditionViolationException);
	/**
	*  @pre m_size has some interger in it
	*  @post responds with the number of Nodes in the Stack
	*  @return an integer, the size of the Stack
	*/
		int size() const;
	/**
	*  @pre A Stack is populated with Node(s)
	*  @post copies values in the Node(s) to an established vector
	*  @return a vector holding the values in the Stack
	*/
		std::vector<T> toVector() const;
	/**
	*  @pre A stack with at least one Node
	*  @post takes the Nodes from the original Stack and adds them to a new stack, resulting in the opposite order
	*  @return a Reverse stack of the original stack
	*/
		Stack<T> makeRevStack();
	/**
	*  @pre the reversed stack and the origianl stack
	*  @post compares all corresponding Nodes ( first with each other, second with each other, etc.) to determine if the given number is a Palindrome
	*  @return true/false based on whether the given number is a palindrome
	*/
		bool isPalindrome(Stack<T>& rS);
	/**
	*  @pre a Stack with at least one Node
	*  @post prints out all the values in the Stack
	*  @return None
	*/
		void printStack(int num) const;
};
#include "Stack.hpp"
#endif
