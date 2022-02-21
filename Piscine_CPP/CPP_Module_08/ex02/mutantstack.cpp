/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:08:34 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/16 18:27:45 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

template <typename T>
MutantStack<T>::MutantStack()
{
    return;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
    return;
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack<T> const & src)
{
    *this = src;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(MutantStack<T> const & src)
{
    (void)src;
    return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return (this->c.end());
}