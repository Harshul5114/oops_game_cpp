#include "Classes.h"
#include "../include/WeaponsList.h"
#include <iostream>
#include <cstdlib>
using namespace std;

#define BOLD "\033[1m"
#define RESET "\033[0m"

// ----- Warrior -----
Warrior::Warrior(string name, float scale) : Champion(name, int(120 * scale), int(20 * scale), int(40 * scale), 4, "Power Slash", &Weapons::rustySword) {}

void Warrior::specialMove(Champion &enemy)
{
    if (spCharge < reqCharge)
    {
        cout << name << " needs to charge their special move!\n";
        return;
    }
    spCharge = 0;
    cout << BOLD << "\n⚔️ " << name << " bellows a war cry and strikes with " << specialMoveName << "! ⚔️\n"
         << RESET;
    cout << "💢 The earth trembles as the blade tears through the air!\n";
    enemy.takeDamage(getEffectiveSpAttack());
}

// ----- Mage -----
Mage::Mage(string name, float scale)
    : Champion(
        name,
        int(80 * scale),     // HP
        int(30 * scale),     // ATK
        int(60 * scale),     // SP ATK
        5,                   // reqCharge
        "Fireball",          // special move name
        &Weapons::apprenticeStaff // starter weapon
    ) {}
void Mage::specialMove(Champion &enemy)
{
    if (spCharge < reqCharge)
    {
        cout << name << " needs to charge their special move!\n";
        return;
    }
    spCharge = 0;
    cout << BOLD << "\n🔥 " << name << " chants ancient incantations...\n"
         << specialMoveName << " bursts into flames!\n"
         << RESET;
    cout << "🌪️ A storm of arcane fire engulfs the enemy!\n";
    int damage = getEffectiveSpAttack();
    enemy.takeDamage(damage);

    // 50% chance for lifesteal
    if (rand() % 2 == 0)
    {   
        cout << "Life Steal!" << endl;
        int healAmount = damage / 2;
        cout << "🩸 " << name << " absorbs life energy and heals for " << healAmount << " HP!\n";
        heal(healAmount);
    }
}

// ----- Tank -----
Tank::Tank(string name, float scale)
    : Champion(
        name,
        int(150 * scale),     // HP
        int(15 * scale),      // ATK
        int(25 * scale),      // SP ATK
        3,
        "Shield Bash",
        &Weapons::woodenShield
    ) {}

void Tank::specialMove(Champion &enemy)
{
    if (spCharge < reqCharge)
    {
        cout << name << " needs to charge their special move!\n";
        return;
    }
    spCharge = 0;
    cout << BOLD << "\n🛡️ " << name << " stomps the ground and lunges forward with " << specialMoveName << "! 💥\n"
         << RESET;
    cout << "🌩️ A thunderous crash knocks the enemy back!\n";
    enemy.takeDamage(getEffectiveSpAttack());
}

void Tank::takeDamage(int dmg)
{
    if (defending)
    {
        cout << name << " blocks with his shield! Damage is greatly reduced.\n";
        dmg /= 5;
    }
    cout << name << " took a hit of " << dmg << " HP!\n";
    hp -= dmg;
    if (hp < 0)
        hp = 0;
}
