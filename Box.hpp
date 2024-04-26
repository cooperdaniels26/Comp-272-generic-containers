#pragma once
#include <string>
#include <ostream>
using namespace std; 

/*
 A box is a generic container that holds a single data item. The typename variable
 T specifies the type of data contained in the box.
 */
template <typename T>
class Box {
protected:

    /*
     The data held by this box
     */
    T data;

public:

    /*
     Creates a box. The data field is uninitialized.
     */
    Box();

    /*
     Creates a box containing the specified data.
     */
    Box(T data);

    //copy constuctor creates an independent copy of input ref
    Box(const Box<T>& abox);

    //class destructor

    ~Box();

    /*
     Returns the data held by this box.
     */
    T getData() const;

    /*
     Stores the specified data in this box. Any data previously
     stored in this box is overwritten.
     */
    void setData(T data);

    
    // 2 boxs are equal if data is equal
    bool operator==(const Box<T>& another);

    // 2 boxs are not equal if data is not equal
    bool operator !=(const Box<T>& another);


    /*
     Returns a string representation of this box.
     */
    std::string toString() const;
};

template <typename T>
ostream& operator<<(std::ostream& outStream,const Box<T>& box);