/**
* Author : Sertaç Derya
* ID: 22003208
* Section : 3
* Homework : 3
* Description : food
*/
#include "Food.h"

Food::Food() {
    this->id = 0;
    this->x = 0;
    this->y = 0;
    this->value = 0;
}

Food::Food(int id, double x, double y, int value) {
    this->id = id;
    this->x = x;
    this->y = y;
    this->value = value;
}

int Food::getValue() {
    return this->value - this->id;
}

double Food::getX() {
    return this->x;
}

double Food::getY() {
    return this->y;
}

int Food::getQuality() {
    return this->value;
}

bool Food::operator<(const Food& f) const {
    if(this->value == f.value) {
        return this->id > f.id;
    } else {
        return this->value < f.value;
    }
}

bool Food::operator>(const Food& f) const {
    if(this->value == f.value) {
        return this->id < f.id;
    } else {
        return this->value > f.value;
    }
}

bool Food::operator<=(const Food& f) const {
    if(this->value == f.value) {
        return this->id >= f.id;
    } else {
        return this->value <= f.value;
    }
}

bool Food::operator>=(const Food& f) const {
    if(this->value == f.value) {
        return this->id <= f.id;
    } else {
        return this->value >= f.value;
    }
}