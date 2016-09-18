/**
 *File: Stack.hpp
 *Author: Ashli Mosiman
 *KUID Number: 2819456
 *Date Last Updated: February 24,2016
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
	else if(m_size == 10)//if the size is ten, since there's only ten VIPs, throws error
	{
		throw PrecondViolatedExcep("Imma need to ask you to leave,you pettifogger!\n");
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
		throw PrecondViolatedExcep("No VIPs in line.\n");
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
		throw PrecondViolatedExcep("No VIPs in line.\n");
	}
	else//returns value within the top Node
	{
		T value=m_top->getValue();
		return(value);
	}
}

template <typename T>
void Stack<T>::printStack() const
{
	if(isEmpty())//prints 'empty' if the Stack is empty
	{
		std::cout<<"empty.";
	}
	else//will run through the Stack printing all the values with two spaces in between
	{
		Node<T>* temp=m_top;
		while(temp != nullptr)
		{
			std::cout<<temp->getValue()<<"  ";
			temp=temp->getNext();
		}
	}
}

template <typename T>
bool Stack<T>::isAnother() const
{
	if(m_size <= 1)//if the size is less than or equal to one, returns false, since one means only one Node
	{
		return(false);
	}
	else//returns true since the size would be greater then one. Thus, another Node is in the Stack
	{
		return(true);
	}
}

template <typename T>
T Stack<T>::getNext() const throw(PrecondViolatedExcep)
{
	if(m_size <= 1)//if size is less than or equal to one, throws an error
	{
		throw PrecondViolatedExcep("There is only one VIP waiting\n");
	}
	else//returns value in the second Node on the Stack
	{
		Node<T>* temp=m_top->getNext();
		return(temp->getValue());
	}
}
