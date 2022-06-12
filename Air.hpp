#pragma once
#ifndef AIR_HPP
#define AIR_HPP
#include <iostream>
#include <vector>
#include <string>
#include "Monster.hpp"

struct Air : Monster{
    static inline std::vector<std::string> weakAgainst;
    static inline  std::vector<std::string> strongAgainst;

    std::string type;

    Air(int strength, int dexterity, int health, int exp, const std::string& special, const std::string& name)
            : Monster(strength, dexterity, health, exp, special, name), type("Air") { }

    static auto init() -> void;
};
#endif
