#include <iostream>
#include <string.h>

#ifndef PHONEBOOK__H
#define PHONEBOOK__H

class Phonebook
{
    private:
        std::string _first_name;
        std::string _last_name;
        std::string _nickname;
        std::string _phone_number;
        std::string _darkest_secret;
        void _print_element(std::string str);
    public :
        void set_param(std::string fn, std::string ln, std::string nk, std::string pn, std::string ds);
        void search();
        void print_search();
};

#endif
