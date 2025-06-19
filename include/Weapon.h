#ifndef WEAPON_H
#define WEAPON_H

#include <string>
using namespace std;

class Weapon {
private:
    string name;
    int atkBoost;
    int spBoost;
    float critChance; // Added crit chance

public:
    Weapon(string name, int atkBoost, int spBoost, float critChance); // Updated constructor

    string getName() const;
    int getAtkBoost() const;
    int getSpBoost() const;
    float getCritChance() const; // Getter for crit chance
    bool is_crit() const;
};

#endif
