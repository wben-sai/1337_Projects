/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:14:44 by wben-sai          #+#    #+#             */
/*   Updated: 2021/09/28 11:20:48 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
    _Hitpoints = 100;
    _EnergyPoints = 50;
    _AttackDamage = 20;
    std::cout << "ScavTrap Default Constructor called" << std::endl;
    return;
}

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name)
{
    _Hitpoints = 100;
    _EnergyPoints = 50;
    _AttackDamage = 20;
    std::cout << "ScavTrap Constructor called" << std::endl;
    return;
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src)
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
    *this = src;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap Destructor called" << std::endl;
    return;
}

ScavTrap& ScavTrap::operator=(ScavTrap const & src)
{
    this->_Name = src._Name;
    this->_Hitpoints = src._Hitpoints;
    this->_EnergyPoints = src._EnergyPoints;
    this->_AttackDamage = src._AttackDamage;
    std::cout << "ScavTrap Assignation operator called" << std::endl;
    return *this;
}

void guardGate()
{
    std::cout << "ScavTrap have enterred in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(std::string const & target)
{
    std::cout << "ScavTrap "<< _Name << " attack " << target << " , causing " << _AttackDamage << " points of damage!" << std::endl;
}
