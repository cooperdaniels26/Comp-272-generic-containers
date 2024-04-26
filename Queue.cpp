#include "Queue.hpp"
#include <sstream>
using namespace std;


//create a queue, defult constructor
template<typename T>
Queue<T>::Queue()
{
	this->lst = new List<T>();
}

//implement toString
template<typename T>
string Queue<T>::toString()
{
	ostringstream sout;
	sout << "Queue at: " << this << endl;
	sout << "This Queue stores items of size " << getSize(T) << " bytes." << endl;
	sout << "This Queue contains " << &(this->data) << " items." << endl;
	return sout.str();
}

//implement enqueue
template<typename T>
void Queue<T>::enqueue(T data)
{
	lst->addAtEnd(data);
}

//implement dequeue
template<typename T>
T Queue<T>::dequeue()
{
	return lst->remove(0);
}

//implement isEmpty
template<typename T>
bool Queue<T>::isEmpty()
{
	return lst->isEmpty();
}

//implement getSize
template<typename T>
int Queue<T>::getSize()
{
	return lst->getSize();
}
//implement peekAtFront
template<typename T>
T Queue<T>::peekAtFront()
{
	return lst->peek(0);
}

