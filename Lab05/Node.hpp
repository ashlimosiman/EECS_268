/**
 *File: Node.hpp
 *Author: Ashli Mosiman
 *KUID Number: 2819456
 *Date Last Updated: February 24,2016
 *Purpose:Defines all methods for the templated Node class
**/

template <typename T>
Node<T>::Node()
{
	//defines private variables to their respective 0s
	m_value=T();
	m_next=nullptr;
	m_previous=nullptr;
}

template <typename T>
void Node<T>::setValue(T val)
{
	//sets the private variable, m_value, to the provided value, value
	m_value=val;
}

template <typename T>
T Node<T>::getValue() const
{
	//returns the Node's value
	return(m_value);
}

template <typename T>
void Node<T>::setNext(Node<T>* prev)
{
	//sets the private variable, m_next, to the provided value, prev
	m_next=prev;
}

template <typename T>
Node<T>* Node<T>::getNext() const
{
	//returns the Node's Next Node it's pointing at
	return(m_next);
}

template <typename T>
void Node<T>::setPrev(Node<T>* prev)
{
	//sets the private variable to the provided value, prev
	m_previous=prev;
}

template <typename T>
Node<T>* Node<T>::getPrev() const
{
	//returns the Node's previous Node it's pointing at
	return(m_previous);
}
