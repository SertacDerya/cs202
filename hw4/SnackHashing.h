/**
* Title: Balanced search trees and hashing
* Author : Sertac Derya
* ID: 22003208
* Section : 3
* Homework : 4
* Description : header
*/
#pragma once
#include "Sertac_Derya_22003208_Snack.h"
#include "Sertac_Derya_22003208_LinkedList.h"

const int TABLE_SIZE_SNACK = 11;
class SnackHashing {
    public:
        SnackHashing(); // we might need to delete each snack pointer in the linkedlists
        ~SnackHashing();
        void insertItem(string S);
        Snack* getItem(string name); // can use this to implement C
        int hash(string name);
    private:
        LinkedList<Snack*> arr[TABLE_SIZE_SNACK]; // direkt linkedlistte tutabilir
};
//#include "SnackHashing.cpp"