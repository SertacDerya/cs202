/**
* Title: Balanced search trees and hashing
* Author : Sertac Derya
* ID: 22003208
* Section : 3
* Homework : 4
* Description : header
*/
#pragma once
#include "Sertac_Derya_22003208_SnackHashing.h"
#include "Sertac_Derya_22003208_AccompanimentHashing.h"

class SnackSystem {
    public:
        SnackSystem();
        void S(string SName);
        void C(string firstSName, string secondSName);
        void D(string firstSName, string secondSName);
        void L(string SName);
        bool Q(string firstSName, string secondSName);
    private:
        SnackHashing sHash;
        AccompanimentHashing aHash;
};