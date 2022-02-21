/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 08:40:21 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/01 08:25:31 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

#ifndef DIAMONDTRAP__H
#define DIAMONDTRAP__H

class DiamondTrap : public ScavTrap , public FragTrap
{
    public :
        DiamondTrap(void);
        DiamondTrap(DiamondTrap const & src);
        ~DiamondTrap(void);
        DiamondTrap& operator=(DiamondTrap const & src);
        DiamondTrap(std::string Name);
        
        void attack(std::string const & target);
        void whoAmI(); 
        void PrintDiamondTrap();
    private:
        std::string _Name;
        
};



#endif
