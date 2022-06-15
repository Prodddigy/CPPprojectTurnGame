#include "Steel.hpp"
/**
 * @init method initialises vectors of weaknesses
 * and strengths of @Steel objects
 *
 */
auto Steel::init() -> void {
    Steel::weakAgainst = {"Fire","Steel"};
    Steel::strongAgainst = {"Water","Air"};

}

/**
 * specialAttack enables player to enhance their Champions stats
 *
 */
void Steel::specialAttack() {



    this->strength +=10;

    this->health +=5;

}
/**
 * undoSpecialAttack are the "foreseen or unforeseen consequence
 * of using special ability
 *
 */
void Steel::undoSpecialAttack()
{
    this->strength -=10;



}


