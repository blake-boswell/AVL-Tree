// Author: Blake Boswell
// Synopsis: This file is used to test out the AVLTree class

#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <ctime>
#include "AVLTree.h"

using namespace std;

int main() {
    bool standardDebug = false;
    AVLTree* avl = new AVLTree();
    BinarySearchTree* tree = new BinarySearchTree();
    if(standardDebug) {
        // LR rot test [Start]
        cout << "Size: " << avl->size() << endl; 
        cout << "Is AVL: " << avl->check() << endl;
        cout << "inserting 6" << endl;
        avl->insert(6);
        cout << "Size: " << avl->size() << endl; 
        cout << "Is AVL: " << avl->check() << endl;
        cout << "inserting 3" << endl;
        avl->insert(3);
        cout << "Size: " << avl->size() << endl; 
        cout << "Is AVL: " << avl->check() << endl;
        cout << "inserting 4" << endl;
        avl->insert(4);
        cout << "Size: " << avl->size() << endl;
        cout << "Is AVL: " << avl->check() << endl;
        avl->show();
        // LR rot test [End]
        // RR rot test [Start]
        cout << "inserting 8" << endl;
        avl->insert(8);
        cout << "Size: " << avl->size() << endl; 
        cout << "Is AVL: " << avl->check() << endl;
        cout << "inserting 9" << endl;
        avl->insert(9);
        cout << "Size: " << avl->size() << endl; 
        cout << "Is AVL: " << avl->check() << endl;
        avl->show();
        // RR rot test [End]
        // RL rot test [Start]
        cout << "inserting 5" << endl;
        avl->insert(5);
        cout << "Size: " << avl->size() << endl; 
        cout << "Is AVL: " << avl->check() << endl;
        avl->show();
        // RL rot test [End]
        // LL rot test [Start]
        cout << "inserting 2" << endl;
        avl->insert(2);
        cout << "Size: " << avl->size() << endl; 
        cout << "Is AVL: " << avl->check() << endl;
        cout << "inserting 1" << endl;
        avl->insert(1);
        cout << "Size: " << avl->size() << endl; 
        cout << "Is AVL: " << avl->check() << endl;
        avl->show();
        // LL rot test [End]
        cout << "Height of tree: " << avl->height() << endl;

        // Testing copy constructor
        cout << "Copied tree: " << endl;
        AVLTree* avl2 = new AVLTree(avl);
        avl2->show();


        cout << "Does 6 exist? " << avl->search(6) << endl;
        cout << "Does 22 exist? " << avl->search(22) << endl;
        cout << "Removing 6" << endl;
        if(avl->remove(6)) {
            cout << "Success!" << endl;
        }
        cout << "Size: " << avl->size() << endl; 
        cout << "Is AVL: " << avl->check() << endl;
        cout << "Does 6 exist? " << avl->search(6) << endl;
        avl->show(); 
        cout << "Removing 3" << endl;
        if(avl->remove(3)) {
            cout << "Success!" << endl;
        }
        cout << "Size: " << avl->size() << endl; 
        cout << "Is AVL: " << avl->check() << endl;
        avl->show();
        cout << "Removing 2" << endl;
        if(avl->remove(2)) {
            cout << "Success!" << endl;
        }
        cout << "Size: " << avl->size() << endl; 
        cout << "Is AVL: " << avl->check() << endl;
        avl->show();
        cout << "Removing 1" << endl;
        if(avl->remove(1)) {
            cout << "Success!" << endl;
        }
        cout << "Size: " << avl->size() << endl; 
        cout << "Is AVL: " << avl->check() << endl;
        avl->show();
        cout << "Removing 8" << endl;
        if(avl->remove(8)) {
            cout << "Success!" << endl;
        }
        cout << "Size: " << avl->size() << endl; 
        cout << "Is AVL: " << avl->check() << endl;
        avl->show();
        cout << "Removing 5" << endl;
        if(avl->remove(5)) {
            cout << "Success!" << endl;
        }
        cout << "Size: " << avl->size() << endl; 
        cout << "Is AVL: " << avl->check() << endl;
        avl->show();
        cout << "Removing 4" << endl;
        if(avl->remove(4)) {
            cout << "Success!" << endl;
        }
        cout << "Size: " << avl->size() << endl; 
        cout << "Is AVL: " << avl->check() << endl;
        avl->show();
        cout << "Removing 9" << endl;
        if(avl->remove(9)) {
            cout << "Success!" << endl;
        }
        cout << "Size: " << avl->size() << endl; 
        cout << "Is AVL: " << avl->check() << endl;
        avl->show();
        cout << "Removing 10" << endl;
        if(avl->remove(8)) {
            cout << "Success!" << endl;
        } else {
            cout << "Failure!" << endl;
        }
        cout << "Size: " << avl->size() << endl; 
        cout << "Is AVL: " << avl->check() << endl;
        avl->show();
        cout << "Does 2 exist? " << avl->search(2) << endl;
        
    } else {
        // Random test
       const int numInserts = 25000;
       int count = 0;
       int input;
       srand(time(NULL));

       // Generate an array of numInserts unique numbers
       int* deletions = new int[numInserts];
       int* inputs = new int[numInserts];
       for(int i = 0; i < numInserts; i++) {
           inputs[i] = i;
       }

       // Shuffle the arrays
       random_shuffle(&inputs[0], &inputs[numInserts]);


       cout << "Beginning insertion test for " << numInserts << " random insertions..." << endl;

       clock_t start;
       double duration;
       start = clock();

       while(count < numInserts) {
           if(avl->insert(inputs[count])) {
               count++;
           }
       }

       duration = (clock() - start) / (double) CLOCKS_PER_SEC;
       cout << "Size: " << avl->size() << endl;
       cout << duration << " seconds to insert " << count << " nodes!" << endl;

       cout << "Is AVL: " << avl->check() << endl;

       // BST insertion comparison

        start = clock();

       while(count < numInserts) {
           if(tree->insert(inputs[count])) {
               count++;
           }
       }

       duration = (clock() - start) / (double) CLOCKS_PER_SEC;
       cout << "Size: " << tree->size() << endl;
       cout << duration << " seconds to insert " << count << " nodes!" << endl;

       cout << "Is BST: " << tree->check() << endl;


       

    //    cout << "Beginning deletion test for " << numInserts << " random deletions..." << endl;
    //    count = 0;
    //    // random_shuffle(&inputs[0], &inputs[numInserts]);
    //    for(int i = 0; i < numInserts; i++) {
    //        if(!avl->search(inputs[i])) {
    //            cout << inputs[i] << " does not exist in the array..." << endl;
    //        }
    //    }
    //    start = clock();
    //    while(count < numInserts) {
    //         cout << count << endl;
    //        // input = (count * rand()) % (numInserts * 10);
    //        cout << "removing " << inputs[count] << endl;
    //        avl->show();
    //        if(avl->remove(inputs[count])) {
    //            count++;
    //            if(avl->size() % (numInserts/1000) == 0)
    //                cout << "Tree now contains " << avl->size() << " nodes." << endl;
    //        } else {
    //            cout << "Value " << inputs[count] << " not found in tree." << endl;
    //            cout << "Does " << inputs[count] << " (Value at index " << count << " exist? " << avl->search(inputs[count]) << endl;
    //            //return 0;
    //        }
    //        count++;
    //    }
    //    duration = (clock() - start) / (double) CLOCKS_PER_SEC;
    //    cout << "Size: " << avl->size() << endl;
    //    cout << duration << " seconds to delete " << count << " nodes!" << endl;
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