#pragma once

#include <iostream>
//#include <utility>
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
    bool evolve;
    Monster(int strength, int dexterity, int health, int exp, const std::string& special, const std::string& name, std::string type,bool evolve);

   void evolveMon();
};


