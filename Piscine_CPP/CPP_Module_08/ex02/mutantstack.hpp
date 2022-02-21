/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 11:49:08 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/16 18:27:38 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <iostream>
#include <stack>


template <typename T>
class MutantStack : public std::stack<T>
{
    private:
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;
        MutantStack();
        ~MutantStack();
        MutantStack(MutantStack<T> const & src);
        MutantStack<T>& operator=(MutantStack<T> const & src);
        iterator begin();
        iterator end();
};

#endif