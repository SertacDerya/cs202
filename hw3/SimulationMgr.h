/**
* Author : Sertaç Derya
* ID: 22003208
* Section : 3
* Homework : 3
* Description : Header for sim class
*/
#pragma once
#include <vector>
#include <string>
#include "Heap.h"
#include "Food.h"
#include "FoodNotPlanted.h"
#include "Creature.h"

using namespace std;

class SimulationMgr {
    public:
        SimulationMgr(const string gameFile);
        bool contGame(); // checks creature health
        FoodNotPlanted getFoodToAdd();
        bool foodsToAddEmpty();
        bool foodsEmpty();
        void deleteFoodToAdd();
        void deleteCurrentFood();
        void creatureAttack(int index);
        void addFood(Food f);
        void printCreatureLoc(int time);
        void consumeFood(int creatureIndex);
        int getCreatureCount();
        void moveCreature(int creatureIndex);
        void decreaseHealth();
    private:
        Heap<Food> currentFood;
        Heap<FoodNotPlanted> foodToAdd;
        vector<Creature> creatures;
        int time;
        int creatureCount;
};
