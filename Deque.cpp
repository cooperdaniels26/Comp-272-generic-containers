#include "Deque.hpp"
#include <sstream>
using namespace std;


//create a deque, defult constructor
template<typename T>
Deque <T>::Deque()
{
	this->lst = new List<T>();
}

//implement toString
template<typename T>
string Deque<T>::toString()
{
	ostringstream sout;
	sout << "Deque at: " << this << endl;
	return sout.str();
}

//implement enqueueFront
template<typename T>
void Deque<T>::enqueueFront(T data)
{
	lst->insertBefore(0, data);
}

//implement dequeueFront
template<typename T>
T Deque<T>::dequeueFront()
{
	return lst->remove(0);
}

//implement isEmpty
template<typename T>
bool Deque<T>::isEmpty()
{
	return lst->isEmpty();
}

//implement getSize
template<typename T>
int Deque<T>::getSize()
{
	return lst->getSize();
}

//implement enqueueBack
template<typename T>
void Deque<T>::enqueueBack(T data)
{
	lst->addAtEnd(data);
}

//implement dequeueBack
template<typename T>
T Deque<T>::dequeueBack()
{
	return lst->remove(lst->getSize() - 1);
}

//implement peekAtFront
template<typename T>
T Deque<T>::peekAtFront()
{
	return lst->peek(0);
}
//implement peekAtBack
template<typename T>
T Deque<T>::peekAtBack()
{
	return lst->peek(lst->getSize() - 1);
}



