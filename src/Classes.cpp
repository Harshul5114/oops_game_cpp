#include "Classes.h"
#include <iostream>
using namespace std;

// ----- Warrior -----
Warrior::Warrior(string name) : Champion(name, 120, 20, 40, 4, "Power Slash") {}

void Warrior::specialMove(Champion& enemy) {
    if (spCharge < reqCharge) {
        cout << name << " needs to charge their special move!\n";
        return;
    }
    spCharge = 0; // Reset charge after using special move
    cout << name << " uses " << specialMoveName << "!\n";
    enemy.takeDamage(spAttack);
}

// ----- Mage -----
Mage::Mage(string name) : Champion(name, 80, 30, 60, 5, "Fireball") {}

void Mage::specialMove(Champion& enemy) {
    if (spCharge < reqCharge) {
        cout << name << " needs to charge their special move!\n";
        return;
    }
    spCharge = 0; // Reset charge after using special move
    cout << name << " uses " << specialMoveName << "!\n";
    enemy.takeDamage(spAttack);
}

// ----- Tank -----
Tank::Tank(string name) : Champion(name, 150, 15, 25, 3, "Shield Bash") {}
void Tank::specialMove(Champion& enemy) {
    if (spCharge < reqCharge) {
        cout << name << " needs to charge their special move!\n";
        return;
    }
    spCharge = 0; // Reset charge after using special move
    cout << name << " uses " << specialMoveName << "!\n";
    enemy.takeDamage(spAttack);
}
