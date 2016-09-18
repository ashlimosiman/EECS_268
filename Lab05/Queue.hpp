/**
 *File: Queue.hpp
 *Author: Ashli Mosiman
 *KUID Number: 2819456
 *Date Last Updated: February 24,2016
 *Purpose: Makes a queue of Nodes. Similar to a line at the store. FIFO (Templated)
**/

template <typename T>
Queue<T>::Queue()
{
	//sets private member variables to their respective zeros
	m_size=0;
	m_first=nullptr;
}

template <typename T>
Queue<T>::~Queue()
{
	while(!(isEmpty()))//removes Nodes until the Queue is empty
	{
		dequeue();
	}
}

template <typename T>
bool Queue<T>::isEmpty() const
{
	if(m_first == nullptr)//determined empty if the pointer equals nullptr
	{
		return(true);
	}
	else//determined not empty if the pointer is looking at a Node
	{
		return(false);
	}
}

template <typename T>
void Queue<T>::enqueue(const T& newEntry) throw (PrecondViolatedExcep)
{
	if(isEmpty())//makes a new Node with the given value if the Queue is empty
	{
		m_first = new Node<T>();
		m_first->setValue(newEntry);
		m_size++;//increases size
	}
	else//runs through the Queue and adds a new Node at the end with the given value
	{
		Node<T>* temp=m_first;
		Node<T>* nextNode=new Node<T>();
		nextNode->setValue(newEntry);

		while(temp->getNext() != nullptr)
		{
			temp=temp->getNext();
		}
		temp-> setNext(nextNode);
		temp=temp->getNext();
		temp->setNext(nullptr);
		m_size++;//increases size
	}
}
template <typename T>
void Queue<T>::dequeue() throw (PrecondViolatedExcep)
{
	if(isEmpty())//if the stack is empty throws an error and message
	{
		throw PrecondViolatedExcep("dequeue attempted on an empty queue");
	}
	else//removing the first Node and making the second Node as the first Node
	{
		Node<T>* temp=m_first;

		m_first=m_first->getNext();

		delete temp;
		temp=nullptr;
		m_size--;//decreasing the size
	}
}

template <typename T>
T Queue<T>::peekFront() const throw (PrecondViolatedExcep)
{
	if(isEmpty())//if stack is empty throws error and message
	{
		throw PrecondViolatedExcep("Peek attempted on an empty queue");
	}
	else//returning the value within the first Node
	{
		return(m_first->getValue());
	}
}

template <typename T>
void Queue<T>::printQueue() const
{
	if(isEmpty())//prints out 'empty' if the Queue is empty
	{
		std::cout<<"empty.";
	}
	else//will print out all Nodes in the Queue with a double space inbetween from the first Node to the last
	{
		Node<T>* temp=m_first;
		while(temp != nullptr)
		{
			std::cout<<temp->getValue()<<"  ";
			temp=temp->getNext();
		}
	}
}

template <typename T>
bool Queue<T>::isAnother() const
{
	if(m_first->getNext() == nullptr || isEmpty())//if the first Node looks at nullptr or it's empty, says there's not another Node
	{
		return(false);
	}
	else//otherwise, says there is a second Node
	{
		return(true);
	}
}

template <typename T>
T Queue<T>::nextCustomer() const throw(PrecondViolatedExcep)
{
	if(isAnother())//if there's a second Node, returns value within the second Node
	{
		Node<T>* next=m_first->getNext();
		return(next->getValue());
	}
	else//otherwise, throws an error
	{
		throw PrecondViolatedExcep("There is only one customer in line.\n");
	}
}
