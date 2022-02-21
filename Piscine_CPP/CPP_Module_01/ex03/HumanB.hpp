#include <string>
#include <iostream>
#include "Weapon.hpp"

#ifndef HUMANB__H
#define HUMANB__H

class HumanB
{
    public :
        void attack();
        HumanB(std::string name);
        void setWeapon(Weapon &weapon);
    private:
        std::string _name;
        Weapon *_weapon;
};

#endif