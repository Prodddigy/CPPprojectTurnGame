#pragma once
#ifndef MONSTER_H
#define MONSTER_H
#include <iostream>
#include <utility>
#include <vector>
#include <string>

struct Monster {
    int strength {};
    int dexterity {};
    int health {};
    int maxHealth {};
    int exp {};
    std::string special;
    std::string name;
    std::string type;
    static inline std::vector<Monster*> necronomicon;

    Monster(int strength, int dexterity, int health, int exp, const std::string& special, const std::string& name, std::string type);
};

#endif
