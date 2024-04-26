#pragma once
#include <string>
#include "List.hpp"

/*
 A class representing binary trees. Data can be stored in the nodes of the tree.
 */
template <typename T>
class BinaryTree {
protected:

    BinaryTree<T>* parent;
    BinaryTree<T>* leftChild;
    BinaryTree<T>* rightChild;
    T data;

public:


    int label;
    /*
     Create a binary tree with a single node and no children.
     */
    BinaryTree();

    /*
     If this binary tree has no parent, then this binary tree is returned.
     Otherwise the root of the parent binary tree is returned.
     */
    BinaryTree<T>* getRoot();

    /*
     Returns the number of nodes in this binary tree.
     */
    int getSize();

    /*
     Returns the data stored in the root node of this tree.
     */
    T getData();

    /*
     Sets the data stored in the root node of this tree.
     */
    void setData(T data);

    /*
     Returns true if and only if this binary tree has a nonempty left child.
     */
    bool hasLeftChild();

    /*
     Returns the left child of this binary tree. A returned value of nullptr
     indicates that this tree has an empty left child.
     */
    BinaryTree<T>* getLeftChild();

    /*
     Sets the left child of this tree to the input tree, and returns the old
     left child as a binary tree with null parent.
     */
    BinaryTree<T>* setLeftChild(BinaryTree<T>* bTree);

    /*
     Removes the left child of this binary tree, replacing it with the empty
     tree, and returns the old left child with its parent attribute set to
     null.
     */
    BinaryTree<T>* removeLeftChild();

    /*
     Returns true if and only if this binary tree has a nonempty right child.
     */
    bool hasRightChild();

    /*
     Returns the right child of this binary tree. A returned value of nullptr
     indicates that this tree has an empty right child.
     */
    BinaryTree<T>* getRightChild();

    /*
     Sets the right child of this tree to the input tree, and returns the old
     right child as a binary tree with null parent.
     */
    BinaryTree<T>* setRightChild(BinaryTree* bTree);

    /*
     Removes the right child of this binary tree, replacing it with the empty
     tree, and returns the old right child with its parent attribute set to
     null.
     */
    BinaryTree<T>* removeRightChild();

    /*
     Returns a description of this binary tree as a string.
     */
    std::string toString();

    
    /*
    Returns true if and only if this binary tree has a non-empty parent.
    */
    bool hasParent();


    /*
     Returns the parent of this binary tree, or the null pointer if this tree
     has no parent.
     */
    BinaryTree<T>* getParent();

    //returns a list containing parent last ordering of the vertics in the tree
    List<BinaryTree<T>*>* parentLastOrdering();

    //returns a list containing parent last ordering of the vertics in the tree
    List<BinaryTree<T>*>* parentFirstOrdering();

    //returns a list containing parent last ordering of the vertics in the tree
    List<BinaryTree<T>*>* parentMiddleOrdering();

    bool isLeaf();

    int getLevel();

    int getHeight();

    BinaryTree<T>* removeParent();

  
};
