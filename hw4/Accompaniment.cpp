/**
* Title: Balanced search trees and hashing
* Author : Sertac Derya
* ID: 22003208
* Section : 3
* Homework : 4
* Description :
*/
#include "Sertac_Derya_22003208_Accompaniment.h"

Accompaniment::Accompaniment() {
    this->firstSnack = nullptr;
    this->secondSnack = nullptr;
    this->name = "";
}

Accompaniment::Accompaniment(string fSnack, string sSnack) {
    this->name = fSnack + sSnack;
    this->firstSnack = nullptr;
    this->secondSnack = nullptr;
}

void Accompaniment::setFirst(Snack* S) {
    this->firstSnack = S;
}

void Accompaniment::setSecond(Snack* S) {
    this->secondSnack = S;
}

string Accompaniment::getName() {
    return this->name;
}

Snack* Accompaniment::getFirstSnack() {
    return this->firstSnack;
}

Snack* Accompaniment::getSecondSnack() {
    return this->secondSnack;
}