/**
 *File: Node.h
 *Author: Ashli Mosiman
 *KUID Number: 2819456
 *Date Last Updated: February 10,2016
 *Purpose: Header file for the Node class
**/

#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node
{
	private:
		int m_value;
		Node* m_next;

	public:
	/**
	*  @pre None
	*  @post sets all private member variables to their respective zeros
	*  @return An object< Node
	*/
		Node();
	/**
	*  @pre an integer value
	*  @post sets m_value to equal val
	*  @return None
	*/
		void setValue(int val);
	/**
	*  @pre m_value has some integer value in it
	*  @post returning the private member variable's, m_value, integer
	*  @return an integer, m_value
	*/
		int getValue() const;
	/**
	*  @pre a Node pointer, prev
	*  @post sets the private member valiable, m_next, to equal prev
	*  @return None
	*/
		void setNext(Node* prev);
	/**
	*  @pre m_next is pointing to something, another Node or nullptr
	*  @post returns m_next
	*  @return a Node pointer, m_next
	*/
		Node* getNext() const;
};
#endif
