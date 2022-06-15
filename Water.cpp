#include <string>
#include "Water.hpp"
#include "Monster.hpp"

auto Water::init() -> void {
    Water::weakAgainst = {"Water"};
    Water::strongAgainst = {"Earth","Fire"};
}

void Water::specialAttack() {

    //this->specialUsed = true;

    this->strength +=5;

    this->health +=15;

}

void Water::undoSpecialAttack()
{
    this->dexterity -=2;



}