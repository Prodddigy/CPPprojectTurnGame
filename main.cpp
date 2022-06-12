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
            for(int i=0 ; i<6; i++) {
                int number=0;
                for(Monster* m : Monster::necronomicon)
                {
                    std::cout<<number++ <<". "<<m->name<<'\n';
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
            std::cout<<enumerate++ <<". "<<m->name<<", hp:"<< m->maxHealth<<"/"<<m->health<<", strg:"<< m->strength<<
            ", dex:"<<m->dexterity <<", spec:"<<m->special <<", exp"<<m->exp << '\n';
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

                void playerAttack(Monster attackingMon, Monster *victimMon)
                {
                    victimMon->health -= attackingMon.strength;


                }


                void battle(Player& player, std::vector<Opponent*> allEnemies) {

                bool playerWins = false;
                int enemyMonsterCounter = 0;
                int enemyCounter=0;

              //  Monster playerMonster = *player.playerArmy[0];
               Monster playerMonster = playerChooseMonster(player);

                Opponent *currentOpponent = allEnemies[enemyCounter];

                Monster *enemyMonster = currentOpponent->enemyArmy[enemyMonsterCounter];

                while (player.checkArmyHp()) {
                    std::cout<<"enters loop?";
                    if (Opponent::isAllEnemiesDead()) {
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
                    else if (enemyMonster->health <= 0) {
                        enemyMonster = currentOpponent->enemyArmy[enemyMonsterCounter++];
                    }

                    std::cout<<"a - playerAttack, s - special, c - change, h - help, q - quit"<<'\n';

std::cout<<"PLAYER "<<"--------------------VS-------------------------------------------------------  "<<currentOpponent->name<<'\n';
std::cout<<"CHAMPION: "<<playerMonster.name<<" ----------------------------------------------------  "<<"CHAMPION: "<<enemyMonster->name<<'\n';
std::cout<<"HP: "<<playerMonster.health<<"/"<<playerMonster.maxHealth<<" -------------------------------------------------------------------------  "<<"HP: "<<enemyMonster->health<<"/"<<enemyMonster->maxHealth<<'\n';
std::cout<<"STRENGTH: "<<playerMonster.strength<<" -----------------------------------------------------------------  "<<"STRENGTH: "<<enemyMonster->strength<<'\n';
std::cout<<"SPECIAL: "<<playerMonster.special<<" ---------------------------------------------------  "<<"SPECIAL: "<<enemyMonster->special<<'\n';
std::cout<<"EXP: "<<playerMonster.exp<<" --------------------------------------------------------------  "<<'\n';

                    char input;
                    std::cin >> input;
                    switch (input) {
                        case 'a' : {//playerAttack
                                std::cout<<"fight"<<'\n';
                            //    std::cout<<playerMonster.name << " vs "<< currentOpponent->name<<" with "<<enemyMonster->name
                              //  << "hp: " << enemyMonster->health<<"/"<<enemyMonster->maxHealth << '\n';

                            playerAttack(playerMonster, enemyMonster);
                            std::cout<<"after attack";
                            std::cout<<playerMonster.name << " vs "<< currentOpponent->name<<" with "<<enemyMonster->name
                                     << "hp: " << enemyMonster->health<<"/"<<enemyMonster->maxHealth<< '\n';
                            break;

                        }
                        case 's': {//special
                            std::cout<<"special";

                            break;

                        }
                        case 'c': {//change
                            std::cout<<"change";
                            playerMonster = playerChooseMonster(player);
                            break;

                        }
                        case 'h': {//help
                            std::cout<<"help";

                            break;
                        }
                        case 'q': {
                            std::cout<<"quit";
                            break;
                        }
                        default : {
                            std::cout << "try again";
                        }
                    }
                    if(input == 'q')
                    {
                        break;
                    }


                }

                //while()

            }

            static Monster playerChooseMonster(Player player)
            {
                std::cout<<"Choose your fighter by index: "<<'\n';
                player.showPlayerArmy();
                int userInput;
                std::cin>> userInput;
                return *player.playerArmy[userInput];
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

    auto steel0 = Steel(1, 3, 10, 0, "Camp protector", "Tommy Jarvis");
    auto water1= Water(1, 3, 10, 0, "Adam injection", "Frank Fontaine");
    auto water2= Water(1, 3, 10, 0, "Adam injection", "Frank Fontaine");
    auto water3 = Water(1, 3, 10, 0, "Rivet gun", "Big Daddy");
    auto water4 = Water(1, 3, 10, 0, "Rivet gun", "Big Daddy");
    auto earth5 = Earth(1, 3, 10, 0, "Undead Wrath", "Jason Voorhees");
    auto earth6 = Earth(1, 3, 10, 0, "Undead Wrath", "Jason Voorhees");
    auto earth7= Earth(1, 3, 10, 0, "Undying desire for vengeance", "Max Payne");
    auto earth8= Earth(1, 3, 10, 0, "Undying desire for vengeance", "Max Payne");
    auto air9 = Air(1, 3, 10, 0, "Flame Thrower", "Ellen Ripley");
    auto air10 = Air(1, 3, 10, 0, "Flame Thrower", "Ellen Ripley");
    auto air11 = Air(1, 3, 10, 0, "Monkey Kombat", "Guybrush Threepwood");
    auto air12 = Air(1, 3, 10, 0, "Monkey Kombat", "Guybrush Threepwood");
    auto fire13= Fire(1, 3, 10, 0, "Flashlight", "Alan Wake");
    auto fire14= Fire(1, 3, 10, 0, "Flashlight", "Alan Wake");
    auto fire15 = Fire(1, 3, 10, 0, "Army of Darkness", "Evil Ash");
    auto fire16 = Fire(1, 3, 10, 0, "Army of Darkness", "Evil Ash");
    auto ice17 = Ice(1, 3, 10, 0, "Tears in rain", "Roy Batty");
    auto ice18 = Ice(1, 3, 10, 0, "Tears in rain", "Roy Batty");
    auto ice19= Ice(1, 3, 10, 0, "Voight-Kampff test", "Rick Deckard");
    auto ice20= Ice(1, 3, 10, 0, "Voight-Kampff test", "Rick Deckard");
    auto steel21 = Steel(1, 3, 10, 0, "Boom-stick", "Ashley Williams");
    auto steel22 = Steel(1, 3, 10, 0, "Boom-stick", "Ashley Williams");
    auto steel23 = Steel(1, 3, 10, 0, "Camp protector", "Tommy Jarvis");
    auto steel24 = Steel(1, 3, 10, 0, "Camp protector", "Tommy Jarvis");
    auto air25 = Air(1, 3, 10, 0, "Monkey Kombat", "Guybrush Threepwood");
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
