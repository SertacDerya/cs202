/**
* Title: Balanced search trees and hashing
* Author : Sertac Derya
* ID: 22003208
* Section : 3
* Homework : 4
* Description : header
*/
#include "Sertac_Derya_22003208_SnackHashing.h"

SnackHashing::SnackHashing() {

} // we might need to delete each snack pointer in the linkedlists

SnackHashing::~SnackHashing() {
    for(int i = 0; i < TABLE_SIZE_SNACK; i++) {
        for(int j = 0; j < this->arr[i].getLength(); j++) {
            delete this->arr[i].getEntry(j);
            this->arr[i].setEntry(j, nullptr);
        }
        this->arr[i].clear();
    }
}

void SnackHashing::insertItem(string S) {
    Snack* snack = new Snack(S);
    int hashVal = this->hash(S);
    this->arr[hashVal].insert(snack, 0);
}

Snack* SnackHashing::getItem(string name) {
    int hashVal = this->hash(name);
    Snack* snack = nullptr;
    LinkedList<Snack*> list = this->arr[hashVal];

    for(int i = 0; i < list.getLength(); i++) {
        snack = list.getEntry(i);
        if(snack->getName() == name) {
            return snack;
        }
    }
    return nullptr;
}

int SnackHashing::hash(string name) {
    int sum = 0;
    for(int i = 0; i < name.length(); i++) {
        sum = sum + (int)name[i];
    }
    return sum % TABLE_SIZE_SNACK;
}