
#include "Weapon.hpp"

std::string const& Weapon::getType(void)
{
    return(_type);
}

void Weapon::setType(std::string type)
{
    _type = type;
}

Weapon::Weapon(void){}

Weapon::Weapon(std::string type)
{
    _type = type;
}
