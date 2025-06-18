#include "Champion.h"
#include "Classes.h" // where Warrior and Mage are defined
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

Champion *createEnemy()
{
    int r = rand() % 3;
    if (r == 0)
        return new Warrior("Enemy Warrior");
    else if (r == 1)
        return new Mage("Enemy Mage");
    else
        return new Tank("Enemy Tank");
}

int main()
{
    SetConsoleOutputCP(CP_UTF8); // Set console to UTF-8 for proper character display
    system("cls"); // Clear console screen
    srand(time(0)); // seed random

    cout << "Enter you name..." << endl;
    string player_name;
    cin >> player_name;

    cout << "Choose your champion:\n1. Warrior\n2. Mage\n3. Tank\n-> ";
    int choice;
    cin >> choice;

    Champion *player;
    switch (choice)
    {
    case 1:
        player = new Warrior(player_name);
        break;
    case 2:
        player = new Mage(player_name);
        break;
    case 3:
        player = new Tank(player_name);
        break;
    default:
        cout << "Invalid choice! Defaulting to Warrior.\n";
        player = new Warrior(player_name);
        break;
    }

    Champion *enemy = createEnemy();
    system("cls");
    cout << "\n💥 Battle Start! 💥\n";

    while (player->isAlive() && enemy->isAlive())
    {
        cout << "\n-- Your Turn --\n";
        player->display();
        enemy->display();

        int playerMove, enemyMove;

        cout << "\nChoose action:\n1. Basic Attack\n2. Special Move\n3. Defend\n> ";
        cin >> playerMove;

        enemyMove = (rand() % 3) + 1;

        system("cls");

        // Apply Defend state immediately
        if (playerMove == 3)
            player->defend();
        if (enemyMove == 3)
            enemy->defend();

        // Player attacks (if not defending)
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
            enemy->specialMove(*player);
        else if (enemyMove == 3)
            cout << enemy->getName() << " was defending!\n";

        if (!player->isAlive())
            break;

        // Reset defense for next round
        player->resetDefend();
        enemy->resetDefend();

        // Charge special moves
        player->increaseCharge();
        enemy->increaseCharge();
    }

    if (player->isAlive())
        cout << "\n🎉 You Win!\n";
    else
        cout << "\n💀 You Lose...\n";

    delete player;
    delete enemy;
    return 0;
}
