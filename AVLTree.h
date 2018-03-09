// Header file for AVLTree
// Author: Blake Boswell
#include "BinarySearchTree.h"

class AVLTree: public BinarySearchTree {
private:
    int balanceVector;
    void rrRotation(AVLTree* &root);
    void rlRotation(AVLTree* &root);
    void llRotation(AVLTree* &root);
    void lrRotation(AVLTree* &root);
    void rotate(AVLTree* &root);

public:
    AVLTree(int data);
    bool insert(AVLTree* &root, int key);
    bool remove(AVLTree* &root, int key);
    bool check();
};