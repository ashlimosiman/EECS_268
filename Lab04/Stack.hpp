/**
 *File: Stack.hpp
 *Author: Ashli Mosiman
 *KUID Number: 2819456
 *Date Last Updated: February 18,2016
 *Purpose: Defines methods for the Stack class, which will make a "stack" of nodes.
  *         Also, will only add to the top and remove from the top.
**/


template <typename T>
Stack<T>::Stack()
{
	//sets all private member variables to their respective zeros
	m_size=0;
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
	//if m_top is equal to nullptr, Stack is considered empty
	if(m_top == nullptr)
	{
		return(true);
	}
	//if it does not, then it's considered not empty. Curve ball!
	else
	{
		return(false);
	}
}

template <typename T>
void Stack<T>::push(const T value)
{
	//checks if the Stack is empty
	if(isEmpty())
	{
		//makes m_top into a new Stack if it is found empty
		m_top=new Node<T>();
		m_top->setValue(value);
		//increasing the size
		m_size++;
	}
	//if m_top is not found as empty, enters this statement
	else
	{
		//a temporary Node to keep track of the current Stack
		Node<T>* temp=m_top;

		//m_top looks away from the current Stack and starting a new Stack with the provide value
		m_top=new Node<T>();
		m_top->setValue(value);
		//setting the next Node to be the top Node of the old Stack. Thus, updain the old Stack with the new Node at the top
		m_top->setNext(temp);
		//increasing the sie by one
		m_size++;
	}
}

template <typename T>
void Stack<T>::pop() throw(PreconditionViolationException)
{
	if(isEmpty())
	{
		//if the stack is empty throws an error and message
		throw PreconditionViolationException("Pop attempted on an empty stack");
	}
	else
	{
		//creating a new Node to look at the top of the Stack
		Node<T>* temp=m_top;

		//m_top manipulated o look at the seond Node on the Stack
		m_top=m_top->getNext();
		//deletes the top Node
		delete temp;
		//setting temp to look at nullptr, in good practice
		temp=nullptr;
		//decreasing the size by one
		m_size--;
	}
}

template <typename T>
T Stack<T>::peek() const throw(PreconditionViolationException)
{
	if(isEmpty())
	{
		//if stack is empty throws error and message
		throw PreconditionViolationException("Peek attempted on an empty stack");
	}
	else
	{
		//returning the value within the top Node
		return(m_top->getValue());
	}
}

template <typename T>
int Stack<T>::size() const
{
	//returns the size of the Stack
	return(m_size);
}

template <typename T>
std::vector<T> Stack<T>::toVector() const
{
	Node<T>* temp=m_top;
	std::vector<T> v;

	//enters statement as long as the stack isn't empty
	if(!isEmpty())
	{
		//stays in the loop until temp's next Node is nullptr
		while(temp->getNext() != nullptr)
		{
			//adding the Node's value to the vector
			v.push_back(temp->getValue());
			//moving to the next node
			temp=temp->getNext();
		}
		//for the case if there's only one Node on the stack
		if(temp != nullptr)
		{
			//adds the value in the node to the vector
			v.push_back(temp->getValue());
		}
	}

	//returns the created vector
	return(v);
}

template <typename T>
Stack<T> Stack<T>::makeRevStack()
{
	//Stack object established
	Stack<T> rev;

	//if the Stack is empty, prints out error message and returns an empty stack
	if(isEmpty())
	{
		std::cout<<"This Stack is empty"<<'\n';
		return(rev);
	}
	//goes through the Stack, adding them to a new Stack in the opposite order until it hits nullptr
	else
	{
		Node<T>* temp = m_top;

		while(temp != nullptr)
		{
			rev.push(temp->getValue());
			temp=temp->getNext();
		}

		return(rev);
	}
}

template <typename T>
bool Stack<T>::isPalindrome(Stack<T>& rS)
{
	//if it's empty, prints out a message saying so and returns false
	if(isEmpty())
	{
		std::cout<<"the Stack is empty."<<'\n';
		return(false);
	}
	//if the Stacks are no the same size, will say so and return false
	else if(m_size != rS.m_size)
	{
		std::cout<<"the stacks' sizes do not match"<<'\n';
		return(false);
	}
	else
	{
		//new Node pointer made to look at the current Stack's top Node
		Node<T>* temp=m_top;
		//new Node pointer made to look at the Stack's (taken in by the parameters) top Node
		Node<T>* rTemp=rS.m_top;

		while(temp != nullptr)
		{
			//moves through until they reach nullptr, comparing each Node
			if(temp->getValue() != rTemp->getValue())
			{
				return(false);//false if one of the pairs do not match
			}
			else if(temp->getValue() == rTemp->getValue())
			{
				//moves to the next pair if the current pair match
				temp=temp->getNext();
				rTemp=rTemp->getNext();
			}
		}
		return(true);//true if all pairs matched
	}
}

template <typename T>
void Stack<T>::printStack(int num) const
{
	//enters if statement as long as the Stack is not empty
	if(!isEmpty())
	{	
		Node<T>* temp=m_top;
		//if the integer taken in from the parameters in negative, will print dash before printing the first Node's value
		if(num < 0)
		{
			std::cout<<"-";
		}

		//Moves through the Stack printing out the Value(s) in the Node(s)
		while(temp != nullptr)
		{
			std::cout<<temp->getValue();
			temp=temp->getNext();
		}
	}
	//prints out "empty" if there are no Nodes on the Stack
	else
	{
		std::cout<<"-empty-"<<'\n';
	}
}
