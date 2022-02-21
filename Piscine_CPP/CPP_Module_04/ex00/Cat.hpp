/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:25:41 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/02 14:19:20 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Animal.hpp"

#ifndef CAT_H
#define CAT_H

class Cat : public Animal
{
    public :
        Cat(void);
        Cat(Cat const & src);
        ~Cat(void);
        Cat& operator=(Cat const & src);
        
        void makeSound() const;
    private :
};

#endif