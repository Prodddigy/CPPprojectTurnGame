#include "Player.hpp"


    Player::Player()
    {

    }

    void Player::moveMonster(std::vector<Monster*> &monsters, int beastIndex )
    {
        playerArmy.push_back(monsters[beastIndex]);
        monsters.erase(monsters.begin()+beastIndex);

    }

    void Player::chooseMonster()
    {
        std::cout<<"CHOOSE YOU CHAMPIONS+++++++++++++++++++++++++++++++++++BY INPUTTING THEIR INDEX"<<'\n';

        for(int i=0 ; i<6; i++) {
            int number=0;
            for(Monster* m : Monster::necronomicon)
            {
                std::cout<<"["<<number <<"]<"<<m->name<<",HP: "<< m->maxHealth<<"/"<<m->health<<",STR: "<< m->strength<<
                         ",DEX: "<<m->dexterity <<",SPEC: "<<m->special <<", EXP: "<<m->exp <<", TYPE: "<<m->type <<">["<<number++ <<"]. "<<'\n';
                std::cout<<"----------------------------------------------------------------------------------------------"<<'\n';
            }

            std::cout<<"CHOOSE YOU CHAMPIONS^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^BY INPUTTING THEIR INDEX ,"<<-(i -6)<<" MORE"<<'\n';
            int input;
            std::cin >> input;
            this->moveMonster(Monster::necronomicon, input);
        }


    }

    void Player::showPlayerArmy()
    {
        int enumerate=0;
        for(Monster* m : playerArmy)
        {

            std::cout <<"["<< enumerate++ << "]. " << m->name << ", HP: " << m->health << "/" << m->maxHealth
                      << ", STR: " << m->strength <<
                      ", DEX: " << m->dexterity << ", SPEC: " << m->special << ", EXP: " << m->exp << ", TYPE: "
                      << m->type << '\n';

        }
        std::cout<<"-----------------------------------------------------------------------------------------"<<'\n';
    }

    bool Player::checkArmyHp()
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
