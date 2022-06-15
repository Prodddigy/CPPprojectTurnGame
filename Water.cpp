
#include "Water.hpp"

/**
 * @init method initialises vectors of weaknesses
 * and strengths of @Water objects
 *
 */
auto Water::init() -> void {
    Water::weakAgainst = {"Water"};
    Water::strongAgainst = {"Earth","Fire"};
}
/**
 * specialAttack enables player to enhance their Champions stats
 *
 */
void Water::specialAttack() {


    this->strength +=5;

    this->health +=15;

}
/**
 * undoSpecialAttack are the "foreseen or unforeseen consequence
 * of using special ability
 *
 */
void Water::undoSpecialAttack()
{
    this->dexterity -=2;



}