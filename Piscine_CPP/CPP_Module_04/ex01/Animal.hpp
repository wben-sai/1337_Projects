/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 09:17:25 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/03 16:05:26 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#ifndef ANIMAL_H
#define ANIMAL_H

class Animal
{
    public :
        Animal(void);
        Animal(Animal const & src);
        virtual ~Animal(void);
        Animal& operator=(Animal const & src);
    
        Animal(std::string type);
        virtual void makeSound() const;
        std::string getType() const;
    protected:
        std::string type;
};

#endif