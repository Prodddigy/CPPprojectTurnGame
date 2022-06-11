#include <iostream>
#include <vector>

/**
 * stuff
 */
        struct Monster{
            int strength;
            int dexterity;
            int health;
            int exp;
            std::string special;
            std::string name;
            static inline std::vector<Monster*> necronomicon;

             Monster(int strength, int dexterity, int health, int exp, std::string special, std::string name)
            : strength(strength), dexterity(dexterity), health(health), exp(exp), special(special),name(name)
            {
                necronomicon.push_back(this);
            }
        };

        struct Water : Monster{

           static inline std::vector<std::string> weakAgainst = {"Water"};
           static inline  std::vector<std::string> strongAgainst={"Earth","Fire"};
           std::string type;

        Water(int strength, int dexterity, int health, int exp, std::string special, std::string name)
        : Monster(strength, dexterity, health, exp, special, name), type("Water")
        {


        }



        };

        struct Earth : Monster{

            static inline  std::vector<std::string> weakAgainst = {"Air"};
            static inline std::vector<std::string>  strongAgainst= {"Fire","Ice","Steel"};
            std::string type;
            Earth(int strength, int dexterity, int health, int exp, std::string special, std::string name)
                    : Monster(strength, dexterity, health, exp, special, name), type("Earth")
            {

            }

        };
        struct Air : Monster{

            static inline std::vector<std::string> weakAgainst = {"Earth","Steel"};
            static inline  std::vector<std::string> strongAgainst={"Ice"};
            std::string type;
            Air(int strength, int dexterity, int health, int exp, std::string special, std::string name)
                    : Monster(strength, dexterity, health, exp, special, name), type("Air")
            {


            }

        };

        struct Fire : Monster{

            static inline  std::vector<std::string> weakAgainst = {"Water","Earth"};
            static inline std::vector<std::string>  strongAgainst= {"Ice","Steel"};
            std::string type;

            Fire(int strength, int dexterity, int health, int exp, std::string special, std::string name)
                    : Monster(strength, dexterity, health, exp, special, name), type("Fire")
            {

            }

        };
        struct Ice : Monster{

            static inline std::vector<std::string> weakAgainst = {"Water","Fire","Ice"};
            static inline  std::vector<std::string> strongAgainst={"Earth"};
            std::string type;

            Ice(int strength, int dexterity, int health, int exp, std::string special, std::string name)
                    : Monster(strength, dexterity, health, exp, special, name), type("Ice")
            {


            }

        };

        struct Steel : Monster{

            static inline std::vector<std::string> weakAgainst = {"Fire","Steel"};
            static inline std::vector<std::string>  strongAgainst= {"Water","Air"};
            std::string type;

            Steel(int strength, int dexterity, int health, int exp, std::string special, std::string name)
                    : Monster(strength, dexterity, health, exp, special, name), type("Steel")
            {

            }

        };


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

        for(Monster* m : playerArmy)
        {
            std::cout<<m->name<<'\n';
        }
        std::cout<<'\n';
    }

        };

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

        };


int main()

{/*
 * make all structs
 * each struct has a seperate file
 *
 *
 */
    auto steel0 = Steel(1, 1, 1, 1, "Boom-stick", "Ashley Williams");
    auto water1= Water(2, 3, 4, 5, "Adam injection", "Frank Fontaine");
    auto water2= Water(2, 3, 4, 5, "Adam injection", "Frank Fontaine");
    auto water3 = Water(1, 1, 1, 1, "Rivet gun", "Big Daddy");
    auto water4 = Water(1, 1, 1, 1, "Rivet gun", "Big Daddy");
    auto earth5 = Earth(1, 1, 1, 1, "Undead Wrath", "Jason Voorhees");
    auto earth6 = Earth(1, 1, 1, 1, "Undead Wrath", "Jason Voorhees");
    auto earth7= Earth(2, 3, 4, 5, "Undying desire for vengeance", "Max Payne");
    auto earth8= Earth(2, 3, 4, 5, "Undying desire for vengeance", "Max Payne");
    auto air9 = Air(1, 1, 1, 1, "Flame Thrower", "Ellen Ripley");
    auto air10 = Air(1, 1, 1, 1, "Flame Thrower", "Ellen Ripley");
    auto air11 = Air(1, 1, 1, 1, "Rewrite destiny", "Guybrush Threepwood");
    auto air12 = Air(1, 1, 1, 1, "Rewrite destiny", "Guybrush Threepwood");
    auto fire13= Fire(2, 3, 4, 5, "Flashlight", "Alan Wake");
    auto fire14= Fire(2, 3, 4, 5, "Flashlight", "Alan Wake");
    auto fire15 = Fire(1, 1, 1, 1, "Army of Darkness", "Evil Ash");
    auto fire16 = Fire(1, 1, 1, 1, "Army of Darkness", "Evil Ash");
    auto ice17 = Ice(1, 1, 1, 1, "Tears in rain", "Roy Batty");
    auto ice18 = Ice(1, 1, 1, 1, "Tears in rain", "Roy Batty");
    auto ice19= Ice(2, 3, 4, 5, "Voight-Kampff test", "Rick Deckard");
    auto ice20= Ice(2, 3, 4, 5, "Voight-Kampff test", "Rick Deckard");
    auto steel21 = Steel(1, 1, 1, 1, "Boom-stick", "Ashley Williams");
    auto steel22 = Steel(1, 1, 1, 1, "Boom-stick", "Ashley Williams");
    auto steel23 = Steel(1, 1, 1, 1, "Camp protector", "Tommy Jarvis");
    auto steel24 = Steel(1, 1, 1, 1, "Camp protector", "Tommy Jarvis");

/*
    for(std::string m : Water::strongAgainst)
    {
            if(m == "Fire")
        std::cout << m <<" is an easy opponet for Water types" <<'\n';
    }
    */


Player me = Player();

        for(Monster* m : Monster::necronomicon)
        {
            std::cout<<m->name<<'\n';
        }

//    me.moveMonster(Monster::necronomicon, 1);
//    me.moveMonster(Monster::necronomicon, 1);
//    me.moveMonster(Monster::necronomicon, 1);
    me.chooseMonster();
    std::cout<<'\n';

    me.showPlayerArmy();

//    for(Monster* m : me.playerArmy)
//    {
//        std::cout<<m->name<<'\n';
//    }
std::cout<<'\n'<<"after selecting champs these are the contents of necronimicon:" << '/n';


    for(Monster* m : Monster::necronomicon)
    {
        std::cout<<m->name<<'\n';
    }

    std::cout<<'\n'<<"Opponents choose their monsters"<< '\n';

    Opponent hercules = Opponent("hercules");
    Opponent zeus = Opponent("zeus");
    Opponent nyx = Opponent("nyx");
    Opponent zagreus = Opponent("zagreus");

    hercules.moveMonster(Monster::necronomicon);
    std::cout<< '\n';
    hercules.showOpponentArmy();

    zeus.moveMonster(Monster::necronomicon);
    std::cout<< '\n';
    zeus.showOpponentArmy();

    nyx.moveMonster(Monster::necronomicon);
    std::cout<< '\n';
    nyx.showOpponentArmy();

    std::cout<<"does it hit here?";

    zagreus.moveMonster(Monster::necronomicon);
 //   std::cout<<"here?" <<'\n';

    zagreus.showOpponentArmy();


    std::cout<<" here is list of monsters that lef"<<'\n';
    for(Monster* m : Monster::necronomicon)
    {
        std::cout<<m->name<<'\n';
    }

   // std::cout << water1.type;
    std::cout<<" are 4 enemies present in allEnemies vector?"<<'\n';
    for(Opponent* o : Opponent::allEnemies)
    {
        std::cout<<o->name<<'\n';
    }

}
