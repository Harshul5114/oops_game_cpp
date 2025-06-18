#pragma once
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

    int spCharge;
    bool defending;

public:
    Champion(string name, int hp, int attack, int spAttack, int reqCharge, string specialMoveName = "Special Move");

    
    void takeDamage(int amount);
    bool isAlive() const;
    void display() const;
    
    void basicAttack(Champion& enemy);
    virtual void specialMove(Champion& enemy) = 0;
    void defend();
    void resetDefend();
    void increaseCharge();



    int getHP() const;
    string getName() const;
    string getSpecialMoveName() const { return specialMoveName; }
};