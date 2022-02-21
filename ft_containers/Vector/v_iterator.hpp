/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:04:18 by wben-sai          #+#    #+#             */
/*   Updated: 2021/12/11 09:41:08 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iterator>

namespace ft
{
    template <typename T>
    class v_iterator : public std::iterator<std::random_access_iterator_tag, T>
    {
        public:
            typedef ptrdiff_t                           difference_type;
            typedef T                                   value_type;
            typedef T*                                  pointer;
            typedef T&                                  reference;
            typedef std::random_access_iterator_tag		iterator_category;
            
        private :
            T *ptr;
        public :
            v_iterator(T *param):ptr(param) {}
            v_iterator(){}
            v_iterator(v_iterator<T> const & src){*this = src;}
            
            v_iterator<T>& operator=(v_iterator<T> const & src){this->ptr = src.ptr;return (*this);}
            
            operator v_iterator<const T>() 
            {
                return v_iterator<const T>(ptr);
            }
            
            reference operator*() const{return (*ptr);}
            
            v_iterator<T>& operator++(){ptr++;return (*this);}
            v_iterator<T>& operator--(){ptr--;return (*this);}
            v_iterator<T> operator++(int){v_iterator<T> temp;temp = *this;this->ptr++;return (temp);}
            v_iterator<T> operator--(int){v_iterator<T> temp;temp = *this;this->ptr--;return (temp);}

            v_iterator<T> operator+(int n)const {return(ptr + n);}
            difference_type operator-(v_iterator<T> const & src){return(this->ptr - src.ptr);}
            v_iterator<T> operator-(int n) const {return(ptr - n);}

            v_iterator<T> operator+=(int n){ptr = ptr + n;return(*this);}
            v_iterator<T> operator-=(int n){ptr = ptr - n;return(*this);}

            T& operator[](difference_type n) const{return(ptr[n]);}

            T* operator->(){return(ptr);}

            template <typename iter, typename iter2>
            friend bool operator ==(const v_iterator<iter>  &a, const v_iterator<iter2>  &b);

            template <typename iter, typename iter2>
            friend bool operator !=(const v_iterator<iter>  &a, const v_iterator<iter2>  &b);

            template <typename iter, typename iter2>
            friend bool operator <(const iter &a, const iter2 &b);

            template <typename iter, typename iter2>
            friend bool operator <=(const iter &a, const iter2 &b);

            template <typename iter, typename iter2>
            friend bool operator >(const iter &a, const iter2 &b);

            template <typename iter, typename iter2>
            friend bool operator >=(const iter &a, const iter2 &b);
    };

    template <typename T>
    v_iterator<T> operator+(int n, v_iterator<T>& a){return(a + n);}

    template <typename iter, typename iter2>
    bool operator ==(const v_iterator<iter>  &a, const v_iterator<iter2>  &b){return(a.ptr == b.ptr);}

    template <typename iter, typename iter2>
    bool operator !=(const v_iterator<iter>  &a, const v_iterator<iter2>  &b){return(a.ptr != b.ptr);}

    template <typename iter, typename iter2>
    bool operator <(const iter &a, const iter2 &b){return(a.ptr < b.ptr);}

    template <typename iter, typename iter2>
    bool operator <=(const iter &a, const iter2 &b){return(a.ptr <= b.ptr);}

    template <typename iter, typename iter2>
    bool operator >(const iter &a, const iter2 &b){return(a.ptr > b.ptr);}

    template <typename iter, typename iter2>
    bool operator >=(const iter &a, const iter2 &b){return(a.ptr >= b.ptr);}
}
