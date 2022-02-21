/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:10:21 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/01 08:36:07 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

#ifndef FRAGTRAP__H
#define FRAGTRAP__H

class FragTrap : public ClapTrap
{
    public :
        FragTrap(void);
        FragTrap(FragTrap const & src);
        ~FragTrap(void);
        FragTrap& operator=(FragTrap const & src);
        FragTrap(std::string Name);
        
        void attack(std::string const & target);
    private:
    
};

void highFivesGuys(void);

#endif