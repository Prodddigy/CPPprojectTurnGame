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
    bool specialUsed{false};
    bool specialUnUsed{false};
    int specialRoundsLeft{2};
    Monster(int strength, int dexterity, int health, int exp, const std::string& special, const std::string& name, const std::string &type,bool evolve);

     void evolveMon();

   virtual void specialAttack();

    virtual void undoSpecialAttack();
};


