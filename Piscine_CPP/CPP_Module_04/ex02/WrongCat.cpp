/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:26:31 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/02 17:29:21 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("Cat")
{
    std::cout << "WrongCat Default Constructor called" << std::endl;
    return;
}

WrongCat::WrongCat(WrongCat const & src)
{
    std::cout << "WrongCat Copy constructor called" << std::endl;
    *this = src;
    return;
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat Destructor called" << std::endl;
    return;
}

WrongCat& WrongCat::operator=(WrongCat const & src)
{
    std::cout << "WrongCat Assignation operator called" << std::endl;
    this->type = src.type;
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat Sound" << std::endl;
}