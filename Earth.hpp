#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include "Monster.hpp"

struct Earth : Monster{
    static inline  std::vector<std::string> weakAgainst;
        static inline std::vector<std::string>  strongAgainst;

  static inline  std::string type;
  bool evolve;

     Earth(int strength, int dexterity, int health, int exp, const std::string& special, const std::string& name, std::string type,bool evolve)
                    : Monster(strength, dexterity, health, exp, special, name,type,evolve)
                    {

                    };

    static auto init() -> void;
};

