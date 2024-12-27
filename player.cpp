//player.cpp
#include <iostream>
#include "player.h"

void displayPlayerInfo(const Player& player) {
    std::cout << "Player Info:" << std::endl;
    std::cout << "Role: " << player.role << std::endl;
    std::cout << "Level: " << player.level << std::endl;
    std::cout << "HP: " << player.hp << std::endl;
    std::cout << "MP: " << player.mp << std::endl;
    std::cout << "Attack: " << player.attack << std::endl;
    std::cout << "Defense: " << player.defense << std::endl;
    std::cout << "Coins: " << player.coins << std::endl;

    std::cout << "Equipped Items:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << "Slot " << (i + 1) << ": " << player.equippedItems[i].name << " - " << player.equippedItems[i].description << std::endl;
        std::cout << "  Attack Bonus: " << player.equippedItems[i].attackBonus << std::endl;
        std::cout << "  Defense Bonus: " << player.equippedItems[i].defenseBonus << std::endl;
    }
}
