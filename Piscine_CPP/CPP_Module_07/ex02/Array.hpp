/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:44:10 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/14 12:57:45 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template <typename T>
class Array
{
    public :
        Array()
        {
           _array = NULL;
           _size = 0;
        }

        ~Array()
        {}
        
        Array(unsigned int n)
        {
            _size = n;
            _array = new T[_size];
        }
        
        Array(Array const & src)
        {
            *this = src;
        }
        
        Array& operator=(Array const & src)
        {
            unsigned int i = 0;
            this->_size = src._size;
            this->_array = new T[src._size];
            while(i < src._size)
            {
                this->_array[i] = src._array[i];
                i++;
            }
            return *this;
        }

        T &operator [](size_t n)
        {
            if(n >= this->_size)
                throw std::exception();
            return(this->_array[n]);
        }
        
        int size()
        {
            return (this->_size);
        }
        
    private:
        unsigned int _size;
	    T *_array;
    
};


#endif