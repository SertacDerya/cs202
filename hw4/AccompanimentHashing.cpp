/**
* Title: Balanced search trees and hashing
* Author : Sertac Derya
* ID: 22003208
* Section : 3
* Homework : 4
* Description : header
*/
#include "Sertac_Derya_22003208_AccompanimentHashing.h"

AccompanimentHashing::AccompanimentHashing() {
    for(int i = 0; i < TABLE_SIZE_ACC; i++) {
        this->arr[i] = nullptr;
    }
}

AccompanimentHashing::~AccompanimentHashing() {
    for(int i = 0; i < TABLE_SIZE_ACC; i++) {
        delete this->arr[i];
    }
}

void AccompanimentHashing::insertItem(Accompaniment* acc) {
    int hashVal = this->hash(acc->getName());
    bool inserted = false;
    int index = 1;
    while(!inserted) {
        if(index == TABLE_SIZE_ACC) {
            inserted = true;
        }
        if(this->arr[hashVal] == nullptr) {
            this->arr[hashVal] = acc;
            inserted = true;
        }
        hashVal = (hashVal + index * index) % TABLE_SIZE_ACC;
        index++;
    }
}

void AccompanimentHashing::deleteAccompaniment(string accName) {
    int hashVal = this->hash(accName);
    bool found = false;
    int index = 1;
    while(!found) {
        if(index == TABLE_SIZE_ACC) {
            found = true;
        }
        if(this->arr[hashVal] != nullptr) {
            if(this->arr[hashVal]->getName() == accName) {
                this->arr[hashVal]->setFirst(nullptr);
                this->arr[hashVal]->setSecond(nullptr);
                delete this->arr[hashVal];
                this->arr[hashVal] = nullptr;
                found = true;
            }
        }
        hashVal = (hashVal + index * index) % TABLE_SIZE_ACC;
        index++;
    }
}

bool AccompanimentHashing::checkAccompaniment(string firstSnack, string secondSnack) {
    string comb = firstSnack + secondSnack;
    int hashVal = this->hash(comb);
    bool found = false;
    int index = 1;
    while(!found) {
        if(index == TABLE_SIZE_ACC) {
            found = true;
        }
        if(this->arr[hashVal] != nullptr) {
            if(this->arr[hashVal]->getName() == comb) {
                return true;
            } 
        }
        hashVal = (hashVal + index * index) % TABLE_SIZE_ACC;
        index++;
    }
    return false;
}

Accompaniment* AccompanimentHashing::getAccomp(string name) {
    int hashVal = this->hash(name);
    bool found = false;
    int index = 1;
    while(!found) {
        if(index == TABLE_SIZE_ACC) {
            found = true;
        }
        if(this->arr[hashVal] != nullptr) {
            if(this->arr[hashVal]->getName() == name) {
                return this->arr[hashVal];
            } 
        }
        hashVal = (hashVal + index * index) % TABLE_SIZE_ACC;
        index++;
    }
    return nullptr;
}

int AccompanimentHashing::hash(string name) {
    int sum = 0;
    for(int i = 0; i < name.length(); i++) {
        sum = sum + (int)name[i];
    }
    return sum % TABLE_SIZE_ACC;
}