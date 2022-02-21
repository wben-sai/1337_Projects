/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:05:05 by wben-sai          #+#    #+#             */
/*   Updated: 2021/12/23 14:00:42 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iterators_traits.hpp"

namespace ft
{
    template <typename Iterator> 
    class reverse_iterator
    {
        public : 
            typedef Iterator                                                iterator_type;
            typedef typename iterator_traits<Iterator>::iterator_category   iterator_category;
            typedef typename iterator_traits<Iterator>::value_type          value_type;
            typedef typename iterator_traits<Iterator>::difference_type     difference_type;
            typedef typename iterator_traits<Iterator>::pointer             pointer;
            typedef typename iterator_traits<Iterator>::reference           reference;
        
        private :
            Iterator ptr;
        public :
            reverse_iterator(){};
            explicit reverse_iterator (iterator_type it): ptr(it){}
            template <class Iter>
            reverse_iterator (const reverse_iterator<Iter>& rev_it){ptr = rev_it.base();}
            reverse_iterator& operator=(reverse_iterator const & src){this->ptr = src.ptr;return (*this);}

            iterator_type base() const{return (ptr);}

            reference operator*()  const
            {
                iterator_type it(ptr);
                return (*(--it));
            }

            reference operator*()
            {
                iterator_type it(ptr);
                return (*(--it));
            }

            //operator reverse_iterator<const iterator_type >() 
            //{
            //    return reverse_iterator<const iterator_type >(ptr);
            //}
            
            reverse_iterator& operator--(){ptr++;return(*this);}
            
            reverse_iterator  operator--(int){reverse_iterator temp(ptr);ptr++;return(temp);}
            
            reverse_iterator& operator++(){ptr--;return(*this);}
            
            reverse_iterator  operator++(int){reverse_iterator temp(ptr);ptr--;return(temp);}

            reverse_iterator operator+ (difference_type n) const{reverse_iterator temp(ptr - n);return(temp);}

            reverse_iterator operator- (difference_type n) const{reverse_iterator temp(ptr + n);return(temp);}

            reverse_iterator& operator+= (difference_type n){*this = *this + n; return(*this);}

            reverse_iterator& operator-= (difference_type n){*this = *this - n; return(*this);}

            reference operator[] (difference_type n) const{iterator_type it= (ptr - n - 1);return (*it);}
            
            pointer operator->() const{return &(operator*());}
            pointer operator->() {return &(operator*());}
            
    };

    template< class Iterator1, class Iterator2 >
    bool operator==( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
    {
        return(rhs.base() == lhs.base());
    }

    template< class Iterator1, class Iterator2 >
    bool operator!=( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
    {
        return(rhs.base() != lhs.base());
    }

    template< class Iterator1, class Iterator2 >
    bool operator>( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
    {
        return(rhs.base() > lhs.base());
    }

    template< class Iterator1, class Iterator2 >
    bool operator>=( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
    {
        return(rhs.base() >= lhs.base());
    }

    template< class Iterator1, class Iterator2 >
    bool operator <( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
    {
        return(rhs.base() < lhs.base());
    }
    
    template< class Iterator1, class Iterator2 >
    bool operator <=( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
    {
        return(rhs.base() <= lhs.base());
    }

    template <class Iterator>
    reverse_iterator<Iterator> operator+ ( typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
    {
        return(rev_it + n);
    }

    template <class OIterator>
    typename reverse_iterator<OIterator>::difference_type operator- (const reverse_iterator<OIterator>& lhs, const reverse_iterator<OIterator>& rhs)
    {
        return(rhs.base() - lhs.base());
    }
}
