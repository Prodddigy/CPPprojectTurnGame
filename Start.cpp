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

        Monster *playerMonster = playerChooseMonster(player);

        Opponent *currentOpponent = allEnemies[enemyCounter];

        Monster *enemyMonster = currentOpponent->enemyArmy[enemyMonsterCounter];

        while (player.checkArmyHp()) {
            //  std::cout<<"enters loop?";
            if (Opponent::isAllEnemiesDead())
            {
                playerWins= true;

                std::cout<<"game ends :) YOU WIN";
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
                std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! " <<'\n';
            std::cout<<"Your current Champion: "<<playerMonster->name<<" status -> DECEASED. Choose a new one:"<<'\n';
                std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! " <<'\n';
                std::cout << " " <<'\n';
                playerMonster = playerChooseMonster(player);
            }


            std::cout << "a - playerAttack, s - special, c - change, h - help, q - quit" << '\n';
            if (enemyMonster->health > 0 && playerMonster->health > 0) {
                playerMonster->evolveMon();
                std::cout << "PLAYER "
                          << "--------------------VS-------------------------------------------------------  "
                          << currentOpponent->name << '\n';
                std::cout << "CHAMPION: " << playerMonster->name
                          << " ----------------------------------------------------  " << "CHAMPION: "
                          << enemyMonster->name << '\n';
                std::cout << "HP: " << playerMonster->health << "/" << playerMonster->maxHealth
                          << " ---------------------------------------------------- "
                          << "HP: " << enemyMonster->health << "/" << enemyMonster->maxHealth << '\n';
                std::cout << "STRENGTH: " << playerMonster->strength
                          << " ---------------------------------------------------- "
                          << "STRENGTH: " << enemyMonster->strength << '\n';
                std::cout << "DEXTERITY: " << playerMonster->dexterity
                          << " ---------------------------------------------------- " << "DEXTERITY: "
                          << enemyMonster->dexterity << '\n';
                std::cout << "SPECIAL: " << playerMonster->special
                          << " ---------------------------------------------------- " << "SPECIAL: "
                          << enemyMonster->special << '\n';
                std::cout << "EXP: " << playerMonster->exp
                          << " ---------------------------------------------------- " << '\n';
                std::cout << "TYPE: " << playerMonster->type
                          << " ---------------------------------------------------- "
                          << "TYPE: "
                          << enemyMonster->type << '\n';
            }
            else {
                std::cout << " " <<'\n';
                std::cout << "GET READY FOR THE NEXT BATTLE" << '\n';

                std::cout << " " <<'\n';
                continue;
            }
                char input;
                std::cin >> input;
                switch (input) {
                case 'a' : {//playerAttack

                    std::cout << "Battle status: " <<'\n';
                    std::cout << "Battle_____________________________________________ " <<'\n';
                    if ((rand() % 10 + 1) + enemyMonster->dexterity >= 7) {
                        playerAttack(playerMonster, enemyMonster);
                        std::cout<<"Player -> "<<playerMonster->name << "has dealt some dmg to "<< enemyMonster->name<< '\n';
                        playerMonster->exp+=2;
                    }
                    else
                    {
                        std::cout << currentOpponent->name<<" -> "<<enemyMonster->name << " has dodged attack" << '\n';
                    }

                    if(playerMonster->specialUsed && !playerMonster->specialUnUsed)
                    {
                        playerMonster->specialRoundsLeft--;

                        if(playerMonster->specialRoundsLeft==0)
                        {
                            playerMonster->undoSpecialAttack();
                            playerMonster->specialUnUsed= true;
                        }
                    }

                    //enemy attacks
                    if ((rand() % 10 + 1) + playerMonster->dexterity >= 7) {

                        playerAttack(enemyMonster, playerMonster);
                        std::cout<<currentOpponent->name<<" -> "<<enemyMonster->name << " has dealt some dmg to "<< playerMonster->name<< '\n';
                    } else {
                        std::cout <<"Player -> "<< playerMonster->name << " has dodged attack" << '\n';
                    }
                    std::cout << "_____________________________________________status " <<'\n';
                    std::cout << " " <<'\n';
                    break;
                }
                case 's': {//special

                    if(!playerMonster->specialUsed)
                    {
                        playerMonster->specialUsed=true;
                        playerMonster->specialAttack();

                    }
                    else{
                        std::cout<<"special~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<'\n';
                        std::cout<<playerMonster->name<<" Has already used his/hers special move..."<<'\n';

                        std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~special"<<'\n';
                    }
                    break;
                }
                case 'c': {//change
                    std::cout << "change";
                    playerMonster = playerChooseMonster(player);
                    break;
                }
                case 'h': {//help
                    std::cout << "help";
                    helpAndRules();
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


    void Start::helpAndRules()
    {
        std::cout <<'\n';
    std::cout <<"OFFICIAL RULES OF \"TURBO KILLER\", THE TURN-BASED STRATEGY GAME THAT'S not TRADE MARKED AND noT LICENCED."<<'\n';;
    std::cout <<"[a] ATTACKS reduce enemy's hp";
    std::cout <<", both Your Champions and Opponent's Champions can dodge attacks."<<'\n';
    std::cout <<"[c] Choose to CHANGE Your Champion."<<'\n';
    std::cout <<"[q] Just QUIT the \'game\'."<<'\n';
    std::cout <<"[s] SPECIAL attacks last only for 2 fights, here is what each SPECIAL does DEPENDING on their type:"<<'\n';
    std::cout <<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<'\n';
    std::cout <<"*AIR* ->+20 HP and +2 STR, but after 2 FIGHTS -3 STR | *EARTH* ->+4 STR and +7 HP, but after 2 FIGHTS -4 DEX."<<'\n';
    std::cout <<"*FIRE* ->+10 STR and +3 DEX, but after 2 FIGHTS -10 STR and -3 DEX | *ICE* ->+3 STR and +7 DEX, but after 2 FIGHTS -5 HP."<<'\n';
    std::cout <<"*STEEL* ->+10 STR and +5 HP, but after 2 FIGHTS -10 STR | *WATER* ->+5 STR and +15 HP, but after 2 FIGHTS -2 DEX."<<'\n';
        std::cout <<'\n';

    }
