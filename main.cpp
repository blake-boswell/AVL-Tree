// Author: Blake Boswell
// Synopsis: This file is used to test out the BinarySearchTree class

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "AVLTree.h"

using namespace std;

int main() {
    AVLTree* avl = new AVLTree();

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