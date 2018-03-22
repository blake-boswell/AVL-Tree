// Header file for AVLTree
// Author: Blake Boswell
#include "BinarySearchTree.h"

struct AVLNode: Node {
    int balanceVector;
};

class AVLTree: public BinarySearchTree {
private:
    AVLNode* root;
    void rrRotation(AVLNode* &node);
    void rlRotation(AVLNode* &node);
    void llRotation(AVLNode* &node);
    void lrRotation(AVLNode* &node);
    void rotate(AVLNode* &node);

public:
    AVLTree();
    bool search(int key);
    bool insert(int key);
    bool remove(int key);
    void show();
    int height();
    int size();
    bool check();
};