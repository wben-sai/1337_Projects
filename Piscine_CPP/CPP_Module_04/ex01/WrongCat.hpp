/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:25:41 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/02 17:47:43 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "WrongAnimal.hpp"

#ifndef WRONGCAT_H
#define WRONGCAT_H

class WrongCat : public WrongAnimal
{
    public :
        WrongCat(void);
        WrongCat(WrongCat const & src);
        ~WrongCat(void);
        WrongCat& operator=(WrongCat const & src);
        
        void makeSound() const;
    private :
};

#endif