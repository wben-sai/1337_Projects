/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:09:48 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/01 08:33:37 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

#ifndef SCAVTRAP__H
#define SCAVTRAP__H

class ScavTrap : virtual public ClapTrap
{
    public :
        ScavTrap(void);
        ScavTrap(ScavTrap const & src);
        ~ScavTrap(void);
        ScavTrap& operator=(ScavTrap const & src);
        ScavTrap(std::string Name);

        void attack(std::string const & target);
        
    private:
        
};

void guardGate(); 

#endif