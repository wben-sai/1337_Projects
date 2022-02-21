/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 09:26:38 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/02 12:41:48 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
    std::cout << "Animal Default Constructor called" << std::endl;
    return;
}

Animal::Animal(Animal const & src)
{
    std::cout << "Animal Copy constructor called" << std::endl;
    *this = src;
    return;
}

Animal::~Animal(void)
{
    std::cout << "Animal Destructor called" << std::endl;
    return;
}

Animal& Animal::operator=(Animal const & src)
{
    std::cout << "Animal Assignation operator called" << std::endl;
    this->type = src.type;
    return *this;
}

Animal::Animal(std::string type) :type(type)
{
    std::cout << "Animal Constructor called" << std::endl;
    return;
}

void Animal::makeSound() const
{
    std::cout << "Animal Sound" << std::endl;
}

std::string Animal::getType() const
{
    return(type);
}