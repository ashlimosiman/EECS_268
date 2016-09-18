/**
*File: Queue.h
*Author: Ashli Mosiman
*KUID Number: 2819456
*Date Last Updated: February 24,2016
*Purpose: Header file for Queue. Templated.
**/
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
#include <stdexcept>
#include "PrecondViolatedExcep.h"
#include "Node.h"
#include "QueueInterface.h"

template <typename T>
class Queue:public QueueInterface<T>
{
	private:
			int m_size;
			Node<T>* m_first;
	public:
		/**
		*  @pre private variables are declared
		*  @post defines all private member variables ot their respective zeros
		*  @return None
		*/
			Queue();
		/**
		*  @pre A Queue object was created
		*  @post dequeues, or removes, all Nodes until the object is empty
		*  @return None
		*/
			~Queue();
			/**
		*  @pre a Queue object was created
		*  @post checks whther the Queue is empty
		*  @return true/false based on whether the object is empty
		*/
			bool isEmpty() const;
			/**
		*  @pre a Queue object is established
		*  @post adds a new Node to the back of the Queue
		*  @return None
		*/
			void enqueue(const T& newEntry) throw (PrecondViolatedExcep);
			/**
		*  @pre A populated Queue was established
		*  @post removes the front Node, throws if the Queue is Empty
		*  @return None
		*/
			void dequeue() throw (PrecondViolatedExcep);
			/**
		*  @pre A populated Queue was established
		*  @post reutrns the value held within the first Node, throws if the Queue is empty
		*  @return value in the first Node
		*/
			T peekFront() const throw (PrecondViolatedExcep);
			/**
		*  @pre a Queue object was created
		*  @post prints out 'empty' if the Queue is empty.
		*				Otherwise, prints out each Node from front to back with a double space between values.
		*  @return None
		*/
			void printQueue() const;
			/**
		*  @pre a Queue object was created
		*  @post checks if there is a second Node in the Queue
		*  @return true/false based on whether a second Node exists in the Queue
		*/
			bool isAnother() const;
			/**
		*  @pre a populated Queue object was created with at least two Nodes
		*  @post returns value in the second Nodes
		*				throws if only one Node or the Queue is empty
		*  @return T value in the second Node
		*/
			T nextCustomer() const throw(PrecondViolatedExcep);
};
#include "Queue.hpp"
#endif
