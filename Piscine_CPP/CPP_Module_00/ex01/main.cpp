#include "phonebook.hpp"

int main()
{
    std::string str;
    std::string str2;
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
    
    Phonebook book[8];
    int size = 0;
    int i = 0;
    int nbr = -1;
    while(1)
    {
        std::cout << "-------------------------------------------" << std::endl;
        std::cout << "-------------|     ADD       |-------------" << std::endl;
        std::cout << "-------------|    SEARCH     |-------------" << std::endl;
        std::cout << "-------------|     EXIT      |-------------" << std::endl;
        std::cout << "-------------------------------------------" << std::endl;
        getline(std::cin, str);
        if (str == "ADD")
        {
            if(size < 8)
            {
                std::cout << "-------------------------------------------" << std::endl;
                std::cout << "First Name" << std::endl;
                getline(std::cin, first_name);
                std::cout << "Last Name" << std::endl;
                getline(std::cin, last_name);
                std::cout << "Nickname" << std::endl;
                getline(std::cin, nickname);
                std::cout << "Phone Number" << std::endl;
                getline(std::cin, phone_number);
                std::cout << "Darkest Secret" << std::endl;
                getline(std::cin, darkest_secret);
                book[size].set_param(first_name, last_name, nickname, phone_number,darkest_secret);
                size++;
            }
            else
                std::cout << "List is full" << std::endl;
        } 
        else if (str == "SEARCH" && size != 0)
        {
            i = 0;
            std::cout << "  index   |first name| last name| nickname |" << std::endl;
            while (i < size)
            {
                std::cout << "    " << i + 1 << "     |";
                book[i].search();
                i++;
            }
            getline(std::cin, str2);
            nbr = atoi(str2.c_str());
            if(nbr <= size && nbr > 0)
                book[nbr - 1].print_search();
            else
                std::cout << "This number is incorrect" << std::endl;
        }
        else if (str == "EXIT")
            break;
    }
    return 0;
}