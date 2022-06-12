#include <string>
#include "Water.hpp"
#include "Monster.hpp"

auto Water::init() -> void {
    Water::weakAgainst = {"Water"};
    Water::strongAgainst = {"Earth","Fire"};
}

Water::Water(int strength, int dexterity, int health, int exp, const std::string& special, const std::string& name) : Monster (
        strength, dexterity, health, exp, special, name) { }