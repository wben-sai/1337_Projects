#include "phonebook.hpp"

void Phonebook::set_param(std::string fn, std::string ln, std::string nk, std::string pn, std::string ds)
{
    _first_name = fn;
    _last_name = ln;
    _nickname = nk;
    _phone_number = pn;
    _darkest_secret = ds;
}

void Phonebook::_print_element(std::string str)
{
    int i;

    i = 0;
    if (str.length() > 10)
    {
        while(i < 9)
            std::cout << str[i++];
        std::cout << ".|";
    }
    else
    {
        std::cout << str;
        i = 10 - str.length();
        while(i-- > 0)
            std::cout << " ";
         std::cout << "|";
    }
}

void Phonebook::print_search(){
    std::cout << "first_name : " << _first_name << std::endl;
    std::cout << "last_name : " << _last_name << std::endl;
    std::cout << "nickname : " << _nickname << std::endl;
    std::cout << "phone_number : " << _phone_number << std::endl;
    std::cout << "darkest_secret : " << _darkest_secret << std::endl;
}

void Phonebook::search()
{
    _print_element(_first_name);
    _print_element(_last_name);
    _print_element(_nickname);
    std::cout << std::endl;
}
