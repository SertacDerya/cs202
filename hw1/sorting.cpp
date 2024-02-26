/**
* Title: Algorithm analysis & Sorting
* Author : Sertaç Derya
* ID: 22003208
* Section : 3
* Homework : 1
* Description : This file contains the sorting functions
*/
#pragma once
#include "22003208_Sertac_Derya.h"
//*********************************************
void insertionSort(int *arr, const int size, int &compCount, int &moveCount) {
    for(int i = 1; i < size; i++) {
        int item = arr[i];
        moveCount++;
        int j = i;
        compCount++;
        for(; j > 0 && arr[j - 1] > item; j--) {
            compCount++;
            arr[j] = arr[j - 1];
            moveCount++;
        }
        arr[j] = item;
    }
}
//*********************************************
void bubbleSort(int *arr, const int size, int &compCount, int &moveCount) {
    bool sorted = false;
    for(int i = size - 1; i > 0 && !sorted; i--) {
        sorted = true;
        for(int j = 0; j < i; j++) {
            compCount++;
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                moveCount = moveCount + 3;
                sorted = false;
            }
        }
    }
}
//*********************************************
void merge(int* arr, int begin1, int begin2, const int end1, const int end2, int &compCount, int &moveCount) {
    const int size = end2 - begin1 + 1;
    int tempArr[size];
    int index = 0;
    int begin = begin1;
    while(begin1 <= end1 && begin2 <= end2) {
        compCount++;//
        if(arr[begin1] < arr[begin2]) {
            tempArr[index] = arr[begin1];
            begin1++;
        } else {
            tempArr[index] = arr[begin2];
            begin2++;
        }
        moveCount++;//
        index++;
    }
    while(begin1 <= end1) {
        tempArr[index] = arr[begin1];
        begin1++;
        index++;
        moveCount++;//        
    }
    while(begin2 <= end2) {
        tempArr[index] = arr[begin2];
        begin2++;
        index++;
        moveCount++;//
    }
    for(int i = begin, j = 0; i <= end2; i++, j++) {
        arr[i] = tempArr[j];
        moveCount++;//
    }
}
void mergeSortHelper(int *arr, int begin, int end, int &compCount, int &moveCount) {
    if((end - begin) <= 0) {
        return;
    } else {
        int half = (begin + end) / 2;
        mergeSortHelper(arr, begin, half, compCount, moveCount);
        mergeSortHelper(arr, half + 1, end, compCount, moveCount);
        merge(arr, begin, half + 1, half, end, compCount, moveCount);
    }
}
void mergeSort(int *arr, const int size, int &compCount, int &moveCount) {
    if(size <= 1) {
        return;
    } else {
        int half = (size - 1) / 2;
        mergeSortHelper(arr, 0, half, compCount, moveCount);
        mergeSortHelper(arr, half + 1, size - 1, compCount, moveCount);
        merge(arr, 0, half + 1, half, size - 1, compCount, moveCount);
    }
}
//*********************************************

void partition(int *arr, int &pivotIndex, int begin, int end, int &compCount, int &moveCount) {
    pivotIndex = begin;
    int pivot = arr[begin];
    for(int i = begin + 1; i < end + 1; i++) {
        compCount++;//
        if(arr[i] < pivot) {
            pivotIndex++;
            int temp = arr[i];
            arr[i] = arr[pivotIndex];
            arr[pivotIndex] = temp;
            moveCount = moveCount + 3;
        }
    }
    arr[begin] = arr[pivotIndex];
    arr[pivotIndex] = pivot;
    moveCount = moveCount + 3;//
}

void quickSortHelper(int *arr, int begin, int end, int &compCount, int &moveCount) {
    if(begin < end) {
        int pivot;
        partition(arr, pivot, begin, end, compCount, moveCount);
        
        quickSortHelper(arr, begin, pivot - 1, compCount, moveCount);
        quickSortHelper(arr, pivot + 1, end, compCount, moveCount);
    }
}

void quickSort(int *arr, const int size, int &compCount, int &moveCount) {
    if(size > 1) {
        int pivot;
        partition(arr, pivot, 0, size - 1, compCount, moveCount);
        
        quickSortHelper(arr, 0, pivot - 1, compCount, moveCount);
        quickSortHelper(arr, pivot + 1, size - 1, compCount, moveCount);
    }
}
//*********************************************
void bubbleHelper(int *arr, int begin, int end, int &compCount, int &moveCount) {
    for(int i = end; i > begin; i--) {
        for(int j = begin; j < i; j++) {
            compCount++;
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                moveCount = moveCount + 3;
            }
        }
    }
}

void hybridSortHelper(int *arr, int begin, int end, int &compCount, int &moveCount) {
    if(begin < end) {
        if(end - begin <= 20) {
            bubbleHelper(arr, begin, end, compCount, moveCount);
        } else {
            int pivot;
            partition(arr, pivot, begin, end, compCount, moveCount);

            hybridSortHelper(arr, begin, pivot - 1, compCount, moveCount);
            hybridSortHelper(arr, pivot + 1, end, compCount, moveCount);
        }
    }
}

void hybridSort(int *arr, const int size, int &compCount, int &moveCount) {
    int pivot;
    partition(arr, pivot, 0, size - 1, compCount, moveCount);

    hybridSortHelper(arr, 0, pivot - 1, compCount, moveCount);
    hybridSortHelper(arr, pivot + 1, size - 1, compCount, moveCount);
}