/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:14:06 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/14 11:01:50 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
#define WHATEVER_H

#include <iostream>

template <typename T>
T max(T x, T y)
{
    return(x>=y ? x: y);
}

template <typename T>
T min(T x, T y)
{
    return(x<=y ? x: y);
}

template <typename T>
void  swap(T & x, T & y){
    T temp;
    temp = x;
    x = y;
    y = temp;
}

#endif