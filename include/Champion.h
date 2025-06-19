#pragma once
#include "../include/Weapon.h"
#include <string>
using namespace std;

class Champion {
protected:
    string name;
    int hp;
    int attack;
    int spAttack; 
    int reqCharge;
    string specialMoveName;
    Weapon* weapon;

    int spCharge;
    bool defending;

public:
    Champion(
    string name,
    int hp, 
    int attack, 
    int spAttack, 
    int reqCharge, 
    string specialMoveName = "Special Move",
    Weapon* weapon = nullptr
    );

    
    void takeDamage(int amount);
    bool isAlive() const;
    void display() const;
    
    void basicAttack(Champion& enemy);
    virtual void specialMove(Champion& enemy) = 0;
    void defend();
    void resetDefend();
    void increaseCharge();

    void equipWeapon(Weapon* w);
    int getEffectiveAttack() const;
    int getEffectiveSpAttack() const;

    int getHP() const;
    string getName() const;
    string getSpecialMoveName() const { return specialMoveName; }
};