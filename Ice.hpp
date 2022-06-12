#pragma once
#ifndef ICE_HPP
#define ICE_HPP
#include <string>
#include <vector>
#include "Monster.hpp"

struct Ice : Monster {

    static inline std::vector<std::string> weakAgainst;
    static inline  std::vector<std::string> strongAgainst;
    std::string type;

    Ice(int strength, int dexterity, int health, int exp, const std::string& special, const std::string& name, std::string type)
            : Monster(strength, dexterity, health, exp, special, name, type) { }

    static auto init() -> void;
};
#endif
