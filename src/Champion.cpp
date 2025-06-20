#include "../include/Champion.h"
#include <iostream>
#include <iomanip>
using namespace std;

Champion::Champion(
    string name, 
    int maxhp, 
    int attack, 
    int spAttack, 
    int reqCharge, 
    string specialMoveName,
    Weapon* weapon
):
specialMoveName(specialMoveName),
name(name), hp(maxhp),maxhp(maxhp), attack(attack), spAttack(spAttack),
defending(false), reqCharge(reqCharge), spCharge(0), weapon(weapon) {}

void Champion::takeDamage(int dmg) {
    if (defending) {
        cout << name << " is defending! Damage is reduced.\n";
        dmg = static_cast<int>(dmg * 0.4) + 1; // rounds to nearest int
    }
    cout << name << " took a hit of " << dmg << " HP!\n";
    hp -= dmg;
    if (hp < 0) hp = 0;
}

void Champion::heal(int amount){
    int healed = min(maxhp - hp, amount);
    cout << "✨ " <<  name << " gained " << healed << "hp!";
    hp = min(maxhp, hp + amount);
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
    int filled = (hp * barWidth) / maxhp;
    string bar = string(filled, '#') + string(barWidth - filled, '-');

    cout << "| 🧍 " << setw(12) << left << name
         << " | ❤️ HP: [" << bar << "]" << hp
         << " | Weapon: " << (weapon ? weapon->getName() : "None")
         << " | 🗡️ ATK: " << setw(4) << getEffectiveAttack()
         << " | ✨ SP: " << setw(6) << getEffectiveSpAttack()
         << " | 🔋 CHRG:"
         << spCharge << "/" << reqCharge
        //  << " | 🛡️ DEF: " << (defending ? "Yes" : " No")
         << " |\n";
}



void Champion::basicAttack(Champion& enemy){
    cout << name << " attacks " << enemy.getName() << "!\n";
    int effattack = getEffectiveAttack();
    if (weapon->is_crit()){
        cout << "🩸 CRITICAL HIT! double damageee.." << endl;
        effattack *= 2;
    }
    enemy.takeDamage(effattack);
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

void Champion::equipWeapon(Weapon* w) {
    weapon = w;
}

int Champion::getEffectiveAttack() const {
    int effattack = attack + (weapon ? weapon->getAtkBoost() : 0);
    return effattack;
}

int Champion::getEffectiveSpAttack() const {
    return spAttack + (weapon ? weapon->getSpBoost() : 0);
}