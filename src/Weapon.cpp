#include "Weapon.h"
#include <iostream>

Weapon::Weapon(string name, int atkBoost, int spBoost, float critChance)
    : name(name), atkBoost(atkBoost), spBoost(spBoost), critChance(critChance) {}

string Weapon::getName() const {
    return name;
}

int Weapon::getAtkBoost() const {
    return atkBoost;
}

int Weapon::getSpBoost() const {
    return spBoost;
}

float Weapon::getCritChance() const {
    return critChance;
}
bool Weapon::is_crit() const {
    float roll = static_cast<float>(rand()) / RAND_MAX;
    if (roll < critChance) {
        return true;
    }

    return false;
}

void Weapon::boostatk(int atk) {
    atkBoost += atk;
}

void Weapon::boostsp(int sp) {
    spBoost += sp;
}