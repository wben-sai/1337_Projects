/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:56:47 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/16 08:49:13 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
#define EASYFIND_H

#include <iostream>
#include <array>
#include <vector>

template <typename T>
int easyfind(T a, int b)
{
    int res = *std::find(a.begin(), a.end(), b);
    if(res == b)
        return (res);
    else
        throw new std::exception();
}

#endif