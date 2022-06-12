#pragma once
#ifndef EARTH_HPP
#define EARTH_HPP
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include "Monster.hpp"

struct Earth : Monster{
    static inline  std::vector<std::string> weakAgainst;
        static inline std::vector<std::string>  strongAgainst;

    std::string type;

     Earth(int strength, int dexterity, int health, int exp, const std::string& special, const std::string& name)
                    : Monster(strength, dexterity, health, exp, special, name), type("Earth") { };

    static auto init() -> void;
};
#endif
