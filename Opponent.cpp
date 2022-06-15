#include "Opponent.hpp"


Opponent::Opponent(std::string name)
: name(name)
        {
                allEnemies.push_back(this);
        }


void Opponent::moveMonster(std::vector<Monster*> &monsters ) {

    for (int i = 0; i < 4; i++) {

        this->enemyArmy.push_back(monsters[i]);
        monsters.erase(monsters.begin() + i);
    }
}

void Opponent::showOpponentArmy()
{
    std::cout<<"name of the opponent: "<<this->name<<'\n';
    for(Monster* m : this->enemyArmy)
    {
        std::cout<<m->name<<'\n';
    }
    std::cout<<'\n';
}

bool Opponent::isEnemyArmyDead()
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

 bool Opponent::isAllEnemiesDead()
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