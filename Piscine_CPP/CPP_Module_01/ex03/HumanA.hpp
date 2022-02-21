#include <string>
#include <iostream>
#include "Weapon.hpp"

#ifndef HUMANA__H
#define HUMANA__H

class HumanA
{
    public :
        void attack();
        HumanA(std::string name, Weapon &weapon);
    private:
        std::string _name;
        Weapon *_weapon;
};

#endif