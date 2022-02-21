/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:36:44 by wben-sai          #+#    #+#             */
/*   Updated: 2021/09/27 12:07:05 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void ) {
    ClapTrap calp("ClapTrap");
    ClapTrap calp2("ClapTrap2");

    calp.attack("ClapTrap2");
    calp.takeDamage(5);
    calp.beRepaired(3);

    calp2.attack("ClapTrap");
    calp2.takeDamage(7);
    calp2.beRepaired(2);
    return 0;
}
