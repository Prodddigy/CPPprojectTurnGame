#pragma once

#include <string>
#include <vector>
#include "Monster.hpp"

struct Ice : Monster {

    static inline std::vector<std::string> weakAgainst;
    static inline  std::vector<std::string> strongAgainst;
    std::string type;

    Ice(int strength, int dexterity, int health, int exp, const std::string& special, const std::string& name, std::string type,bool evolve)
            : Monster(strength, dexterity, health, exp, special, name, type,evolve) { }

    static auto init() -> void;
};

