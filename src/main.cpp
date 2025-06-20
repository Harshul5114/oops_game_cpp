#include "Champion.h"
#include "Classes.h" // where Warrior and Mage are defined
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <limits>
#include "../include/WeaponsList.h"
using namespace std;

Champion *createEnemy()
{
    int r = rand() % 3;
    Champion *enemy = nullptr;
    switch (r)
    {
    case 0:
        cout << "An enemy Warrior appears: Dreadblade!\n";
        enemy = new Warrior("Dreadblade");
        break;
    case 1:
        cout << "An enemy Mage appears: Maltheron!\n";
        enemy = new Mage("Maltheron");
        break;
    case 2:
        cout << "An enemy Tank appears: Gor'Mar!\n";
        enemy = new Tank("Gor'Mar");
        break;
    default:
        cout << "An unknown enemy appears: Nameless Horror!\n";
        enemy = new Warrior("Nameless Horror");
        break;
    }
    return enemy;
}

Champion *setupPlayer();
bool playBattle(Champion *player, int &enemiesDefeated);
bool askReplay();
void showShop(Champion *player, int &coins);

int coins;
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    srand(time(0));

    while (true)
    {
        Champion *player = setupPlayer();
        int enemiesDefeated = 0;
        coins = 0;
        bool stillAlive = true;
        while (stillAlive)
        {
            stillAlive = playBattle(player, enemiesDefeated);
            if (!stillAlive)
                break;

            cout << "\n🎉 You defeated the enemy!\n";
            int reward = 50 + rand() % 51; // Random 50–100 coins
            coins += reward;
            cout << "\n💰 You earned " << reward << " coins! Total: " << coins << "\n";

            showShop(player, coins);

            system("cls");

            cout << "\nGo to next stage? (you gain 40HP)\n1. Yes\n2. No\n> ";
            int cont;
            cin >> cont;
            if (cont != 1)
                break;
            player->heal(40); // Heal
        }

        delete player;

        if (!askReplay())
            break;
    }

    cout << "\n👋 Thanks for playing!\n";
    return 0;
}
Champion *setupPlayer()
{
    system("cls");
    cout << "Enter your name...\n";
    string player_name;
    cin >> player_name;

    cout << "Choose your champion:\n1. Warrior (Balanced)\n2. Mage (50% chance of lifesteal when using special)\n3. Tank (greatly reduces damage on successful defend)\n-> ";
    int choice;
    cin >> choice;
    system("cls");

    switch (choice)
    {
    case 1:
        return new Warrior(player_name);
    case 2:
        return new Mage(player_name);
    case 3:
        return new Tank(player_name);
    default:
        cout << "Invalid choice! Defaulting to Warrior.\n";
        return new Warrior(player_name);
    }
}
bool playBattle(Champion *player, int &enemiesDefeated)
{
    system("cls");
    cout << "\n💥 Battle Start! 💥\n";
    Champion *enemy = createEnemy();

    while (player->isAlive() && enemy->isAlive())
    {
        cout << "\n🏆 Enemies Defeated: " << enemiesDefeated << "\n";
        cout << "\n-- Your Turn --\n";
        player->display();
        enemy->display();

        int playerMove;
        while (true)
        {
            cout << "\nChoose action:\n1. Basic Attack\n2. Special Move(" << player->getSpecialMoveName() << ") \n3. Defend\n> ";
            cin >> playerMove;
            if (cin.fail() || playerMove < 1 || playerMove > 3)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter 1, 2, or 3.\n";
            }
            else
            {
                break;
            }
        }

        int enemyMove = rand() % 3 + 1;
        system("cls");

        if (playerMove == 3)
            player->defend();
        if (enemyMove == 3)
            enemy->defend();

        if (playerMove == 1)
            player->basicAttack(*enemy);
        else if (playerMove == 2)
            player->specialMove(*enemy);

        if (!enemy->isAlive())
            break;

        cout << "\n-- Enemy Turn --\n";
        if (enemyMove == 1)
            enemy->basicAttack(*player);
        else if (enemyMove == 2)
        {
            cout << enemy->getName() << " is using their special move!\n";
            enemy->specialMove(*player);
        }
        else
        {
            cout << enemy->getName() << " was defending!\n";
        }

        player->resetDefend();
        enemy->resetDefend();

        player->increaseCharge();
        enemy->increaseCharge();
    }

    bool alive = player->isAlive();
    if (!alive)
    {
        cout << "\n💀 You were defeated after beating " << enemiesDefeated << " enemies.\n";
    }
    else
    {
        enemiesDefeated++;
    }

    delete enemy;
    return alive;
}
bool askReplay()
{
    cout << "\n🔁 Do you want to play again?\n1. Yes\n2. No\n> ";
    int replay;
    cin >> replay;
    return replay == 1;
}

void upgradeWeaponAtk(Weapon *weapon, int &coins)
{
    int cost = 75;
    if (coins < cost)
    {
        cout << "❌ Not enough coins to upgrade.\n";
        return;
    }

    coins -= cost;
    weapon->boostatk(2); // Example: +2 ATK, +1 SP
    cout << "✅ Weapon upgraded! 🔼 +" << 2 << " ATK, +" << 1 << " SP\n";
}
void upgradeWeaponSp(Weapon *weapon, int &coins)
{
    int cost = 90;
    if (coins < cost)
    {
        cout << "❌ Not enough coins to upgrade.\n";
        return;
    }

    coins -= cost;
    weapon->boostsp(1); // Example: +2 ATK, +1 SP
    cout << "✅ Weapon upgraded! 🔼 +" << 2 << " ATK, +" << 1 << " SP\n";
}

void showShop(Champion *player, int &coins)
{
    Weapon *currentWeapon = player->getWeapon();
    int choice;
    while (true)
    {
        cout << "\n🏪 Welcome to the Weapon Shop!\n";
        cout << "You have 💰 " << coins << " coins.\n";
        cout << "Current Weapon: " << currentWeapon->getName()
             << " (+ATK: " << currentWeapon->getAtkBoost()
             << ", +SP: " << currentWeapon->getSpBoost()
             << ", Crit: " << int(currentWeapon->getCritChance() * 100) << "%)\n";

        cout << "\nOptions:\n";
        cout << "1. Upgrade current weapon's ATK (+2) – 75 coins\n";
        cout << "2. Upgrade current weapon's SP (+4) – 90 coins\n";
        cout << "3. Buy 'Rage Blade' (10 ATK, 4 SP, 25% crit) – 150 coins\n";
        cout << "4. Leave Shop\n> ";

        if (!(cin >> choice))
        {
            cout << "❌ Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            Sleep(1500);
            system("cls");
            continue;
        }

        switch (choice)
        {
        case 1:
            if (coins < 75)
            {
                cout << "❌ Not enough coins to upgrade ATK.\n";
            }
            else
            {
                coins -= 75;
                currentWeapon->boostatk(2);
                cout << "✅ Weapon upgraded! 🔼 +2 ATK\n";
                Sleep(2000);
                return; // Exit shop
            }
            break;

        case 2:
            if (coins < 90)
            {
                cout << "❌ Not enough coins to upgrade SP.\n";
            }
            else
            {
                coins -= 90;
                currentWeapon->boostsp(4);
                cout << "✅ Weapon upgraded! ✨ +4 SP\n";
                Sleep(2000);
                return; // Exit shop
            }
            break;

        case 3:
            if (coins < 150)
            {
                cout << "❌ Not enough coins for Rage Blade.\n";
            }
            else
            {
                coins -= 150;
                Weapon *newWep = &Weapons::rageblade;
                player->equipWeapon(newWep);
                cout << "🗡️ You now wield the legendary Rage Blade!\n";
                Sleep(2000);
                return; // Exit shop
            }
            break;

        case 4:
            cout << "Leaving shop...\n";
            Sleep(1500);
            return; // Exit shop

        default:
            cout << "Invalid choice.\n";
            break;
        }

        Sleep(1500);
        system("cls"); // Small pause before re-showing shop
    }
}