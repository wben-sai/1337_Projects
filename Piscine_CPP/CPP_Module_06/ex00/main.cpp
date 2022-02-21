/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 10:35:29 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/11 11:42:59 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cast.hpp"

int main(int ac, char **av)
{
    if(ac != 2)
        return (0);
    cast obj(av[1]);
    (void)static_cast<char> (obj);
    (void)static_cast<int> (obj);
    (void)static_cast<float> (obj);
    (void)static_cast<double> (obj);
    return (0);
}