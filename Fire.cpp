#include "Fire.hpp"


/**
 * @init method initialises vectors of weaknesses
 * and strengths of @Fire objects
 *
 */
auto Fire::init() -> void {
   Fire::weakAgainst = {"Water","Earth"};
   Fire::strongAgainst = {"Ice","Steel"};
}
/**
 * specialAttack enables player to enhance their Champions stats
 *
 */
void Fire::specialAttack() {



    this->strength +=10;

    this->dexterity +=3;


}
/**
 * undoSpecialAttack are the "foreseen or unforeseen consequence
 * of using special ability
 *
 */
void Fire::undoSpecialAttack()
{
    this->strength -=10;

    this->dexterity -=3;
}