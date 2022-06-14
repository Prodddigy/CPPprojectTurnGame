

#pragma once
#include "Monster.hpp"

struct Opponent{

    std::vector<Monster*> enemyArmy;

    static inline std::vector<Opponent*> allEnemies;
    std::string name;

    Opponent(std::string name);



    void moveMonster(std::vector<Monster*> &monsters );

    void showOpponentArmy();

    bool isEnemyArmyDead();

    static bool isAllEnemiesDead();
};