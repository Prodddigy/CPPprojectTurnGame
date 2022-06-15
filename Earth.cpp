#include "Earth.hpp"

auto Earth::init() -> void {
    Earth::weakAgainst = {"Air"};
    Earth::strongAgainst =  {"Fire","Ice","Steel"};
}

void Earth::specialAttack() {



    this->strength +=4;

    this->health +=7;

}

void Earth::undoSpecialAttack()
{
    this->dexterity -=4;



}