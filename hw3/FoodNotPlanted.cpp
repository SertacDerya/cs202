/**
* Author : Sertaç Derya
* ID: 22003208
* Section : 3
* Homework : 3
* Description : Food class that has spawn time as comparison
*/
#include "FoodNotPlanted.h"

FoodNotPlanted::FoodNotPlanted() {
    this->id = 0;
    this->x = 0;
    this->y = 0;
    this->value = 0;
    this->spawnTime = -999;
}

FoodNotPlanted::FoodNotPlanted(int id, double x, double y, int value, int spawnTime) {
    this->id = id;
    this->x = x;
    this->y = y;
    this->value = value;
    this->spawnTime = spawnTime;
}

int FoodNotPlanted::getValue() {
    return this->spawnTime;
}

int FoodNotPlanted::getSpawnTime() {
    return this->spawnTime;
}

int FoodNotPlanted::getID() {
    return this->id;
}

double FoodNotPlanted::getX() {
    return this->x;
}

double FoodNotPlanted::getY() {
    return this->y;
}

int FoodNotPlanted::getQuality() {
    return this->value;
}

bool FoodNotPlanted::operator<(const FoodNotPlanted& f) const {
    return this->spawnTime > f.spawnTime;
}

bool FoodNotPlanted::operator>(const FoodNotPlanted& f) const {
    return this->spawnTime < f.spawnTime;
}

bool FoodNotPlanted::operator<=(const FoodNotPlanted& f) const {
    return this->spawnTime >= f.spawnTime;
}

bool FoodNotPlanted::operator>=(const FoodNotPlanted& f) const {
    return this->spawnTime <= f.spawnTime;
}