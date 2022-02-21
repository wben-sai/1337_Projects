/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 08:58:34 by wben-sai          #+#    #+#             */
/*   Updated: 2021/09/27 12:22:24 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#ifndef CLAPTRAP__H
#define CLAPTRAP__H

class ClapTrap
{
    public :
        ClapTrap(void);
        ClapTrap(ClapTrap const & src);
        ~ClapTrap(void);
        ClapTrap& operator=(ClapTrap const & src);
        
        ClapTrap(std::string Name);
        void attack(std::string const & target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        
    protected :
        std::string _Name;
        int _Hitpoints;
        int _EnergyPoints;
        int _AttackDamage;
};

#endif