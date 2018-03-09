//
// Created by blake on 3/3/2018.
// Implementation of the BinarySearchTree using recursive functions
//
#include "BinarySearchTree.h"
#include <iostream>

using namespace std;

BinarySearchTree::BinarySearchTree(int data) {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
}

/**
 * Returns the node with data equal to the given key
 * @param key
 * @return BinarySearchTree
 */
BinarySearchTree* BinarySearchTree::search(int key) {
    if(this == NULL) {
        // Tree is empty
        return NULL;
    }
    if(this->data == key) {
        // Found the node
        return this;
    }
    if(this->data > key) {
        // Go down the left subtree
        return this->left->search(key);
    } else {
        // Go down the right subtree
        return this->right->search(key);
    }
}

/**
 * Inserts a new node into the tree with data equal to the key
 * @param root
 * @param key
 * @return True if successful, False otherwise
 */
bool BinarySearchTree::insert(BinarySearchTree* &root, int key) {
    if(root == NULL) {
        root = new BinarySearchTree(key);
        root->left = NULL;
        root->right = NULL;
        return true;
    }
    if(this->data == key) {
        // Data already exists
        return false;
    }
    if(root->data > key) {
        // Go down the left subtree
        return insert(root->left, key);
    } else {
        // Go down the right subtree
        return insert(root->right, key);
    }
}

/**
 * Remove a node that has 2 children
 * @param root
 */
void BinarySearchTree::removeBoth(BinarySearchTree* &root) {
    BinarySearchTree* temp = root;
    root = root->right;
    root->left = temp->left;
    delete temp;
}

/**
 * Remove a node that has only 1 child
 * @param root
 */
void BinarySearchTree::removeNode(BinarySearchTree* & root) {
    if(root->left == NULL && root->right == NULL) {
        // Leaf node
        delete root;
        root = NULL;
    } else if(root->left == NULL) {
        // Single child on the right
        BinarySearchTree* temp = root;
        root = root->right;
        delete temp;
    } else if(root->right == NULL) {
        // Single child on the left
        BinarySearchTree* temp = root;
        root = root->left;
        delete temp;
    } else {
        removeBoth(root);
    }
}

/**
 * Remove a node with data equal to the given key
 * @param root
 * @param key
 * @return True if successful, False otherwise
 */
bool BinarySearchTree::remove(BinarySearchTree* &root, int key) {
    if(root == NULL) {
        return false;
    }
    if(root->data == key) {
        removeNode(root);
    } else if(root->data > key) {
        return remove(root->left, key);
    } else if(root->data < key) {
        return remove(root->right, key);
    }
}

/**
 * Prints the tree in Inorder
 */
void BinarySearchTree::showInorder() {
    if(this == NULL) {
        return;
    }
    this->left->showInorder();
    cout << this->data << ", ";
    this->right->showInorder();

}

/**
 * Prints the tree in Postorder
 */
void BinarySearchTree::showPostorder() {
    if(this == NULL) {
        return;
    }
    this->left->showPostorder();
    this->right->showPostorder();
    cout << this->data << ", ";
}

/**
 * Print out both the Inorder and Postorder of the tree
 */
void BinarySearchTree::show() {
    cout << "Inorder:\n";
    this->showInorder();
    cout << "\nPostOrder:\n";
    this->showPostorder();
    cout << "\n";
}

/**
 * Finds the height of the tree
 * @return height
 */
int BinarySearchTree::height() {
    if(this == NULL) {
        return 0;
    }
    return 1 + max(this->left->height(), this->right->height());
}

/**
 * Helper function to size
 * @param size
 * @return size
 */
int BinarySearchTree::sizeHelper(int& size) {
    if(this == NULL) {
        return size;
    }
    size++;
    this->left->sizeHelper(size);
    this->right->sizeHelper(size);
    return size;
}

/**
 * Finds the total number of nodes in the tree
 * @return size
 */
int BinarySearchTree::size() {
    int size = 0;
    return sizeHelper(size);
}

/**
 * Checks that the tree is a Binary Search Tree
 * left data < node data < right data
 * @return T/F
 */
bool BinarySearchTree::check() {
    if(this == NULL) {
        return true;
    }
    if(this->left == NULL && this->right != NULL) {
        return (this->data < this->right->data);
    }
    if(this->left != NULL && this->right == NULL) {
        return (this->data > this->left->data);
    }
    if(this->left->check() == false || this->right->check() == false) {
        return false;
    } else {
        return true;
    }
}

/**
 * Function for debugging the check function
 * @param data
 */
void BinarySearchTree::setData(int data) {
    this->data = data;
}

