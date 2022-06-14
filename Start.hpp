#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Monster.hpp"
#include "Opponent.hpp"
#include "Player.hpp"

static int round;
static int turn;

struct Start {

Start();

static void playerAttack(Monster *attackingMon, Monster *victimMon);

void  battle(Player player, std::vector<Opponent*> allEnemies);

static Monster* playerChooseMonster(Player player);

};