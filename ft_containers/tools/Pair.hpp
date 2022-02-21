/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 10:10:11 by wben-sai          #+#    #+#             */
/*   Updated: 2021/12/19 14:01:39 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PAIR_H
#define _PAIR_H

    namespace ft
    { 
        template <class T1, class T2>
        struct pair
        {
            typedef T1      first_type;
            typedef T2      second_type;

            first_type      first;
            second_type     second;

            pair(){}
            pair (const first_type& a, const second_type& b) : first(a) , second(b){}
            
            template<class U, class V>
            pair (const pair<U, V> &pr) : first(pr.first){second = pr.second;}
            
            pair& operator= (const pair& pr)
            {
                this->first = pr.first;
                this->second = pr.second;
                return (*this);
            }
        };
        
        template <class T1, class T2>
        bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
        { return lhs.first==rhs.first && lhs.second==rhs.second; }

        template <class T1, class T2>
        bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
        { return !(lhs==rhs); }

        template <class T1, class T2>
        bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
        { return lhs.first < rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

        template <class T1, class T2>
        bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
        { return !(rhs<lhs); }

        template <class T1, class T2>
        bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
        { return rhs<lhs; }

        template <class T1, class T2>
        bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
        { return !(lhs<rhs); }
    }
#endif