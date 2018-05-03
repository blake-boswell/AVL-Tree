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
        // // Insertion Rotation Test
        // // LR rot test [Start]
        // cout << "Size: " << avl->size() << endl; 
        // cout << "Is AVL: " << avl->check() << endl;
        // cout << "inserting 6" << endl;
        // avl->insert(6);
        // cout << "Size: " << avl->size() << endl; 
        // cout << "Is AVL: " << avl->check() << endl;
        // cout << "inserting 3" << endl;
        // avl->insert(3);
        // cout << "Size: " << avl->size() << endl; 
        // cout << "Is AVL: " << avl->check() << endl;
        // cout << "inserting 4" << endl;
        // avl->insert(4);
        // cout << "Size: " << avl->size() << endl;
        // cout << "Is AVL: " << avl->check() << endl;
        // avl->show();
        // // LR rot test [End]
        // // RR rot test [Start]
        // cout << "inserting 8" << endl;
        // avl->insert(8);
        // cout << "Size: " << avl->size() << endl; 
        // cout << "Is AVL: " << avl->check() << endl;
        // avl->show();
        // cout << "inserting 9" << endl;
        // avl->insert(9);
        // cout << "Size: " << avl->size() << endl; 
        // cout << "Is AVL: " << avl->check() << endl;
        // avl->show();
        // // RR rot test [End]
        // // RL rot test [Start]
        // cout << "inserting 5" << endl;
        // avl->insert(5);
        // cout << "Size: " << avl->size() << endl; 
        // cout << "Is AVL: " << avl->check() << endl;
        // avl->show();
        // // RL rot test [End]
        // // LL rot test [Start]
        // cout << "inserting 2" << endl;
        // avl->insert(2);
        // cout << "Size: " << avl->size() << endl; 
        // cout << "Is AVL: " << avl->check() << endl;
        // cout << "inserting 1" << endl;
        // avl->insert(1);
        // cout << "Size: " << avl->size() << endl; 
        // cout << "Is AVL: " << avl->check() << endl;
        // avl->show();
        // // LL rot test [End]
        // cout << "Height of tree: " << avl->height() << endl;

        // // Testing copy constructor
        // cout << "Copied tree: " << endl;
        // AVLTree* avl2 = new AVLTree(avl);
        // avl2->show();


        // cout << "Does 6 exist? " << avl->search(6) << endl;
        // cout << "Does 22 exist? " << avl->search(22) << endl;
        // cout << "Removing 6" << endl;
        // if(avl->remove(6)) {
        //     cout << "Success!" << endl;
        // }
        // cout << "Size: " << avl->size() << endl; 
        // cout << "Is AVL: " << avl->check() << endl;
        // cout << "Does 6 exist? " << avl->search(6) << endl;
        // avl->show(); 
        // cout << "Removing 3" << endl;
        // if(avl->remove(3)) {
        //     cout << "Success!" << endl;
        // }
        // cout << "Size: " << avl->size() << endl; 
        // cout << "Is AVL: " << avl->check() << endl;
        // avl->show();
        // cout << "Removing 2" << endl;
        // if(avl->remove(2)) {
        //     cout << "Success!" << endl;
        // }
        // cout << "Size: " << avl->size() << endl; 
        // cout << "Is AVL: " << avl->check() << endl;
        // avl->show();
        // cout << "Removing 1" << endl;
        // if(avl->remove(1)) {
        //     cout << "Success!" << endl;
        // }
        // cout << "Size: " << avl->size() << endl; 
        // cout << "Is AVL: " << avl->check() << endl;
        // avl->show();
        // cout << "Removing 8" << endl;
        // if(avl->remove(8)) {
        //     cout << "Success!" << endl;
        // }
        // cout << "Size: " << avl->size() << endl; 
        // cout << "Is AVL: " << avl->check() << endl;
        // avl->show();
        // cout << "Removing 5" << endl;
        // if(avl->remove(5)) {
        //     cout << "Success!" << endl;
        // }
        // cout << "Size: " << avl->size() << endl; 
        // cout << "Is AVL: " << avl->check() << endl;
        // avl->show();
        // cout << "Removing 4" << endl;
        // if(avl->remove(4)) {
        //     cout << "Success!" << endl;
        // }
        // cout << "Size: " << avl->size() << endl; 
        // cout << "Is AVL: " << avl->check() << endl;
        // avl->show();
        // cout << "Removing 9" << endl;
        // if(avl->remove(9)) {
        //     cout << "Success!" << endl;
        // }
        // cout << "Size: " << avl->size() << endl; 
        // cout << "Is AVL: " << avl->check() << endl;
        // avl->show();
        // cout << "Removing 10" << endl;
        // if(avl->remove(8)) {
        //     cout << "Success!" << endl;
        // } else {
        //     cout << "Failure!" << endl;
        // }
        // cout << "Size: " << avl->size() << endl; 
        // cout << "Is AVL: " << avl->check() << endl;
        // avl->show();
        // cout << "Does 2 exist? " << avl->search(2) << endl;

        // Remove tests
        AVLTree* llAVL = new AVLTree();
        llAVL->insert(10);
        llAVL->insert(5);
        llAVL->insert(18);
        llAVL->insert(2);
        llAVL->insert(7);
        llAVL->insert(16);
        llAVL->insert(20);
        llAVL->insert(1);
        llAVL->insert(12);
        llAVL->insert(19);
        llAVL->insert(22);
        llAVL->insert(23);
        llAVL->show();
        cout << "\n\nTesting remove rotations\n\n" << endl;
        cout << "Removing 7 for LL ROT on 5" << endl;
        llAVL->remove(7);
        llAVL->show();
        cout << "Is AVL: " << llAVL->check() << endl;
        cout << "\n\n\n";
        
        AVLTree* lrAVL = new AVLTree();
        lrAVL->insert(10);
        lrAVL->insert(5);
        lrAVL->insert(18);
        lrAVL->insert(2);
        lrAVL->insert(7);
        lrAVL->insert(16);
        lrAVL->insert(20);
        lrAVL->insert(3);
        lrAVL->insert(12);
        lrAVL->insert(19);
        lrAVL->insert(22);
        lrAVL->insert(23);
        lrAVL->show();
        cout << "Testing remove rotations" << endl;
        cout << "Removing 7 for LR ROT on 5" << endl;
        lrAVL->remove(7);
        lrAVL->show();
        cout << "Is AVL: " << lrAVL->check() << endl;
        cout << "\n\n\n";

        AVLTree* rrAVL = new AVLTree();
        rrAVL->insert(10);
        rrAVL->insert(5);
        rrAVL->insert(18);
        rrAVL->insert(2);
        rrAVL->insert(7);
        rrAVL->insert(16);
        rrAVL->insert(20);
        rrAVL->insert(1);
        rrAVL->insert(12);
        rrAVL->insert(19);
        rrAVL->insert(22);
        rrAVL->insert(23);
        rrAVL->show();
        cout << "Testing remove rotations" << endl;
        cout << "Removing 19 for RR ROT on 20" << endl;
        rrAVL->remove(19);
        rrAVL->show();
        cout << "Is AVL: " << rrAVL->check() << endl;
        cout << "\n\n\n";

        AVLTree* rlAVL = new AVLTree();
        rlAVL->insert(10);
        rlAVL->insert(5);
        rlAVL->insert(18);
        rlAVL->insert(2);
        rlAVL->insert(7);
        rlAVL->insert(16);
        rlAVL->insert(20);
        rlAVL->insert(1);
        rlAVL->insert(12);
        rlAVL->insert(19);
        rlAVL->insert(22);
        rlAVL->insert(21);
        rlAVL->show();
        cout << "Testing remove rotations" << endl;
        cout << "Removing 19 for RL ROT on 20" << endl;
        rlAVL->remove(19);
        rlAVL->show();
        cout << "Is AVL: " << rlAVL->check() << endl;

        
    } else {
        // Random test
        const int numInserts = 10000000;
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


        cout << "[AVL] Beginning insertion test for " << numInserts << " random insertions..." << endl;

        clock_t start;
        double duration;
        start = clock();

        while(count < numInserts) {
            if(numInserts <= 20) 
                cout << "Inserting " << inputs[count] << endl;
            if(avl->insert(inputs[count])) {
                count++;
                // avl->show();
                // cout << "Is AVL: " << avl->check() << endl;
            } else {
                cout << "FAILED inserting " << inputs[count] << endl;
                return 0;
            }
        }

        duration = (clock() - start) / (double) CLOCKS_PER_SEC;
        cout << "Size: " << avl->size() << endl;
        cout << duration << " seconds to insert " << count << " nodes!" << endl;

        cout << "Is AVL: " << avl->check() << endl;

        // BST insertion comparison
        cout << "[BST] Beginning insertion test for " << numInserts << " random insertions..." << endl;
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


       

       cout << "[AVL] Beginning deletion test for " << numInserts << " random deletions..." << endl;
       count = 0;
       // random_shuffle(&inputs[0], &inputs[numInserts]);
       for(int i = 0; i < numInserts; i++) {
           if(!avl->search(inputs[i])) {
               cout << inputs[i] << " does not exist in the array..." << endl;
           }
       }
       start = clock();
       while(count < numInserts) {
           if(avl->remove(inputs[count])) {
            //   count++;
            //    if(avl->size() % (numInserts/1000) == 0)
            //        cout << "Tree now contains " << avl->size() << " nodes." << endl;
           } else {
               cout << "Value " << inputs[count] << " not found in tree." << endl;
               cout << "Does " << inputs[count] << " (Value at index " << count << " exist? " << avl->search(inputs[count]) << endl;
               //return 0;
           }
           count++;
       }
       duration = (clock() - start) / (double) CLOCKS_PER_SEC;
       cout << "Size: " << avl->size() << endl;
       cout << duration << " seconds to delete " << count << " nodes!" << endl;
       cout << "Is AVL: " << avl->check() << endl;

       // BST deletion comparison
        cout << "[BST] Beginning deletion test for " << numInserts << " random deletions..." << endl;
        start = clock();

        while(count < numInserts) {
            if(tree->remove(inputs[count])) {
                count++;
            }
        }

        duration = (clock() - start) / (double) CLOCKS_PER_SEC;
        cout << "Size: " << tree->size() << endl;
        cout << duration << " seconds to delete " << count << " nodes!" << endl;

        cout << "Is BST: " << tree->check() << endl;
    }    
    return 0;
}