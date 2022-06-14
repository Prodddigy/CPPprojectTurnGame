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

    void Player::showPlayerArmy()
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
