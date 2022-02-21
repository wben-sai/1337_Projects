/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 14:49:57 by wben-sai          #+#    #+#             */
/*   Updated: 2021/09/26 13:23:22 by wben-sai         ###   ########.fr       */
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
        
        //ex02
        Fixed operator+(const Fixed &b) const;
        Fixed operator-(const Fixed &b) const;
        Fixed operator*(const Fixed &b) const;
        Fixed operator/(const Fixed &b) const;

        Fixed& operator++();
        Fixed& operator--();
        Fixed operator++(int);
        Fixed operator--(int);

        static Fixed& min(Fixed &a, Fixed &b);
        static const Fixed& min(Fixed const &a, Fixed const &b);
        static Fixed& max(Fixed &a, Fixed &b);
        static const Fixed& max(Fixed const &a, Fixed const &b);


        
    private:
        int _FixedPoint;
        static const int _NbrFra = 8;
};

//ex00
std::ostream & operator<<(std::ostream & o ,Fixed const & src);

//ex02
bool operator>(Fixed const &a, Fixed const &b);
bool operator<(Fixed const &a, Fixed const &b);
bool operator>=(Fixed const &a, Fixed const &b);
bool operator<=(Fixed const &a, Fixed const &b);
bool operator==(Fixed const &a, Fixed const &b);
bool operator!=(Fixed const &a, Fixed const &b);
        

#endif