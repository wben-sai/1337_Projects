/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:51:21 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/05 08:37:01 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{

    Animal* j = new Dog();
    Animal* i = new Cat();
    //Animal* x = new Animal();
    //Animal z;
    j->makeSound();
    i->makeSound();
    delete j;
    delete i;

}