#include "Air.hpp"

auto Air::init() -> void {
    Air::weakAgainst = {"Earth","Steel"};
    Air::strongAgainst = {"Ice"};

}


void Air::specialAttack() {

    //this->specialUsed = true;

    this->health +=20;

    this->strength +=2;

}

void Air::undoSpecialAttack()
{
    this->strength -=3;



}