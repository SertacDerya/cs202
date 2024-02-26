/**
* Title: Binary Search Trees
* Author : Sertaç Derya
* ID: 22003208
* Section : 3
* Homework : 2
* Description : contains the analysis implementation
*/
#include "analysis.h"
#include "BST.h"
#include <iostream>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <vector>
#include <random>
using namespace std;

void timeAnalysis() {
    int arr[15000];
    for(int i = 0; i < 15000; i++) {
        arr[i] = i;
    }

    BST bst;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle (arr, arr + 14999, std::default_random_engine(seed));

    cout << "Part e - Time analysis of Binary Search Tree- part 1" << endl;
    cout << "-----------------------------------------------------" << endl;
    printf("%-*s%-*s\n", 20, "Tree size", 20, "Time elapsed");
    cout << "-----------------------------------------------------" << endl;
    //Declare necessary variables
    chrono::time_point< chrono::system_clock > startTime;
    chrono::duration< double, milli > elapsedTime1;
    //Store the starting time
    startTime = chrono::system_clock::now();
    //Compute the number of milliseconds that passed since the starting time

    for(int i = 1; i <= 15000; i++) {
        bst.insertItem(arr[i - 1]);
        if(i % 1500 == 0) {
            elapsedTime1 = chrono::system_clock::now() - startTime;
            printf("%-*d%-*f\n", 20, i, 20, elapsedTime1);
            startTime = chrono::system_clock::now();
        }
    }
    cout << endl;

    seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle (arr, arr + 14999, std::default_random_engine(seed));
    cout << "Part e - Time analysis of Binary Search Tree- part 2" << endl;
    cout << "-----------------------------------------------------" << endl;
    printf("%-*s%-*s\n", 20, "Tree size", 20, "Time elapsed");
    cout << "-----------------------------------------------------" << endl;
    startTime = chrono::system_clock::now();
    for(int i = 1; i <= 15000; i++) {
        bst.deleteItem(arr[i - 1]);
        if(i % 1500 == 0) {
            elapsedTime1 = chrono::system_clock::now() - startTime;
            printf("%-*d%-*f\n", 20, 15000 - i, 20, elapsedTime1);
            startTime = chrono::system_clock::now();
        }
    }
}