#include "BattleSystem.h"
#include <iostream>
using namespace std;

// Battle system implementation
void battle(Player &player) {
    Enemy enemy("Goblin", 50, 10); // Create an enemy instance
    cout << "A wild " << enemy.name << " appears!" << endl;
    enemy.showStats();

    while (player.hp > 0 && enemy.hp > 0) {
        cout << "Choose an action: 1. Attack 2. Defend" << endl;
        int choice;
        cin >> choice;

        if (choice == 1) {
            // Player attacks
            enemy.hp -= player.attack;
            cout << "You attacked the enemy! Enemy HP is now: " << enemy.hp << endl;

            if (enemy.hp <= 0) {
                cout << "You defeated the " << enemy.name << "!" << endl;
                player.coins += 10; // Reward coins
                cout << "You earned 10 coins! Current coins: " << player.coins << endl;
                return;
            }
        }

        // Enemy counterattacks
        player.hp -= enemy.attack;
        cout << "The enemy attacked you! Your HP is now: " << player.hp << endl;

        if (player.hp <= 0) {
            cout << "You were defeated! Game Over." << endl;
            exit(0); // End the game
        }
    }
}

