#include "Player.hpp"


    Player::Player()
    {

    }


    /**
     * moveMonster adds a Monster object from the @necronomicon vector (holds all Monster that are available in game)
     * to @User Monster vector
     * After addition, that same Monster is then removed from @necronomicon
     * @param monsters
     * @param beastIndex
     */
    void Player::moveMonster(std::vector<Monster*> &monsters, int beastIndex )
    {
        playerArmy.push_back(monsters[beastIndex]);
        monsters.erase(monsters.begin()+beastIndex);

    }
/**
 *chooseMonster let's @User to add 6 no more , no less monsters to it's personal Monster vector
 * @User chooses it's champions who have none of their own will
 */
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
/**
 * showPlayerArmy who all current Monster that belong to the @User
 */
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
/**
 * @Users death is defined by the number of available Champion whom are not dead
 * if all 6 Champions have zeroed(or less) health
 * they are assumed as dead
 *
 * @return boolean
 */
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

        {   std::cout<<'\n'<<"GAME OVER"<<'\n';
            return false;

        }
        else
            return true;
    }
