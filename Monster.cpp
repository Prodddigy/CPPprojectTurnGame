#include <iostream>
#include "Monster.hpp"


/**
 *Monster class creates object of monsters or champions
 * @param strength
 * @param dexterity
 * @param health
 * @param exp
 * @param special
 * @param name
 * @param type
 * @param evolve
 *
 */
Monster::Monster(int strength, int dexterity, int health, int exp, const std::string &special, const std::string &name, const std::string &type,bool evolve)
:strength(strength),dexterity(dexterity),health(health),maxHealth(health),exp(exp),special(special),name(name), type(type),evolve(evolve){
    necronomicon.push_back(this);}


    /**
     * evolveMon amplifies Monsters fields
     * additonally sets evolve to 'true'
     * @param void
     * @return void
     *
     */
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

/**
 * these methods are meant to be overridden in structs which inherit from Monster struct
 */
 void Monster::undoSpecialAttack() {

}
/**
 * these methods are meant to be overridden in structs which inherit from Monster struct
 */
void Monster::specialAttack() {

}

