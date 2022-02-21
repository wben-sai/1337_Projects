#include "Zombie.hpp"

void Zombie::announce( void )
{
    std::cout << _name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie( void )
{
    std::cout << "destructor " << _name << std::endl;
}

Zombie::Zombie(std::string name)
{
    _name = name;
}

Zombie::Zombie()
{
}

void Zombie::setter(std::string name)
{
    _name = name;
}

std::string Zombie::getter()
{
    return (_name);
}
