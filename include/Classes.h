#pragma once
#include "Champion.h"

// All derived class declarations

class Warrior : public Champion {
public:
    Warrior(string name, float scale);
    void specialMove(Champion& enemy) override;
};

class Mage : public Champion {
public:
    Mage(string name, float scale); // ✅ must match definition
    void specialMove(Champion& enemy) override;
};

class Tank : public Champion {
public:
    Tank(string name, float scale);
    void specialMove(Champion& enemy) override;
    void takeDamage(int dmg) override;
};