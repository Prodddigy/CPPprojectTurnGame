#include <string>
#include "Water.hpp"
#include "Monster.hpp"

auto Water::init() -> void {
    Water::weakAgainst = {"Water"};
    Water::strongAgainst = {"Earth","Fire"};
}

