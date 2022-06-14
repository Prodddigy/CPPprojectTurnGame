#include "Start.hpp"
#include "Earth.hpp"
#include "Fire.hpp"
#include "Water.hpp"
#include "Steel.hpp"
#include "Ice.hpp"
#include "Air.hpp"
#include "Opponent.hpp"

Start::Start()
    {

    }

    void Start::playerAttack(Monster *attackingMon, Monster *victimMon)
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


    void Start::battle(Player player, std::vector<Opponent*> allEnemies) {

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

     Monster* Start::playerChooseMonster(Player player)
    {
        std::cout<<"Choose your fighter by index: "<<'\n';
        player.showPlayerArmy();
        int userInput=0;

        std::cout<<"Please choose Champion that is NOT dead, thank you";
        std::cin >> userInput;

        return player.playerArmy[userInput];
    }

