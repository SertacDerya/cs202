/**
* Title: Balanced search trees and hashing
* Author : Sertac Derya
* ID: 22003208
* Section : 3
* Homework : 4
* Description : header
*/
#include "Sertac_Derya_22003208_Node.h"
#include "Sertac_Derya_22003208_Snack.h"

template<class ItemType>
Node<ItemType>::Node() {
    //this = nullptr;
    this->next = nullptr;
}
template<class ItemType>
Node<ItemType>::Node(const ItemType& item, Node<ItemType>* nextNodePtr) {
    this->next = nextNodePtr;
    this->item = item;
}
template<class ItemType>
Node<ItemType>::Node(const ItemType& item) {
    this->next = nullptr;
    this->item = item; 
}
template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr) {
    this->next = nextNodePtr;
}
template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anitem) {
    item = anitem;
}

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const {
    return this->next;
}
template<class ItemType>
ItemType Node<ItemType>::getItem() const {
    return this->item;
}

template class Node<Snack*>;
