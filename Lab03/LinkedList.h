/**
 *File: LinkedList.h
 *Author: Ashli Mosiman
 *KUID Number: 2819456
 *Date Last Updated: February 13,2016
 *Purpose: Header file for the LinkedList class
**/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <vector>
#include "Node.h"

class LinkedList
{
	private:
		Node* m_front;
		int m_size;
	public:
	/**
	*  @pre None
	*  @post sets all private member variables to their respective zeros
	*  @return None
	*/
		LinkedList();
	/**
	*  @pre A non-empty LinkedList of Node pointers exists
	*  @post deletes all the Nodes until the list is empty
	*  @return None
	*/
		~LinkedList();
	/**
	*  @pre A LinkedList object exists
	*  @post checks if the list is empty, is the variable pointing to nullptr?
	*  @return true/false based on whether the list is empty or not
	*/
		bool isEmpty() const;
	/**
	*  @pre m_size has some integer value
	*  @post merely returns m_size
	*  @return an integer, m_size
	*/
		int size() const;
	/**
	*  @pre a LinkedList object with at least one Node pointer was created and an integer was taken in
	*  @post compares each value in the list with the intger for which it is searching
	*  @return true/false based on whether it found the given value
	*/
		bool search(int value) const;
	/**
	*  @pre a LinkedList with at least one Node pointer exists
	*  @post prints out a list of all the values within the Node pointer(s)
	*  @return None
	*/
		void printList() const;
	/**
	*  @pre an integer was taken in
	*  @post will either create a new List with the given value or just add it to the back of the already created list of Node pointers
	*  @return None
	*/
		void addBack(int value);
	/**
	*  @pre an integer was taken in
	*  @post will either create a new List of Node pointers with the given value or just add it to the front of the existing list
	*  @return None
	*/
		void addFront(int value);
	/**
	*  @pre A non-empty list exists
	*  @post removes the last Node from the list
	*  @return true/false based on whether a Node was in fact removed
	*/
		bool removeBack();
	/**
	*  @pre a non-empty list exists
	*  @post removes the first Node from the list
	*  @return true/false based on whether a Node was removed
	*/
		bool removeFront();
	/**
	*  @pre a non-empty list exists
	*  @post puts all the values into a vector established in this method
	*  @return a vector holding the values from an existing list
	*/
		std::vector<int> toVector() const;
};
#endif
