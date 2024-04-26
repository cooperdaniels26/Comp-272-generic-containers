#pragma once
#include <string>
#include "List.hpp"

template <typename T>
class Deque {
protected:

    /*
     The list backing up this deque.
     */
    List<T>* lst;

public:

    /*
     Creates an empty deque.
     */
    Deque();

    /*
     Returns true if and only if this deque is empty.
     */
    bool isEmpty();

    /*
     Returns the number of items in the deque.
     */
    int getSize();

    /*
     Adds the specified data to the front of the deque.
     */
    void enqueueFront(T data);

    /*
     Adds the specified data to the back of the deque.
     */
    void enqueueBack(T data);

    /*
     Removes and returns the data at the front of the deque.
     */
    T dequeueFront();

    /*
     Removes and returns the data at the back of the deque.
     */
    T dequeueBack();

    /*
     Returns the data at the front of the deque, but does not remove it.
     */
    T peekAtFront();

    /*
     Returns the data at the back of the deque, but does not remove it.
     */
    T peekAtBack();

    /*
     Returns a string representation of this deque.
     */
    std::string toString();

};