#include "Ice.hpp"

auto Ice::init() -> void {
    Ice::weakAgainst = {"Water","Fire","Ice"};
    Ice::strongAgainst = {"Earth"};
}

void Ice::specialAttack() {



    this->strength +=3;

    this->dexterity +=7;

}

void Ice::undoSpecialAttack()
{
    this->health -=5;

}