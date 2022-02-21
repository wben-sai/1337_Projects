/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:51:21 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/04 14:42:00 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    int i = -1;
    int len = 10;
    Animal *array[len];
    
    while (++i < len)
    {
        if(i % 2  == 0)
            array[i] = new Cat();
        else
            array[i] = new Dog();
    }
    
    i = -1;
    while (++i < len)
    {
        std::cout  << array[i]->getType() << std::endl;
    }

    Cat testcopy;
    {
        Cat testcopy2 = testcopy;
        std::cout << (testcopy2.printBrain())<<  std::endl;
        std::cout << (testcopy.printBrain()) << std::endl;
    }

    Dog testcopy3;
    {
        Dog testcopy4 = testcopy3;
        std::cout << (testcopy3.printBrain())<<  std::endl;
        std::cout << (testcopy4.printBrain()) << std::endl;
    }
    
    i = -1;
    while (++i < len)
        delete array[i];
        
    return(0);
}