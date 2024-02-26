/**
* Author : Sertaç Derya
* ID: 22003208
* Section : 3
* Homework : 3
* Description : Header for max heap
*/
#pragma once
#include "vector"

using namespace std;
template<class ItemType>
class Heap {
    public:
        Heap();
        bool isEmpty() const;
        void heapInsert(const ItemType& item);
        void heapDelete();
        ItemType getFront();
    private:
        void heapRebuild(int root);
        ItemType arr[50];
        int size;
};
//#include "Heap.cpp"
