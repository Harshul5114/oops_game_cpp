#include "Champion.h"
#include "Classes.h" // where Warrior and Mage are defined
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

Champion* createEnemy() {
    int r = rand() % 3;
    Champion* enemy = nullptr;
    switch (r) {
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

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    srand(time(0));

    while (true)
    {
        Champion *player = setupPlayer();
        int enemiesDefeated = 0;

        bool stillAlive = true;
        while (stillAlive)
        {
            stillAlive = playBattle(player, enemiesDefeated);
            if (!stillAlive)
                break;

            cout << "\n🎉 You defeated the enemy!\n";
            cout << "\nGo to next stage? (you gain 40HP)\n1. Yes\n2. No\n> ";
            int cont;
            cin >> cont;
            if (cont != 1)
                break;
            player->takeDamage(-40); // Heal
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

    cout << "Choose your champion:\n1. Warrior\n2. Mage\n3. Tank\n-> ";
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

        int playerMove, enemyMove;
        cout << "\nChoose action:\n1. Basic Attack\n2. Special Move(" << player->getSpecialMoveName() << ") \n3. Defend\n> ";
        cin >> playerMove;

        enemyMove = rand() % 3 + 1;
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


