/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 08:49:58 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/01 08:53:58 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
    _Name = "unknown";
    ClapTrap::_Name += "_clap_name";
    _Hitpoints = FragTrap::_Hitpoints;
    _EnergyPoints = ScavTrap::_EnergyPoints;
    _AttackDamage = FragTrap::_AttackDamage;
    std::cout << "DiamondTrap Default Constructor called" << std::endl;
    return;
}

DiamondTrap::DiamondTrap(std::string Name) : ClapTrap(Name + "_clap_name"), ScavTrap(Name), FragTrap(Name)
{
    _Name = Name;
    _Hitpoints = FragTrap::_Hitpoints;
    _EnergyPoints = ScavTrap::_EnergyPoints;
    _AttackDamage = FragTrap::_AttackDamage;
    std::cout << "DiamondTrap Constructor called" << std::endl;
    return;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src)
{
    std::cout << "DiamondTrap Copy constructor called" << std::endl;
    *this = src;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap Destructor called" << std::endl;
    return;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const & src)
{
    this->_Name = src._Name;
    this->_Hitpoints = src._Hitpoints;
    this->_EnergyPoints = src._EnergyPoints;
    this->_AttackDamage = src._AttackDamage;
    std::cout << "FragTrap Assignation operator called" << std::endl;
    return *this;
}

void DiamondTrap::PrintDiamondTrap()
{
    std::cout << "NAME " << _Name << "\n _Hitpoints " << _Hitpoints <<"\n _EnergyPoints " << _EnergyPoints << "\n _AttackDamage " << _AttackDamage <<std::endl;
}

void DiamondTrap::attack(std::string const & target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "NAME :" << _Name << " clapTrap name :" << ClapTrap::_Name << std::endl;
}