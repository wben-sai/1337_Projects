#include <string>
#include <iostream>

#ifndef WEAPON__H
#define WEAPON__H

class Weapon
{
    public :
        std::string const& getType(void);
        void setType(std::string type);
        Weapon(std::string type);
        Weapon(void);
    private:
        std::string _type;
};

#endif