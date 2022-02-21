/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:17:11 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/02 12:36:14 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
    std::cout << "Dog Default Constructor called" << std::endl;
    return;
}

Dog::Dog(Dog const & src)
{
    std::cout << "Dog Copy constructor called" << std::endl;
    *this = src;
    return;
}

Dog::~Dog(void)
{
    std::cout << "Dog Destructor called" << std::endl;
    return;
}

Dog& Dog::operator=(Dog const & src)
{
    std::cout << "Dog Assignation operator called" << std::endl;
    this->type = src.type;
    return *this;
}

void Dog::makeSound() const
{ 
    std::cout << "Dog Sound" << std::endl;
}
