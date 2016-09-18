/**
 *File: Stack.hpp
 *Author: Ashli Mosiman
 *KUID Number: 2819456
 *Date Last Updated: March 03,2016
 *Purpose: Defines methods for the Stack class, which will make a "stack" of nodes.
  *         Also, will only add to the top and remove from the top. LIFO
**/


template <typename T>
Stack<T>::Stack()
{
	//sets private member variables to their respective zeros
	m_size= 0;
	m_top=nullptr;
}

template <typename T>
Stack<T>::~Stack()
{
	//removes Nodes until the Stack is empty
	while(!(isEmpty()))
	{
		pop();
	}
}

template <typename T>
bool Stack<T>::isEmpty() const
{

	if(m_top == nullptr)//Stack is empty
	{
		return(true);
	}
	else//There's at least one Node in the Stack
	{
		return(false);
	}
}

template <typename T>
void Stack<T>::push(const T& newEntry) throw(PrecondViolatedExcep)
{

	if(isEmpty())//Creates a new Node on the Stack with the given value if the Stack is empty
	{
		m_top=new Node<T>();
		m_top->setValue(newEntry);
		m_size++;//increase size
	}
	else//adds a new Node containing the new value to the top of the Stack
	{
		Node<T>* temp=new Node<T>();
		temp->setValue(newEntry);
		temp->setNext(m_top);
		m_top=temp;
		temp=nullptr;
		m_size++;//increases size
	}
}

template <typename T>
void Stack<T>::pop() throw(PrecondViolatedExcep)
{
	if(isEmpty())//throws error if the STack is empty
	{
		throw PrecondViolatedExcep("it is missing a few operands\n");
	}
	else//removes the top Node
	{
		Node<T>* temp=m_top;
		m_top=m_top->getNext();
		delete temp;
		temp = nullptr;
		m_size--;//decreases size
	}
}

template <typename T>
T Stack<T>::peek() const throw(PrecondViolatedExcep)
{
	if(isEmpty())//throws error if the Stack is empty
	{
		throw PrecondViolatedExcep("it is missing a few operands\n");
	}
	else//returns value within the top Node
	{
		T value=m_top->getValue();
		return(value);
	}
}
