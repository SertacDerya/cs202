/**
* Title: Balanced search trees and hashing
* Author : Sertac Derya
* ID: 22003208
* Section : 3
* Homework : 4
* Description : header
*/
#pragma once
#include "Sertac_Derya_22003208_Node.h"

template <class ItemType>
class LinkedList
{
private:
    Node<ItemType> *headPtr = nullptr;
    int itemCount = 0;
    Node<ItemType> *getNodeAt(int position) const;

public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList<ItemType> &list);
    int getLength() const;
    bool isEmpty() const;
    bool remove(int position);
    bool insert(const ItemType &entry, int position);
    void clear();
    ItemType getEntry(int position) const;
    void setEntry(int position, const ItemType &newEntry);
    LinkedList<ItemType> &operator=(const LinkedList<ItemType> &aList);
};
//#include "LinkedList.cpp"