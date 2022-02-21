/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 09:26:38 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/02 14:15:03 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
    std::cout << "WrongAnimal Default Constructor called" << std::endl;
    return;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
    std::cout << "WrongAnimal Copy constructor called" << std::endl;
    *this = src;
    return;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal Destructor called" << std::endl;
    return;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const & src)
{
    std::cout << "WrongAnimal Assignation operator called" << std::endl;
    this->type = src.type;
    return *this;
}

WrongAnimal::WrongAnimal(std::string type) :type(type)
{
    std::cout << "WrongAnimal Constructor called" << std::endl;
    return;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal Sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return(type);
}