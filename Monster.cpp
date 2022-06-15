#include <iostream>
#include "Monster.hpp"

Monster::Monster(int strength, int dexterity, int health, int exp, const std::string &special, const std::string &name, std::string type,bool evolve)
:strength(strength),dexterity(dexterity),health(health),maxHealth(health),exp(exp),special(special),name(name), type(type),evolve(evolve){
    necronomicon.push_back(this);}

void Monster::evolveMon() {

    if(this->exp==10 && !evolve)
    {
        this->health += 10;
        this->maxHealth += 10;
        this->strength +=10;
        this->dexterity +=10;
        this->evolve= true;
        std::cout<<"************************************************"<<'\n';
        std::cout<<"*Your creature "<< this->name<<" Has evolved!!!!!*"<<'\n';
        std::cout<<"************************************************"<<'\n';

    }

}
