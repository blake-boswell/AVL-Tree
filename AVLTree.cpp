// Author: Blake Boswell
#include "AVLTree.h"
#include <iostream>

using namespace std;

AVLTree::AVLTree(): BinarySearchTree() {
    this->root = NULL;
}

AVLTree::AVLTree(AVLTree* tree) {
    if(tree->root == NULL) {
        this->root = NULL;
    } else {
        copyTree(this->root, tree->root);
    }
}

void AVLTree::copyTree(AVLNode* &thisRoot, AVLNode* &sourceRoot) {
    if(sourceRoot == NULL) {
        thisRoot = NULL;
    } else {
        thisRoot = new AVLNode;
        thisRoot->data = sourceRoot->data;
        copyTree(thisRoot->left, sourceRoot->left);
        copyTree(thisRoot->right, sourceRoot->right);
    }
}

void AVLTree::rrRotation(AVLNode* &node) {
    AVLNode* temp = node;
    node = temp->right;
    AVLNode* tempLeft = node->left;
    node->left = temp;
    node->left->right = tempLeft;

    // Fix balance factors
    node->balanceFactor += 1;
    node->left->balanceFactor += 2;
    // +1 to parent
}

void AVLTree::rlRotation(AVLNode* &node) {
    AVLNode* temp = node;
    node = node->right->left;
    AVLNode* tempLeft = node->left;
    node->left = temp;
    AVLNode* tempRight = node->right;
    node->right = temp->right;
    temp->right = tempLeft;
    node->right->left = tempRight;

    // Fix balance factors
    node->balanceFactor -= 1;
    node->right->balanceFactor -= 2;
    node->left->balanceFactor += 2;
    // +1 to parent
}

void AVLTree::llRotation(AVLNode* &node) {
    AVLNode* temp = node;
    node = node->left;
    AVLNode* tempRight = node->right;
    node->right = temp;
    node->right->left = tempRight;

    // Fix balance factors
    node->balanceFactor -= 1;
    node->right->balanceFactor -= 2;
}

void AVLTree::lrRotation(AVLNode* &node) {
    // Pull up new root to this subtree
    AVLNode* temp;
    temp = node;
    node = temp->left->right;
    AVLNode* tempRight = node->right;
    node->right = temp;
    node->right->left->right = node->left;
    temp = node->right->left;
    node->right->left = tempRight;
    node->left = temp;

    // Fix balance factors
    node->right->balanceFactor -= 2;
    node->left->balanceFactor += 1;
    
    
    
}

// Purpose: Determine what rotation to perform
void AVLTree::rotate(AVLNode* &node) {

}

// Purpose: Find the data in the tree given a key
bool AVLTree::search(int key) {

}

/**
 * Return values:
 * 0: value already exists
 * 1: insert success
 * 2: insert and rotation
*/
int AVLTree::insertHelper(AVLNode* &node, int key) {
    if(node == NULL) {
        node = new AVLNode;
        node->data = key;
        node->left = NULL;
        node->right = NULL;
        node->balanceFactor = 0;
        return 1;
    }
    if(node->data == key) {
        // Data already exists
        return 0;
    }
    if(node->data > key) {
        // Go down the left subtree
        int didRotate = insertHelper(node->left, key);
        if(didRotate > 0) {
            cout << "[L] " << node->data << endl;
            if(didRotate != 2) {
                node->balanceFactor += 1;
            }

            if(node->balanceFactor >= 2) {
                // Rotate L*
                cout << "Need to rotate [" << node->data << "]: BV: " << node->balanceFactor << endl;
                if(node->left->balanceFactor < 0) {
                    // Rotate LR
                    cout << "Rotating [" << node->data << "] LR" << endl;
                    lrRotation(node);
                    return 2;
                    // Still need to add 1 to the parent BF if this is the right
                } else if(node->left->balanceFactor > 0) {
                    // Rotate LL
                    cout << "Rotating [" << node->data << "] LL" << endl; 
                    llRotation(node);
                    return 2;
                }
            }
            return didRotate;
        }
    } else {
        // Go down the right subtree
        int didRotate = insertHelper(node->right, key);
        if(didRotate > 0) {
            cout << "[R] " << node->data << endl;
            if(didRotate != 2) {
                node->balanceFactor -= 1;
            }
            
            if(node->balanceFactor <= -2) {
                // Rotate R*
                cout << "Need to rotate [" << node->data << "]: BV: " << node->balanceFactor << endl;
                if(node->right->balanceFactor < 0) {
                    // Rotate RR
                    cout << "Rotating [" << node->data << "] RR" << endl;
                    rrRotation(node);
                    return 2;
                    // Still need to add 1 to parent BF if this is the right
                } else if(node->right->balanceFactor > 0) {
                    // Rotate RL
                    cout << "Rotating [" << node->data << "] RL" << endl;
                    rlRotation(node);
                    return 2;
                }
            }
            return didRotate;
        }
    }
}

// Purpose: Insert into the tree and balance it
bool AVLTree::insert(int key) {
    return insertHelper(this->root, key);

}

// Purpose: Remove from the tree and balance it
bool AVLTree::remove(int key) {

}

/**
 * Prints the tree in Inorder
 */
void AVLTree::showInorder(AVLNode* node) {
    if(node == NULL) {
        return;
    }
    showInorder(node->left);
    cout << "[" << node->data << "] :: " << node->balanceFactor << ", ";
    showInorder(node->right);

}

/**
 * Prints the tree in Postorder
 */
void AVLTree::showPostorder(AVLNode* node) {
    if(node == NULL) {
        return;
    }
    showPostorder(node->left);
    showPostorder(node->right);
    cout << "[" << node->data << "] :: " << node->balanceFactor << ", ";
}

// Purpose: Show the contents of the tree
void AVLTree::show() {
    cout << "Inorder:\n";
    this->showInorder(this->root);
    cout << "\nPostOrder:\n";
    this->showPostorder(this->root);
    cout << "\n";
}

// Purpose: Retrieve the height of the tree
int AVLTree::height() {

}

// Purpose: Retrieve the number of nodes in the tree
int AVLTree::size() {

}

// Purpose: Check to see if this tree is an AVL tree
bool AVLTree::check() {

}