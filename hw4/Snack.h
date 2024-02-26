/**
* Title: Balanced search trees and hashing
* Author : Sertac Derya
* ID: 22003208
* Section : 3
* Homework : 4
* Description : header
*/
#pragma once
#include "Sertac_Derya_22003208_LinkedList.h"
#include <string>

using namespace std;

class Snack {
    public:
        Snack();
        Snack(string name);
        void addSnackComb(Snack* S);
        void removeSnackComb(Snack* S);
        string getName();
        int accListLength();
        Snack* getFromList(int index);
        void removeSnackFromList(int index);
    private:
        LinkedList<Snack*> accompanimentList;
        string name;
};
//#include "Snack.cpp"