// Header file for AVLTree
// Author: Blake Boswell
#include "BinarySearchTree.h"

struct AVLNode: Node {
    int balanceFactor;
    AVLNode* left;
    AVLNode* right;

    // AVLNode::AVLNode(AVLNode* node) {
    //     this->balanceVector = node->balanceVector;
    //     copyNode(this, node);
    // }
    static void copyNode(AVLNode* &thisNode, AVLNode* &sourceNode) {
        if(sourceNode == NULL) {
            thisNode = NULL;
        } else {
            thisNode = new AVLNode;
            thisNode->data = sourceNode->data;
            thisNode->balanceFactor = sourceNode->balanceFactor;
            copyNode(thisNode->left, sourceNode->left);
            copyNode(thisNode->right, sourceNode->right);
        }
    }
};

class AVLTree: public BinarySearchTree {
private:
    AVLNode* root;
    void copyTree(AVLNode* &thisRoot, AVLNode* &sourceRoot);
    void rebalance(AVLNode* &node);
    bool insertHelper(AVLNode* &node, int key);
    int calculateHeight(AVLNode* node);
    void showInorder(AVLNode* node);
    void showPostorder(AVLNode* node);
    void rrRotation(AVLNode* &node);
    void rlRotation(AVLNode* &node);
    void llRotation(AVLNode* &node);
    void lrRotation(AVLNode* &node);
    void rotate(AVLNode* &node);
    bool searchHelper(AVLNode* node, int key);

public:
    AVLTree();
    AVLTree(AVLTree* tree);
    bool search(int key);
    bool insert(int key);
    bool remove(int key);
    void show();
    int height();
    int size();
    bool check();
};