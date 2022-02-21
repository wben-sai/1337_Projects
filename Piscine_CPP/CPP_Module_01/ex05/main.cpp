#include "Karen.hpp"

int main(int ac, char **av)
{
    if(ac != 2)
        return(1);
    std::string str = av[1];
    Karen ka;
    ka.complain(str);
    return(0);
}