/**
* Author : Sertaç Derya
* ID: 22003208
* Section : 3
* Homework : 3
* Description : Header for creature
*/
#pragma once

class Creature {
    public:
        Creature(int id, double x, double y, int health);
        
        int getHealth();
        void setHealth(int i);
        void move();
        int getID();
        double getX();
        double getY();
        void setX(double x);
        void setY(double y);
        bool operator<(const Creature& c) const;
    private:
        int id;
        int health;
        double x;
        double y;
};
//#include "Creature.cpp"
