/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:25:41 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/04 13:25:02 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

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
        Brain* printBrain();
    private :
        Brain* brain;
};

#endif