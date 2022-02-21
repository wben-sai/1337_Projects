/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 14:49:57 by wben-sai          #+#    #+#             */
/*   Updated: 2021/09/27 08:29:45 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cmath>

#ifndef FIXED__H
#define FIXED__H

class Fixed
{
    public :
        //ex00
        Fixed(void);
        Fixed(Fixed const & src);
        ~Fixed(void);
        Fixed& operator=(Fixed const & src);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        
        //ex01
        Fixed(int const src);
        Fixed(float const src);
        float toFloat(void) const; 
        int toInt(void) const;
        
    private:
        int _FixedPoint;
        static const int _NbrFra = 8;
};

std::ostream & operator<<(std::ostream & o ,Fixed const & src);

#endif