/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:14:51 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/04 14:36:46 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

#ifndef DOG__H
#define DOG__H

class Dog : public Animal
{
    public :
        Dog(void);
        Dog(Dog const & src);
        ~Dog(void);
        Dog& operator=(Dog const & src);
        
        void makeSound() const;
        Brain *printBrain();
    private :
        Brain* brain;
};

#endif