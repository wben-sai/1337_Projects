/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 14:49:57 by wben-sai          #+#    #+#             */
/*   Updated: 2021/09/25 15:56:22 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#ifndef FIXED__H
#define FIXED__H

class Fixed
{
    public :
        Fixed(void);
        Fixed(Fixed const & src);
        ~Fixed(void);
        Fixed& operator=(Fixed const & src);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        
    private:
        int _FixedPoint;
        static const int _NbrFra = 8;
};

#endif