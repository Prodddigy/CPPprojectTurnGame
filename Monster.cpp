#include <iostream>
#include "Monster.hpp"

Monster::Monster(int strength, int dexterity, int health, int exp, const std::string &special, const std::string &name)
:strength(strength),dexterity(dexterity),health(health),maxHealth(health),exp(exp),special(special),name(name){
    necronomicon.push_back(this);
}
