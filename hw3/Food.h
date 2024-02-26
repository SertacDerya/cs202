/**
* Author : Sertaç Derya
* ID: 22003208
* Section : 3
* Homework : 3
* Description : Header for food
*/
#pragma once

class Food {
    public:
        Food();
        Food(int id, double x, double y, int value);
        int getValue();
        double getX();
        double getY();
        int getQuality();
        bool operator<(const Food& f) const;
        bool operator>(const Food& f) const;
        bool operator<=(const Food& f) const;
        bool operator>=(const Food& f) const;
    private:
        int value;
        double x;
        double y;
        int id;
};
//#include "Food.cpp"
