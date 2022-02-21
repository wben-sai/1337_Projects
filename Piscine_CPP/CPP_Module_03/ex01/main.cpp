/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:36:44 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/01 08:48:06 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main( void ) {

    ScavTrap Scav;
    ScavTrap Scav2("Name");
    
    Scav.attack("Name");
    
    ScavTrap Scav3(Scav2);
    
    guardGate();
    return 0;
}
