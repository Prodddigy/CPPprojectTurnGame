#pragma once
#ifndef WATER_H
#define WATER_H
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include "Monster.hpp"

struct Water : Monster {

    static inline std::vector<std::string> weakAgainst;
    static inline  std::vector<std::string> strongAgainst;
    std::string type;

    Water(int strength, int dexterity, int health, int exp, const std::string& special, const std::string& name,std::string type)
    : Monster(strength, dexterity, health, exp, special, name,type){};

    //Methods
    static auto init() -> void;
};
#endif
