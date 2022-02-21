/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 14:49:33 by wben-sai          #+#    #+#             */
/*   Updated: 2021/09/27 08:29:30 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _FixedPoint(0)
{
    std::cout << "Default Constructor called" << std::endl;
    return;
}

Fixed::Fixed(Fixed const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
    return;
}

Fixed& Fixed::operator=(Fixed const & src)
{
    std::cout << "Assignation operator called" << std::endl;
    this->_FixedPoint = src.getRawBits();
    return *this;
}

int Fixed::getRawBits( void ) const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return(_FixedPoint);
}

void Fixed::setRawBits( int const raw )
{
    _FixedPoint = raw;
}

//ex01

Fixed::Fixed(int const src)
{
    _FixedPoint = src * (1 << _NbrFra);
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const src)
{
    _FixedPoint = (float)(roundf(src * (1 << _NbrFra)));
    std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
    return ((float)_FixedPoint / (float)(1 << _NbrFra));
}

int Fixed::toInt(void) const
{
    return ((int)_FixedPoint / (int)(1 << _NbrFra));
}

std::ostream & operator<<(std::ostream & o ,Fixed const & src)
{
    o<<src.toFloat();
    return(o);
}
