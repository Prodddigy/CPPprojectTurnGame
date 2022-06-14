#include <iostream>
#include <vector>
#include "Monster.hpp"
#include "Water.hpp"
#include "Earth.hpp"
#include "Air.hpp"
#include "Fire.hpp"
#include "Ice.hpp"
#include "Steel.hpp"
#include "Player.hpp"
#include "Opponent.hpp"
#include "Start.hpp"


//-------------------------------------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------------------------------

int main() {/*
 * make all structs
 * each struct has a seperate file
 *
 *
 */
    Water::init();
    Earth::init();
    Air::init();
    Fire::init();
    Ice::init();
    Steel::init();

    //std::cout<<Air::type;
    auto steel0 = Steel(4, 3, 10, 0, "Camp protector", "Tommy Jarvis","Steel");
    auto water1= Water(4, 3, 10, 0, "Adam injection", "Frank Fontaine","Water");
    auto water2= Water(4, 3, 10, 0, "Adam injection", "Frank Fontaine","Water");
    auto water3 = Water(4, 3, 10, 0, "Rivet gun", "Big Daddy","Water");
    auto water4 = Water(4, 3, 10, 0, "Rivet gun", "Big Daddy","Water");
    auto earth5 = Earth(4, 3, 10, 0, "Undead Wrath", "Jason Voorhees","Earth");
    auto earth6 = Earth(4, 3, 10, 0, "Undead Wrath", "Jason Voorhees","Earth");
    auto earth7= Earth(4, 3, 10, 0, "Undying desire for vengeance", "Max Payne","Earth");
    auto earth8= Earth(4, 3, 10, 0, "Undying desire for vengeance", "Max Payne","Earth");
    auto air9 = Air(4, 3, 10, 0, "Flame Thrower", "Ellen Ripley","Air");
    auto air10 = Air(4, 3, 10, 0, "Flame Thrower", "Ellen Ripley","Air");
    auto air11 = Air(4, 3, 10, 0, "Monkey Kombat", "Guybrush Threepwood","Air");
    auto air12 = Air(4, 3, 10, 0, "Monkey Kombat", "Guybrush Threepwood","Air");
    auto fire13= Fire(4, 3, 10, 0, "Flashlight", "Alan Wake","Fire");
    auto fire14= Fire(4, 3, 10, 0, "Flashlight", "Alan Wake","Fire");
    auto fire15 = Fire(4, 3, 10, 0, "Army of Darkness", "Evil Ash","Fire");
    auto fire16 = Fire(4, 3, 10, 0, "Army of Darkness", "Evil Ash","Fire");
    auto ice17 = Ice(4, 3, 10, 0, "Tears in rain", "Roy Batty","Ice");
    auto ice18 = Ice(4, 3, 10, 0, "Tears in rain", "Roy Batty","Ice");
    auto ice19= Ice(4, 3, 10, 0, "Voight-Kampff test", "Rick Deckard","Ice");
    auto ice20= Ice(4, 3, 10, 0, "Voight-Kampff test", "Rick Deckard","Ice");
    auto steel21 = Steel(4, 3, 10, 0, "Boom-stick", "Ashley Williams","Steel");
    auto steel22 = Steel(4, 3, 10, 0, "Boom-stick", "Ashley Williams","Steel");
    auto steel23 = Steel(4, 3, 10, 0, "Camp protector", "Tommy Jarvis","Steel");
    auto steel24 = Steel(4, 3, 10, 0, "Camp protector", "Tommy Jarvis","Steel");
    auto air25 = Air(4, 3, 10, 0, "Monkey Kombat", "Guybrush Threepwood","Air");
/*
    for(std::string m : Water::strongAgainst)
    {
            if(m == "Fire")
        std::cout << m <<" is an easy opponet for Water types" <<'\n';
    }
    */


Player me = Player();

    me.chooseMonster();

    Opponent hercules = Opponent("hercules");
    Opponent zeus = Opponent("zeus");
    Opponent nyx = Opponent("nyx");
    Opponent zagreus = Opponent("zagreus");

    hercules.moveMonster(Monster::necronomicon);

    zeus.moveMonster(Monster::necronomicon);

    nyx.moveMonster(Monster::necronomicon);

    zagreus.moveMonster(Monster::necronomicon);

    Start start = Start();

    start.battle(me,Opponent::allEnemies);
}
