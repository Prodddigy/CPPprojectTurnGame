#include <iostream>
#include <vector>

/**
 * stuff
 */
        struct monster{
            int strength;
            int dexterity;
            int health;
            int exp;
            std::string special;
            std::string name;
            static inline std::vector<monster*> necronomicon;

             monster(int strength, int dexterity, int health, int exp, std::string special,std::string name)
            : strength(strength), dexterity(dexterity), health(health), exp(exp), special(special),name(name)
            {
                necronomicon.push_back(this);
            }
        };

        struct water : monster{

           static inline std::vector<std::string> weakAgainst = {"water"};
           static inline  std::vector<std::string> strongAgainst={"earth","fire"};
           std::string type;

        water(int strength, int dexterity, int health, int exp, std::string special,std::string name)
        : monster(strength, dexterity, health, exp, special,name),type("water")
        {


        }



        };

        struct earth : monster{

            static inline  std::vector<std::string> weakAgainst = {"air"};
            static inline std::vector<std::string>  strongAgainst= {"fire","ice","steel"};
            std::string type;
            earth(int strength, int dexterity, int health, int exp, std::string special,std::string name)
                    : monster(strength, dexterity, health, exp, special,name),type("earth")
            {

            }

        };
        struct air : monster{

            static inline std::vector<std::string> weakAgainst = {"earth","steel"};
            static inline  std::vector<std::string> strongAgainst={"ice"};
            std::string type;
            air(int strength, int dexterity, int health, int exp, std::string special,std::string name)
                    : monster(strength, dexterity, health, exp, special,name), type("air")
            {


            }

        };

        struct fire : monster{

            static inline  std::vector<std::string> weakAgainst = {"water","earth"};
            static inline std::vector<std::string>  strongAgainst= {"ice","steel"};
            std::string type;

            fire(int strength, int dexterity, int health, int exp, std::string special,std::string name)
                    : monster(strength, dexterity, health, exp, special,name), type("fire")
            {

            }

        };
        struct ice : monster{

            static inline std::vector<std::string> weakAgainst = {"water","fire","ice"};
            static inline  std::vector<std::string> strongAgainst={"earth"};
            std::string type;

            ice(int strength, int dexterity, int health, int exp, std::string special,std::string name)
                    : monster(strength, dexterity, health, exp, special,name), type("ice")
            {


            }

        };

        struct steel : monster{

            static inline std::vector<std::string> weakAgainst = {"fire","steel"};
            static inline std::vector<std::string>  strongAgainst= {"water","air"};
            std::string type;

            steel(int strength, int dexterity, int health, int exp, std::string special,std::string name)
                    : monster(strength, dexterity, health, exp, special,name), type("steel")
            {

            }

        };


        struct player {

            std::vector<monster*> playerArmy;

        int round;
        player()
        {

        }

        void moveMonster(std::vector<monster*> &monsters, int beastIndex )
        {


            playerArmy.push_back(monsters[beastIndex]);
            monsters.erase(monsters.begin()+beastIndex);

            std::cout << "here";
            for(monster* m : monster::necronomicon)
            {
                std::cout<<m->name<<'\n';
            }

    }

    void chooseMonster()
    {
            for(int i=0 ; i<6; i++) {
                for(monster* m : monster::necronomicon)
                {
                    std::cout<<m->name<<'\n';
                }
                int input;
                std::cin >> input;
                moveMonster(monster::necronomicon, input);
            }
    }

    void showPlayerArmy()
    {

        for(monster* m : playerArmy)
        {
            std::cout<<m->name<<'\n';
        }
        std::cout<<'\n';
    }

        };


int main()
{

    water water1= water(2,3,4,5,"water","water1");
    water water2 = water(1,1,1,1,"hi","water2");
    earth earth1 = earth(1,1,1,1,"hi1","earth1");
    earth earth2= earth(2,3,4,5,"water","earth2");
    air air1 = air(1,1,1,1,"hi","air1");
    air air2 = air(1,1,1,1,"hi1","air2");
    fire fire1= fire(2,3,4,5,"water","fire1");
   fire fire2 = fire(1,1,1,1,"hi","fire2");
    auto ice1 = ice(1,1,1,1,"hi1","ice1");
  auto ice2= ice(2,3,4,5,"water","ice2");
   auto steel1 = steel(1,1,1,1,"hi","steel1");
    auto steel2 = steel(1,1,1,1,"hi1","steel2");
/*
    for(std::string m : water::strongAgainst)
    {
            if(m == "fire")
        std::cout << m <<" is an easy opponet for water types" <<'\n';
    }
    */


player me = player();

        for(monster* m : monster::necronomicon)
        {
            std::cout<<m->name<<'\n';
        }

    me.moveMonster(monster::necronomicon, 1);


    std::cout<<'\n';

    for(monster* m : me.playerArmy)
    {
        std::cout<<m->name<<'\n';
    }
std::cout<<'\n';

    for(monster* m : monster::necronomicon)
    {
        std::cout<<m->name<<'\n';
    }


   // std::cout << water1.type;


}
