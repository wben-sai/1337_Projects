/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:18:39 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/01 08:37:26 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
    _Hitpoints = 100;
    _EnergyPoints = 50;
    _AttackDamage = 30;
    std::cout << "FragTrap Default Constructor called" << std::endl;
    return;
}

FragTrap::FragTrap(std::string Name) : ClapTrap(Name)
{
    _Hitpoints = 100;
    _EnergyPoints = 50;
    _AttackDamage = 30;
    std::cout << "FragTrap Constructor called" << std::endl;
    return;
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src)
{
    std::cout << "FragTrap Copy constructor called" << std::endl;
    *this = src;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap Destructor called" << std::endl;
    return;
}

FragTrap& FragTrap::operator=(FragTrap const & src)
{
    this->_Name = src._Name;
    this->_Hitpoints = src._Hitpoints;
    this->_EnergyPoints = src._EnergyPoints;
    this->_AttackDamage = src._AttackDamage;
    std::cout << "FragTrap Assignation operator called" << std::endl;
    return *this;
}

void highFivesGuys(void)
{
    std::cout << "" << std::endl;
}

void FragTrap::attack(std::string const & target)
{
    std::cout << "FragTrap "<< _Name << " attack " << target << " , causing " << _AttackDamage << " points of damage!" << std::endl;
}
