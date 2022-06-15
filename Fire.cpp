#include "Fire.hpp"

auto Fire::init() -> void {
   Fire::weakAgainst = {"Water","Earth"};
   Fire::strongAgainst = {"Ice","Steel"};
}

void Fire::specialAttack() {

    //this->specialUsed = true;

    this->strength +=10;

    this->dexterity +=3;


}

void Fire::undoSpecialAttack()
{
    this->strength -=10;

    this->dexterity -=3;
}