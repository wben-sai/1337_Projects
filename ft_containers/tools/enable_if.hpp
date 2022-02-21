/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:14:51 by wben-sai          #+#    #+#             */
/*   Updated: 2022/01/04 13:23:48 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
    template <bool Cond, class T = void> 
    struct enable_if{
    };

    template<class T>
    struct enable_if<true, T> {
        typedef T type;
    };
}
