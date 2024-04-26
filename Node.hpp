#pragma once
#include "Box.hpp"
using namespace std; 

/*
 A node is a generic container that can link to another node.
 */
template <typename T>
class Node : public Box<T> {
protected:

    /*
     The pointer to the node that this one links to.
     */
    Node<T>* nextNode;

public:

    /*
     The default constructor creates an empty node with no successor.
     */
    Node();

    /*
     Creates a node containing the specified data, and whose successor is null.
     */
    Node(T data);



    /*
     Creates a node containing the specied data and with the specified successor.
     */
    Node(T data, Node<T>* nextNode);

    //copy constructor

    Node(const Node<T>& original);


    //class destructor
    ~Node();

    /*
     Returns a pointer to the successor node of this one. A null pointer is returned
     if this node has no successor.
     */
    Node<T>* getNextNode() const;

    /*
     Sets this node's successor to the specified value.
     */
    void setNextNode(Node<T>* next);


    bool operator==(const Node<T>& another);

    bool operator!=(const Node<T>& another);

    /*
     Returns a string representation of this node.
     */
    std::string toString() const;
};

/*
 Overload stream insertion. This enables an object of type Complex to be
 directly given to the stream insertion operator <<.
 */
template <typename T>
ostream& operator<<(std::ostream& outStream,const Node<T>& original);