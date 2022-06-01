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
            static inline std::vector<monster> necronomicon;


             monster(int strength, int dexterity, int health, int exp, std::string special,std::string name)
            : strength(strength), dexterity(dexterity), health(health), exp(exp), special(special),name(name)
            {
                necronomicon.push_back(*this);
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

            fire(int strength, int dexterity, int health, int exp, std::string special,std::string)
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


int main()
{

    auto water1= water(2,3,4,5,"water","watermox");
    auto water2 = water(1,1,1,1,"hi","mons");
    auto earth1 = earth(1,1,1,1,"hi1","mons1");
    auto earth2= earth(2,3,4,5,"water","watermox");
    auto air1 = air(1,1,1,1,"hi","mons");
    auto air2 = air(1,1,1,1,"hi1","mons1");
    auto fire1= fire(2,3,4,5,"water","watermox");
   // auto fire2 = fire(1,1,1,1,"hi","mons"); //here it breaks
//    auto ice1 = ice(1,1,1,1,"hi1","mons1");
//    auto ice2= ice(2,3,4,5,"water","watermox");
//    auto steel1 = steel(1,1,1,1,"hi","mons");
//    auto steel2 = steel(1,1,1,1,"hi1","mons1");
/*
    for(std::string m : water::strongAgainst)
    {
            if(m == "fire")
        std::cout << m <<" is an easy opponet for water types" <<'\n';
    }
    */



   // std::cout << water1.type;


}
