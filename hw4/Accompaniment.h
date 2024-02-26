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

class Accompaniment {
    public:
        Accompaniment();
        Accompaniment(string fSnack, string sSnack);
        void setFirst(Snack* S);
        void setSecond(Snack* S);
        Snack* getFirstSnack();
        Snack* getSecondSnack();
        string getName();
    private:
        Snack* firstSnack;
        Snack* secondSnack;
        string name;
};
//#include "Accompaniment.cpp"