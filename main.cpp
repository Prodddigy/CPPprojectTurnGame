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

int main() {

    Water::init();
    Earth::init();
    Air::init();
    Fire::init();
    Ice::init();
    Steel::init();

    //std::cout<<Air::type;
    auto steel0 = Steel(4, 3, 10, 0, "Camp protector", "Tommy Jarvis","Steel",false);
    auto water1= Water(4, 3, 10, 0, "Adam injection", "Frank Fontaine","Water",false);
    auto water2= Water(4, 3, 10, 0, "Adam injection", "Frank Fontaine","Water",false);
    auto water3 = Water(4, 3, 10, 0, "Rivet gun", "Big Daddy","Water",false);
    auto water4 = Water(4, 3, 10, 0, "Rivet gun", "Big Daddy","Water",false);
    auto earth5 = Earth(4, 3, 10, 0, "Undead Wrath", "Jason Voorhees","Earth",false);
    auto earth6 = Earth(4, 3, 10, 0, "Undead Wrath", "Jason Voorhees","Earth",false);
    auto earth7= Earth(4, 3, 10, 0, "Undying desire for vengeance", "Max Payne","Earth",false);
    auto earth8= Earth(4, 3, 10, 0, "Undying desire for vengeance", "Max Payne","Earth",false);
    auto air9 = Air(6, 3, 10, 0, "Flame Thrower", "Ellen Ripley","Air",false);
    auto air10 = Air(6, 3, 10, 0, "Flame Thrower", "Ellen Ripley","Air",false);
    auto air11 = Air(2, 6, 25, 0, "Holding breath underwater for 10 minutes", "Guybrush Threepwood","Air",false);
    auto air12 = Air(2, 6, 25, 0, "Holding breath underwater for 10 minutes", "Guybrush Threepwood","Air",false);
    auto fire13= Fire(4, 3, 10, 0, "Flashlight", "Alan Wake","Fire",false);
    auto fire14= Fire(4, 3, 10, 0, "Flashlight", "Alan Wake","Fire",false);
    auto fire15 = Fire(4, 3, 10, 0, "Army of Darkness", "Evil Ash","Fire",false);
    auto fire16 = Fire(4, 3, 10, 0, "Army of Darkness", "Evil Ash","Fire",false);
    auto ice17 = Ice(4, 3, 10, 0, "Tears in rain", "Roy Batty","Ice",false);
    auto ice18 = Ice(4, 3, 10, 0, "Tears in rain", "Roy Batty","Ice",false);
    auto ice19= Ice(4, 3, 10, 0, "Voight-Kampff test", "Rick Deckard","Ice",false);
    auto ice20= Ice(4, 3, 10, 0, "Voight-Kampff test", "Rick Deckard","Ice",false);
    auto steel21 = Steel(4, 3, 10, 0, "Boom-stick", "Ashley Williams","Steel",false);
    auto steel22 = Steel(4, 3, 10, 0, "Boom-stick", "Ashley Williams","Steel",false);
    auto steel23 = Steel(4, 3, 10, 0, "Camp protector", "Tommy Jarvis","Steel",false);
    auto steel24 = Steel(4, 3, 10, 0, "Camp protector", "Tommy Jarvis","Steel",false);
    auto air25 = Air(2, 6, 25, 0, "Holding breath underwater for 10 minutes", "Guybrush Threepwood","Air",false);


Player me = Player();

    me.chooseMonster();

    Opponent Hercules = Opponent("Hercules");
    Opponent Zeus = Opponent("Zeus");
    Opponent Nyx = Opponent("Nyx");
    Opponent Zagreus = Opponent("Zagreus");

    Hercules.moveMonster(Monster::necronomicon);

    Zeus.moveMonster(Monster::necronomicon);

    Nyx.moveMonster(Monster::necronomicon);

    Zagreus.moveMonster(Monster::necronomicon);

    Start start = Start();

    start.battle(me,Opponent::allEnemies);
}
