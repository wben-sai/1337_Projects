/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:26:31 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/05 08:36:01 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
    std::cout << "Cat Default Constructor called" << std::endl;
    this->brain =new Brain();
    return;
}

Cat::Cat(Cat const & src)
{
    std::cout << "Cat Copy constructor called" << std::endl;
    *this = src;
    return;
}

Cat::~Cat(void)
{
    std::cout << "Cat Destructor called" << std::endl;
    delete brain;
    return;
}

Cat& Cat::operator=(Cat const & src)
{
    std::cout << "Cat Assignation operator called" << std::endl;
    this->type = src.type;
    this->brain = new Brain(*src.brain);
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Cat Sound" << std::endl;
}

Brain *Cat::printBrain()
{
    return (this->brain);
}