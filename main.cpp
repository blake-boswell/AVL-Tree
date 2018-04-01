// Author: Blake Boswell
// Synopsis: This file is used to test out the BinarySearchTree class

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "AVLTree.h"

using namespace std;

int main() {
    bool standardDebug = true;
    AVLTree* avl = new AVLTree();
    if(standardDebug) {
        // LR rot test [Start]
        cout << "Size: " << avl->size() << endl;
        cout << "inserting 6" << endl;
        avl->insert(6);
        cout << "Size: " << avl->size() << endl;
        cout << "inserting 3" << endl;
        avl->insert(3);
        cout << "Size: " << avl->size() << endl;
        cout << "inserting 4" << endl;
        avl->insert(4);
        cout << "Size: " << avl->size() << endl;
        avl->show();
        // LR rot test [End]
        // RR rot test [Start]
        cout << "inserting 8" << endl;
        avl->insert(8);
        cout << "Size: " << avl->size() << endl;
        cout << "inserting 9" << endl;
        avl->insert(9);
        cout << "Size: " << avl->size() << endl;
        avl->show();
        // RR rot test [End]
        // RL rot test [Start]
        cout << "inserting 5" << endl;
        avl->insert(5);
        cout << "Size: " << avl->size() << endl;
        avl->show();
        // RL rot test [End]
        // LL rot test [Start]
        cout << "inserting 2" << endl;
        avl->insert(2);
        cout << "Size: " << avl->size() << endl;
        cout << "inserting 1" << endl;
        avl->insert(1);
        cout << "Size: " << avl->size() << endl;
        avl->show();
        // LL rot test [End]
        cout << "Height of tree: " << avl->height();

        cout << "Does 6 exist? " << avl->search(6) << endl;
        cout << "Does 22 exist? " << avl->search(22) << endl;
        cout << "Removing 6" << endl;
        if(avl->remove(6)) {
            cout << "Success!" << endl;
        }
        cout << "Size: " << avl->size() << endl;
        cout << "Does 6 exist? " << avl->search(6) << endl;
        avl->show(); 
        cout << "Removing 3" << endl;
        if(avl->remove(3)) {
            cout << "Success!" << endl;
        }
        cout << "Size: " << avl->size() << endl;
        avl->show();
        cout << "Removing 2" << endl;
        if(avl->remove(2)) {
            cout << "Success!" << endl;
        }
        cout << "Size: " << avl->size() << endl;
        avl->show();
        cout << "Removing 1" << endl;
        if(avl->remove(1)) {
            cout << "Success!" << endl;
        }
        cout << "Size: " << avl->size() << endl;
        avl->show();
        cout << "Removing 8" << endl;
        if(avl->remove(8)) {
            cout << "Success!" << endl;
        }
        cout << "Size: " << avl->size() << endl;
        avl->show();
        cout << "Removing 5" << endl;
        if(avl->remove(5)) {
            cout << "Success!" << endl;
        }
        cout << "Size: " << avl->size() << endl;
        avl->show();
        cout << "Removing 4" << endl;
        if(avl->remove(4)) {
            cout << "Success!" << endl;
        }
        cout << "Size: " << avl->size() << endl;
        avl->show();
        cout << "Removing 9" << endl;
        if(avl->remove(9)) {
            cout << "Success!" << endl;
        }
        cout << "Size: " << avl->size() << endl;
        avl->show();
        cout << "Removing 10" << endl;
        if(avl->remove(8)) {
            cout << "Success!" << endl;
        } else {
            cout << "Failure!" << endl;
        }
        cout << "Size: " << avl->size() << endl;
        avl->show();
        cout << "Does 2 exist? " << avl->search(2) << endl;
        
    } else {
         // Random test
        const int numInserts = 10;
        int count = 0;
        int input;
        srand(time(NULL));
        while(count < numInserts) {
            // cout << count << endl;
            input = (count * rand()) % (numInserts * 10);
            cout << "inserting " << input << endl;
            if(avl->insert(input)) {
                avl->show();
                count++;
            } else {
                cout << "That didn't work..." << endl;
            }
        }
    }    

    // Empirical study
    // cout << "\n\nEmpirical Study\n\n" << endl;

    // int count = 0;
    // const int numInserts = 1000000;
    // srand(time(NULL));
    // BinarySearchTree* test = new BinarySearchTree();

    // clock_t start;
    // double duration;
    // start = clock();

    // while(count < numInserts) {
    //     // cout << count << endl;
    //     if(test->insert((count * rand()) % (numInserts * 10))) {
    //         count++;
    //     }
    // }
    // duration = (clock() - start) / (double) CLOCKS_PER_SEC;
    // cout << "Size: " << test->size() << endl;
    // cout << duration << " seconds to insert " << count << " nodes!" << endl;

    return 0;
}