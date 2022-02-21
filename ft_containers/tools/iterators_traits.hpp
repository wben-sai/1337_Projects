/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators_traits.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:57:17 by wben-sai          #+#    #+#             */
/*   Updated: 2022/01/04 13:08:18 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

namespace ft
{
    template <class Iterator> 
    class iterator_traits
    {
        public:
            typedef typename Iterator::difference_type      difference_type;
            typedef typename Iterator::value_type           value_type;
            typedef typename Iterator::pointer              pointer;
            typedef typename Iterator::reference	        reference;
            typedef typename Iterator::iterator_category	iterator_category;
    };

    template <class T> 
    class iterator_traits<T*>
    {
        public:
            typedef  ptrdiff_t                          difference_type;
            typedef  T                                  value_type;
            typedef  T*                                 pointer;
            typedef  T&                                 reference;
            typedef  std::random_access_iterator_tag	iterator_category;
    };


    template <class T> 
    class iterator_traits<const T*>
    {
        public:
            typedef ptrdiff_t                           difference_type;
            typedef T                                   value_type;
            typedef const T*                            pointer;
            typedef const T&                            reference;
            typedef std::random_access_iterator_tag		iterator_category;
    };
}
