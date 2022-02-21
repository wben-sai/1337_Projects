/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:16:00 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/10 16:19:21 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAST_H
#define CAST_H

#include <iostream>

class cast
{
    private:
        std::string str;
    public:
        cast(void);
        cast(cast const & src);
        ~cast(void);
        cast& operator=(cast const & src);
        
        cast(std::string str);
        operator int ();
        operator char ();
        operator float ();
        operator double ();
};

#endif