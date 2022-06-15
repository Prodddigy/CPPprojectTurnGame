#include "Ice.hpp"
/**
 * @init method initialises vectors of weaknesses
 * and strengths of @Ice objects
 *
 */
auto Ice::init() -> void {
    Ice::weakAgainst = {"Water","Fire","Ice"};
    Ice::strongAgainst = {"Earth"};
}
/**
 * specialAttack enables player to enhance their Champions stats
 *
 */
void Ice::specialAttack() {



    this->strength +=3;

    this->dexterity +=7;

}
/**
 * undoSpecialAttack are the "foreseen or unforeseen consequence
 * of using special ability
 *
 */
void Ice::undoSpecialAttack()
{
    this->health -=5;

}