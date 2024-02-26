/**
* Title: Algorithm analysis & Sorting
* Author : Sertaç Derya
* ID: 22003208
* Section : 3
* Homework : 1
* Description : Contains the main
*/
#include <cstdlib>
#include <iostream>
#include <chrono>
#include <time.h>
#include <cmath>
#include "22003208_Sertac_Derya.h"
using namespace std;

int main() {
    const int sizes[] = {1000, 5000, 10000, 20000};
    cout << "                          Part 2-b-1: Performance analysis of random integers array" << endl;
    for(int i = 0; i < 4; i++) {
        const int size = sizes[i];

        int randArray1[size];
        int randArray2[size];
        int randArray3[size];
        int randArray4[size];
        int randArray5[size];

        int compCount1 = 0;
        int switchCount1 = 0;

        int compCount2 = 0;
        int switchCount2 = 0;

        int compCount3 = 0;
        int switchCount3 = 0;

        int compCount4 = 0;
        int switchCount4 = 0;

        int compCount5 = 0;
        int switchCount5 = 0;

        for(int i = 0; i < size; i++) {
            int r = rand()%size;
            randArray1[i] = r;

            randArray2[i] = r;

            randArray3[i] = r;

            randArray4[i] = r;

            randArray5[i] = r;
        }
        //Declare necessary variables
        chrono::time_point< chrono::system_clock > startTime;
        chrono::duration< double, milli > elapsedTime1;
        //Store the starting time
        startTime = chrono::system_clock::now();
        insertionSort(randArray1, size, compCount1, switchCount1);
        //Compute the number of milliseconds that passed since the starting time
        elapsedTime1 = chrono::system_clock::now() - startTime;

        //Declare necessary variables
         startTime;
        chrono::duration< double, milli > elapsedTime2;
        //Store the starting time
        startTime = chrono::system_clock::now();
        bubbleSort(randArray2, size, compCount2, switchCount2);
        //Compute the number of milliseconds that passed since the starting time
        elapsedTime2 = chrono::system_clock::now() - startTime;

        //Declare necessary variables
         startTime;
        chrono::duration< double, milli > elapsedTime3;
        //Store the starting time
        startTime = chrono::system_clock::now();
        mergeSort(randArray3, size, compCount3, switchCount3);
        //Compute the number of milliseconds that passed since the starting time
        elapsedTime3 = chrono::system_clock::now() - startTime;

        //Declare necessary variables
         startTime;
        chrono::duration< double, milli > elapsedTime4;
        //Store the starting time
        startTime = chrono::system_clock::now();
        quickSort(randArray4, size, compCount4, switchCount4);
        //Compute the number of milliseconds that passed since the starting time
        elapsedTime4 = chrono::system_clock::now() - startTime;

        //Declare necessary variables
         startTime;
        chrono::duration< double, milli > elapsedTime5;
        //Store the starting time
        startTime = chrono::system_clock::now();
        hybridSort(randArray5, size, compCount5, switchCount5);
        //Compute the number of milliseconds that passed since the starting time
        elapsedTime5 = chrono::system_clock::now() - startTime;

        cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
        printf("%*s%*s%*s\n", 40, "Elapsed time", 40, "Comp. count", 40, "Move count");
        cout << "Array Size: " << size << endl;
        printf("%-*s%*f%*d%*d\n", 15, "Insertion Sort", 25, elapsedTime1, 40, compCount1, 40, switchCount1);
        printf("%-*s%*f%*d%*d\n", 15, "Bubble Sort", 25, elapsedTime2, 40, compCount2, 40, switchCount2);
        printf("%-*s%*f%*d%*d\n", 15, "Merge Sort", 25, elapsedTime3, 40, compCount3, 40, switchCount3);
        printf("%-*s%*f%*d%*d\n", 15, "Quick Sort", 25, elapsedTime4, 40, compCount4, 40, switchCount4);
        printf("%-*s%*f%*d%*d\n", 15, "Hybrid Sort", 25, elapsedTime5, 40, compCount5, 40, switchCount5);
        cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
    }

    cout << "                          Part 2-b-2: Performance analysis of partially ascending integers array" << endl;
    for(int i = 0; i < 4; i++) {
        const int size = sizes[i];

        int randArray1[size];
        int randArray2[size];
        int randArray3[size];
        int randArray4[size];
        int randArray5[size];

        int compCount1 = 0;
        int switchCount1 = 0;

        int compCount2 = 0;
        int switchCount2 = 0;

        int compCount3 = 0;
        int switchCount3 = 0;

        int compCount4 = 0;
        int switchCount4 = 0;

        int compCount5 = 0;
        int switchCount5 = 0;

        int log = log2(size);
        int multiplier = 0;
        for(int i = 0; i < size; i++) {
            if(i % log == 0) {
                multiplier = multiplier + log;
            }
            int r = rand()%log;
            r = r + multiplier;
            randArray1[i] = r;

            randArray2[i] = r;

            randArray3[i] = r;

            randArray4[i] = r;

            randArray5[i] = r;
        }
        //Declare necessary variables
        chrono::time_point< chrono::system_clock > startTime;
        chrono::duration< double, milli > elapsedTime1;
        //Store the starting time
        startTime = chrono::system_clock::now();
        insertionSort(randArray1, size, compCount1, switchCount1);
        //Compute the number of milliseconds that passed since the starting time
        elapsedTime1 = chrono::system_clock::now() - startTime;

        //Declare necessary variables
         startTime;
        chrono::duration< double, milli > elapsedTime2;
        //Store the starting time
        startTime = chrono::system_clock::now();
        bubbleSort(randArray2, size, compCount2, switchCount2);
        //Compute the number of milliseconds that passed since the starting time
        elapsedTime2 = chrono::system_clock::now() - startTime;

        //Declare necessary variables
         startTime;
        chrono::duration< double, milli > elapsedTime3;
        //Store the starting time
        startTime = chrono::system_clock::now();
        mergeSort(randArray3, size, compCount3, switchCount3);
        //Compute the number of milliseconds that passed since the starting time
        elapsedTime3 = chrono::system_clock::now() - startTime;

        //Declare necessary variables
         startTime;
        chrono::duration< double, milli > elapsedTime4;
        //Store the starting time
        startTime = chrono::system_clock::now();
        quickSort(randArray4, size, compCount4, switchCount4);
        //Compute the number of milliseconds that passed since the starting time
        elapsedTime4 = chrono::system_clock::now() - startTime;

        //Declare necessary variables
         startTime;
        chrono::duration< double, milli > elapsedTime5;
        //Store the starting time
        startTime = chrono::system_clock::now();
        hybridSort(randArray5, size, compCount5, switchCount5);
        //Compute the number of milliseconds that passed since the starting time
        elapsedTime5 = chrono::system_clock::now() - startTime;

        cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
        printf("%*s%*s%*s\n", 40, "Elapsed time", 40, "Comp. count", 40, "Move count");
        cout << "Array Size: " << size << endl;
        printf("%-*s%*f%*d%*d\n", 15, "Insertion Sort", 25, elapsedTime1, 40, compCount1, 40, switchCount1);
        printf("%-*s%*f%*d%*d\n", 15, "Bubble Sort", 25, elapsedTime2, 40, compCount2, 40, switchCount2);
        printf("%-*s%*f%*d%*d\n", 15, "Merge Sort", 25, elapsedTime3, 40, compCount3, 40, switchCount3);
        printf("%-*s%*f%*d%*d\n", 15, "Quick Sort", 25, elapsedTime4, 40, compCount4, 40, switchCount4);
        printf("%-*s%*f%*d%*d\n", 15, "Hybrid Sort", 25, elapsedTime5, 40, compCount5, 40, switchCount5);
        cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
    }

    cout << "                          Part 2-b-3: Performance analysis of partially descending integers array" << endl;
    for(int i = 0; i < 4; i++) {
        const int size = sizes[i];

        int randArray1[size];
        int randArray2[size];
        int randArray3[size];
        int randArray4[size];
        int randArray5[size];

        int compCount1 = 0;
        int switchCount1 = 0;

        int compCount2 = 0;
        int switchCount2 = 0;

        int compCount3 = 0;
        int switchCount3 = 0;

        int compCount4 = 0;
        int switchCount4 = 0;

        int compCount5 = 0;
        int switchCount5 = 0;

        int log = log2(size);
        int multiplier = 0;
        for(int i = 0; i < size; i++) {
            if(i % log == 0) {
                multiplier = multiplier + log;
            }
            int r = rand()%log;
            r = r + size - multiplier;
            randArray1[i] = r;

            randArray2[i] = r;

            randArray3[i] = r;

            randArray4[i] = r;

            randArray5[i] = r;
        }
        //Declare necessary variables
        chrono::time_point< chrono::system_clock > startTime;
        chrono::duration< double, milli > elapsedTime1;
        //Store the starting time
        startTime = chrono::system_clock::now();
        insertionSort(randArray1, size, compCount1, switchCount1);
        //Compute the number of milliseconds that passed since the starting time
        elapsedTime1 = chrono::system_clock::now() - startTime;

        //Declare necessary variables
         startTime;
        chrono::duration< double, milli > elapsedTime2;
        //Store the starting time
        startTime = chrono::system_clock::now();
        bubbleSort(randArray2, size, compCount2, switchCount2);
        //Compute the number of milliseconds that passed since the starting time
        elapsedTime2 = chrono::system_clock::now() - startTime;

        //Declare necessary variables
         startTime;
        chrono::duration< double, milli > elapsedTime3;
        //Store the starting time
        startTime = chrono::system_clock::now();
        mergeSort(randArray3, size, compCount3, switchCount3);
        //Compute the number of milliseconds that passed since the starting time
        elapsedTime3 = chrono::system_clock::now() - startTime;

        //Declare necessary variables
         startTime;
        chrono::duration< double, milli > elapsedTime4;
        //Store the starting time
        startTime = chrono::system_clock::now();
        quickSort(randArray4, size, compCount4, switchCount4);
        //Compute the number of milliseconds that passed since the starting time
        elapsedTime4 = chrono::system_clock::now() - startTime;

        //Declare necessary variables
         startTime;
        chrono::duration< double, milli > elapsedTime5;
        //Store the starting time
        startTime = chrono::system_clock::now();
        hybridSort(randArray5, size, compCount5, switchCount5);
        //Compute the number of milliseconds that passed since the starting time
        elapsedTime5 = chrono::system_clock::now() - startTime;

        cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
        printf("%*s%*s%*s\n", 40, "Elapsed time", 40, "Comp. count", 40, "Move count");
        cout << "Array Size: " << size << endl;
        printf("%-*s%*f%*d%*d\n", 15, "Insertion Sort", 25, elapsedTime1, 40, compCount1, 40, switchCount1);
        printf("%-*s%*f%*d%*d\n", 15, "Bubble Sort", 25, elapsedTime2, 40, compCount2, 40, switchCount2);
        printf("%-*s%*f%*d%*d\n", 15, "Merge Sort", 25, elapsedTime3, 40, compCount3, 40, switchCount3);
        printf("%-*s%*f%*d%*d\n", 15, "Quick Sort", 25, elapsedTime4, 40, compCount4, 40, switchCount4);
        printf("%-*s%*f%*d%*d\n", 15, "Hybrid Sort", 25, elapsedTime5, 40, compCount5, 40, switchCount5);
        cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
    }
    return 0;
}