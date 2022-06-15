#include "Steel.hpp"

auto Steel::init() -> void {
    Steel::weakAgainst = {"Fire","Steel"};
    Steel::strongAgainst = {"Water","Air"};

}

void Steel::specialAttack() {



    this->strength +=10;

    this->health +=5;

}

void Steel::undoSpecialAttack()
{
    this->strength -=10;



}


