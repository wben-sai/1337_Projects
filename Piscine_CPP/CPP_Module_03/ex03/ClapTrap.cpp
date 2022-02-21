/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 08:59:59 by wben-sai          #+#    #+#             */
/*   Updated: 2021/09/27 13:15:07 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _Name("unknown"), _Hitpoints(10), _EnergyPoints(10), _AttackDamage(0)
{
    std::cout << "ClapTrap Default Constructor called" << std::endl;
    return;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    *this = src;
    return;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap Destructor called" << std::endl;
    return;
}

ClapTrap& ClapTrap::operator=(ClapTrap const & src)
{
    std::cout << "ClapTrap Assignation operator called" << std::endl;
    this->_Name = src._Name;
    this->_Hitpoints = src._Hitpoints;
    this->_EnergyPoints = src._EnergyPoints;
    this->_AttackDamage = src._AttackDamage;
    return *this;
}

ClapTrap::ClapTrap(std::string Name) : _Name(Name), _Hitpoints(10), _EnergyPoints(10), _AttackDamage(0)
{
    std::cout << "ClapTrap Constructor called" << std::endl;
    return;
}

void ClapTrap::attack(std::string const & target)
{
    std::cout << "ClapTrap "<< _Name << " attack " << target << " , causing " << _AttackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap "<< _Name << " takeDamage " << amount << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << "ClapTrap "<< _Name << " beRepaired " << amount << std::endl;
}
