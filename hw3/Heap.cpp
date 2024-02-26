/**
* Author : Sertaç Derya
* ID: 22003208
* Section : 3
* Homework : 3
* Description : Header for max heap
*/
#include "Heap.h"
#include "Food.h"
#include "FoodNotPlanted.h"

template<class ItemType>
Heap<ItemType>::Heap() {
    this->size = 0;
}

template<class ItemType>
bool Heap<ItemType>::isEmpty() const {
    return size == 0;
}

template<class ItemType>
void Heap<ItemType>::heapInsert(const ItemType& item) {
    this->arr[size] = item;//
    int place = size;
    int parent = (place - 1) / 2;

    while(place > 0 && (this->arr[place] > this->arr[parent])) {
        ItemType temp = this->arr[parent];
        this->arr[parent] = this->arr[place];
        this->arr[place] = temp;

        place = parent;
        parent = (place - 1) / 2;
    }
    size++;
}

template<class ItemType>
void Heap<ItemType>::heapDelete() {
    if(size > 0) {
        //item = this->list[0];
        this->arr[0] = this->arr[--size];
        this->heapRebuild(0);
    }
}

template<class ItemType>
ItemType Heap<ItemType>::getFront() {
    return this->arr[0];
}

template<class ItemType>
void Heap<ItemType>::heapRebuild(int root) {
    int child = 2 * root + 1;
    if(child < size) {
        int rightChild = child + 1;
        if((rightChild < size) && this->arr[rightChild] > this->arr[child]) {
            child = rightChild;
        }

        if(this->arr[root] < this->arr[child]) {
            ItemType temp = this->arr[root];
            this->arr[root] = this->arr[child];
            this->arr[child] = temp;
            
            this->heapRebuild(child);
        }
    }
}

template class Heap<Food>;
template class Heap<FoodNotPlanted>;
