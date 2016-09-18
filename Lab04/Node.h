/**
 *File: Node.h
 *Author: Ashli Mosiman
 *KUID Number: 2819456
 *Date Last Updated: February 17,2016
 *Purpose: Templated Header file for the Node class
**/

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

template <typename T>
class Node
{
	private:
		T m_value;
		Node<T>* m_next;
		Node<T>* m_previous;

	public:
	/**
	*  @pre None
	*  @post sets all private member variables to their respective zeros
	*  @return An object Node
	*/
		Node();
	/**
	*  @pre a templated value
	*  @post sets m_value to equal val
	*  @return None
	*/
		void setValue(T val);
	/**
	*  @pre m_value has some templated value in it
	*  @post returning the private member variable's, m_value, templated value
	*  @return a templated value, m_value
	*/
		T getValue() const;
	/**
	*  @pre a Node pointer, prev
	*  @post sets the private member valiable, m_next, to equal prev
	*  @return None
	*/
		void setNext(Node<T>* prev);
	/**
	*  @pre m_next is pointing to something, another Node or nullptr
	*  @post returns m_next
	*  @return a tamplated Node pointer, m_next
	*/
		Node<T>* getNext() const;
	/**
	*  @pre m_previous is pointing to a Node before it or nullptr
	*  @post sets the private member variable to prev
	*  @return None
	*/
		void setPrev(Node<T>* prev);
	/**
	*  @pre m_previous is pointing to the Node before it or nullptr
	*  @post returns m_orevious
	*  @return a tamplated Node pointer, m_previous
	*/
		Node<T>* getPrev() const;
};
#include "Node.hpp"
#endif
