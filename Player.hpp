
#pragma once
#include "Monster.hpp"

struct Player {
    std::vector<Monster*> playerArmy;

    int round;
    Player();


    void moveMonster(std::vector<Monster*> &monsters, int beastIndex );

    void chooseMonster();

    void showPlayerArmy();

    bool checkArmyHp();
};