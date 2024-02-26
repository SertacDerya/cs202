/**
* Author : Sertaç Derya
* ID: 22003208
* Section : 3
* Homework : 3
* Description : creature
*/
#include "Creature.h"

Creature::Creature(int id, double x, double y, int health) {
    this->id = id;
    this->x = x;
    this->y = y;
    this->health = health;
}

int Creature::getHealth() {
    return this->health;
}

void Creature::setHealth(int i) {
    this->health = i;
}

int Creature::getID() {
    return this->id;
}

double Creature::getX() {
    return this->x;
}

double Creature::getY() {
    return this->y;
}

void Creature::setX(double x) {
    this->x = x;
}

void Creature::setY(double y) {
    this->y = y;
}

bool Creature::operator<(const Creature& c) const {
    return this->id < c.id;
}