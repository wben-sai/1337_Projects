/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 14:49:33 by wben-sai          #+#    #+#             */
/*   Updated: 2021/09/26 18:20:13 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _FixedPoint(0)
{
    //std::cout << "Default Constructor called" << std::endl;
    return;
}

Fixed::Fixed(Fixed const & src)
{
    //std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return;
}

Fixed::~Fixed(void)
{
    //std::cout << "Destructor called" << std::endl;
    return;
}

Fixed& Fixed::operator=(Fixed const & src)
{
    //std::cout << "Assignation operator called" << std::endl;
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
    //std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const src)
{
    _FixedPoint = (float)(roundf(src * (1 << _NbrFra)));
    //std::cout << "Float constructor called" << std::endl;
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


//ex02

bool operator>(Fixed const &a, Fixed const &b)
{
    return(a.getRawBits() > b.getRawBits());
}

bool operator<(Fixed const &a, Fixed const &b)
{
    return(a.getRawBits() < b.getRawBits());
}

bool operator>=(Fixed const &a, Fixed const &b)
{
    return(a.getRawBits() >= b.getRawBits());
}

bool operator<=(Fixed const &a, Fixed const &b)
{
    return(a.getRawBits() <= b.getRawBits());
}

bool operator==(Fixed const &a, Fixed const &b)
{
    return(a.getRawBits() == b.getRawBits());
}

bool operator!=(Fixed const &a, Fixed const &b)
{
    return(a.getRawBits() != b.getRawBits());
}

Fixed Fixed::operator+(const Fixed &b) const
{
    return (Fixed(this->toFloat() + b.toFloat()));
}

Fixed Fixed::operator-(const Fixed &b) const
{
    return (Fixed(this->toFloat() - b.toFloat()));
}

Fixed Fixed::operator*(const Fixed &b) const
{
    return (Fixed(this->toFloat() * b.toFloat()));
}

Fixed Fixed::operator/(const Fixed &b) const
{
    return (Fixed(this->toFloat() / b.toFloat()));
}

Fixed& Fixed::operator++()
{
    this->_FixedPoint++;
    return *this;
}

Fixed& Fixed::operator--()
{
    this->_FixedPoint--;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->_FixedPoint++;
    return (temp);
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->_FixedPoint--;
    return (temp);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    if(a._FixedPoint > b._FixedPoint)
        return (b);
    return (a);
}

const Fixed& Fixed::min(Fixed const &a, Fixed const &b)
{
    if(a._FixedPoint > b._FixedPoint)
        return (b);
    return (a);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    if(a._FixedPoint < b._FixedPoint)
        return (b);
    return (a);
}

const Fixed& Fixed::max(Fixed const &a, Fixed const &b)
{
    if(a._FixedPoint < b._FixedPoint)
        return (b);
    return (a);
}