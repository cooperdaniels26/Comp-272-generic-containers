#include "Node.hpp"
#include <sstream>
#include <iostream>
using namespace std; 

template <typename T>
Node<T>::Node() {
    this->nextNode = nullptr;
};

template <typename T>
Node<T>::Node(T data) : Box<T>(data)
{
    this->nextNode = nullptr; 
}

template <typename T>
Node<T>::Node(T data, Node<T>* nextNode) : Box<T>(data) {
    this->nextNode = nextNode; 
}

//copy constructor
template <typename T>
Node<T>::Node(const Node<T>& node)
{
    //cout << "node copy constructor here" << endl;
    this->data = node.data;
    this->nextNode = node.nextNode;
}


template <typename T>
Node<T>::~Node()
{
    cout << "Node destructor here: " << endl;
}


template <typename T>
Node<T>* Node<T>::getNextNode() const {
    return this->nextNode;
}

template <typename T>
void Node<T>::setNextNode(Node* next) {
    this->nextNode = next;
}

template <typename T>
bool Node<T>::operator ==(const Node<T>& another)
{
    return(this->data == another.data && this->nextNode == another.nextNode);
}

template <typename T>
bool Node<T>::operator !=(const Node<T>& another)
{
    return(this->data == another.data);
}



template <typename T>
std::string Node<T>::toString() const {
    std::ostringstream sout;
    sout << "Node at " << this << std::endl;
    sout << " storing " << sizeof(T) << " bytes of data at " << &(this->data) << std::endl;
    return sout.str();
}


/*
 Overload stream insertion. This enables an object of type Complex to be
 directly given to the stream insertion operator <<.
 */

template <typename T>
std::ostream& operator<<(std::ostream& outStream,const Node<T>& original) {
    outStream << original.toString();
    return outStream;
}
