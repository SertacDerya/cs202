/**
* Title: Balanced search trees and hashing
* Author : Sertac Derya
* ID: 22003208
* Section : 3
* Homework : 4
* Description : header
*/
#pragma once
#include "Sertac_Derya_22003208_Accompaniment.h"

const int TABLE_SIZE_ACC = 71;

class AccompanimentHashing {
    public:
        AccompanimentHashing();
        ~AccompanimentHashing();
        void insertItem(Accompaniment* acc);
        void deleteAccompaniment(string accName);
        bool checkAccompaniment(string firstSnack, string secondSnack);
        Accompaniment* getAccomp(string name);
        int hash(string name);
    private:
        Accompaniment* arr[TABLE_SIZE_ACC]; // direkt linkedlistte tutabilir
};
//#include "AccompanimentHashing.cpp"