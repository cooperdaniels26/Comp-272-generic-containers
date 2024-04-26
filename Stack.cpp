#include <sstream>
#include <iostream>
#include "Stack.hpp"
using namespace std;


//defult constructor 

template <typename T>
Stack<T>::Stack()
{
	this->top = nullptr;
}

template <typename T>
Stack<T>::Stack(const Stack<T>& s) 
{
	this->top = nullptr;
	if (s.top != nullptr) 
	{
		this->top = new Node<T>(*s.top);
		Node<T>* currOrigNode = s.top;
		Node<T>* currCopyNode = this->top;
		while (currOrigNode->getNextNode() != nullptr)
		{
			Node<T>* nextCopyNode = new Node<T>(*(currOrigNode->getNextNode()));
			currCopyNode->setNextNode(nextCopyNode);
			currCopyNode = nextCopyNode;
			currOrigNode = currOrigNode->getNextNode();
		}
	}
}

template <typename T>
Stack<T>::~Stack() {
	//    std::cout << "~Stack() here:" << std::endl;
	Node* currNode = this->top;
	int cnt = 0;
	while (currNode != nullptr) {
		Node* nextNode = currNode->getNextNode();
		delete currNode;
		currNode = nextNode;
		cnt++;
	}
	//    std::cout << cnt << " items deleted." << std::endl;
}

//implement is empty
template <typename T>
bool Stack<T>::isEmpty() const
{
	return this->top == nullptr;
}

//implement getSize
template <typename T>
int Stack<T>::getSize() const
{
	if (this->top == nullptr)
	{
		return 0; 
	}
	else
	{
		Node<T>* currentNode = this->top;
		int count = 1; 
		while (currentNode->getNextNode() != nullptr)
		{
			count++;
			currentNode = currentNode->getNextNode();
		}
		return count; 
	}
}


//implement push(t data)

template<typename T>
void Stack<T>::push(T data)
{
	if (this->isEmpty())
	{
		//create top node and store data in  it
		this->top = new Node<T>(data);
	}
	else
	{
		//create node put data in it
		//nextNode pointer shoud piont to current top of the stack.
		//then we set the top f the pointer to the new one.
		Node<T>* newTop = new Node<T>(data);
		newTop->setNextNode(this->top);
		this->top = newTop;
	}
}

// implement pop() task 2 
template<typename T>
T Stack<T>::pop()
{
	if (this->isEmpty())
	{
		//error
		throw std::exception("Cannot pop from an empty stack!");
	}
	else if(this->getSize() == 1)
	{
		//grab data off the top, then set top = nullptr
		T result = this->top->getData();
		this->top = nullptr;
		return result;
	}
	else
	{
		//grab data off the top, then set top to piont to to top->getNextNode
		T result = this->top->getData();
		this->top = this->top->getNextNode();
		return result;
	}
}


//Implement peek() task 3 
template<typename T>
T Stack<T>::peek() const
{
	if (this->isEmpty())
	{
		//error
		throw exception("Cannot pop from an empty stack!");
	}
	else 
	{
		//grab data off the top
		T result = this->top->getData();
		return result;
	}
}

//to string of this stack task 3 
template<typename T>
string Stack<T>::toString() const
{
	ostringstream sout;
	sout << "Stack at: " << this << std::endl;
	sout << "This stack is currently storing " << getSize(T) << " items" << std::endl;
	sout << "Each item on this stack occupies " << &(this->data) << std::endl;
	return sout.str();
}


/*
 Overload stream insertion. This enables an object of type Complex to be
 directly given to the stream insertion operator <<.
 */
template<typename T>
std::ostream& operator<<(std::ostream& outStream, const const Stack<T>& another) {
	outStream << another.toString();
	return outStream;
}