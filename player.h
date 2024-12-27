#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

// 道具结构体
struct Item {
    std::string name;
    std::string description;
    int attackBonus;
    int defenseBonus;
};

// 玩家结构体
struct Player {
    std::string role;
    int level;
    int hp;
    int mp;
    int attack;
    int defense;
    int coins;
    std::vector<Item> inventory;         // 玩家背包
    Item equippedItems[3] = {            // 初始裝備默認為 "None"
        {"None", "No item equipped", 0, 0},
        {"None", "No item equipped", 0, 0},
        {"None", "No item equipped", 0, 0}
    };
};

// 显示玩家信息
void displayPlayerInfo(const Player& player);

#endif
