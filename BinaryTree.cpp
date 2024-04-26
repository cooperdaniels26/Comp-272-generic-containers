#include <sstream>
#include "BinaryTree.hpp"
#include "List.hpp"
#include <cmath>
using namespace std;

template <typename T>
BinaryTree<T>::BinaryTree()
{
	this->parent = nullptr;
	this->leftChild = nullptr;
	this->rightChild = nullptr; 
	this->label = 0; 
}

//implement toString
template<typename T>
string BinaryTree<T>::toString()
{
	ostringstream sout;
	sout << "Binary Tree at: " << this << endl;
	return sout.str();
}

//implement getRoot
template<typename T>
BinaryTree<T>* BinaryTree<T>:: getRoot()
{
	if (this->parent == nullptr)
	{
		return this;
	}
	else
	{
		return this->parent->getRoot();
	}
}

//implement hasLeftChild
template<typename T>
bool BinaryTree<T>:: hasLeftChild()
{
	return this->leftChild != nullptr;
}

//implement hasRighChild
template<typename T>
bool BinaryTree<T>::hasRightChild()
{
	return this->rightChild != nullptr;
}

//implement getLeftChild
template<typename T>
BinaryTree<T>* BinaryTree<T>::getLeftChild()
{
	return this->leftChild;
}

//implement getRighChild
template<typename T>
BinaryTree<T>* BinaryTree<T>::getRightChild()
{
	return this->rightChild;
}

template<typename T>
BinaryTree<T>* BinaryTree<T>::setLeftChild(BinaryTree<T>* bTree)
{
	BinaryTree<T>* result = this->leftChild;
	//if there is an actual leftchild ...
	if (this->leftChild != nullptr)
	{
		//set parent ro nullptr
		this->leftChild->parent = nullptr;
	}
	//set input tree as the leftChild
	this->leftChild = bTree; 
	//if we have new left child
	if (this->leftChild != nullptr)
	{
		//set parent to point to binary tree
		this->leftChild->parent = this;
	}
	return result;
}


template<typename T>
BinaryTree<T>* BinaryTree<T>::setRightChild(BinaryTree<T>* bTree)
{
	BinaryTree<T>* result = this->rightChild;
	//if there is an actual rightchild ...
	if (this->rightChild != nullptr)
	{
		//set parent ro nullptr
		this->rightChild->parent = nullptr;
	}
	//set input tree as the rightChild
	this->rightChild = bTree;
	//if we have new right child
	if (this->rightChild != nullptr)
	{
		//set parent to point to binary tree
		this->rightChild->parent = this;
	}
	return result;
}

//implement remove leftChild
template<typename T>
BinaryTree<T>* BinaryTree<T>::removeLeftChild()
{
	BinaryTree<T>* result = this->leftChild;
	if (this->leftChild != nullptr)
	{
		//remove this bT as parent of left child
		this->leftChild->parent = nullptr;
		//remove the left child from this binary tree
		this->leftChild = nullptr;
	}
	return result;
}

//implement remove rightChild
template<typename T>
BinaryTree<T>* BinaryTree<T>::removeRightChild()
{
	BinaryTree<T>* result = this->rightChild;
	if (this->rightChild != nullptr)
	{
		//remove this bT as parent of right child
		this->rightChild->parent = nullptr;
		//remove the right child from this binary tree
		this->rightChild = nullptr;
	}
	return result;
}

template<typename T>
int BinaryTree<T>::getSize()
 {
	if (this->leftChild != nullptr && this->rightChild != nullptr)
	{
		return 1 + this->leftChild->getSize() + this->rightChild->getSize();
	}
	else if (this->leftChild != nullptr && this->rightChild == nullptr)
	{
		return 1 + this->leftChild->getSize();
	}
	else if (this->leftChild == nullptr && this->rightChild != nullptr)
	{
		return 1 + this->rightChild->getSize();
	}
	else
	{
		return 1; 
	}
 }

//implement getdata task 3
template<typename T>
T BinaryTree<T>::getData()
{
	return this->data;
}

template<typename T>
void BinaryTree<T>::setData(T data)
{
	this -> data = data;
}

template<typename T>
bool BinaryTree<T>::hasParent()
{
		return this->parent != nullptr;	
}

template<typename T>
BinaryTree<T>* BinaryTree<T>::getParent()
{
		return this->parent;
}


template<typename T>
bool BinaryTree<T>::isLeaf()
{
	return this->leftChild == nullptr && this->rightChild == nullptr;
}

/*
 Returns the level of this tree in its parent tree.
 */
template<typename T>
int BinaryTree<T>::getLevel() {
	int level = 0;
	BinaryTree<T>* currentVertex = this;
	while (currentVertex->parent != nullptr) {
		level++;
		currentVertex = currentVertex->parent;
	}
	return level;
}


/*
 Returns the height of this tree.
 */
template<typename T>
int BinaryTree<T>::getHeight() {
	if (this->leftChild != nullptr && this->rightChild != nullptr) 
	{
		return 1 + std::max(this->leftChild->getHeight(), this->rightChild->getHeight());
	}
	else if (this->leftChild != nullptr && this->rightChild == nullptr) 
	{
		return 1 + this->leftChild->getHeight();
	}
	else if (this->leftChild == nullptr && this->rightChild != nullptr)
	{
		return 1 + this->rightChild->getHeight();
	}
	else {
		return 0;
	}
}

/*
 Sets the parent attribute of this tree to nullptr (the empty tree),
 and returns the old parent, minus this tree.
 */
template<typename T>
BinaryTree<T>* BinaryTree<T>::removeParent() {
	// storage to return the parent
	BinaryTree<T>* result = nullptr;
	if (this->parent != nullptr) 
	{
		// clean up the parent tree
		if (this->parent->leftChild == this)
		{
			// remove the left child from the parent
			this->parent->leftChild = nullptr;
		}
		else if (this->parent->rightChild == this)
		{
			// remove the right child from the parent
			this->parent->rightChild = nullptr;
		}
		// save the parent tree to return
		result = this->parent;
		// remove this tree's parent
		this->parent = nullptr;
	}
	// return the parent tree
	return result;
}


/*
 Returns the data stored in the root node of this tree.
*/
template<typename T>
T getData() {
	return this->data;
}

/*
 Sets the data stored in the root node of this tree.
 */
template<typename T>
void setData(T data) {
	this->data = data;
}

/*
 Returns a pointer to a list containing a parent-last ordering of
 the nodes in this binary tree.
 */
template<typename T>
List<BinaryTree<T>*>* BinaryTree<T>::parentLastOrdering() {
	List<BinaryTree<T>*>* result = nullptr;
	if (this->leftChild != nullptr && this->rightChild != nullptr) {
		result = this->leftChild->parentLastOrdering();
		result->joinBefore(this->rightChild->parentLastOrdering());
		result->addAtEnd(this);
	}
	else if (this->leftChild != nullptr && this->rightChild == nullptr) {
		result = this->leftChild->parentLastOrdering();
		result->addAtEnd(this);
	}
	else if (this->leftChild == nullptr && this->rightChild != nullptr) {
		result = this->rightChild->parentLastOrdering();
		result->addAtEnd(this);
	}
	else {
		result = new List<BinaryTree<T>*>(this);
	}
	return result;
}
/*
 Returns a pointer to a list containing a parent-middle ordering of
 the nodes in this binary tree.
 */
template<typename T>
List<BinaryTree<T>*>* BinaryTree<T>::parentMiddleOrdering() {
	List<BinaryTree<T>*>* result = nullptr;
	if (this->leftChild != nullptr && this->rightChild != nullptr)
	{
		result = this->leftChild->parentMiddleOrdering();
		result->addAtEnd(this);
		result->joinBefore(this->rightChild->parentMiddleOrdering());
	}
	else if (this->leftChild != nullptr && this->rightChild == nullptr)
	{
		result = this->leftChild->parentMiddleOrdering();
		result->addAtEnd(this);
	}
	else if (this->leftChild == nullptr && this->rightChild != nullptr)
	{
		result = this->rightChild->parentMiddleOrdering();
		result->addAtEnd(this);
	}
	else
	{
		result = new List<BinaryTree<T>*>(this);
	}
	return result;
}

// //Returns a pointer to a list containing a parent-first ordering of
// //the nodes in this binary tree.
// 
template<typename T>
List<BinaryTree<T>*>* BinaryTree<T>::parentFirstOrdering() {
	//List<BinaryTree<T>*>* result = nullptr;
	List<BinaryTree<T>*>* result = new List<BinaryTree<T>*>();
	if (this->leftChild != nullptr && this->rightChild != nullptr)
	{
		result->addAtEnd(this);
		result->joinBefore(this->leftChild->parentFirstOrdering());
		result->joinBefore(this->rightChild->parentFirstOrdering());
	}
	else if (this->leftChild != nullptr && this->rightChild == nullptr)
	{
		result->addAtEnd(this);
		result->joinBefore(this->leftChild->parentFirstOrdering());
	}
	else if (this->leftChild == nullptr && this->rightChild != nullptr)
	{
		result->addAtEnd(this);
		result->joinBefore(this->rightChild->parentFirstOrdering());
	}
	else
	{
		//result = new List<BinaryTree<T>*>(this);
		result->addAtEnd(this);
	}
	return result;
}


