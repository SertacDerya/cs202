/**
* Title: Binary Search Trees
* Author : Sertaç Derya
* ID: 22003208
* Section : 3
* Homework : 2
* Description : contains the main file
*/
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include "BST.h"
#include "BSTNode.h"
#include "analysis.h"
using namespace std;

BST* merge(const BST& tree1, const BST& tree2);

int main() {
    int arr1[] = {8, 4, 3, 6, 1, 2, 5, 13, 12, 10, 15, 14};
    cout << "Array 1 elements: ";
    for(int i = 0; i < 12; i++) {
        cout << arr1[i] << ", ";
    }
    cout << endl;

    int arr2[15];
    for(int i = 0; i < 15; i++) {
        arr2[i] = i + 16;
    }
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle (arr2, arr2 + 14, std::default_random_engine(seed));
    cout << "Array 2 elements: ";
    for(int i = 0; i < 15; i++) {
        cout << arr2[i] << ", ";
    }
    cout << endl;
    
    BST bst1;
    for(int i = 0; i < 12; i++) {
        bst1.insertItem(arr1[i]);
    }

    BST bst2;
    for(int i = 0; i < 15; i++) {
        bst2.insertItem(arr2[i]);
    }
    int len1 = 13;
    int* traversal1 = bst1.inorderTraversal(len1);

    cout << "Traversals Array 1 is: ";
    for(int i = 0; i < 12; i++) {
        cout << traversal1[i] << ", ";
    }
    cout << endl;

    int len2 = 15;
    int* traversal2 = bst2.inorderTraversal(len2);

    cout << "Traversals Array 2 is: ";
    for(int i = 0; i < 15; i++) {
        cout << traversal2[i] << ", ";
    }
    cout << endl << endl;

    delete[] traversal1;
    delete[] traversal2;

    int seq1[] = {4, 6, 8};
    int seq2[] = {10, 12, 13, 14, 15};
    int seq3[] = {10, 11, 12};
    int seq4[] = {8, 4, 3, 6, 1, 2, 5, 13, 12, 10, 15, 14};
    int seq5[] = {5, 8, 10, 12, 13, 14};
    int seq6[] = {1, 2, 3, 4, 5, 6, 8, 10, 12, 14};
    int seq7[] = {1, 2, 3, 4, 5, 6, 8, 10, 12, 13, 14, 15};

    bool s1 = bst1.hasSequence(seq1, 3); // false
    cout << "Sequence 1: ";
    for(int i = 0; i < 3; i++) {
        cout << seq1[i] << ", ";
    }
    cout << "True/False: " << s1 << endl;
    bool s2 = bst1.hasSequence(seq2, 5); // true
    cout << "Sequence 2: ";
    for(int i = 0; i < 5; i++) {
        cout << seq2[i] << ", ";
    }
    cout << "True/False: " << s2 << endl;
    bool s3 = bst1.hasSequence(seq3, 3); // false
    cout << "Sequence 3: ";
    for(int i = 0; i < 3; i++) {
        cout << seq3[i] << ", ";
    }
    cout << "True/False: " << s3 << endl;
    bool s4 = bst1.hasSequence(seq4, 12); // false
    cout << "Sequence 4: ";
    for(int i = 0; i < 12; i++) {
        cout << seq4[i] << ", ";
    }
    cout << "True/False: " << s4 << endl;
    bool s5 = bst1.hasSequence(seq5, 6); // false
    cout << "Sequence 5: ";
    for(int i = 0; i < 6; i++) {
        cout << seq5[i] << ", ";
    }
    cout << "True/False: " << s5 << endl;
    bool s6 = bst1.hasSequence(seq6, 10); // false
    cout << "Sequence 6: ";
    for(int i = 0; i < 10; i++) {
        cout << seq6[i] << ", ";
    }
    cout << "True/False: " << s6 << endl;
    bool s7 = bst1.hasSequence(seq7, 11); // true
    cout << "Sequence 7: ";
    for(int i = 0; i < 11; i++) {
        cout << seq7[i] << ", ";
    }
    cout << "True/False: " << s7 << endl << endl;


    cout << "Merging the trees" << endl;
    BST* bptr = merge(bst1, bst2);
    int len3 = bptr->getNodeCount();
    int* traversal3 = bptr->inorderTraversal(len3);
    for(int i = 0; i < len3; i++) {
        cout << traversal3[i] << ", ";
    }
    cout << endl << endl;
    delete[] traversal3;
    delete bptr;
    timeAnalysis();
}

BST* merge(const BST& tree1, const BST& tree2) {
    int length1 = tree1.getNodeCount();
    int length2 = tree2.getNodeCount();

    int* arr1 = tree1.inorderTraversal(length1);
    int* arr2 = tree2.inorderTraversal(length2);
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle (arr1, arr1 + length1, std::default_random_engine(seed));

    seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle (arr2, arr2 + length2, std::default_random_engine(seed));

    BST* bst = new BST();
    for(int i = 0; i < length1; i++) {
        bst->insertItem(arr1[i]);
    }

    for(int i = 0; i < length2; i++) {
        bst->insertItem(arr2[i]);
    }
    delete[] arr1;
    delete[] arr2;
    return bst;
}