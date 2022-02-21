/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:27:26 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/12 10:00:53 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cast.hpp"

cast::cast(void) 
{
    //std::cout << "cast Default Constructor called" << std::endl;
    return;
}

cast::cast(cast const & src) 
{
    //std::cout << "cast Copy constructor called" << std::endl;
    *this = src;
    return;
}

cast::~cast(void)
{
    //std::cout << "cast Destructor called" << std::endl;
    return;
}

cast& cast::operator=(cast const & src)
{
    //std::cout << "cast Assignation operator called" << std::endl;
    this->str = src.str;
    return *this;
}

cast::cast(std::string str)
{
    if (str.length() == 1 && !isdigit(str[0]))
        str = std::to_string((int)str[0]);
    this->str = str;
}

cast::operator int ()
{
    try
    {
        int i = std::stoi(this->str);
        std::cout << "int: " << i << '\n';
        return i;
    }
    catch(const std::exception& e)
    {
        std::cout << "int: impossible" << '\n';
    }
    return 0; 
}

cast::operator char ()
{
    try
    {
        char c = stoi(this->str);
        if(!std::isprint(c))
            std::cout << "char: Non displayable" << '\n';
        else
            std::cout << "char: '" << c << "'" << '\n';
        return c;
    }
    catch(const std::exception& e)
    {
        std::cout << "char: impossible" << '\n';
    }
    return (0); 
}

cast::operator float ()
{
    try
    {
        float i = std::stof(this->str);
        if (i != (int)i)
            std::cout << "Float: " << i << "f\n";
        else
            std::cout << "Float: " << i << ".0f\n";
        return (i);
    }
    catch(const std::exception& e)
    {
        std::cout << "float: impossible" << '\n';
    }
    return (0); 
}

cast::operator double ()
{
    try
    {
        double i = std::stod(this->str);
        std::cout << "double: " << i;
        if (i == (int)i)
            std::cout << ".0";
        std::cout << "\n";
        return (i);
    }
    catch(const std::exception& e)
    {
        std::cout << "double: impossible" << '\n';
    } 
    return (0);
}
