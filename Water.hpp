#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include "Monster.hpp"

struct Water : Monster {

    static inline std::vector<std::string> weakAgainst;
    static inline  std::vector<std::string> strongAgainst;
    std::string type;

    Water(int strength, int dexterity, int health, int exp, const std::string& special, const std::string& name,std::string type,bool evolve)
    : Monster(strength, dexterity, health, exp, special, name,type,evolve){};

    //Methods
    static auto init() -> void;

    void specialAttack() override;

    void undoSpecialAttack() override;
};

