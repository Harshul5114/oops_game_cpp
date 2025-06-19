#include "Classes.h"
#include "../include/WeaponsList.h"
#include <iostream>
using namespace std;

#define BOLD "\033[1m"
#define RESET "\033[0m"

// ----- Warrior -----
Warrior::Warrior(string name) : Champion(name, 120, 20, 40, 4, "Power Slash", &Weapons::rustySword) {}

void Warrior::specialMove(Champion& enemy) {
    if (spCharge < reqCharge) {
        cout << name << " needs to charge their special move!\n";
        return;
    }
    spCharge = 0;
    cout << BOLD << "\n⚔️ " << name << " bellows a war cry and strikes with " << specialMoveName << "! ⚔️\n" << RESET;
    cout << "💢 The earth trembles as the blade tears through the air!\n";
    enemy.takeDamage(getEffectiveSpAttack());
}

// ----- Mage -----
Mage::Mage(string name) : Champion(name, 80, 30, 60, 5, "Fireball", &Weapons::apprenticeStaff) {}

void Mage::specialMove(Champion& enemy) {
    if (spCharge < reqCharge) {
        cout << name << " needs to charge their special move!\n";
        return;
    }
    spCharge = 0;
    cout << BOLD << "\n🔥 " << name << " chants ancient incantations...\n"
         << specialMoveName << " bursts into flames!\n" << RESET;
    cout << "🌪️ A storm of arcane fire engulfs the enemy!\n";
    enemy.takeDamage(getEffectiveSpAttack());
}

// ----- Tank -----
Tank::Tank(string name) : Champion(name, 150, 15, 25, 3, "Shield Bash", &Weapons::woodenShield) {}

void Tank::specialMove(Champion& enemy) {
    if (spCharge < reqCharge) {
        cout << name << " needs to charge their special move!\n";
        return;
    }
    spCharge = 0;
    cout << BOLD << "\n🛡️ " << name << " stomps the ground and lunges forward with " << specialMoveName << "! 💥\n" << RESET;
    cout << "🌩️ A thunderous crash knocks the enemy back!\n";
    enemy.takeDamage(getEffectiveSpAttack());
}
