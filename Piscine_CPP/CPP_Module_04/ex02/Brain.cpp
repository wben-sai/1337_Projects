/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 14:54:57 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/03 15:21:47 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain Default Constructor called" << std::endl;
    return;
}

Brain::Brain(Brain const & src)
{
    std::cout << "Brain Copy constructor called" << std::endl;
    *this = src;
    return;
}

Brain::~Brain(void)
{
    std::cout << "Brain Destructor called" << std::endl;
    return;
}

Brain& Brain::operator=(Brain const & src)
{
    int i = -1;
    std::cout << "Brain Assignation operator called" << std::endl;
    while(++i < 100)
        this->ideas[i] = src.ideas[i];
    return *this;
}