

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

            static inline std::vector<monster> necronomicon;


             monster(int strength, int dexterity, int health, int exp, std::string special)
            : strength(strength), dexterity(dexterity), health(health), exp(exp), special(special)
            {
                necronomicon.push_back(*this);
            }
        };

        struct water : monster{

            std::vector<std::string> weakAgainst = {"water"};
            std::vector<std::string> strongAgainst={"earth","fire"};

        water(int strength, int dexterity, int health, int exp, std::string special)
        : monster(strength, dexterity, health, exp, special)
        {


        }

        };

struct earth : monster{

    std::vector<std::string> weakAgainst = {"air"};
    std::vector<std::string>  strongAgainst= {"fire","ice","steel"};

    earth(int strength, int dexterity, int health, int exp, std::string special)
            : monster(strength, dexterity, health, exp, special)
    {

    }

};


int main()

{
auto mons = earth(1,1,1,1,"hi");
    auto mons1 = earth(1,1,1,1,"hi");

    


}
