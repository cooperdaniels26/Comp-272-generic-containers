#include <iostream>
#include <sstream>
#include "List.hpp"
using namespace std; 


//defult constructor
template<typename T>
List<T>::List()
{
	this->mainStack = new Stack<T>();
	this->auxStack = new Stack<T>();
}

template <typename T>
List<T>::List(T data) {
	this->mainStack = new Stack<T>();
	this->auxStack = new Stack<T>();
	this->mainStack->push(data);
}

//copy constructor
template <typename T>
List<T>::List(const List<T>& l) {
	//cout << "list copy constructor her" << endl;
	this->mainStack = new Stack<T>(*(l.mainStack));
	this->auxStack = new Stack<T>(*(l.auxStack));
}

//destructor
template <typename T>
List<T>::~List() {
	//    std::cout << "~List here..." << std::endl;
	//    std::cout << " deleting mainStack..." << std::endl;
	delete mainStack;
	//    std::cout << " deleting auxStack..." << std::endl;
	delete auxStack;
}


//is empty
template <typename T>
bool List<T>::isEmpty() const
{
	return this->mainStack->isEmpty();	
}

//implement getSize
template <typename T>
int List<T>::getSize() const
{
	return this->mainStack->getSize();
}

//add data to end of the list
template <typename T> 
void List<T>::addAtEnd(T data)
{
	this->mainStack->push(data);
}

//implement T peek(int ndx)
template <typename T>
T List<T>::peek(int ndx) const
{
	// calculate the number of items to pop off the main stack
	int n = this->getSize() - ndx;
	// use a for loop to pop that many items off the main stack and onto the aux stack
	for (int k = 0; k< n; k++)
	{
		this->auxStack->push(this->mainStack->pop());
	}
	// use auxStack's peek() function to get the value at the top of the aux stack. Store
	T result = this->auxStack->peek();
	// pop all items off the aux stack and push onto main stack
	while (!this->auxStack->isEmpty())
	{
		this->mainStack->push(this->auxStack->pop());
	}
	// in a variable
	return result;
}

//implement void insert before
template <typename T>
void List<T>::insertBefore(int ndx, T data)
{
		int n = this->getSize() - ndx;
		for(int k = 0; k < n; k++)
		{
			this->auxStack->push(this->mainStack->pop());
		}
		this->mainStack->push(data);
		while (!this->auxStack->isEmpty())
		{
			this->mainStack->push(this->auxStack->pop());
		}
		
}

//Task 5 remove(int ndx)
template <typename T>
T List<T>::remove(int ndx)
{
		int n = this->getSize() - ndx;
		for (int k = 0; k < n; k++)
		{
			this->auxStack->push(this->mainStack->pop());
		}
		T result = this->auxStack->pop();
		while (!this->auxStack->isEmpty())
		{
			this->mainStack->push(this->auxStack->pop());
		}
		return result;
}

template <typename T>
void List<T>::joinBefore(List<T>* suffix)
{
	for (int k = 0; k < suffix->getSize(); k++)
	{
		this->mainStack->push(suffix->peek(k));
	}
}

template <typename T>
List<T>* List<T>::splitBefore(int ndx)
{
	int numToPop = this->getSize() - ndx;
	List<T>* result = new List<T>();
	for (int k = 0; k < numToPop; k++)
	{
		T tempData = this->mainStack->pop();
		result->insertBefore(0, tempData);
	}
	return result; 
}


//toString 
template<typename T>
string List<T>::toString() const
{
	ostringstream sout;
	sout << "List at: " << this << endl;
	sout << "This List stores items of size " << getSize(T) << " bytes." << endl;
	sout << "This list contains " << &(this->data) << " items." << endl; 
	return sout.str();
}


/*
 Overload stream insertion. This enables an object of type Complex to be
 directly given to the stream insertion operator <<.
 */
template <typename T>
std::ostream& operator<<(std::ostream& outStream, const List<T>& l) {
	outStream << l.toString();
	return outStream;
}