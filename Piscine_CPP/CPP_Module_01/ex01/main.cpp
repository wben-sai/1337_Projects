#include "Zombie.hpp"

int main()
{
    int N = 5, i = -1;
    Zombie *zom = zombieHorde(N, "zombie");
    while(++i < N)
        zom[i].announce();
    delete[] zom;
    return (0);
}