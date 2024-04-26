#include "Box.hpp"
#include <sstream>
#include <iostream>
using namespace std;

template <typename T>
Box<T>::Box() {}

template  <typename T>
Box<T>::Box(T data) 
{
    this->data = data;
}

template  <typename T>
Box<T>::Box(const Box<T>& abox)
{
  // cout << "Box copy constructor here: " << endl;
    this->data = abox.data; 
}

template  <typename T>
Box<T>::~Box()
{
   // cout << "Box destructor here: " << endl;
}

template  <typename T>
T Box<T>::getData() const
{ 
    return this->data; 
}

template  <typename T>
void Box<T>::setData(T data) 
{ 
    this->data = data; 
}

template <typename T>
bool Box<T>::operator==(const Box<T>& another)
{
    return (this->data == another.data);
}

template <typename T>
bool Box<T>::operator!=(const Box<T>& another)
{
    return !(*this == another);
}

template  <typename T>
std::string Box<T>::toString() const {
    std::ostringstream sout;
    sout << "Box at " << this << std::endl;
    sout << " storing data of size " << sizeof(T) << " bytes." << std::endl;
    return sout.str();
}


//Overload stream insertion.This enables an object of type Complex to be
//directly given to the stream insertion operator <<.

template <typename T>
std::ostream & operator<<(std::ostream& outStream,const Box<T>& box)
{
    outStream << box.toString();
    return outStream;
}
