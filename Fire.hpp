#pragma once
#ifndef FIRE_HPP
#define FIRE_HPP
#include <vector>
#include <string>
#include "Monster.hpp"

struct Fire : Monster {

    static inline  std::vector<std::string> weakAgainst;
    static inline std::vector<std::string>  strongAgainst;
    std::string type;

    Fire(int strength, int dexterity, int health, int exp, const std::string& special, const std::string& name, std::string type)
            : Monster(strength, dexterity, health, exp, special, name, type) { }

    static auto init() -> void;
};
#endif
