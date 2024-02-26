/**
* Title: Balanced search trees and hashing
* Author : Sertac Derya
* ID: 22003208
* Section : 3
* Homework : 4
* Description : header
*/
#include "Sertac_Derya_22003208_Snack.h"

Snack::Snack() {
    this->name = "";
}

Snack::Snack(string name) {
    this->name = name;
}

void Snack::addSnackComb(Snack* S) {
    this->accompanimentList.insert(S, 0);
}

void Snack::removeSnackComb(Snack* S) {
    for(int i = 0; i < this->accompanimentList.getLength(); i++) {
        if(this->accompanimentList.getEntry(i) == S) {
            this->accompanimentList.remove(i);
            return;
        }
    }
}

string Snack::getName() {
    return this->name;
}

int Snack::accListLength() {
    return this->accompanimentList.getLength();
}

Snack* Snack::getFromList(int index) {
    return this->accompanimentList.getEntry(index);
}

void Snack::removeSnackFromList(int index) {
    this->accompanimentList.remove(index);
}
