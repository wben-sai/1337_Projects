/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:36:44 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/01 08:51:08 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main( void ) {

    FragTrap Scav;
    FragTrap Scav2("Name");
    
    Scav.attack("Name");
    
    FragTrap Scav3(Scav2);
    highFivesGuys();
    return 0;
}
