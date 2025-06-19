#ifndef WEAPONSLIST_H
#define WEAPONSLIST_H

#include "Weapon.h"
#include <vector>

// Create global or static weapons
namespace Weapons {
    // starter weapons
    static Weapon rustySword("Rusty Sword", 5, 3, 0.10f);              // 10% crit chance
    static Weapon apprenticeStaff("Apprentice Staff", 2, 8, 0.15f);    // 15% crit chance
    static Weapon woodenShield("Wooden Shield", 7, 1, 0.05f);          // 5% crit chance

    static Weapon infernoWand("Inferno Wand", 0, 15, 0.20f);           // 20% crit chance
    static Weapon rageblade("Rageblade", 10, 5, 0.25f);                // 25% crit chance
    static Weapon healingCrystal("Healing Crystal", 2, 5, 0.08f);      // 8% crit chance

    static std::vector<Weapon*> weaponPool = {
        &rustySword,
        &infernoWand,
        &rageblade,
        &healingCrystal
    };
}

#endif
