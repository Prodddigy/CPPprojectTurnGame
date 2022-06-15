#include "Earth.hpp"
/**
 * @init method initialises vectors of weaknesses
 * and strengths of @Earth objects
 *
 */
auto Earth::init() -> void {
    Earth::weakAgainst = {"Air"};
    Earth::strongAgainst =  {"Fire","Ice","Steel"};
}
/**
 * specialAttack enables player to enhance their Champions stats
 *
 */
void Earth::specialAttack() {



    this->strength +=4;

    this->health +=7;

}
/**
 * undoSpecialAttack are the "foreseen or unforeseen consequence
 * of using special ability
 *
 */
void Earth::undoSpecialAttack()
{
    this->dexterity -=4;



}