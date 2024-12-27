#include <iostream>
#include "player.h"
#include "shop.h"
#include "save_load.h"

using namespace std;

void initializePlayer(Player& player, int roleChoice) {
    player.role = roleChoice == 1 ? "Warrior" : "Mage";
    player.level = 1;
    player.hp = roleChoice == 1 ? 100 : 70;
    player.mp = roleChoice == 1 ? 30 : 50;
    player.attack = roleChoice == 1 ? 15 : 10;
    player.defense = roleChoice == 1 ? 10 : 5;
    player.coins = 20;
    player.inventory.clear();
    for (int i = 0; i < 3; ++i) {
        player.equippedItems[i] = { "None", "No item equipped", 0, 0 };
    }
}

int main() {
    srand(time(NULL)); // 初始化随机数生成器
    Player player;
    vector<Item> shopItems = createShopItems();

    cout << "Welcome to the RPG game!" << endl;
    cout << "1. Load Game\n2. Create New Character\n";
    int startOption;
    cin >> startOption;

    if (startOption == 1) {
        loadGame(player);
        if (player.role.empty()) {
            cout << "No save file found. Creating a new character..." << endl;
            cout << "Please choose a role: 1. Warrior 2. Mage\n";
            int choice;
            cin >> choice;
            initializePlayer(player, choice);
        }
    }
    else if (startOption == 2) {
        cout << "Please choose a role: 1. Warrior 2. Mage\n";
        int choice;
        cin >> choice;
        initializePlayer(player, choice);
    }
    else {
        cerr << "Invalid choice! Creating a new character..." << endl;
        cout << "Please choose a role: 1. Warrior 2. Mage\n";
        int choice;
        cin >> choice;
        initializePlayer(player, choice);
    }

    while (true) {
        cout << "\n--- Main Menu ---" << endl;
        cout << "1. Save Game\n2. Load Game\n3. Display Player Info\n4. Go to Shop\n5. View Inventory\n6. Equip Item\n7. Exit\n";
        int option;
        cin >> option;

        switch (option) {
        case 1:
            saveGame(player);
            break;
        case 2:
            loadGame(player);
            break;
        case 3:
            displayPlayerInfo(player);
            break;
        case 4:
            purchaseItem(player, shopItems);
            break;
        case 5:
            displayInventory(player);
            break;
        case 6:
            equipItemFromInventory(player);
            break;
        case 7:
            cout << "Goodbye!" << endl;
            return 0;
        default:
            cerr << "Invalid option! Please try again." << endl;
        }
    }
}
