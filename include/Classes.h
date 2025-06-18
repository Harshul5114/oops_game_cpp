#pragma once
#include "Champion.h"

// All derived class declarations

class Warrior : public Champion {
public:
    Warrior(string name);
    void specialMove(Champion& enemy) override;
};

class Mage : public Champion {
public:
    Mage(string name);
    void specialMove(Champion& enemy) override;
};

class Tank : public Champion {
public:
    Tank(string name);
    void specialMove(Champion& enemy) override;
};