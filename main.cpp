// Author: Blake Boswell
// Synopsis: This file is used to test out the BinarySearchTree class

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "BinarySearchTree.h"

using namespace std;

int main() {
    BinarySearchTree* tree = new BinarySearchTree();
    BinarySearchTree* result;
    // tree->show();
    tree->insert(3);
    tree->insert(4);
    tree->insert(2);
    tree->insert(1);
    tree->insert(7);
    tree->insert(6);
    tree->insert(8);
    tree->insert(9);
    cout << "Size: " << tree->size() << endl;
    cout << "Height: " << tree->height() << endl;
    cout << "isTree?: " << tree->check() << endl;
    tree->show();
    tree->remove(2);
    cout << "Removing 2" << endl;
    cout << "Size: " << tree->size() << endl;
    cout << "Height: " << tree->height() << endl;
    cout << "isTree?: " << tree->check() << endl;
    tree->show();
    tree->remove(1);
    cout << "Removing 1" << endl;
    cout << "Size: " << tree->size() << endl;
    cout << "Height: " << tree->height() << endl;
    cout << "isTree?: " << tree->check() << endl;
    tree->show();
    tree->remove(8);
    cout << "Removing 8" << endl;
    cout << "Size: " << tree->size() << endl;
    cout << "Height: " << tree->height() << endl;
    cout << "isTree?: " << tree->check() << endl;
    tree->show();
    tree->remove(7);
    cout << "Removing 7" << endl;
    cout << "Size: " << tree->size() << endl;
    cout << "Height: " << tree->height() << endl;
    cout << "isTree?: " << tree->check() << endl;
    tree->show();
    tree->search(6)->data = 10;
    cout << "Set 6 to 10, to test the check function out" << endl;
    tree->show();
    cout << "Size: " << tree->size() << endl;
    cout << "Height: " << tree->height() << endl;
    cout << "isTree?: " << tree->check() << endl;

    // Empirical study
    cout << "\n\nEmpirical Study\n\n" << endl;

    int count = 0;
    const int numInserts = 1000000;
    srand(time(NULL));
    BinarySearchTree* test = new BinarySearchTree();

    clock_t start;
    double duration;
    start = clock();

    while(count < numInserts) {
        // cout << count << endl;
        if(test->insert((count * rand()) % (numInserts * 10))) {
            count++;
        }
    }
    duration = (clock() - start) / (double) CLOCKS_PER_SEC;
    cout << "Size: " << test->size() << endl;
    cout << duration << " seconds to insert " << count << " nodes!" << endl;

    return 0;
}