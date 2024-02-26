/**
* Author : Sertaç Derya
* ID: 22003208
* Section : 3
* Homework : 3
* Description : Header for food with spawn time
*/
#pragma once

class FoodNotPlanted {
    public:
        FoodNotPlanted();
        FoodNotPlanted(int id, double x, double y, int value, int spawnTime);

        int getValue();
        int getSpawnTime();
        int getID();
        double getX();
        double getY();
        int getQuality();
        bool operator<(const FoodNotPlanted& f) const;
        bool operator>(const FoodNotPlanted& f) const;
        bool operator<=(const FoodNotPlanted& f) const;
        bool operator>=(const FoodNotPlanted& f) const;
    private:
        int spawnTime;
        int value;
        double x;
        double y;
        int id;
};
//#include "FoodNotPlanted.cpp"
