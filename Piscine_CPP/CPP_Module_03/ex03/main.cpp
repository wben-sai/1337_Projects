/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:36:44 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/01 08:56:18 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main( void ) {

    DiamondTrap Scav("DiamondTrap");
    //Scav.PrintDiamondTrap();
    Scav.attack("DiamondTrap");
    Scav.whoAmI();
    return 0;
}
