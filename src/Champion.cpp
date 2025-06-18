#include "../include/Champion.h"
#include <iostream>
#include <iomanip>
using namespace std;

Champion::Champion(string name, int hp, int attack, int spAttack, int reqCharge, string specialMoveName):
specialMoveName(specialMoveName),
name(name), hp(hp), attack(attack), spAttack(spAttack),
defending(false), reqCharge(reqCharge), spCharge(0) {}

void Champion::takeDamage(int dmg) {
    if (defending) {
        cout << name << " is defending! Damage is halved.\n";
        dmg /= 2;
    }
    hp -= dmg;
    if (hp < 0) hp = 0;
}

void Champion::defend() {
    cout << name << " is in a defensive stance!\n";
    defending = true;
}

void Champion::resetDefend() {
    defending = false;
}

bool Champion::isAlive() const {
    return hp > 0;
}

void Champion::increaseCharge() {
    if (spCharge < reqCharge) {
        spCharge++;
    }
}

void Champion::display() const {
    const int barWidth = 10;
    int filled = (spCharge * barWidth) / reqCharge;
    string bar = string(filled, '#') + string(barWidth - filled, '-');

    cout << "| 🧍 " << setw(12) << left << name
         << " | ❤️ HP: " << setw(4) << hp
         << " | 🗡️ ATK: " << setw(4) << attack
         << " | ✨ SP: " << setw(6) << spAttack
         << " | 🔋 [" << bar << "] "
         << spCharge << "/" << reqCharge
        //  << " | 🛡️ DEF: " << (defending ? "Yes" : " No")
         << " |\n";
}



void Champion::basicAttack(Champion& enemy){
    cout << name << " attacks " << enemy.getName() << "!\n";
    enemy.takeDamage(attack);
}

// void Champion::specialMove(Champion& enemy) {
//     if (spCharge < reqCharge) {
//         cout << name << " needs to charge their special move!\n";
//         return;
//     }
//     spCharge = 0;
//     cout << name << " uses " << specialMoveName << "!\n";
//     enemy.takeDamage(spAttack);
// }

int Champion::getHP() const{
    return hp;
}

string Champion::getName() const{
    return name;
}
