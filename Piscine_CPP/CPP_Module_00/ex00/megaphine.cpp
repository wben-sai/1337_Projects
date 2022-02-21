#include <iostream>

std::string toupper_string(std::string s)
{
    int i = 0;
    int len = s.length();
    std::string str = "";

    while(i < len)
    {
        str += toupper(s[i]);
        i++;
    }
    return(str);
}

int main(int ac, char **av)
{
    int i = 1;
    
    if (ac == 1)
        std::cout << "* LOUD ANND UNBERABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        while (i < ac)
        {
            std::cout << toupper_string(av[i]);
            if(i != ac -1)
                std::cout << " ";
            i++;
        }
    }
    return 0;
}