#include <iostream>
#include <vector>
#include "Monster.hpp"
#include "Water.hpp"
#include "Earth.hpp"
#include "Air.hpp"
#include "Fire.hpp"
#include "Ice.hpp"
#include "Steel.hpp"

        struct Player {
        std::vector<Monster*> playerArmy;

        int round;
        Player()
        {

        }

        void moveMonster(std::vector<Monster*> &monsters, int beastIndex )
        {


            playerArmy.push_back(monsters[beastIndex]);
            monsters.erase(monsters.begin()+beastIndex);

            //std::cout << "here";
//            for(Monster* m : Monster::necronomicon)
//            {
//                std::cout<<m->name<<'\n';
//            }

    }

    void chooseMonster()
    {
            std::cout<<"Choose your champions"<<'\n';

            for(int i=0 ; i<6; i++) {
                int number=0;
                for(Monster* m : Monster::necronomicon)
                {
                    std::cout<<number++ <<". "<<m->name<<", hp: "<< m->maxHealth<<"/"<<m->health<<", strg: "<< m->strength<<
                             ", dex: "<<m->dexterity <<", spec: "<<m->special <<", exp: "<<m->exp <<", type: "<<m->type<< '\n';
                    std::cout<<"----------------------------------------------------------------------------------------------"<<'\n';
                }
                int input;
                std::cin >> input;
                this->moveMonster(Monster::necronomicon, input);
            }
    }

    void showPlayerArmy()
    {
        int enumerate=0;
        for(Monster* m : playerArmy)
        {

                std::cout << enumerate++ << ". " << m->name << ", hp: " << m->health << "/" << m->maxHealth
                          << ", strg: " << m->strength <<
                          ", dex: " << m->dexterity << ", spec: " << m->special << ", exp: " << m->exp << ", type: "
                          << m->type << '\n';

        }
        std::cout<<'\n';
    }

    bool checkArmyHp()
    {
            int deadites =0;
            for(Monster *m : playerArmy)
            {
                if(m->health <= 0)
                {
                    deadites++;
                }
            }
            if(deadites==6)
            {
                return false;
            }
            else
                return true;
    }
        };
//-------------------------------------------------------------------------------------------------------------------

        struct Opponent{

            std::vector<Monster*> enemyArmy;

            static inline std::vector<Opponent*> allEnemies;
            std::string name;

            Opponent(std::string name)
            : name(name)
            {
                allEnemies.push_back(this);

            }


            void moveMonster(std::vector<Monster*> &monsters ) {

                for (int i = 0; i < 4; i++) {
                   // if(i >= (monsters.size()-1))

                    this->enemyArmy.push_back(monsters[i]);
                    monsters.erase(monsters.begin() + i);
                }
            }

            void showOpponentArmy()
            {
                std::cout<<"name of the opponent: "<<this->name<<'\n';
                for(Monster* m : this->enemyArmy)
                {
                    std::cout<<m->name<<'\n';
                }
                std::cout<<'\n';
            }

            bool isEnemyArmyDead()
            {
                int deadites =0;
                for(Monster *m : enemyArmy)
                {
                    if(m->health <= 0)
                    {
                        deadites++;
                    }
                }
                if(deadites==4)//4 set to 4!!!
                {
                    return true;
                }
                else
                    return false;
            }

            static bool isAllEnemiesDead()
            {
                int deadites=0;
                for( Opponent* o : allEnemies)
                {
                    if(o->isEnemyArmyDead())
                    {
                        deadites++;
                    }
                }
                if(deadites ==4)
                {
                    return true;
                }
                else{
                    return false;
                }

            }
        };

//-------------------------------------------------------------------------------------------------------------------

        struct Start {

            static int round;
            static int turn;

            Start()
            {
                std::cout<<"starts the game";
            }

                void playerAttack(Monster *attackingMon, Monster *victimMon)
                {
                        bool foundSpot = false;

                if(attackingMon->type =="Earth")
                {
                    for( const std::string& weak : Earth::weakAgainst)
                    {
                        if(weak == victimMon->type)
                        {
                            victimMon->health -= (attackingMon->strength-3);
                            foundSpot =true;
                        }
                    }
                    if(!foundSpot) {
                        for (const std::string &strong: Earth::strongAgainst) {
                            if (strong == victimMon->type) {
                                victimMon->health -= (attackingMon->strength + 3);
                                foundSpot= true;
                            }
                        }
                        if(!foundSpot)
                            victimMon->health -= (attackingMon->strength );
                    }
                }
                else if(attackingMon->type =="Fire")
                {
                    for( const std::string& weak : Fire::weakAgainst)
                    {
                        if(weak == victimMon->type)
                        {
                            victimMon->health -= (attackingMon->strength-3);
                            foundSpot= true;
                        }
                    }
                    if(!foundSpot){
                    for( const std::string& strong : Fire::strongAgainst)
                    {
                        if(strong == victimMon->type)
                        {
                            victimMon->health -= (attackingMon->strength+3);
                            foundSpot =true;
                        }
                    }
                }  if(!foundSpot)
                        victimMon->health -= (attackingMon->strength );
                }
                else if(attackingMon->type =="Water")
                {
                    for( const std::string& weak : Water::weakAgainst)
                    {
                        if(weak == victimMon->type)
                        {
                            victimMon->health -= (attackingMon->strength-3);
                            foundSpot= true;
                        }

                    }
                    if(!foundSpot){
                    for( const std::string& strong : Water::strongAgainst)
                    {
                        if(strong == victimMon->type)
                        {
                            victimMon->health -= (attackingMon->strength+3);
                            foundSpot = true;
                        }
                    }
                }  if(!foundSpot)
                        victimMon->health -= (attackingMon->strength );
                }

                else if(attackingMon->type =="Steel")
                {
                    for( const std::string& weak : Steel::weakAgainst)
                    {
                        if(weak == victimMon->type)
                        {
                            victimMon->health -= (attackingMon->strength-3);
                            foundSpot =true;
                        }
                    }
                    if(!foundSpot) {
                        for (const std::string &strong: Steel::strongAgainst) {
                            if (strong == victimMon->type) {
                                victimMon->health -= (attackingMon->strength + 3);
                                foundSpot= true;
                            }
                        }
                    }
                    if(!foundSpot)
                        victimMon->health -= (attackingMon->strength );
                }
                else if(attackingMon->type =="Ice")
                {
                    for( const std::string& weak : Ice::weakAgainst)
                    {
                        if(weak == victimMon->type)
                        {
                            victimMon->health -= (attackingMon->strength-3);
                            foundSpot=true;
                        }
                    }
                    if(!foundSpot){
                    for( const std::string& strong : Ice::strongAgainst)
                    {
                        if(strong == victimMon->type)
                        {
                            victimMon->health -= (attackingMon->strength+3);
                            foundSpot=true;
                        }
                    }
                    }
                    if(!foundSpot)
                            victimMon->health -= (attackingMon->strength );
                }
                else if(attackingMon->type =="Air")
                {
                    for( const std::string& weak : Air::weakAgainst)
                    {
                        if(weak == victimMon->type)
                        {
                            victimMon->health -= (attackingMon->strength-3);
                            foundSpot =true;
                        }
                    }
                    if(!foundSpot) {
                        for (const std::string &strong: Air::strongAgainst) {
                            if (strong == victimMon->type) {
                                victimMon->health -= (attackingMon->strength + 3);
                                foundSpot =true;
                            }
                        }
                    }
                    if(!foundSpot)
                        victimMon->health -= (attackingMon->strength );
                  }
                }
           // void playerAttack(Monster *attackingMon, Monster *victimMon)
            void enemyAttack(Monster *attackingMon, Monster *victimMon)
            {
                bool foundSpot = false;
                victimMon->health -= attackingMon->strength;

                if(attackingMon->type =="Earth")
                {
                    for( const std::string& weak : Earth::weakAgainst)
                    {
                        if(weak == victimMon->type)
                        {
                            victimMon->health -= (attackingMon->strength-3);
                            foundSpot =true;
                        }
                    }
                    if(!foundSpot) {
                        for (const std::string &strong: Earth::strongAgainst) {
                            if (strong == victimMon->type) {
                                victimMon->health -= (attackingMon->strength + 3);
                                foundSpot= true;
                            }
                        }
                        if(!foundSpot)
                            victimMon->health -= (attackingMon->strength );
                    }
                }
                else if(attackingMon->type =="Fire")
                {
                    for( const std::string& weak : Fire::weakAgainst)
                    {
                        if(weak == victimMon->type)
                        {
                            victimMon->health -= (attackingMon->strength-3);
                            foundSpot= true;
                        }
                    }
                    if(!foundSpot){
                        for( const std::string& strong : Fire::strongAgainst)
                        {
                            if(strong == victimMon->type)
                            {
                                victimMon->health -= (attackingMon->strength+3);
                                foundSpot =true;
                            }
                        }
                    }  if(!foundSpot)
                        victimMon->health -= (attackingMon->strength );
                }
                else if(attackingMon->type =="Water")
                {
                    for( const std::string& weak : Water::weakAgainst)
                    {
                        if(weak == victimMon->type)
                        {
                            victimMon->health -= (attackingMon->strength-3);
                            foundSpot= true;
                        }

                    }
                    if(!foundSpot){
                        for( const std::string& strong : Water::strongAgainst)
                        {
                            if(strong == victimMon->type)
                            {
                                victimMon->health -= (attackingMon->strength+3);
                                foundSpot = true;
                            }
                        }
                    }  if(!foundSpot)
                        victimMon->health -= (attackingMon->strength );
                }

                else if(attackingMon->type =="Steel")
                {
                    for( const std::string& weak : Steel::weakAgainst)
                    {
                        if(weak == victimMon->type)
                        {
                            victimMon->health -= (attackingMon->strength-3);
                            foundSpot =true;
                        }
                    }
                    if(!foundSpot) {
                        for (const std::string &strong: Steel::strongAgainst) {
                            if (strong == victimMon->type) {
                                victimMon->health -= (attackingMon->strength + 3);
                                foundSpot= true;
                            }
                        }
                    }
                    if(!foundSpot)
                        victimMon->health -= (attackingMon->strength );
                }
                else if(attackingMon->type =="Ice")
                {
                    for( const std::string& weak : Ice::weakAgainst)
                    {
                        if(weak == victimMon->type)
                        {
                            victimMon->health -= (attackingMon->strength-3);
                            foundSpot=true;
                        }
                    }
                    if(!foundSpot){
                        for( const std::string& strong : Ice::strongAgainst)
                        {
                            if(strong == victimMon->type)
                            {
                                victimMon->health -= (attackingMon->strength+3);
                                foundSpot=true;
                            }
                        }
                    }
                    if(!foundSpot)
                        victimMon->health -= (attackingMon->strength );
                }
                else if(attackingMon->type =="Air")
                {
                    for( const std::string& weak : Air::weakAgainst)
                    {
                        if(weak == victimMon->type)
                        {
                            victimMon->health -= (attackingMon->strength-3);
                            foundSpot =true;
                        }
                    }
                    if(!foundSpot) {
                        for (const std::string &strong: Air::strongAgainst) {
                            if (strong == victimMon->type) {
                                victimMon->health -= (attackingMon->strength + 3);
                                foundSpot =true;
                            }
                        }
                    }
                    if(!foundSpot)
                        victimMon->health -= (attackingMon->strength );
                }

            }

                auto battle(Player player, std::vector<Opponent*> allEnemies) {

                bool playerWins = false;
                int enemyMonsterCounter = 0;
                int enemyCounter=0;


              //  Monster playerMonster = *player.playerArmy[0];
               Monster *playerMonster = playerChooseMonster(player);

             // int *hp = &playerMonster.health;
                Opponent *currentOpponent = allEnemies[enemyCounter];

                Monster *enemyMonster = currentOpponent->enemyArmy[enemyMonsterCounter];

                while (player.checkArmyHp()) {
                  //  std::cout<<"enters loop?";
                    if (Opponent::isAllEnemiesDead())
                    {
                        playerWins= true;

                        std::cout<<"game ends :)";
                        break;
                    }
                    else if (currentOpponent->isEnemyArmyDead())//checks if enemy's army is dead
                    {
                        enemyMonsterCounter =0;
                        enemyCounter++;
                        currentOpponent=allEnemies[enemyCounter];
                    }
                    else if (enemyMonster->health <= 0)
                    {
                        enemyMonster = currentOpponent->enemyArmy[enemyMonsterCounter++];
                    }

                    if(playerMonster->health<=0)
                    {

                        playerMonster = playerChooseMonster(player);
                    }


                        std::cout << "a - playerAttack, s - special, c - change, h - help, q - quit" << '\n';
                        if (enemyMonster->health > 0 && playerMonster->health > 0) {

                            std::cout << "PLAYER "
                                      << "--------------------VS-------------------------------------------------------  "
                                      << currentOpponent->name << '\n';
                            std::cout << "CHAMPION: " << playerMonster->name
                                      << " ----------------------------------------------------  " << "CHAMPION: "
                                      << enemyMonster->name << '\n';
                            std::cout << "HP: " << playerMonster->health << "/" << playerMonster->maxHealth
                                      << " -------------------------------------------------------------------------  "
                                      << "HP: " << enemyMonster->health << "/" << enemyMonster->maxHealth << '\n';
                            std::cout << "STRENGTH: " << playerMonster->strength
                                      << " -----------------------------------------------------------------  "
                                      << "STRENGTH: " << enemyMonster->strength << '\n';
                            std::cout << "SPECIAL: " << playerMonster->special
                                      << " ---------------------------------------------------  " << "SPECIAL: "
                                      << enemyMonster->special << '\n';
                            std::cout << "EXP: " << playerMonster->exp
                                      << " --------------------------------------------------------------  " << '\n';
                            std::cout << "TYPE: " << playerMonster->type
                                      << " -----------------------------------------------------------------  "
                                      << "TYPE: "
                                      << enemyMonster->type << '\n';
                        }
                        else {
                            std::cout << "GET READY FOR THE NEXT BATTLE" << '\n';
                            continue;
                        }


                        char input;
                        std::cin >> input;
                        switch (input) {
                            case 'a' : {//playerAttack
                                // std::cout<<"fight"<<'\n';

                                if ((rand() % 10 + 1) + enemyMonster->dexterity >= 7) {
                                    playerAttack(playerMonster, enemyMonster);
                                } else {
                                    std::cout << enemyMonster->name << " has dodged attack" << '\n';
                                }

                                //enemy attacks
                              // playerMonster->health -= enemyMonster->strength;
                                if ((rand() % 10 + 1) + playerMonster->dexterity >= 7) {
                                    std::cout << "does it hit enemy attack?";
                                    playerAttack(enemyMonster, playerMonster);
                                } else {
                                    std::cout << playerMonster->name << " has dodged attack" << '\n';
                                }

                                break;
                            }
                            case 's': {//special
                                std::cout << "special";

                                break;
                            }
                            case 'c': {//change
                                std::cout << "change";
                               playerMonster = playerChooseMonster(player);
                                break;
                            }
                            case 'h': {//help
                                std::cout << "help";
                                break;
                            }
                            case 'q': {
                                std::cout << "quit";
                                break;
                            }
                            default : {
                                std::cout << "try again";
                            }
                        }
                        if (input == 'q') {
                            break;
                        }



                }

                //while()

            }

            static Monster* playerChooseMonster(Player player)
            {
                std::cout<<"Choose your fighter by index: "<<'\n';
                player.showPlayerArmy();
                int userInput=0;

                std::cout<<"Please choose Champion that is NOT dead, thank you";
                std::cin >> userInput;

                return player.playerArmy[userInput];
            }

        };
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
