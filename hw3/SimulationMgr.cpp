/**
* Author : Sertaç Derya
* ID: 22003208
* Section : 3
* Homework : 3
* Description : imp for sim
*/
#include "SimulationMgr.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>


SimulationMgr::SimulationMgr(const string gameFile) {
    ifstream inputFile;
    string line;
    inputFile.open(gameFile.c_str(), ios_base::in);
    int creatureCnt;
    string c;
    getline(inputFile, line);
    stringstream cnt(line);
    getline(cnt, c);
    creatureCnt = stoi(c);
    this->creatureCount = creatureCnt;
    for(int i = 0; i < creatureCnt; i++) {
        string id;
        string x;
        string y;
        string health;
        int idI;
        double xD;
        double yD;
        int healthI;
        getline(inputFile, line);
        stringstream creatureLine(line);
        getline(creatureLine, id, ',');
        getline(creatureLine, x, ',');
        getline(creatureLine, y, ',');
        getline(creatureLine, health, ',');
        idI = stoi(id);
        xD = stod(x);
        yD = stod(y);
        healthI = stoi(health);
        Creature c(idI, xD, yD, healthI);
        this->creatures.push_back(c);
    }

    while(getline(inputFile, line)) {
        string id;
        string x;
        string y;
        string quality;
        string sTime;
        int idI;
        double xD;
        double yD;
        int qualityI;
        int sTimeI;
        stringstream foodLine(line);
        getline(foodLine, id, ',');
        getline(foodLine, x, ',');
        getline(foodLine, y, ',');
        getline(foodLine, quality, ',');
        getline(foodLine, sTime, ',');

        idI = stoi(id);
        xD = stod(x);
        yD = stod(y);
        qualityI = stoi(quality);
        sTimeI = stoi(sTime);

        FoodNotPlanted food(idI, xD, yD, qualityI, sTimeI);
        this->foodToAdd.heapInsert(food);
    }
    sort(this->creatures.begin(), this->creatures.end());
}

int SimulationMgr::getCreatureCount() {
    return this->creatureCount;
}


bool SimulationMgr::contGame() {
    bool cont = false;
    for(int i = 0; i < this->creatureCount && !cont; i++) {
        if(this->creatures[i].getHealth() > 0) {
            cont = true;
        }
    }
    return cont;
}

bool SimulationMgr::foodsToAddEmpty() {
    return this->foodToAdd.isEmpty();
}

bool SimulationMgr::foodsEmpty() {
    return this->currentFood.isEmpty();
}

FoodNotPlanted SimulationMgr::getFoodToAdd() {
    return this->foodToAdd.getFront();
}

void SimulationMgr::deleteFoodToAdd() {
    this->foodToAdd.heapDelete();
}

void SimulationMgr::deleteCurrentFood() {
    this->currentFood.heapDelete();
}

void SimulationMgr::creatureAttack(int index) {// the creature in the index looks if it can attack anyone
    Creature c = this->creatures[index];
    double attackerX = c.getX();
    double attackerY = c.getY();
    int attackerHealth = c.getHealth();
    double defenderX;
    double defenderY;
    int defenderHealth;
    for(int i = 0; i < this->creatures.size() && attackerHealth != 0; i++) {
        if(index != i) {
            defenderX = this->creatures[i].getX();
            defenderY = this->creatures[i].getY();
            defenderHealth = this->creatures[i].getHealth();
            if(attackerHealth >= defenderHealth && defenderHealth != 0) {
                double distance = pow(attackerX - defenderX, 2) + pow(attackerY - defenderY, 2);
                distance = sqrt(distance);
                if(distance < 2) {
                    this->creatures[i].setHealth(0);
                }
            }
        }
        
    }
}

void SimulationMgr::addFood(Food f) {
    this->currentFood.heapInsert(f);
}

void SimulationMgr::printCreatureLoc(int time) {
    //cout << "Time: " << time << endl;
    for(int i = 0; i < this->creatures.size(); i++) {
        Creature c = this->creatures[i];
        printf("%s%d%s%.2f%s%.2f\n", "Creature ", this->creatures[i].getID(), ": ", this->creatures[i].getX(), ", ", c.getY());
    }
}

void SimulationMgr::consumeFood(int creatureIndex) {
    double creatureX = this->creatures[creatureIndex].getX();
    double creatureY = this->creatures[creatureIndex].getY();
    double foodX = this->currentFood.getFront().getX();
    double foodY = this->currentFood.getFront().getY();

    if(this->creatures[creatureIndex].getHealth() > 0) {
        double distance = pow(creatureX - foodX, 2) + pow(creatureY - foodY, 2);
        distance = sqrt(distance);
        if(distance < 1) {
            this->creatures[creatureIndex].setHealth(this->creatures[creatureIndex].getHealth() + this->currentFood.getFront().getQuality());
            this->currentFood.heapDelete();
        }
    }
}

void SimulationMgr::moveCreature(int creatureIndex) {
    double creatureX = this->creatures[creatureIndex].getX();
    double creatureY = this->creatures[creatureIndex].getY();
    int health = this->creatures[creatureIndex].getHealth();
    double foodX = this->currentFood.getFront().getX();
    double foodY = this->currentFood.getFront().getY();

    if(health > 0) {
        double distance = pow(creatureX - foodX, 2) + pow(creatureY - foodY, 2);
        distance = sqrt(distance);
        if(health <= 10 && distance != 0) {
            creatureX = creatureX + (foodX - creatureX) / distance;
            creatureY = creatureY + (foodY - creatureY) / distance;
        } else if(distance != 0) {
            double dist = 10.0 / health;
            creatureX = creatureX + (foodX - creatureX) / distance * dist;
            creatureY = creatureY + (foodY - creatureY) / distance * dist;
        }
        this->creatures[creatureIndex].setX(creatureX);
        this->creatures[creatureIndex].setY(creatureY);
    }
}

void SimulationMgr::decreaseHealth() {
    for(int i = 0; i < this->creatureCount; i++) {
        int health = this->creatures[i].getHealth();
        if(health > 0) {
            this->creatures[i].setHealth(this->creatures[i].getHealth() - 1);
        }
    }
}

/**
 * @brief 
 * Locations should be printed
 * Foods should be spawned
 * Every creature should check if there is attack opportunity
 * Creatures consume food
 * And then move by 10/h
 * Health should decrease
 */

int main(int argc, char* argv[]) {
    /* string game;
    cin >> game; */
    string arg(argv[1]);
    SimulationMgr mgr(arg);

    int time = 0;
    while(mgr.contGame()) {
        mgr.printCreatureLoc(time); // print creatures
        bool contToAddFood = !mgr.foodsToAddEmpty();
        while(contToAddFood && !mgr.foodsToAddEmpty()) {// plant food
            FoodNotPlanted fN = mgr.getFoodToAdd();
            if(fN.getValue() == time) {
                Food f(fN.getID(), fN.getX(), fN.getY(), fN.getQuality());
                mgr.addFood(f);
                mgr.deleteFoodToAdd();
            } else {
                contToAddFood = false;
            }
        }
        for(int i = 0; i < mgr.getCreatureCount(); i++) {// attack
            mgr.creatureAttack(i);
        }
        for(int i = 0; i < mgr.getCreatureCount() && !mgr.foodsEmpty(); i++) {
            mgr.consumeFood(i);
        }
        for(int i = 0; i < mgr.getCreatureCount() && !mgr.foodsEmpty(); i++) {
            mgr.moveCreature(i);
        }
        mgr.decreaseHealth();
        time++;
    }
    //delete[] argv;
}
