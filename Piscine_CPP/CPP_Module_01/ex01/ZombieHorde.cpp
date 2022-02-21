#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name)
{
    int i = -1;
    Zombie* zom = new Zombie[N];
    while(++i < N)
        zom[i].setter(name);
    return(zom);
}