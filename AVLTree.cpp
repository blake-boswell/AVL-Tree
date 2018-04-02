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
        thisRoot->balanceFactor = sourceRoot->balanceFactor;
        copyTree(thisRoot->left, sourceRoot->left);
        copyTree(thisRoot->right, sourceRoot->right);
    }
}

AVLTree::~AVLTree() {
    delete root;
}

void AVLTree::rrRotation(AVLNode* &node) {
    AVLNode* temp = node;
    node = temp->right;
    AVLNode* tempLeft = node->left;
    node->left = temp;
    node->left->right = tempLeft;

    // Fix balance factors
    // node->balanceFactor += 1;
    // node->left->balanceFactor += 2;
    rebalance(node);
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
    // node->balanceFactor -= 1;
    // node->right->balanceFactor -= 2;
    // node->left->balanceFactor += 2;
    rebalance(node);
    // +1 to parent
}

void AVLTree::llRotation(AVLNode* &node) {
    AVLNode* temp = node;
    node = node->left;
    AVLNode* tempRight = node->right;
    node->right = temp;
    node->right->left = tempRight;

    // Fix balance factors
    // node->balanceFactor -= 1;
    // node->right->balanceFactor -= 2;
    rebalance(node);
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
    // node->right->balanceFactor -= 2;
    // node->left->balanceFactor += 1;
    rebalance(node);
    
    
    
}

// Purpose: Determine what rotation to perform
void AVLTree::rotate(AVLNode* &node) {

}

bool AVLTree::searchHelper(AVLNode* node, int key) {
    if(node == NULL) {
        // Tree is empty
        return NULL;
    }
    if(node->data == key) {
        // Found the node
        return node;
    }
    if(node->data > key) {
        // Go down the left subtree
        return searchHelper(node->left, key);
    } else {
        // Go down the right subtree
        return searchHelper(node->right, key);
    }
}

// Purpose: Find the data in the tree given a key
bool AVLTree::search(int key) {
    return searchHelper(this->root, key);
}

void AVLTree::rebalance(AVLNode* &node) {
    cout << "Rebalancing" << endl;
    if(node == NULL) {
        return;
    }
    calculateBalanceFactors(node);
    rebalance(node->left);
    rebalance(node->right);
}

/**
 * Helper method for a recursive insert into the tree
*/
bool AVLTree::insertHelper(AVLNode* &node, int key) {
    if(node == NULL) {
        node = new AVLNode;
        node->data = key;
        node->left = NULL;
        node->right = NULL;
        node->balanceFactor = 0;
        return true;
    }
    if(node->data == key) {
        // Data already exists
        return false;
    }
    if(node->data > key) {
        // Go down the left subtree
        if(insertHelper(node->left, key)) {
            cout << "[L] " << node->data << endl;
            calculateBalanceFactors(node);
            
            

            if(node->balanceFactor >= 2) {
                // Rotate L*
                cout << "Need to rotate [" << node->data << "]: BV: " << node->balanceFactor << endl;
                if(node->left->balanceFactor < 0) {
                    // Rotate LR
                    cout << "Rotating [" << node->data << "] LR" << endl;
                    lrRotation(node);
                    // Still need to add 1 to the parent BF if this is the right
                } else if(node->left->balanceFactor > 0) {
                    // Rotate LL
                    cout << "Rotating [" << node->data << "] LL" << endl; 
                    llRotation(node);
                }
            }
            return true;
        }
    } else {
        // Go down the right subtree
        if(insertHelper(node->right, key)) {
            cout << "[R] " << node->data << endl;
            calculateBalanceFactors(node);
            
            
            
            if(node->balanceFactor <= -2) {
                // Rotate R*
                cout << "Need to rotate [" << node->data << "]: BV: " << node->balanceFactor << endl;
                if(node->right->balanceFactor < 0) {
                    // Rotate RR
                    cout << "Rotating [" << node->data << "] RR" << endl;
                    rrRotation(node);
                    // Still need to add 1 to parent BF if this is the right
                } else if(node->right->balanceFactor > 0) {
                    // Rotate RL
                    cout << "Rotating [" << node->data << "] RL" << endl;
                    rlRotation(node);
                }
            }
            return true;
        }
    }
}

// Purpose: Insert into the tree and balance it
bool AVLTree::insert(int key) {
    return insertHelper(this->root, key);

}

AVLNode* getLargest(AVLNode* node) {
    if(node == NULL) {
        return NULL;
    }
    if(node->right != NULL) {
        return getLargest(node->right);
    } else {
        return node;
    }
}

/**
 * Remove a node that has 2 children
 * @param root
 */
void AVLTree::removeBoth(AVLNode* &node) {
    int newNodeValue = getLargest(node->left)->data;
    remove(newNodeValue);
    node->data = newNodeValue;
}

/**
 * Remove a node that has only 1 child
 * @param root
 */
void AVLTree::removeNode(AVLNode* & node) {
    if(node->left == NULL && node->right == NULL) {
        // Leaf node
        delete node;
        node = NULL;
    } else if(node->left == NULL) {
        // Single child on the right
        AVLNode* temp = node;
        node = node->right;
        delete temp;
    } else if(node->right == NULL) {
        // Single child on the left
        AVLNode* temp = node;
        node = node->left;
        delete temp;
    } else {
        removeBoth(node);
    }
}

bool AVLTree::removeHelper(AVLNode* &node, int key) {
    if(node == NULL) {
        return false;
    }
    if(node->data == key) {
        removeNode(node);
        // rebalance(node);
    } else if(node->data > key) {
        if(removeHelper(node->left, key)) {
            calculateBalanceFactors(node);

            if(node->balanceFactor <= -2) {
                // Rotate R*
                cout << "Need to rotate [" << node->data << "]: BV: " << node->balanceFactor << endl;
                if(node->right->balanceFactor <= 0) {
                    // Rotate RR
                    cout << "Rotating [" << node->data << "] RR" << endl;
                    rrRotation(node);
                    // Still need to add 1 to parent BF if this is the right
                } else if(node->right->balanceFactor > 0) {
                    // Rotate RL
                    cout << "Rotating [" << node->data << "] RL" << endl;
                    rlRotation(node);
                }
            }
            return true;
        }
    } else if(node->data < key) {
        if(removeHelper(node->right, key)) {

            // calculateBalanceFactor
            calculateBalanceFactors(node);

            // check rotation left
            if(node->balanceFactor >= 2) {
                // Rotate L*
                cout << "Need to rotate [" << node->data << "]: BV: " << node->balanceFactor << endl;
                if(node->left->balanceFactor < 0) {
                    // Rotate LR
                    cout << "Rotating [" << node->data << "] LR" << endl;
                    lrRotation(node);
                    // Still need to add 1 to the parent BF if this is the right
                } else if(node->left->balanceFactor >= 0) {
                    // Rotate LL
                    cout << "Rotating [" << node->data << "] LL" << endl; 
                    llRotation(node);
                }
            }
            return true;
        }
    }
}

// Purpose: Remove from the tree and balance it
bool AVLTree::remove(int key) {
    return removeHelper(this->root, key);
}

void AVLTree::calculateBalanceFactors(AVLNode* &node) {
    int leftHeight = calculateHeight(node->left);
    int rightHeight = calculateHeight(node->right);
    node->balanceFactor = leftHeight - rightHeight;
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

int AVLTree::calculateHeight(AVLNode* node) { 
    if(node == NULL) {
        return 0;
    }
    return 1 + max(calculateHeight(node->left), calculateHeight(node->right));
}

// Purpose: Retrieve the height of the tree
int AVLTree::height() {
    return calculateHeight(this->root);
}

int AVLTree::sizeHelper(AVLNode* node, int &size) {
    if(node == NULL) {
        return size;
    }
    size++;
    sizeHelper(node->left, size);
    sizeHelper(node->right, size);
    return size;
}

// Purpose: Retrieve the number of nodes in the tree
int AVLTree::size() {
    int size = 0;
    return sizeHelper(this->root, size);
}

bool AVLTree::checkHelper(AVLNode* node) {
    if(node == NULL) {
        return true;
    }
    if(node->left == NULL && node->right != NULL) {
        bool isBST = (node->data < node->right->data);
        bool isAVL = (abs(calculateHeight(node->left) - calculateHeight(node->right)) <= 1);
        return (isBST && isAVL);

    }
    if(node->left != NULL && node->right == NULL) {
        bool isBST = (node->data > node->left->data);
        bool isAVL = (abs(calculateHeight(node->left) - calculateHeight(node->right)) <= 1);
        return (isBST && isAVL);
    }
    if(checkHelper(node->left) == false || checkHelper(node->right) == false) {
        return false;
    } else {
        return true;
    }
}

// Purpose: Check to see if this tree is an AVL tree
bool AVLTree::check() {
    return checkHelper(this->root);
}