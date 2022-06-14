#ifndef DAMIAN_STEEL_HPP
#define DAMIAN_STEEL_HPP
#pragma once
#include <vector>
#include <string>
#include "Monster.hpp"

struct Steel : Monster {

    static inline std::vector<std::string> weakAgainst;
    static inline std::vector<std::string>  strongAgainst;
    std::string type;

    Steel(int strength, int dexterity, int health, int exp, const std::string& special, const std::string& name, std::string type)
            : Monster(strength, dexterity, health, exp, special, name, type) { }

    static auto init() -> void;
};
#endif
